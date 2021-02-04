#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N, K;
  int target;
  cin >> N >> K;

  vector<vector<int>> graph;
  vector<int> inDegree;
  vector<int> costs, times;

  graph.resize(N + 1);
  costs.resize(N + 1);
  times.resize(N + 1);
  inDegree.resize(N + 1);

  for (int node = 1; node <= N; node++) {
    cin >> costs[node];
    times[node] = costs[node];
  }

  int from, to;
  for (int i = 0; i < K; i++) {
    cin >> from >> to;
    graph[from].push_back(to);
    inDegree[to] += 1;
  }

  cin >> target;

  queue<int> q;
  for (int node = 1; node <= N; node++) {
    if (inDegree[node] == 0) {
      q.push(node);
    }
  }

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (int next : graph[cur]) {
      times[next] = max(times[next], costs[next] + times[cur]);

      inDegree[next] -= 1;
      if (inDegree[next] == 0) {
        q.push(next);
      }
    }
  }

  cout << times[target] << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  while (T--) {
    solution();
  }

  return 0;
}