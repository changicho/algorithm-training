#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define INF 800001

using namespace std;

struct Edge {
  int to, cost;

  bool operator<(const Edge &b) const {
    return cost > b.cost;
  }
};

vector<vector<Edge>> graph;
vector<int> costs;

void dijkstra(int from) {
  priority_queue<Edge> pq;

  costs[from] = 0;
  pq.push({from, 0});

  while (!pq.empty()) {
    Edge cur = pq.top();
    pq.pop();

    for (Edge next : graph[cur.to]) {
      int new_val = costs[cur.to] + next.cost;
      int before_val = costs[next.to];

      if (new_val < before_val) {
        costs[next.to] = new_val;
        pq.push({next.to, new_val});
      }
    }
  }
}

void solution() {
  int N, E;
  int from, to, cost;

  cin >> N >> E;

  graph.resize(N + 1);

  for (int i = 0; i < E; i++) {
    cin >> from >> to >> cost;

    graph[from].push_back({to, cost});
    graph[to].push_back({from, cost});
  }

  int v1, v2;
  cin >> v1 >> v2;

  int v1_to_v2 = 0, v2_to_v1 = 0;

  costs.clear();
  costs.resize(N + 1, INF);
  dijkstra(1);

  v1_to_v2 += costs[v1];
  v2_to_v1 += costs[v2];

  costs.clear();
  costs.resize(N + 1, INF);
  dijkstra(v1);
  int throughCost = costs[v2];

  v1_to_v2 += throughCost;
  v2_to_v1 += throughCost;

  costs.clear();
  costs.resize(N + 1, INF);
  dijkstra(N);

  v1_to_v2 += costs[v2];
  v2_to_v1 += costs[v1];

  int answer = min(v1_to_v2, v2_to_v1);
  if (answer >= INF) answer = -1;

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}