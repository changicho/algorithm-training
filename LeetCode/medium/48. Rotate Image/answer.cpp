#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use new matrix

class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int size = matrix.size();

    vector<vector<int>> rotatedMatrix(size, vector<int>(size));

    for (int y = 0; y < size; y++) {
      for (int x = 0; x < size; x++) {
        rotatedMatrix[x][size - 1 - y] = matrix[y][x];
      }
    }

    matrix = rotatedMatrix;
  }
};

// use relect, transpose

class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    transpose(matrix);
    reflect(matrix);
  }
  void transpose(vector<vector<int>>& matrix) {
    int size = matrix.size();

    for (int y = 0; y < size; y++) {
      for (int x = y; x < size; x++) {
        swap(matrix[x][y], matrix[y][x]);
      }
    }
  }
  void reflect(vector<vector<int>>& matrix) {
    int size = matrix.size();

    for (int y = 0; y < size; y++) {
      for (int x = 0; x < size / 2; x++) {
        swap(matrix[y][x], matrix[y][size - x - 1]);
      }
    }
  }
};

// use rotate groups of four cells

class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int size = matrix.size();
    for (int y = 0; y < (size + 1) / 2; y++) {
      for (int x = 0; x < size / 2; x++) {
        int temp = matrix[size - 1 - x][y];
        matrix[size - 1 - x][y] = matrix[size - 1 - y][size - 1 - x];
        matrix[size - 1 - y][size - 1 - x] = matrix[x][size - 1 - y];
        matrix[x][size - 1 - y] = matrix[y][x];
        matrix[y][x] = temp;
      }
    }
  }
};