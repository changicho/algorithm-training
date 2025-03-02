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
// time : O(V + E + V * log_2(E))
// space : O(V + E)
class Solution {
 private:
  struct Edge {
    int a, b, w;

    bool operator<(const Edge &b) const { return w > b.w; }
  };

 public:
  int minMaxWeight(int n, vector<vector<int>> &edges, int threshold) {
    vector<vector<Edge>> graph(n);

    vector<int> outDegrees(n);
    for (vector<int> &e : edges) {
      graph[e[1]].push_back({e[1], e[0], e[2]});
      outDegrees[e[0]]++;
    }

    vector<int> costs(n, INT_MAX);
    priority_queue<Edge> pq;
    pq.push({-1, 0, 0});

    int maxW = 0;
    while (!pq.empty()) {
      Edge cur = pq.top();
      pq.pop();

      if (cur.w >= costs[cur.b]) {
        outDegrees[cur.b]--;
        continue;
      }

      costs[cur.b] = cur.w;

      maxW = max(maxW, cur.w);

      for (Edge &e : graph[cur.b]) {
        pq.push({e.a, e.b, max(e.w, cur.w)});
      }
    }

    for (int i = 0; i < n; i++) {
      if (outDegrees[i] > threshold) return -1;
    }
    for (int i = 0; i < n; i++) {
      if (costs[i] == INT_MAX) return -1;
    }
    return maxW;
  }
};