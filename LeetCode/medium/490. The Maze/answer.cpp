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

  Axis dirs[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

  bool isSafe(Axis a, int rows, int cols) {
    return a.y >= 0 && a.y < rows && a.x >= 0 && a.x < cols;
  }

 public:
  bool hasPath(vector<vector<int>>& maze, vector<int>& start,
               vector<int>& destination) {
    int rows = maze.size(), cols = maze[0].size();

    bool visited[101][101] = {false};

    queue<Axis> q;
    q.push({start[0], start[1]});

    while (!q.empty()) {
      Axis cur = q.front();
      q.pop();

      if (visited[cur.y][cur.x]) continue;
      visited[cur.y][cur.x] = true;

      for (Axis& dir : dirs) {
        Axis next = cur;

        while (isSafe(next, rows, cols) && maze[next.y][next.x] == 0) {
          next.y += dir.y;
          next.x += dir.x;
        }

        next.y -= dir.y;
        next.x -= dir.x;

        q.push(next);
      }
    }

    return visited[destination[0]][destination[1]];
  }
};