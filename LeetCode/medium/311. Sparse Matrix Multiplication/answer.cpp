#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use index multi

class Solution {
 public:
  vector<vector<int>> multiply(vector<vector<int>>& mat1,
                               vector<vector<int>>& mat2) {
    int m = mat1.size();
    int k = mat1.front().size();
    int n = mat2.front().size();

    vector<vector<int>> ret(m, vector<int>(n, 0));

    for (int y = 0; y < m; y++) {
      for (int x = 0; x < n; x++) {
        for (int i = 0; i < k; i++) {
          ret[y][x] += mat1[y][i] * mat2[i][x];
        }
      }
    }

    return ret;
  }
};

// use backtracking

class Solution {
 public:
  vector<vector<int>> multiply(vector<vector<int>>& mat1,
                               vector<vector<int>>& mat2) {
    int rows1 = mat1.size(), cols1 = mat1[0].size();
    int rows1 = mat2.size(), cols2 = mat2[0].size();

    vector<bool> isZeros1(rows1, true), isZeros2(cols2, true);

    for (int y = 0; y < rows1; ++y) {
      bool isZero = true;
      for (int x = 0; x < cols1; ++x) {
        if (mat1[y][x] != 0) {
          isZero = false;
          break;
        }
      }
      isZeros1[y] = isZero;
    }

    for (int x = 0; x < cols2; ++x) {
      bool isZero = true;
      for (int y = 0; y < rows1; ++y) {
        if (mat2[y][x] != 0) {
          isZero = false;
          break;
        }
      }
      isZeros2[x] = isZero;
    }

    vector<vector<int>> res(rows1, vector<int>(cols2, 0));

    for (int y = 0; y < rows1; ++y) {
      if (isZeros1[y]) continue;

      for (int x = 0; x < cols2; ++x) {
        if (isZeros2[x]) continue;

        int sum = 0;
        for (int k = 0; k < cols1; ++k) {
          sum += mat1[y][k] * mat2[k][x];
        }
        res[y][x] = sum;
      }
    }
    return res;
  }
};