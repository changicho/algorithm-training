#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use 3 dijkstra
// time : O(E * log_2(V))
// space : O(V)
class Solution {
 private:
  struct Edge {
    int from, to;
    long long cost;

    bool operator<(const Edge &b) const { return cost > b.cost; }
  };

  void dijkstra(vector<vector<Edge>> &graph, vector<long long> &costs,
                int src) {
    priority_queue<Edge> pq;

    pq.push({0, src, 0});
    while (!pq.empty()) {
      Edge cur = pq.top();
      pq.pop();

      if (costs[cur.to] <= cur.cost) continue;
      costs[cur.to] = cur.cost;

      for (Edge &next : graph[cur.to]) {
        if (costs[next.to] > cur.cost + next.cost) {
          pq.push({next.from, next.to, cur.cost + next.cost});
        }
      }
    }
  }

 public:
  long long minimumWeight(int n, vector<vector<int>> &edges, int src1, int src2,
                          int dest) {
    vector<vector<Edge>> graph(n), reversed(n);

    for (vector<int> &edge : edges) {
      int from = edge[0], to = edge[1], cost = edge[2];
      graph[from].push_back({from, to, cost});
      reversed[to].push_back({to, from, cost});
    }

    priority_queue<Edge> pq;
    vector<long long> costs1(n, LONG_MAX), costs2(n, LONG_MAX),
        costsR(n, LONG_MAX);

    dijkstra(graph, costs1, src1);
    dijkstra(graph, costs2, src2);
    dijkstra(reversed, costsR, dest);

    long long answer = LONG_MAX;
    for (int node = 0; node < n; node++) {
      if (costs1[node] == LONG_MAX || costs2[node] == LONG_MAX ||
          costsR[node] == LONG_MAX)
        continue;
      answer = min(answer, costs1[node] + costs2[node] + costsR[node]);
    }
    return answer == LONG_MAX ? -1 : answer;
  }
};
