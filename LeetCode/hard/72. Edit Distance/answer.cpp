#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming

class Solution {
 public:
  int minDistance(string word1, string word2) {
    int N = word1.size(), M = word2.size();
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));

    for (int idx1 = 1; idx1 <= N; idx1++) {
      dp[idx1][0] = idx1;
    }
    for (int idx2 = 1; idx2 <= M; idx2++) {
      dp[0][idx2] = idx2;
    }

    for (int idx1 = 1; idx1 <= N; idx1++) {
      for (int idx2 = 1; idx2 <= M; idx2++) {
        if (word1[idx1 - 1] == word2[idx2 - 1]) {
          dp[idx1][idx2] = dp[idx1 - 1][idx2 - 1];
          continue;
        }

        int fromFirst = dp[idx1 - 1][idx2];
        int fromSecond = dp[idx1][idx2 - 1];
        int fromBoth = dp[idx1 - 1][idx2 - 1];

        dp[idx1][idx2] = 1 + min(fromBoth, min(fromFirst, fromSecond));
      }
    }
    return dp[N][M];
  }
};

// use dynamic programming

class Solution {
 public:
  int minDistance(string word1, string word2) {
    int N = word1.size(), M = word2.size();
    vector<int> cur(M + 1, 0), pre(M + 1, 0);

    for (int idx2 = 1; idx2 <= M; idx2++) {
      pre[idx2] = idx2;
    }

    for (int idx1 = 1; idx1 <= N; idx1++) {
      cur[0] = idx1;

      for (int idx2 = 1; idx2 <= M; idx2++) {
        if (word1[idx1 - 1] == word2[idx2 - 1]) {
          cur[idx2] = pre[idx2 - 1];
        } else {
          cur[idx2] = min(pre[idx2 - 1], min(cur[idx2 - 1], pre[idx2])) + 1;
        }
      }

      // fill(pre.begin(), pre.end(), 0);
      swap(pre, cur);
    }

    return pre.back();
  }
};

// use dynamic programming (spaced optimized)

class Solution {
 public:
  int minDistance(string word1, string word2) {
    int N = word1.size(), M = word2.size();
    int pre;

    vector<int> cur(M + 1, 0);
    for (int idx2 = 1; idx2 <= M; idx2++) {
      cur[idx2] = idx2;
    }

    for (int idx1 = 1; idx1 <= N; idx1++) {
      pre = cur[0];
      cur[0] = idx1;

      for (int idx2 = 1; idx2 <= M; idx2++) {
        int temp = cur[idx2];

        if (word1[idx1 - 1] == word2[idx2 - 1]) {
          cur[idx2] = pre;
        } else {
          cur[idx2] = min(pre, min(cur[idx2 - 1], cur[idx2])) + 1;
        }

        pre = temp;
      }
    }

    return cur.back();
  }
};