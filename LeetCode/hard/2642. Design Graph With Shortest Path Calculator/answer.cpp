#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use dijkstra
// time : O(N + M * (V + E * log_2(V)))
// space : O(V + E + N)
class Graph {
 private:
  struct Edge {
    int from, to, cost;

    bool operator<(const Edge &b) const { return cost > b.cost; }
  };

  vector<vector<Edge>> graph;

 public:
  Graph(int n, vector<vector<int>> &edges) {
    graph.resize(n);
    for (vector<int> &e : edges) {
      int from = e[0], to = e[1], cost = e[2];

      graph[from].push_back({from, to, cost});
      // graph[to].push_back({to, from, cost});
    }
  }

  void addEdge(vector<int> edge) {
    int from = edge[0], to = edge[1], cost = edge[2];

    graph[from].push_back({from, to, cost});
  }

  int shortestPath(int node1, int node2) {
    int size = graph.size();
    priority_queue<Edge> pq;
    vector<int> costs(size, INT_MAX);

    costs[node1] = 0;
    pq.push({-1, node1, 0});

    while (!pq.empty()) {
      Edge cur = pq.top();
      pq.pop();

      for (Edge &next : graph[cur.to]) {
        if (costs[next.to] <= next.cost + cur.cost) continue;
        costs[next.to] = next.cost + cur.cost;
        pq.push({next.from, next.to, next.cost + cur.cost});
      }
    }

    if (costs[node2] == INT_MAX) return -1;
    return costs[node2];
  }
};
