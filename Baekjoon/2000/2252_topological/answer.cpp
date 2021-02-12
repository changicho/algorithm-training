#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N, M;
  cin >> N >> M;

  vector<vector<int> > graph(N + 1);
  vector<int> inDegree(N + 1);
  vector<int> result(N);

  int from, to;
  for (int i = 0; i < M; i++) {
    cin >> from >> to;

    inDegree[to] += 1;
    graph[from].push_back(to);
  }

  queue<int> q;
  for (int node = 1; node <= N; node++) {
    if (inDegree[node] == 0) {
      q.push(node);
    }
  }

  for (int index = 0; index < N; index++) {
    if (q.empty()) {
      break;
    }

    int cur = q.front();
    q.pop();
    result[index] = cur;

    for (int next : graph[cur]) {
      inDegree[next]--;

      if (inDegree[next] == 0) {
        q.push(next);
      }
    }
  }

  for (int node : result) {
    cout << node << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}