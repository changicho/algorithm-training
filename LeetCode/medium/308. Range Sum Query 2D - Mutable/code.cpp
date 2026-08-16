#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

using ll = long long;

// brute force
// time : build : O(RC), update : O(1), sumRegion : O(RC)
// space : O(RC)
class NumMatrix {
 private:
  vector<vector<int>> matrix;

 public:
  NumMatrix(vector<vector<int>>& matrix) { this->matrix = matrix; }

  void update(int row, int col, int val) { matrix[row][col] = val; }

  int sumRegion(int row1, int col1, int row2, int col2) {
    int sum = 0;

    for (int y = row1; y <= row2; y++) {
      for (int x = col1; x <= col2; x++) {
        sum += matrix[y][x];
      }
    }
    return sum;
  }
};

// 1D prefix sum
// time : build : O(RC), update : O(C), sumRegion : O(R)
// space : O(RC)
class NumMatrix {
 private:
  vector<vector<int>> rowPrefix;
  vector<vector<int>> matrix;

 public:
  NumMatrix(vector<vector<int>>& matrix) {
    this->matrix = matrix;
    int rows = matrix.size(), cols = matrix[0].size();

    rowPrefix.resize(rows, vector<int>(cols + 1));

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        rowPrefix[y][x + 1] = rowPrefix[y][x] + matrix[y][x];
      }
    }
  }

  void update(int row, int col, int val) {
    int rows = matrix.size(), cols = matrix[0].size();

    matrix[row][col] = val;
    for (int x = 0; x < cols; x++) {
      rowPrefix[row][x + 1] = rowPrefix[row][x] + matrix[row][x];
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    int sum = 0;

    for (int y = row1; y <= row2; y++) {
      sum += rowPrefix[y][col2 + 1] - rowPrefix[y][col1];
    }
    return sum;
  }
};

// binary indexed tree
class NumMatrix {
 private:
  int rows, cols;
  vector<vector<int>> bit;

  int lsb(int n) { return n & (-n); }

  void updateBIT(int r, int c, int val) {
    for (int i = r; i <= rows; i += lsb(i)) {
      for (int j = c; j <= cols; j += lsb(j)) {
        this->bit[i][j] += val;
      }
    }
  }

  int queryBIT(int r, int c) {
    int sum = 0;

    for (int i = r; i > 0; i -= lsb(i)) {
      for (int j = c; j > 0; j -= lsb(j)) {
        sum += this->bit[i][j];
      }
    }
    return sum;
  }

  void buildBIT(vector<vector<int>>& matrix) {
    for (int i = 1; i <= rows; ++i) {
      for (int j = 1; j <= cols; ++j) {
        int val = matrix[i - 1][j - 1];
        updateBIT(i, j, val);
      }
    }
  }

 public:
  NumMatrix(vector<vector<int>>& matrix) {
    rows = matrix.size();
    cols = matrix[0].size();

    bit.resize(rows + 1);
    for (int i = 1; i <= rows; ++i) bit[i].resize(cols + 1, 0);
    buildBIT(matrix);
  }

  void update(int row, int col, int val) {
    int old_val = sumRegion(row, col, row, col);
    row++;
    col++;
    int diff = val - old_val;
    updateBIT(row, col, diff);
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    // handling 1-based indexing
    row1++;
    col1++;
    row2++;
    col2++;

    int a = queryBIT(row2, col2);
    int b = queryBIT(row1 - 1, col1 - 1);
    int c = queryBIT(row2, col1 - 1);
    int d = queryBIT(row1 - 1, col2);
    return (a + b) - (c + d);
  }
};