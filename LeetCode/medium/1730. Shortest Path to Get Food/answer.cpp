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
  int getFood(vector<vector<char>>& grid) {
    int rows = grid.size();
    int cols = grid.front().size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    queue<Axis> q;

    // find location
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (grid[y][x] != '*') continue;

        q.push({y, x});
        visited[y][x] = true;
      }
    }

    int answer = -1;
    int step = 0;

    while (!q.empty() && answer == -1) {
      int size = q.size();
      while (size--) {
        Axis cur = q.front();
        q.pop();

        if (grid[cur.y][cur.x] == '#') {
          answer = step;
          break;
        }

        for (Axis& d : dirs) {
          Axis n = {cur.y + d.y, cur.x + d.x};

          if (n.y < 0 || n.y >= rows || n.x < 0 || n.x >= cols) continue;
          if (grid[n.y][n.x] == 'X') continue;
          if (visited[n.y][n.x] == true) continue;

          visited[n.y][n.x] = true;
          q.push(n);
        }
      }

      step++;
    }

    return answer;
  }
};