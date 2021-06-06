#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dp O(N^2)

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