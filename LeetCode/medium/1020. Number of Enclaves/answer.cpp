#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use BFS
// time : O(N)
// space : O(N)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  void visitBFS(vector<vector<int>>& grid, Axis start) {
    int rows = grid.size(), cols = grid[0].size();

    queue<Axis> q;
    q.push(start);

    while (!q.empty()) {
      Axis cur = q.front();
      q.pop();

      if (grid[cur.y][cur.x] == 0) continue;
      grid[cur.y][cur.x] = 0;

      for (Axis& dir : dirs) {
        Axis next = {cur.y + dir.y, cur.x + dir.x};

        if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
          continue;
        if (grid[next.y][next.x] == 0) continue;
        q.push(next);
      }
    }
  }

 public:
  int numEnclaves(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();

    for (int y = 0; y < rows; y++) {
      if (grid[y][0] == 1) {
        visitBFS(grid, {y, 0});
      }
      if (grid[y][cols - 1] == 1) {
        visitBFS(grid, {y, cols - 1});
      }
    }
    for (int x = 0; x < cols; x++) {
      if (grid[0][x] == 1) {
        visitBFS(grid, {0, x});
      }
      if (grid[rows - 1][x] == 1) {
        visitBFS(grid, {rows - 1, x});
      }
    }
    int answer = 0;
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (grid[y][x] == 1) answer++;
      }
    }
    return answer;
  }
};