#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use disjoint set
// time : O(R * C)
// space : O(R * C)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  vector<int> parents;

  int find(int node) {
    if (parents[node] == node) return node;
    return parents[node] = find(parents[node]);
  }

  void merge(int a, int b) {
    a = find(a), b = find(b);

    if (a == b) return;
    if (a > b) swap(a, b);
    parents[b] = a;
  }

 public:
  int latestDayToCross(int row, int col, vector<vector<int>> &cells) {
    int rows = row, cols = col;
    // finally all axis will flood
    vector<vector<int>> board(rows, vector<int>(cols, 1));

    parents.resize(rows * cols + 3);
    for (int i = 0; i < rows * cols + 3; i++) {
      parents[i] = i;
    }

    int top = rows * cols + 1, bottom = rows * cols + 2;
    for (int x = 0; x < cols; x++) {
      if (board[0][x] == 0) merge(top, x);
      if (board[rows - 1][x] == 0) merge(bottom, (rows - 1) * cols + x);
    }

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (board[y][x] == 1) continue;

        for (Axis &dir : dirs) {
          Axis next = {y + dir.y, x + dir.x};

          if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
            continue;
          if (board[next.y][next.x] == 1) continue;

          merge(y * cols + x, next.y * cols + next.x);
        }
      }
    }

    if (find(bottom) == find(top)) return cells.size();

    for (int i = cells.size() - 1; i >= 0; i--) {
      vector<int> c = cells[i];
      int y = c[0] - 1, x = c[1] - 1;
      board[y][x] = 0;

      if (y == 0) merge(y * cols + x, top);
      if (y == rows - 1) merge(y * cols + x, bottom);

      for (Axis &dir : dirs) {
        Axis next = {y + dir.y, x + dir.x};

        if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
          continue;
        if (board[next.y][next.x] == 1) continue;

        merge(y * cols + x, next.y * cols + next.x);
      }

      if (find(bottom) == find(top)) return i;
    }
    return 0;
  }
};