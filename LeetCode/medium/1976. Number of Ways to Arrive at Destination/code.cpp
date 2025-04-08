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
// time : O(E * log_2(V))
// space : O(V + E)
class Solution {
 private:
  const int MOD = 1e9 + 7;

  struct Edge {
    int from, to;
    long long cost;

    bool operator<(const Edge &b) const { return cost > b.cost; }
  };

 public:
  int countPaths(int n, vector<vector<int>> &roads) {
    vector<vector<Edge>> graph(n);
    for (vector<int> &e : roads) {
      int a = e[0], b = e[1], c = e[2];

      graph[a].push_back({a, b, c});
      graph[b].push_back({b, a, c});
    }

    priority_queue<Edge> pq;

    vector<long long> costs(n, LLONG_MAX);
    vector<int> counts(n, 0);

    costs[0] = 0;
    counts[0] = 1;

    pq.push({-1, 0, 0});
    while (!pq.empty()) {
      Edge cur = pq.top();
      pq.pop();

      long long cost = cur.cost;
      int node = cur.to;

      if (cost > costs[node]) continue;

      for (Edge &next : graph[node]) {
        if (cost + next.cost < costs[next.to]) {
          costs[next.to] = cost + next.cost;
          counts[next.to] = counts[node];

          pq.push({next.from, next.to, costs[next.to]});
        } else if (cost + next.cost == costs[next.to]) {
          counts[next.to] += counts[node];
          counts[next.to] %= MOD;
        }
      }
    }

    return counts[n - 1];
  }
};