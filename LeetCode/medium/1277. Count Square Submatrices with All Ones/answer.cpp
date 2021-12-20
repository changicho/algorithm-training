#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dp

class Solution {
 public:
  int countSquares(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix.front().size();
    int answer = 0;

    // matrix[y][x] : maximum length of square end at (y,x)
    // that means count of square end at (y,x)
    for (int y = 1; y < rows; y++) {
      for (int x = 1; x < cols; x++) {
        if (matrix[y][x] != 1) continue;

        int fromUp = matrix[y - 1][x], fromLeft = matrix[y][x - 1],
            fromLeftUp = matrix[y - 1][x - 1];

        matrix[y][x] = min({fromUp, fromLeft, fromLeftUp}) + 1;
      }
    }

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        answer += matrix[y][x];
      }
    }

    return answer;
  }
};

// use count of from left, from up

class Solution {
 public:
  int countSquares(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix.front().size();

    int limit = min(rows, cols);
    vector<vector<int>> countFromUp(rows, vector<int>(cols, 0));
    vector<vector<int>> countFromLeft(rows, vector<int>(cols, 0));

    // fill countFromUp
    for (int x = 0; x < cols; x++) {
      countFromUp[0][x] = matrix[0][x] == 1;

      for (int y = 1; y < rows; y++) {
        if (matrix[y][x] != 1) {
          countFromUp[y][x] = 0;
          continue;
        }
        countFromUp[y][x] = countFromUp[y - 1][x] + 1;
      }
    }

    // fill countFromLeft
    for (int y = 0; y < rows; y++) {
      countFromLeft[y][0] = matrix[y][0] == 1;

      for (int x = 1; x < cols; x++) {
        if (matrix[y][x] != 1) {
          countFromLeft[y][x] = 0;
          continue;
        }
        countFromLeft[y][x] = countFromLeft[y][x - 1] + 1;
      }
    }

    // dp[y][x][length] : can make length square from (y,x)
    vector<vector<vector<bool>>> dp(
        rows, vector<vector<bool>>(cols, vector<bool>(limit + 1, false)));

    int answer = 0;
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (matrix[y][x] != 1) continue;

        dp[y][x][1] = true;
        answer += 1;
      }
    }

    for (int length = 2; length <= limit; length++) {
      for (int y = 0; y + length - 1 < rows; y++) {
        for (int x = 0; x + length - 1 < cols; x++) {
          int nextY = y + length - 1, nextX = x + length - 1;

          bool isBeforeFine = dp[y][x][length - 1];
          bool isRightFine = countFromLeft[nextY][nextX] >= length;
          bool isDownFine = countFromUp[nextY][nextX] >= length;

          if (isBeforeFine && isRightFine && isDownFine) {
            dp[y][x][length] = true;
            answer += 1;
          }
        }
      }
    }

    return answer;
  }
};
