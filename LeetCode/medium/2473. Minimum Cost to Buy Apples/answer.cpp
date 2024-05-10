#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use dijkstra algorithm
// time : O(V * E * log_2(V))
// space : O(V + E)
class Solution {
 private:
  struct Edge {
    int from, to;
    long long cost;

    bool operator<(const Edge &b) const { return cost > b.cost; }
  };

 public:
  vector<long long> minCost(int n, vector<vector<int>> &roads,
                            vector<int> &appleCost, int k) {
    vector<vector<Edge>> graph(n);

    for (vector<int> &e : roads) {
      int from = e[0] - 1, to = e[1] - 1, cost = e[2];

      graph[from].push_back({from, to, cost});
      graph[to].push_back({to, from, cost});
    }

    vector<long long> answer(n);

    for (int start = 0; start < n; start++) {
      vector<long long> costs(n, LLONG_MAX);
      costs[start] = 0;

      priority_queue<Edge> pq;
      pq.push({-1, start, 0});

      while (!pq.empty()) {
        Edge cur = pq.top();
        pq.pop();

        for (Edge &e : graph[cur.to]) {
          long long nextCost = cur.cost + e.cost;

          if (costs[e.to] <= nextCost) continue;
          costs[e.to] = nextCost;

          pq.push({e.from, e.to, cur.cost + e.cost});
        }
      }

      long long ret = appleCost[start];
      for (int to = 0; to < n; to++) {
        if (costs[to] == LLONG_MAX) continue;
        ret = min(ret, costs[to] * (1 + k) + appleCost[to]);
      }
      answer[start] = ret;
    }
    return answer;
  }
};

// use one pass dijkstra
// time : O((V + E) * log_2(V + E))
// space : O(V + E)
class Solution {
 private:
  struct Edge {
    int from, to;
    long long cost;

    bool operator<(const Edge &b) const { return cost > b.cost; }
  };

 public:
  vector<long long> minCost(int n, vector<vector<int>> &roads,
                            vector<int> &appleCost, int k) {
    vector<vector<Edge>> graph(n);

    for (vector<int> &e : roads) {
      int from = e[0] - 1, to = e[1] - 1, cost = e[2];

      graph[from].push_back({from, to, cost});
      graph[to].push_back({to, from, cost});
    }

    vector<long long> answer(appleCost.begin(), appleCost.end());

    priority_queue<Edge> pq;
    for (int start = 0; start < n; start++) {
      pq.push({-1, start, appleCost[start]});
    }

    while (!pq.empty()) {
      Edge cur = pq.top();
      pq.pop();

      for (Edge &e : graph[cur.to]) {
        long long nextCost = answer[cur.to] + (k + 1) * e.cost;

        if (answer[e.to] > nextCost) {
          answer[e.to] = nextCost;

          pq.push({e.from, e.to, nextCost});
        }
      }
    }

    return answer;
  }
};