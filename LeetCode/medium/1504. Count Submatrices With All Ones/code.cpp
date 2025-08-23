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

// use brute force
// time : O(R^2 * C^2)
// space : O(R * C)
class Solution {
 public:
  int numSubmat(vector<vector<int>>& mat) {
    int rows = mat.size(), cols = mat[0].size();

    int colCounts[150][150] = {
        0,
    };

    for (int x = 0; x < cols; x++) {
      int temp = 0;
      for (int y = 0; y < rows; y++) {
        temp += mat[y][x] == 1;

        colCounts[y][x] = temp;
      }
    }

    int answer = 0;
    // (sy, sx) ~ (ey, ex)
    for (int sy = 0; sy < rows; sy++) {
      for (int sx = 0; sx < cols; sx++) {
        for (int ey = sy; ey < rows; ey++) {
          int temp = 0;

          for (int ex = sx; ex < cols; ex++) {
            temp +=
                colCounts[ey][ex] - ((sy - 1 >= 0) ? colCounts[sy - 1][ex] : 0);

            int yLength = ey - sy + 1;
            int xLength = ex - sx + 1;

            if (temp == yLength * xLength) {
              answer++;
            }
          }
        }
      }
    }

    return answer;
  }
};

// use continuous 1's count
// time : O(R^2 * C)
// space : O(R * C)
class Solution {
 public:
  int numSubmat(vector<vector<int>>& mat) {
    int rows = mat.size(), cols = mat[0].size();

    int rowCounts[150][150] = {
        0,
    };

    int answer = 0;
    for (int y = 0; y < rows; y++) {
      int ones = 0;
      for (int x = 0; x < cols; x++) {
        if (mat[y][x] == 0) {
          ones = 0;
        } else {
          ones++;
        }

        rowCounts[y][x] = ones;
        int cur = rowCounts[y][x];

        for (int by = y; by >= 0; by--) {
          cur = min(cur, rowCounts[by][x]);
          if (cur == 0) break;

          answer += cur;
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
  int numSubmat(vector<vector<int>>& mat) {
    int rows = mat.size(), cols = mat[0].size();

    int heights[150] = {
        0,
    };

    int answer = 0;
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        heights[x] = (mat[y][x] == 0) ? 0 : heights[x] + 1;
      }

      stack<vector<int>> stk;
      stk.push({-1, 0, -1});
      for (int x = 0; x < cols; x++) {
        int height = heights[x];

        while (stk.top()[2] >= height) {
          stk.pop();
        }
        vector<int>& top = stk.top();
        int beforeX = top[0];
        int prev = top[1];
        int cur = prev + (x - beforeX) * height;
        stk.push({x, cur, height});
        answer += cur;
      }
    }

    return answer;
  }
};