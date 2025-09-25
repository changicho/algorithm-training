#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dp O(N^2)
// time : O(N^2)
// space : O(N^2)
class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int size = triangle.size();
    vector<vector<int>> dp(size, vector<int>(size, 0));

    dp[0][0] = triangle[0][0];

    for (int y = 1; y < size; y++) {
      dp[y][0] = triangle[y][0] + dp[y - 1][0];
      for (int x = 1; x < y; x++) {
        dp[y][x] = triangle[y][x] + min(dp[y - 1][x - 1], dp[y - 1][x]);
      }
      dp[y][y] = triangle[y][y] + dp[y - 1][y - 1];
    }

    int answer = dp[size - 1][0];
    for (int val : dp[size - 1]) answer = min(answer, val);
    return answer;
  }
};

// use dp O(N)
// time : O(N^2)
// space : O(N)
class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int size = triangle.size();
    vector<int> dp(size, 0);

    dp[0] = triangle[0][0];

    for (int y = 1; y < size; y++) {
      dp[y] = triangle[y][y] + dp[y - 1];
      for (int x = y - 1; x > 0; x--) {
        dp[x] = triangle[y][x] + min(dp[x - 1], dp[x]);
      }
      dp[0] = triangle[y][0] + dp[0];
    }

    int answer = dp[0];
    for (int val : dp) answer = min(answer, val);
    return answer;
  }
};

// use dynamic programming (in-place)
// time : O(N^2)
// space : O(1)
class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int size = triangle.size();

    for (int y = 1; y < size; y++) {
      for (int x = 0; x <= y; x++) {
        int target = INT_MAX;

        if (x > 0) {
          target = min(target, triangle[y - 1][x - 1]);
        }
        if (x < y) {
          target = min(target, triangle[y - 1][x]);
        }

        triangle[y][x] += target;
      }
    }

    int answer = INT_MAX;
    for (int i = 0; i < size; i++) {
      answer = min(answer, triangle[size - 1][i]);
    }
    return answer;
  }
};