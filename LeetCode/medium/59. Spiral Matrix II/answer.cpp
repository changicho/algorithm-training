#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

Axis dirs[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

// fill by count with rotate

class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    int dirIdx = 0;
    int limit = n * n;
    Axis cur = {0, 0};
    Axis dir = dirs[dirIdx];

    for (int number = 1; number <= limit; number++) {
      matrix[cur.y][cur.x] = number;

      Axis next = cur;
      next.y += dir.y;
      next.x += dir.x;
      bool needRotate = false;

      if ((next.y < 0 || next.y >= n || next.x < 0 || next.x >= n)) {
        needRotate = true;
      } else if (matrix[next.y][next.x] != 0) {
        needRotate = true;
      }

      if (needRotate) {
        dirIdx = (dirIdx + 1) % 4;
        dir = dirs[dirIdx];

        next = cur;
        next.y += dir.y;
        next.x += dir.x;
      }

      cur = next;
    }

    return matrix;
  }
};

// fill by layer

class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));

    int number = 1;
    for (int layer = 0; layer < (n + 1) / 2; layer++) {
      // from left to right
      for (int index = layer; index < n - layer; index++) {
        matrix[layer][index] = number;
        number++;
      }
      // from top to bottom
      for (int index = layer + 1; index < n - layer; index++) {
        matrix[index][n - layer - 1] = number;
        number++;
      }
      // from right to left
      for (int index = n - layer - 2; index >= layer; index--) {
        matrix[n - layer - 1][index] = number;
        number++;
      }
      // from bottom to top
      for (int index = n - layer - 2; index > layer; index--) {
        matrix[index][layer] = number;
        number++;
      }
    }

    return matrix;
  }
};