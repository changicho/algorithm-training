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

// use dynamic programming
// time : O(Q * (N + Q))
// space : O(N + Q)
class Solution {
 private:
  int calc(vector<vector<int>> &graph, int n) {
    vector<int> dp(n);
    dp[n - 1] = 0;

    for (int cur = n - 2; cur >= 0; cur--) {
      int minimum = n;

      for (int &next : graph[cur]) {
        minimum = min(minimum, dp[next] + 1);
      }
      dp[cur] = minimum;
    }
    return dp[0];
  }

 public:
  vector<int> shortestDistanceAfterQueries(int n,
                                           vector<vector<int>> &queries) {
    vector<int> answer;
    vector<vector<int>> graph(n);

    for (int i = 0; i < n - 1; i++) {
      graph[i].push_back(i + 1);
    }

    for (vector<int> &query : queries) {
      int a = query[0];
      int b = query[1];
      graph[a].push_back(b);

      answer.push_back(calc(graph, n));
    }
    return answer;
  }
};