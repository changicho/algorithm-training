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
  int orangesRotting(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid.front().size();

    queue<Axis> q;
    int remain = 0;
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (grid[y][x] == 1)
          remain += 1;
        else if (grid[y][x] == 2)
          q.push({y, x});
      }
    }

    int time = 0;
    while (!q.empty()) {
      int size = q.size();

      while (size--) {
        Axis cur = q.front();
        q.pop();

        for (Axis dir : dirs) {
          Axis next = {cur.y + dir.y, cur.x + dir.x};

          if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
            continue;
          if (grid[next.y][next.x] != 1) continue;

          grid[next.y][next.x] = 2;
          q.push(next);
          remain -= 1;
        }
      }
      time += 1;
    }

    if (remain > 0) return -1;
    return max(time - 1, 0);
  }
};