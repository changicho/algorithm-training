#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use dijkstra
// time : O(E + V * log_2(E))
// space : O(V + E)
class Solution {
 private:
  struct Edge {
    int from, to, cost;

    bool operator<(const Edge& b) const { return b.cost < cost; }
  };

 public:
  int minCost(int n, vector<vector<int>>& edges) {
    vector<vector<Edge>> graph(n);
    for (vector<int>& e : edges) {
      int from = e[0], to = e[1], cost = e[2];

      graph[from].push_back({from, to, cost});
      graph[to].push_back({to, from, cost * 2});
    }

    priority_queue<Edge> pq;
    pq.push({0, 0, 0});

    vector<int> costs(n + 1, INT_MAX);

    while (!pq.empty()) {
      Edge cur = pq.top();
      pq.pop();

      if (costs[cur.to] < cur.cost) continue;

      for (Edge& next : graph[cur.to]) {
        int nextCost = cur.cost + next.cost;
        if (nextCost >= costs[next.to]) continue;
        costs[next.to] = nextCost;

        pq.push({next.from, next.to, nextCost});
      }
    }

    if (costs[n - 1] == INT_MAX) return -1;
    return costs[n - 1];
  }
};