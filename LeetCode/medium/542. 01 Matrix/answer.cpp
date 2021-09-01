#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use BFS

class Solution {
 private:
  struct Axis {
    int y, x;
  };
  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat.front().size();
    int limit = rows + cols;  // The distance of cells is up to (M + N)

    queue<Axis> q;

    Axis start = {-1, -1};
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (mat[y][x] == 0) {
          q.push({y, x});
        } else {
          mat[y][x] = limit;
        }
      }
    }

    while (!q.empty()) {
      int size = q.size();

      while (size--) {
        Axis cur = q.front();
        q.pop();

        for (Axis dir : dirs) {
          Axis next = {cur.y + dir.y, cur.x + dir.x};

          if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
            continue;
          if (mat[next.y][next.x] <= mat[cur.y][cur.x] + 1) continue;

          mat[next.y][next.x] = mat[cur.y][cur.x] + 1;
          q.push(next);
        }
      }
    }

    return mat;
  }
};

// use dynamic programming

class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat.front().size();
    int limit = rows + cols;  // The distance of cells is up to (M + N)

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (mat[y][x] == 0) continue;

        int top = limit, left = limit;
        if (y - 1 >= 0) top = mat[y - 1][x];
        if (x - 1 >= 0) left = mat[y][x - 1];

        mat[y][x] = min(top, left) + 1;
      }
    }
    for (int y = rows - 1; y >= 0; y--) {
      for (int x = cols - 1; x >= 0; x--) {
        if (mat[y][x] == 0) continue;
        int bottom = limit, right = limit;

        if (y + 1 < rows) bottom = mat[y + 1][x];
        if (x + 1 < cols) right = mat[y][x + 1];
        mat[y][x] = min(mat[y][x], min(bottom, right) + 1);
      }
    }
    return mat;
  }
};