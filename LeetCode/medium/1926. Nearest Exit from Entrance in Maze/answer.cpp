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

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  bool isExit(Axis& axis, int rows, int cols) {
    return axis.x == 0 || axis.y == 0 || axis.y == rows - 1 ||
           axis.x == cols - 1;
  }

 public:
  int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    int rows = maze.size(), cols = maze.front().size();

    int answer = -1;
    Axis start = {entrance[0], entrance[1]};

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    queue<Axis> q;
    q.push(start);
    visited[start.y][start.x] = true;

    int step = 0;
    while (!q.empty() && answer == -1) {
      int size = q.size();

      while (size--) {
        Axis cur = q.front();
        q.pop();

        if (isExit(cur, rows, cols) &&
            !(cur.y == entrance[0] && cur.x == entrance[1])) {
          answer = step;
          break;
        }

        for (Axis& dir : dirs) {
          Axis next = {cur.y + dir.y, cur.x + dir.x};

          if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
            continue;
          if (maze[next.y][next.x] == '+') continue;
          if (visited[next.y][next.x]) continue;
          visited[next.y][next.x] = true;

          q.push(next);
        }
      }
      step++;
    }

    return answer;
  }
};