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

class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    bool isFirstColumnZero = false;  // to distinct matrix[0][x] == 0 or matrix[y][0] == 0
    int row_size = matrix.size();
    int col_size = matrix.front().size();

    for (int y = 0; y < row_size; y++) {
      if (matrix[y][0] == 0) isFirstColumnZero = true;

      for (int x = 1; x < col_size; x++) {
        if (matrix[y][x] == 0) {
          matrix[0][x] = 0;
          matrix[y][0] = 0;
        }
      }
    }

    for (int y = 1; y < row_size; y++) {
      for (int x = 1; x < col_size; x++) {
        if (matrix[y][0] == 0 || matrix[0][x] == 0) {
          matrix[y][x] = 0;
        }
      }
    }

    if (matrix[0][0] == 0) {
      for (int x = 0; x < col_size; x++) {
        matrix[0][x] = 0;
      }
    }

    if (isFirstColumnZero) {
      for (int i = 0; i < row_size; i++) {
        matrix[i][0] = 0;
      }
    }
  }
};
