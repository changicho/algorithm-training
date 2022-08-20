#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// time : 40min
long long recursive(int node, vector<long long> &totalValues,
                    vector<int> &values, vector<vector<int>> &graph,
                    vector<bool> &visited) {
  if (visited[node]) return 0;
  visited[node] = true;
  long long valueSum = 0;

  for (int &next : graph[node]) {
    if (visited[next]) continue;
    long long nextVal = recursive(next, totalValues, values, graph, visited);
    valueSum = max(valueSum, nextVal);
  }

  valueSum += values[node];
  visited[node] = false;
  totalValues[node] = valueSum;
  return valueSum;
}

long long solution(int n, vector<int> &values, vector<vector<int>> &graph) {
  vector<long long> totalValues(n + 1, 0);
  totalValues[1] = values[1];

  vector<bool> visited(n + 1, false);

  recursive(1, totalValues, values, graph, visited);

  vector<long long> maxSums;
  for (int &child : graph[1]) {
    maxSums.push_back(totalValues[child]);
  }
  sort(maxSums.begin(), maxSums.end(), greater<long long>());

  long long answer = values[1];
  if (maxSums.size() >= 1) {
    answer += maxSums[0];
  }
  if (maxSums.size() >= 2) {
    answer += maxSums[1];
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int N;
    cin >> N;

    vector<int> values(N + 1);
    for (int i = 0; i < N; i++) {
      cin >> values[i + 1];
    }

    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < N - 1; i++) {
      int A, B;
      cin >> A >> B;

      graph[A].push_back(B);
      graph[B].push_back(A);
    }

    long long answer = solution(N, values, graph);

    cout << "Case #" << testCase << ": ";
    cout << answer << "\n";
  }

  return 0;
}