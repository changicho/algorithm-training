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

// dynamic programming
// time : O(N * D)
// space : O(N)
class Solution {
 private:
  vector<int> dp;

  int dfs(vector<int>& arr, int node, int d) {
    int size = arr.size();

    if (dp[node] != -1) {
      return dp[node];
    }
    dp[node] = 1;

    for (int i = 1; i <= d; i++) {
      if (node - i < 0 || arr[node] <= arr[node - i]) break;

      int cur = dfs(arr, node - i, d);
      dp[node] = max(dp[node], cur + 1);
    }

    for (int i = 1; i <= d; i++) {
      if (node + i >= size || arr[node] <= arr[node + i]) break;

      int cur = dfs(arr, node + i, d);
      dp[node] = max(dp[node], cur + 1);
    }

    return dp[node];
  }

 public:
  int maxJumps(vector<int>& arr, int d) {
    int size = arr.size();
    dp.resize(size, -1);

    int answer = 0;
    for (int i = 0; i < size; ++i) {
      int cur = dfs(arr, i, d);
      answer = max(answer, cur);
    }
    return answer;
  }
};