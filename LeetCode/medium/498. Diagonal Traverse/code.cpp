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

// use one pass
// time : O(R * C)
// space : O(R * C)
class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int rows = mat.size(), cols = mat[0].size();

    vector<int> answer;
    for (int x = 0; x < cols; x++) {
      int size = answer.size();

      for (int y = 0; y < rows; y++) {
        if (x - y < 0) break;
        answer.push_back(mat[y][x - y]);
      }
      if (x % 2 == 0) {
        reverse(answer.begin() + size, answer.end());
      }
    }
    for (int y = 1; y < rows; y++) {
      int size = answer.size();

      for (int x = 0; x < cols; x++) {
        if (y + x >= rows || cols - 1 - x < 0) break;

        answer.push_back(mat[y + x][cols - 1 - x]);
      }

      if ((cols - 1 + y) % 2 == 0) {
        reverse(answer.begin() + size, answer.end());
      }
    }

    return answer;
  }
};

// use one pass
// time : O(R * C)
// space : O(R * C)
class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int rows = mat.size(), cols = mat[0].size();
    vector<int> answer;
    int row = 0, col = 0;

    for (int i = 0; i < rows * cols; i++) {
      answer.emplace_back(mat[row][col]);

      if ((row + col) % 2 == 0) {
        if (col == cols - 1) {
          row++;
        } else if (row == 0) {
          col++;
        } else {
          row--;
          col++;
        }
      } else {
        if (row == rows - 1) {
          col++;
        } else if (col == 0) {
          row++;
        } else {
          row++;
          col--;
        }
      }
    }

    return answer;
  }
};