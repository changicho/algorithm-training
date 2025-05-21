#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use hash set (space complexity : O(N + M))

class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    int row_size = matrix.size();
    int col_size = matrix.front().size();
    unordered_set<int> rows;
    unordered_set<int> cols;

    for (int y = 0; y < row_size; y++) {
      for (int x = 0; x < col_size; x++) {
        if (matrix[y][x] != 0) continue;

        rows.insert(y);
        cols.insert(x);
      }
    }

    for (int y = 0; y < row_size; y++) {
      for (int x = 0; x < col_size; x++) {
        if (rows.find(y) != rows.end() || cols.find(x) != cols.end()) {
          matrix[y][x] = 0;
        }
      }
    }
  }
};

// use matrix to check array (space complexity : O(1))
// time : O(R * C)
// space : O(1)
class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();

    // check first row and first column
    bool firstCol = false;
    bool firstRow = false;
    for (int x = 0; x < cols; x++) {
      if (matrix[0][x] == 0) {
        firstRow = true;
      }
    }
    for (int y = 0; y < rows; y++) {
      if (matrix[y][0] == 0) {
        firstCol = true;
      }
    }

    // check and mark zero at first row and first column
    for (int y = 1; y < rows; y++) {
      for (int x = 1; x < cols; x++) {
        if (matrix[y][x] == 0) {
          matrix[0][x] = matrix[y][0] = 0;
        }
      }
    }

    // set zero to the rest of the matrix
    for (int y = 1; y < rows; y++) {
      for (int x = 1; x < cols; x++) {
        if (matrix[0][x] == 0 || matrix[y][0] == 0) {
          matrix[y][x] = 0;
        }
      }
    }
    if (firstRow) {
      for (int x = 0; x < cols; x++) {
        matrix[0][x] = 0;
      }
    }
    if (firstCol) {
      for (int y = 0; y < rows; y++) {
        matrix[y][0] = 0;
      }
    }
  }
};