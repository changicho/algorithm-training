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

// use prefix sum
// time : O(R * C)
// space : O(R * C)
class Solution {
 public:
  int maxSideLength(vector<vector<int>>& mat, int threshold) {
    int rows = mat.size(), cols = mat[0].size();

    vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        dp[y + 1][x + 1] = dp[y + 1][x] + dp[y][x + 1] - dp[y][x] + mat[y][x];
      }
    }

    int answer = 0;
    int limit = min(rows, cols);
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        for (int length = answer + 1; length <= limit; length++) {
          if (y + length > rows || x + length > cols) break;
          int sum = dp[y + length][x + length] - dp[y + length][x] -
                    dp[y][x + length] + dp[y][x];

          if (sum <= threshold) {
            answer = max(answer, length);
          } else {
            break;
          }
        }
      }
    }
    return answer;
  }
};