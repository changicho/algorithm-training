#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use step dijkstra
// time : O((K * V + E) * log_2(K * V))
// space : O(K * V + E)
class Solution {
 private:
  struct Edge {
    int from, to, cost;

    int discount;

    bool operator<(const Edge &b) const { return cost > b.cost; }
  };

 public:
  int minimumCost(int n, vector<vector<int>> &highways, int discounts) {
    vector<vector<int>> costs(discounts + 1, vector<int>(n, INT_MAX));
    vector<vector<Edge>> graph(n);

    for (vector<int> &edge : highways) {
      int from = edge[0], to = edge[1], cost = edge[2];

      graph[from].push_back({from, to, cost, 0});
      graph[to].push_back({to, from, cost, 0});
    }

    priority_queue<Edge> pq;
    pq.push({-1, 0, 0, discounts});
    costs[discounts][0] = 0;

    while (!pq.empty()) {
      Edge cur = pq.top();
      pq.pop();

      for (Edge &next : graph[cur.to]) {
        int from = next.from, to = next.to, cost = next.cost;

        if (costs[cur.discount][to] > (cur.cost + cost)) {
          costs[cur.discount][to] = (cur.cost + cost);
          pq.push({from, to, cur.cost + cost, cur.discount});
        }

        if (cur.discount > 0 &&
            costs[cur.discount - 1][to] > (cur.cost + cost / 2)) {
          costs[cur.discount - 1][to] = (cur.cost + cost / 2);
          pq.push({from, to, cur.cost + cost / 2, cur.discount - 1});
        }
      }
    }

    int answer = INT_MAX;
    for (int i = 0; i <= discounts; i++) {
      answer = min(answer, costs[i][n - 1]);
    }

    if (answer == INT_MAX) return -1;
    return answer;
  }
};