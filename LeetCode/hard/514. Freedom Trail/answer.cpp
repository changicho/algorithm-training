#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(K * N^2)
// space : O(K * N)
class Solution {
 public:
  int findRotateSteps(string ring, string key) {
    int size = ring.size();
    int kSize = key.size();

    vector<vector<int>> dp(kSize, vector<int>(size, INT_MAX));
    for (int i = 0; i < size; i++) {
      if (ring[i] == key[0]) {
        int step = 1 + i;
        int rStep = 1 + (size - i);

        dp[0][i] = min({dp[0][i], step, rStep});
      }
    }

    for (int i = 1; i < kSize; i++) {
      for (int target = 0; target < size; target++) {
        if (ring[target] != key[i]) continue;

        for (int before = 0; before < size; before++) {
          int beforeStep = dp[i - 1][before];
          if (beforeStep == INT_MAX) continue;

          int bigger = max(before, target), smaller = min(before, target);
          int step = bigger - smaller + 1;
          int rStep = (smaller + size) - bigger + 1;

          dp[i][target] =
              min({dp[i][target], beforeStep + step, beforeStep + rStep});
        }
      }
    }

    int answer = *min_element(dp[kSize - 1].begin(), dp[kSize - 1].end());
    return answer;
  }
};

// use dynamic programming
// time : O(K * N^2)
// space : O(K * N)
class Solution {
 public:
  int findRotateSteps(string ring, string key) {
    int size = ring.size();
    int kSize = key.size();

    vector<vector<int>> dp(kSize, vector<int>(size, INT_MAX));

    for (int i = 0; i < kSize; i++) {
      for (int target = 0; target < size; target++) {
        if (ring[target] != key[i]) continue;

        for (int before = 0; before < size; before++) {
          if (i - 1 < 0 && before > 0) break;
          int beforeStep = (i - 1 < 0) ? 0 : dp[i - 1][before];

          if (beforeStep == INT_MAX) continue;

          int bigger = max(before, target), smaller = min(before, target);
          int step = bigger - smaller + 1;
          int rStep = (smaller + size) - bigger + 1;

          dp[i][target] =
              min({dp[i][target], beforeStep + step, beforeStep + rStep});
        }
      }
    }

    int answer = *min_element(dp[kSize - 1].begin(), dp[kSize - 1].end());
    return answer;
  }
};

// use dynamic programming (space optimized)
// time : O(K * N^2)
// space : O(N)
class Solution {
 public:
  int findRotateSteps(string ring, string key) {
    int size = ring.size();
    int kSize = key.size();

    vector<int> dp(size, INT_MAX);
    for (int i = 0; i < size; i++) {
      if (ring[i] == key[0]) {
        int step = 1 + i;
        int rStep = 1 + (size - i);

        dp[i] = min({dp[i], step, rStep});
      }
    }

    for (int i = 1; i < kSize; i++) {
      vector<int> newDp(size, INT_MAX);

      for (int target = 0; target < size; target++) {
        if (ring[target] != key[i]) continue;

        for (int before = 0; before < size; before++) {
          int beforeStep = dp[before];
          if (beforeStep == INT_MAX) continue;

          int bigger = max(before, target), smaller = min(before, target);
          int step = bigger - smaller + 1;
          int rStep = (smaller + size) - bigger + 1;

          newDp[target] =
              min({newDp[target], beforeStep + step, beforeStep + rStep});
        }
      }

      dp = newDp;
    }

    int answer = *min_element(dp.begin(), dp.end());
    return answer;
  }
};