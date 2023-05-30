#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming (bottom-up)
// time : O(M^3)
// space : O(M^2)
class Solution {
 public:
  int minCost(int n, vector<int>& cuts) {
    cuts.push_back(0);
    cuts.push_back(n);

    sort(cuts.begin(), cuts.end());

    int size = cuts.size();
    vector<vector<int>> dp(size, vector<int>(size, INT_MAX));

    for (int i = 0; i < size - 1; i++) {
      dp[i][i + 1] = 0;
    }
    for (int i = 0; i < size - 2; i++) {
      dp[i][i + 2] = cuts[i + 2] - cuts[i];
    }

    for (int len = 4; len <= size; len++) {
      for (int left = 0; left <= size - len; left++) {
        int right = left + len - 1;

        for (int mid = left + 1; mid < right; mid++) {
          int cur = dp[left][mid] + dp[mid][right] + cuts[right] - cuts[left];

          dp[left][right] = min(dp[left][right], cur);
        }
      }
    }

    return dp[0][size - 1];
  }
};

// use dynamic programming (top-down)
// time : O(M^3)
// space : O(M^2)
class Solution {
 private:
  int dp[102][102] = {};
  vector<int> cuts;

  int recursive(int left, int right) {
    if (right - left <= 1) return 0;

    if (dp[left][right]) return dp[left][right];
    dp[left][right] = INT_MAX;

    for (int mid = left + 1; mid <= right - 1; mid++) {
      int cur = cuts[right] - cuts[left] + recursive(left, mid) +
                recursive(mid, right);

      dp[left][right] = min(dp[left][right], cur);
    }

    return dp[left][right];
  }

 public:
  int minCost(int n, vector<int>& cuts) {
    cuts.push_back(0);
    cuts.push_back(n);
    sort(begin(cuts), end(cuts));

    this->cuts = cuts;

    int size = cuts.size();
    recursive(0, size - 1);

    return dp[0][size - 1];
  }
};