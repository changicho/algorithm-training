#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use BFS
// time : O(E \* K)
// space : O(N + E \* K)
class Solution {
 private:
  struct Edge {
    int from, to, cost;
  };

  struct Status {
    int node, cost, step;
  };

 public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int k) {
    vector<vector<Edge>> graph(n);
    vector<int> minCosts(n, INT_MAX);

    for (vector<int> &f : flights) {
      int from = f[0], to = f[1], cost = f[2];

      graph[from].push_back({from, to, cost});
    }

    queue<Status> q;
    q.push({src, 0, 0});

    int answer = INT_MAX;
    while (!q.empty()) {
      Status cur = q.front();
      q.pop();

      if (cur.step > k + 1) continue;
      if (minCosts[cur.node] < cur.cost) continue;
      minCosts[cur.node] = cur.cost;
      if (cur.node == dst) {
        answer = min(answer, cur.cost);
      }

      for (Edge &e : graph[cur.node]) {
        q.push({e.to, cur.cost + e.cost, cur.step + 1});
      }
    }

    return answer == INT_MAX ? -1 : answer;
  }
};

// use bellman ford
// time : O(E * K)
// space : O(N * K)
class Solution {
 public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int k) {
    // dp[step][node]; Dist to reach node using atmost step edges from src
    vector<vector<int>> dp(k + 2, vector<int>(n, INT_MAX));
    for (int step = 0; step <= k + 1; step++) {
      dp[step][src] = 0;  // Dist to reach src always zero
    }

    for (int step = 1; step <= k + 1; step++) {
      for (vector<int> &f : flights) {
        int from = f[0], to = f[1], cost = f[2];

        if (dp[step - 1][from] != INT_MAX)
          dp[step][to] = min(dp[step][to], dp[step - 1][from] + cost);
      }
    }

    return (dp[k + 1][dst] == INT_MAX) ? -1 : dp[k + 1][dst];
  }
};