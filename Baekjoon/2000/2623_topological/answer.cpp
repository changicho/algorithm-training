#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> graph;

void solution() {
  int N, M;

  cin >> N >> M;

  graph.resize(N + 1);
  vector<int> inDegree(N + 1, 0);
  vector<int> result(N);

  int size;
  while (M--) {
    cin >> size;
    if (size == 0) continue;

    vector<int> array(size);
    cin >> array[0];
    for (int i = 1; i < size; i++) {
      cin >> array[i];

      int from = array[i - 1], to = array[i];
      graph[from].push_back(to);
      inDegree[to] += 1;
    }
  }

  queue<int> q;
  for (int node = 1; node <= N; node++) {
    if (inDegree[node] == 0) {
      q.push(node);
    }
  }

  for (int index = 0; index < N; index++) {
    if (q.empty()) {
      result.resize(0);
      result.clear();
      result.push_back(0);

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
    cout << node << "\n";
  }
  cout << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}