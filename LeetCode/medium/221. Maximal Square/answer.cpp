#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming (4 way direction)

class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int rows = matrix.size();
    int cols = matrix.front().size();

    vector<vector<int>> dpLeft(rows, vector<int>(cols, 0));
    vector<vector<int>> dpRight(rows, vector<int>(cols, 0));
    vector<vector<int>> dpUp(rows, vector<int>(cols, 0));
    vector<vector<int>> dpDown(rows, vector<int>(cols, 0));

    for (int y = 0; y < rows; ++y) {
      for (int x = 0; x < cols; ++x) {
        int reverseY = rows - 1 - y;

        if (y == 0) {
          dpDown[y][x] = matrix[y][x] == '1' ? 1 : 0;
          dpUp[reverseY][x] = matrix[reverseY][x] == '1' ? 1 : 0;
          continue;
        }

        dpDown[y][x] = matrix[y][x] == '1' ? dpDown[y - 1][x] + 1 : 0;
        dpUp[reverseY][x] =
            matrix[reverseY][x] == '1' ? dpUp[reverseY + 1][x] + 1 : 0;
      }
    }

    for (int x = 0; x < cols; ++x) {
      for (int y = 0; y < rows; ++y) {
        int reverseX = cols - 1 - x;

        if (x == 0) {
          dpRight[y][x] = matrix[y][x] == '1' ? 1 : 0;
          dpLeft[y][reverseX] = matrix[y][reverseX] == '1' ? 1 : 0;
          continue;
        }

        dpRight[y][x] = matrix[y][x] == '1' ? dpRight[y][x - 1] + 1 : 0;
        dpLeft[y][reverseX] =
            matrix[y][reverseX] == '1' ? dpLeft[y][reverseX + 1] + 1 : 0;
      }
    }

    int limitSize = min(rows, cols);
    int answer = 0;
    for (int y = 0; y < rows; ++y) {
      for (int x = 0; x < cols; ++x) {
        for (int size = 1; size <= limitSize; ++size) {
          int endY = y + size - 1;
          int endX = x + size - 1;
          if (endY >= rows || endX >= cols) break;

          int squareLength = min(min(dpRight[endY][endX], dpDown[endY][endX]),
                                 min(dpUp[y][x], dpLeft[y][x]));

          if (squareLength >= size) {
            answer = max(answer, (size) * (size));
          } else {
            break;
          }
        }
      }
    }

    return answer;
  }
};

// use dynamic programming (one pass)

class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int rows = matrix.size();
    int cols = matrix.front().size();

    vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));
    int length = 0;

    for (int y = 1; y <= rows; y++) {
      for (int x = 1; x <= cols; x++) {
        if (matrix[y - 1][x - 1] != '1') continue;

        dp[y][x] = min(min(dp[y][x - 1], dp[y - 1][x]), dp[y - 1][x - 1]) + 1;
        length = max(length, dp[y][x]);
      }
    }

    return length * length;
  }
};

// use dynamic programming (space optimized)

class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int rows = matrix.size();
    int cols = matrix.front().size();

    vector<int> dp(cols + 1, 0);
    int length = 0;
    int prev = 0;

    for (int y = 1; y <= rows; y++) {
      for (int x = 1; x <= cols; x++) {
        int temp = dp[x];

        if (matrix[y - 1][x - 1] == '1') {
          dp[x] = min(prev, min(dp[x - 1], dp[x])) + 1;
        } else {
          dp[x] = 0;
        }
        length = max(length, dp[x]);
        prev = temp;
      }
    }
    return length * length;
  }
};