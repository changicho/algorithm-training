#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming

class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix.front().size();
    int limit = 100001;

    vector<int> dp(cols, 0);

    for (int x = 0; x < cols; x++) {
      dp[x] = matrix.front()[x];
    }

    for (int y = 1; y < rows; y++) {
      vector<int> temp(cols, limit);

      for (int x = 0; x < cols; x++) {
        int left = max(0, x - 1);
        int right = min(cols - 1, x + 1);

        int minimum = dp[left];
        for (int i = left; i <= right; i++) {
          minimum = min(dp[i], minimum);
        }

        temp[x] = minimum + matrix[y][x];
      }

      dp = temp;
    }

    int answer = limit;
    for (int val : dp) {
      answer = min(val, answer);
    }
    return answer;
  }
};