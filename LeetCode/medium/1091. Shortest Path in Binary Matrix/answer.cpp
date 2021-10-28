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

  Axis dirs[8] = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                  {1, 0},  {1, -1}, {0, -1}, {-1, -1}};

 public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int size = grid.size();

    if (grid[0][0] == 1) return -1;
    vector<vector<bool>> visited(size, vector<bool>(size, false));

    queue<Axis> q;
    q.push({0, 0});
    visited[0][0] = true;
    bool isConnected = false;
    int length = 1;

    while (!q.empty()) {
      int qSize = q.size();

      while (qSize--) {
        Axis cur = q.front();
        q.pop();

        if (cur.y == size - 1 && cur.x == size - 1) {
          isConnected = true;
          break;
        }

        for (Axis dir : dirs) {
          Axis next = {cur.y + dir.y, cur.x + dir.x};

          if (next.y < 0 || next.y >= size || next.x < 0 || next.x >= size)
            continue;
          if (grid[next.y][next.x] != 0) continue;
          if (visited[next.y][next.x]) continue;

          visited[next.y][next.x] = true;
          q.push(next);
        }
      }

      if (isConnected) break;
      length++;
    }

    return isConnected ? length : -1;
  }
};

// use BFS space compact

class Solution {
 private:
  struct Axis {
    int y, x;
  };

  Axis dirs[8] = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                  {1, 0},  {1, -1}, {0, -1}, {-1, -1}};

 public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int size = grid.size();

    if (grid[0][0] == 1) return -1;

    queue<Axis> q;
    q.push({0, 0});
    grid[0][0] = true;
    bool isConnected = false;
    int length = 1;

    while (!q.empty()) {
      int qSize = q.size();

      while (qSize--) {
        Axis cur = q.front();
        q.pop();

        if (cur.y == size - 1 && cur.x == size - 1) {
          isConnected = true;
          break;
        }

        for (Axis dir : dirs) {
          Axis next = {cur.y + dir.y, cur.x + dir.x};

          if (next.y < 0 || next.y >= size || next.x < 0 || next.x >= size)
            continue;
          if (grid[next.y][next.x] != 0) continue;
          if (grid[next.y][next.x]) continue;

          grid[next.y][next.x] = true;
          q.push(next);
        }
      }

      if (isConnected) break;
      length++;
    }

    return isConnected ? length : -1;
  }
};