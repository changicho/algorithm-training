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

  const int INF = 2147483647;
  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

 public:
  void wallsAndGates(vector<vector<int>>& rooms) {
    int rows = rooms.size();
    int cols = rooms.front().size();
    queue<Axis> q;

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (rooms[y][x] == 0) {
          q.push({y, x});
        }
      }
    }

    while (!q.empty()) {
      Axis axis = q.front();
      q.pop();

      bool hasNext = false;
      for (Axis dir : dirs) {
        Axis next = {axis.y + dir.y, axis.x + dir.x};

        if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols) continue;
        if (rooms[next.y][next.x] == -1) continue;
        if (rooms[next.y][next.x] <= rooms[axis.y][axis.x] + 1) continue;

        rooms[next.y][next.x] = rooms[axis.y][axis.x] + 1;
        q.push(next);
      }
    }
  }
};