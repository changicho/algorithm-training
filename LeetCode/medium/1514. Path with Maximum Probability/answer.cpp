#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use dijkstra
// time : O(V * log_2(E))
// space : O(V + E)
class Solution {
 private:
  struct Edge {
    int from, to;
    double cost;

    bool operator<(const Edge& b) const { return cost < b.cost; }
  };

 public:
  double maxProbability(int n, vector<vector<int>>& edges,
                        vector<double>& succProb, int start, int end) {
    vector<vector<Edge>> graph(n);

    for (int i = 0; i < edges.size(); i++) {
      int from = edges[i][0], to = edges[i][1];
      double cost = succProb[i];

      graph[from].push_back({from, to, cost});
      graph[to].push_back({to, from, cost});
    }

    priority_queue<Edge> pq;
    pq.push({-1, start, 1.0});

    vector<double> visited(n, 0);

    while (!pq.empty()) {
      Edge cur = pq.top();
      pq.pop();

      if (visited[cur.to] >= cur.cost) continue;
      visited[cur.to] = cur.cost;

      if (cur.to == end) continue;

      for (Edge& next : graph[cur.to]) {
        pq.push({next.from, next.to, next.cost * cur.cost});
      }
    }

    return visited[end];
  }
};