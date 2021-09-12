#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use left right dynamic programming

class Solution {
 public:
  long long maxPoints(vector<vector<int>>& points) {
    int rows = points.size();
    int cols = points.front().size();

    vector<vector<long long>> dp(rows, vector<long long>(cols, 0));
    vector<long long> left(cols, 0), right(cols, 0);

    for (int x = 0; x < cols; x++) {
      dp[0][x] = points[0][x];
    }

    for (int y = 1; y < rows; y++) {
      fill(left.begin(), left.end(), 0);
      fill(right.begin(), right.end(), 0);

      left.front() = dp[y - 1].front();
      for (int x = 1; x < cols; x++) {
        left[x] = max(left[x - 1], dp[y - 1][x] + x);
      }

      right.back() = dp[y - 1].back() - (cols - 1);
      for (int x = cols - 2; x >= 0; x--) {
        right[x] = max(right[x + 1], dp[y - 1][x] - x);
      }

      for (int x = 0; x < cols; x++) {
        dp[y][x] = points[y][x] + max(left[x] - x, right[x] + x);
      }
    }

    long long answer = dp.back().front();
    for (long long& val : dp.back()) {
      answer = max(answer, val);
    }
    return answer;
  }
};

// use dynamic programming O(1)

class Solution {
 public:
  long long maxPoints(vector<vector<int>>& points) {
    long long rows = points.size(), cols = points.front().size();

    vector<vector<long long>> dp(2, vector<long long>(cols, 0));
    vector<long long> left(cols, 0), right(cols, 0);
    bool current = 0;

    for (int x = 0; x < cols; x++) {
      dp[current][x] = points.front()[x];
    }

    for (int y = 1; y < rows; y++) {
      bool next = !current;
      // clear
      fill(dp[next].begin(), dp[next].end(), 0);
      fill(left.begin(), left.end(), 0);
      fill(right.begin(), right.end(), 0);

      // traverse left to right
      left.front() = dp[current].front();
      for (int x = 1; x < cols; x++) {
        left[x] = max(left[x - 1], dp[current][x] + x);
      }

      // traverse right to left
      right.back() = dp[current].back() - (cols - 1);
      for (int x = cols - 2; x >= 0; x--) {
        right[x] = max(right[x + 1], dp[current][x] - x);
      }

      // update current with max from left, right + value
      for (int x = 0; x < cols; x++) {
        dp[next][x] = points[y][x] + max(left[x] - x, right[x] + x);
      }

      current = next;
    }

    long long answer = dp[current].front();
    for (long long& val : dp[current]) {
      answer = max(answer, val);
    }
    return answer;
  }
};