#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define MAX 100000001

using namespace std;

struct Edge {
  int to, cost;
};

struct Route {
  int cost;
  vector<int> nodes;
};

struct Status {
  Edge edge;
  vector<int> nodes;

  bool operator<(const Status &b) const {
    return edge.cost > b.edge.cost;
  }
};

int N, M;
vector<vector<Edge>> graph;
vector<int> costs;
vector<vector<int>> routes;

void solution() {
  cin >> N >> M;

  graph.resize(N + 1);
  routes.resize(N + 1);
  costs.resize(N + 1, MAX);

  int from, to, cost;
  for (int i = 0; i < M; i++) {
    cin >> from >> to >> cost;

    graph[from].push_back({to, cost});
  }

  cin >> from >> to;
  costs[from] = 0;

  priority_queue<Status> pq;
  pq.push({{from, 0}, {from}});

  while (!pq.empty()) {
    Status cur = pq.top();
    Edge curEdge = cur.edge;
    pq.pop();

    for (Edge next : graph[curEdge.to]) {
      int new_val = costs[curEdge.to] + next.cost;
      int before_val = costs[next.to];

      if (new_val < before_val) {
        vector<int> nodes = cur.nodes;
        nodes.push_back(next.to);

        costs[next.to] = new_val;
        routes[next.to] = nodes;

        pq.push({{next.to, new_val}, nodes});
      }
    }
  }

  cout << costs[to] << "\n";
  cout << routes[to].size() << "\n";
  for (int node : routes[to]) {
    cout << node << " ";
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