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

long long solution(int size, vector<int> &a, vector<int> &b) {
  unordered_map<int, int> graph;

  for (int i = 0; i < size; i++) {
    int first = a[i], second = b[i];

    graph[first] = second;
  }

  vector<bool> visited(size + 1, false);

  long long edgeCount = 0;
  for (int i = 1; i <= size; i++) {
    int cycleSize = 0;
    queue<int> q;
    q.push(i);

    // use BFS to count cycle size
    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      if (visited[cur]) continue;
      visited[cur] = true;
      cycleSize++;

      q.push(graph[cur]);
    }
    // cycleSize / 2 is min('peakCount','valleyCount')
    edgeCount += cycleSize / 2;
  }

  return edgeCount * (size - edgeCount) * 2;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 0; testCase < T; testCase++) {
    int N;
    cin >> N;

    vector<int> first(N), second(N);
    for (int i = 0; i < N; i++) {
      cin >> first[i];
    }
    for (int i = 0; i < N; i++) {
      cin >> second[i];
    }

    long long res = solution(N, first, second);
    cout << res << "\n";
  }

  return 0;
}