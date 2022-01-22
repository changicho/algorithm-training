#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force

class Solution {
 public:
  bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix.front().size();

    for (int x = 0; x < cols; x++) {
      // y = 0
      int target = matrix[0][x];
      for (int i = 0; i < rows && x + i < cols; i++) {
        if (matrix[i][x + i] != target) return false;
      }
    }

    for (int y = 0; y < rows; y++) {
      // x = 0
      int target = matrix[y][0];
      for (int i = 0; y + i < rows && i < cols; i++) {
        if (matrix[y + i][i] != target) return false;
      }
    }

    return true;
  }
};

// use compare top left

class Solution {
 public:
  bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix.front().size();

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (y - 1 < 0 || x - 1 < 0) continue;

        if (matrix[y - 1][x - 1] != matrix[y][x]) return false;
      }
    }

    return true;
  }
};