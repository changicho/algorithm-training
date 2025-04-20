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
// space : O(E + V)
class Solution {
 private:
  struct Edge {
    int from, to, cost;

    bool operator<(const Edge &b) const { return cost > b.cost; }
  };

 public:
  int minimumDistance(int n, vector<vector<int>> &edges, int s,
                      vector<int> &marked) {
    vector<vector<Edge>> graph(n);
    for (vector<int> &e : edges) {
      int from = e[0], to = e[1], cost = e[2];

      graph[from].push_back({from, to, cost});
    }

    vector<int> costs(n, INT_MAX);
    priority_queue<Edge> pq;
    pq.push({-1, s, 0});

    while (!pq.empty()) {
      Edge cur = pq.top();
      pq.pop();

      if (costs[cur.to] < cur.cost) continue;

      for (Edge &next : graph[cur.to]) {
        int nCost = cur.cost + next.cost;

        if (costs[next.to] < nCost) continue;
        costs[next.to] = nCost;
        pq.push({next.from, next.to, nCost});
      }
    }

    int answer = INT_MAX;
    for (int &node : marked) {
      answer = min(costs[node], answer);
    }
    if (answer == INT_MAX) return -1;
    return answer;
  }
};