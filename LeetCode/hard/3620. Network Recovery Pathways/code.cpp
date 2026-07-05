#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

using ll = long long;

// binary search & DFS
// time : O((V + E) * log_2(C))
// space : O(V + E)
class Solution {
 private:
  struct Edge {
    int a, b;
    long long c;

    bool operator<(const Edge& b) const { return c > b.c; }
  };

  bool check(vector<vector<Edge>>& graph, vector<bool>& online, int limit,
             long long k) {
    int size = online.size();

    vector<long long> dp(size + 1, -1);

    auto recursive = [&](this auto&& recursive, int u) -> long long {
      if (u == size - 1) {
        return 0;
      }
      if (dp[u] != -1) {
        return dp[u];
      }
      long long ret = LLONG_MAX / 2;
      for (auto& [a, b, c] : graph[u]) {
        if (c < limit) continue;

        long long newCost = recursive(b) + c;
        ret = min(ret, newCost);
      }
      return dp[u] = ret;
    };

    return recursive(0) <= k;
  }

 public:
  int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
                       long long k) {
    int size = online.size();
    vector<vector<Edge>> graph(size + 1);

    int left = INT_MAX, right = 0;

    for (vector<int>& e : edges) {
      int a = e[0], b = e[1], c = e[2];

      if (!online[a] || !online[b]) continue;

      left = min(left, c);
      right = max(right, c);

      graph[a].push_back({a, b, c});
    }

    if (!check(graph, online, left, k)) return -1;

    int answer = -1;
    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (check(graph, online, mid, k)) {
        left = mid + 1;
        answer = max(answer, mid);
      } else {
        right = mid - 1;
      }
    }

    return answer;
  }
};