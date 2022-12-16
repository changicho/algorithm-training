#include <algorithm>
#include <climits>
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

vector<double> solution(int size, vector<vector<bool>> &graph, int day,
                        int start, vector<int> &targets) {
  vector<double> counts(size, 0);
  counts[start] = 1;

  while (day--) {
    vector<double> curCounts(size, 0);

    for (int from = 0; from < size; from++) {
      double allCaseCount = 0;
      for (int to = 0; to < size; to++) {
        if (graph[from][to]) allCaseCount++;
      }

      for (int to = 0; to < size; to++) {
        if (!graph[from][to]) continue;

        curCounts[to] += counts[from] / allCaseCount;
      }
    }

    counts = curCounts;
  }

  vector<double> answer;
  for (int &target : targets) {
    answer.push_back(counts[target]);
  }
  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // decimal point
  cout << fixed;
  cout.precision(8);

  freopen("./input.txt", "r", stdin);

  int C;
  cin >> C;

  for (int testCase = 1; testCase <= C; testCase++) {
    int N, D, P, Q;
    cin >> N >> D >> P;

    vector<vector<bool>> graph(N, vector<bool>(N, false));

    for (int y = 0; y < N; y++) {
      for (int x = 0; x < N; x++) {
        int temp;
        cin >> temp;
        graph[y][x] = temp;
      }
    }

    cin >> Q;
    vector<int> targets(Q);
    for (int i = 0; i < Q; i++) {
      cin >> targets[i];
    }

    vector<double> answer = solution(N, graph, D, P, targets);

    for (double &cur : answer) {
      cout << cur << " ";
    }
    cout << "\n";
  }

  return 0;
}
