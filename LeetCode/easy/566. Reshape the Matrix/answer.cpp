#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use divide, modular operation

class Solution {
 public:
  vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    int rows = mat.size();
    int cols = mat.front().size();

    if (rows * cols != r * c) return mat;

    vector<vector<int>> newMatrix(r, vector<int>(c));
    int index = 0;

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        newMatrix[index / c][index % c] = mat[y][x];
        index++;
      }
    }

    return newMatrix;
  }
};

// use queue

class Solution {
 public:
  vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    int rows = mat.size();
    int cols = mat.front().size();

    if (rows * cols != r * c) return mat;

    vector<vector<int>> newMatrix(r, vector<int>(c));
    queue<int> q;

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        q.push(mat[y][x]);
      }
    }

    for (int y = 0; y < r; y++) {
      for (int x = 0; x < c; x++) {
        newMatrix[y][x] = q.front();
        q.pop();
      }
    }

    return newMatrix;
  }
};