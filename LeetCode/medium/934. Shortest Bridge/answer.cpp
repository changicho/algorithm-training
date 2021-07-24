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
  int shortestBridge(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid.front().size();

    queue<Axis> islands;
    for (int y = 0; y < rows && islands.empty(); y++) {
      for (int x = 0; x < cols && islands.empty(); x++) {
        if (grid[y][x] != 1) continue;

        queue<Axis> q;
        q.push({y, x});

        while (!q.empty()) {
          Axis cur = q.front();
          q.pop();

          if (grid[cur.y][cur.x] == -1) continue;
          grid[cur.y][cur.x] = -1;

          islands.push(cur);

          for (Axis dir : dirs) {
            Axis next = {dir.y + cur.y, dir.x + cur.x};

            if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols) continue;
            if (grid[next.y][next.x] != 1) continue;

            q.push(next);
          }
        }
      }
    }

    int step = 0;
    bool isLinked = false;
    while (!isLinked) {
      step += 1;
      int size = islands.size();

      while (size-- && !isLinked) {
        Axis cur = islands.front();
        islands.pop();

        for (Axis dir : dirs) {
          Axis next = {dir.y + cur.y, dir.x + cur.x};

          if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols) continue;
          if (grid[next.y][next.x] < 0) continue;
          if (grid[next.y][next.x] == 1) {
            isLinked = true;
            break;
          }

          grid[next.y][next.x] = grid[cur.y][cur.x] - 1;
          islands.push(next);
        }
      }
    }
    return step - 1;
  }
};