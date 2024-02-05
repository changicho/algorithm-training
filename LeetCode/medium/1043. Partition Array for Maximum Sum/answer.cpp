#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N * K)
// space : O(N)
class Solution {
 public:
  int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int size = arr.size();
    vector<int> dp(size);

    for (int i = 0; i < size; i++) {
      int maximum = 0, best = 0;

      for (int chosen = 1; chosen <= k; chosen++) {
        int curI = i - (chosen - 1);
        int beforeI = curI - 1;

        if (curI < 0) break;
        maximum = max(maximum, arr[curI]);

        int curBest = maximum * (chosen) + (beforeI < 0 ? 0 : dp[beforeI]);

        best = max(best, curBest);
      }
      dp[i] = best;
    }

    return dp[size - 1];
  }
};