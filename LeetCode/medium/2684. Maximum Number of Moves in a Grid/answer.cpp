#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use BFS
// time : O(R * C)
// space : O(R * C)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  Axis dirs[3] = {{-1, 1}, {0, 1}, {1, 1}};

 public:
  int maxMoves(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();

    int answer = 0;

    int step = 0;

    bool visited[1001][1001] = {
        false,
    };

    queue<Axis> q;

    for (int y = 0; y < rows; y++) {
      q.push({y, 0});
    }

    while (!q.empty()) {
      int size = q.size();

      while (size--) {
        Axis cur = q.front();
        q.pop();

        if (cur.x == cols - 1) continue;
        if (visited[cur.y][cur.x]) continue;
        visited[cur.y][cur.x] = true;

        for (Axis dir : dirs) {
          Axis next = {cur.y + dir.y, cur.x + dir.x};

          if (next.y < 0 || next.y >= rows) continue;
          if (grid[next.y][next.x] <= grid[cur.y][cur.x]) continue;

          q.push(next);
        }
      }

      step++;
    }

    return step - 1;
  }
};