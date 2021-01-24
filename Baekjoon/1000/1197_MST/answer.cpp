#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Edge {
  int vertex, cost;
};

struct Status {
  Edge edge;

  bool operator<(const Status &b) const {
    return edge.cost > b.edge.cost;
  }
};

void solution() {
  int V, E;
  cin >> V >> E;

  vector<vector<Edge>> graph(V + 1);

  int from, to, cost;
  for (int i = 0; i < E; i++) {
    cin >> from >> to >> cost;
    graph[from].push_back({to, cost});
    graph[to].push_back({from, cost});
  }

  // Prim's Algorithm
  priority_queue<Status> pq;
  vector<bool> visited(V + 1, false);

  visited[1] = true;
  for (Edge cur : graph[1]) {
    pq.push({cur});
  }

  long long answer = 0;

  while (!pq.empty()) {
    Status cur = pq.top();
    pq.pop();
    Edge edge = cur.edge;

    if (visited[edge.vertex]) continue;
    visited[edge.vertex] = true;

    answer += edge.cost;

    for (Edge next : graph[edge.vertex]) {
      pq.push({next});
    }
  }

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}