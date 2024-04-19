#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(R^2 * C)
// space : O(R * C)
class Solution {
 public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();

    int answer = 0;
    int dp[201][201] = {
        0,
    };

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (matrix[y][x] == '0') continue;

        dp[y][x] = x == 0 ? 1 : dp[y][x - 1] + 1;

        int width = dp[y][x];

        for (int by = y; by >= 0; by--) {
          width = min(width, dp[by][x]);
          answer = max(answer, width * (y - by + 1));
        }
      }
    }
    return answer;
  }
};

// use monotonic stack
// time : O(R * C)
// space : O(C)
class Solution {
 public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();

    vector<int> heights(cols);
    int answer = 0;

    for (int y = 0; y < rows; y++) {
      stack<int> stk;

      for (int x = 0; x < cols; x++) {
        heights[x] = (matrix[y][x] == '0') ? 0 : heights[x] + 1;

        while (!stk.empty() && (heights[x] < heights[stk.top()])) {
          int left = stk.top();
          stk.pop();

          int before = (stk.empty() ? -1 : stk.top());
          int width = x - before - 1;

          answer = max(answer, heights[left] * width);
        }

        stk.push(x);
      }

      // last case
      while (!stk.empty()) {
        int left = stk.top();
        stk.pop();

        int before = (stk.empty() ? -1 : stk.top());
        int width = cols - before - 1;

        answer = max(answer, heights[left] * width);
      }
    }

    return answer;
  }
};

// use dynamic programming
// time : O(R * C)
// space : O(C)
class Solution {
 private:
  int largestRectangleArea(vector<int>& heights, int cols) {
    if (cols == 0) return 0;

    vector<int> lefts(cols), rights(cols);
    rights[cols - 1] = cols, lefts[0] = -1;

    for (int x = 1; x < cols; x++) {
      int prev = x - 1;
      while (prev >= 0 && heights[prev] >= heights[x]) {
        prev = lefts[prev];
      }

      lefts[x] = prev;
    }

    int maxArea = heights[cols - 1] * (rights[cols - 1] - lefts[cols - 1] - 1);

    for (int x = cols - 2; x >= 0; x--) {
      int prev = x + 1;
      while (prev < cols && heights[prev] >= heights[x]) {
        prev = rights[prev];
      }

      rights[x] = prev;
      maxArea = max(maxArea, heights[x] * (rights[x] - lefts[x] - 1));
    }

    return maxArea;
  }

 public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();

    vector<int> heights(cols);
    int answer = 0;

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        heights[x] = (matrix[y][x] == '0') ? 0 : heights[x] + 1;
      }

      answer = max(answer, largestRectangleArea(heights, cols));
    }
    return answer;
  }
};