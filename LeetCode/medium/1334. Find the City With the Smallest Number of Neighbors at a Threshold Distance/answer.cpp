#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use floyd warshall

class Solution {
 public:
  int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    // we can calculate INT_MAX + INT_MAX case when we update
    // so value must not overflow
    vector<vector<int>> costs(n, vector<int>(n, INT_MAX / 10));

    // initialize costs
    for (vector<int>& edge : edges) {
      int from = edge[0], to = edge[1], cost = edge[2];

      costs[from][to] = cost;
      costs[to][from] = cost;
    }
    for (int node = 0; node < n; node++) {
      costs[node][node] = 0;
    }

    // use floyd warshall
    for (int through = 0; through < n; through++) {
      for (int from = 0; from < n; from++) {
        for (int to = 0; to < n; to++) {
          costs[from][to] =
              min(costs[from][to], costs[from][through] + costs[through][to]);
        }
      }
    }

    // update answer

    int neighbors = n;
    int answer = -1;
    for (int from = 0; from < n; from++) {
      int count = 0;
      for (int to = 0; to < n; to++) {
        if (from == to) continue;

        if (costs[from][to] <= distanceThreshold) count++;
      }

      if (count <= neighbors) {
        neighbors = min(neighbors, count);
        answer = from;
      }
    }

    return answer;
  }
};