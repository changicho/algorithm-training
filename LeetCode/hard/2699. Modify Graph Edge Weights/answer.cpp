#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use dijkstra
// time : O(E * (E * log_2(V)))
// space : O(V)
class Solution {
 private:
  struct Edge {
    int from, to, cost;

    bool operator<(const Edge &b) const { return cost > b.cost; }
  };

  vector<vector<Edge>> graph;

  vector<int> dijkstra(int source, int destination) {
    vector<int> costs(graph.size(), INT_MAX);
    priority_queue<Edge> pq;
    pq.push({-1, source, 0});

    while (!pq.empty()) {
      Edge cur = pq.top();
      pq.pop();

      if (costs[cur.to] <= cur.cost) continue;
      costs[cur.to] = cur.cost;

      for (Edge &next : graph[cur.to]) {
        int nextCost = next.cost == -1 ? 0 : cur.cost + next.cost;
        pq.push({next.from, next.to, nextCost});
      }
    }
    return costs;
  }

 public:
  vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges,
                                         int source, int destination,
                                         int target) {
    graph.resize(n);
    vector<Edge> froms(n, {-1, -1, -1});

    for (vector<int> &e : edges) {
      int from = e[0], to = e[1], cost = e[2];

      if (cost == -1) {
        continue;
      }
      graph[from].push_back({from, to, cost});
      graph[to].push_back({to, from, cost});
    }

    vector<int> costs = dijkstra(source, destination);

    if (costs[destination] < target) {
      return {};
    }
    if (costs[destination] == target) {
      // convert all -1 edge to maximum number
      for (auto &it : edges) {
        if (it[2] == -1) it[2] = 2e9;
      }

      return edges;
    }

    for (int i = 0; i < edges.size(); i++) {
      vector<int> &e = edges[i];
      int &from = e[0], &to = e[1], &cost = e[2];

      if (cost != -1) continue;

      cost = 1;
      graph[from].push_back({from, to, cost});
      graph[to].push_back({to, from, cost});

      vector<int> costs = dijkstra(source, destination);

      if (costs[destination] <= target) {
        cost += (target - costs[destination]);

        for (int j = i + 1; j < edges.size(); j++) {
          // convert all -1 edge to maximum number
          if (edges[j][2] == -1) edges[j][2] = 2e9;
        }
        return edges;
      }
    }
    return {};
  }
};