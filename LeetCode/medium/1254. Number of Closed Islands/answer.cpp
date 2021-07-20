#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use BFS flood fill

class Solution {
 private:
  struct Axis {
    int y, x;
    Axis operator+(Axis& b) const { return {y + b.y, x + b.x}; }
  };
  Axis dirs[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

  void explorer(Axis start, vector<vector<int>>& grid,
                vector<vector<bool>>& visited) {
    int row = grid.size();
    int col = grid.front().size();

    queue<Axis> q;
    q.push(start);

    while (!q.empty()) {
      Axis cur = q.front();
      q.pop();

      if (visited[cur.y][cur.x]) continue;
      visited[cur.y][cur.x] = true;

      for (Axis dir : dirs) {
        Axis next = cur + dir;

        if (next.y < 0 || next.y >= row || next.x < 0 || next.x >= col)
          continue;
        if (visited[next.y][next.x]) continue;

        if (grid[next.y][next.x] == 1) continue;

        q.push(next);
      }
    }
  }

 public:
  int closedIsland(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid.front().size();

    vector<vector<bool>> visited(row, vector<bool>(col, false));

    for (int y = 0; y < row; y++) {
      if (grid[y][0] == 0) explorer({y, 0}, grid, visited);
      if (grid[y][col - 1] == 0) explorer({y, col - 1}, grid, visited);
    }

    for (int x = 0; x < col; x++) {
      if (grid[0][x] == 0) explorer({0, x}, grid, visited);
      if (grid[row - 1][x] == 0) explorer({row - 1, x}, grid, visited);
    }

    int answer = 0;
    for (int y = 1; y < row - 1; y++) {
      for (int x = 1; x < col - 1; x++) {
        if (grid[y][x] == 1) continue;
        if (visited[y][x]) continue;

        answer += 1;

        explorer({y, x}, grid, visited);
      }
    }

    return answer;
  }
};

// use DFS flood fill

class Solution {
 private:
  int fill(vector<vector<int>>& grid, int y, int x) {
    if (y < 0 || x < 0 || y >= grid.size() || x >= grid[y].size()) return 0;
    if (grid[y][x] > 0) return 0;

    grid[y][x] = 1;
    return grid[y][x] + fill(grid, y + 1, x) + fill(grid, y, x + 1) +
           fill(grid, y - 1, x) + fill(grid, y, x - 1);
  }

 public:
  int closedIsland(vector<vector<int>>& grid) {
    int answer = 0;

    for (int y = 0; y < grid.size(); ++y) {
      for (int x = 0; x < grid[y].size(); ++x) {
        if (y * x == 0 || y == grid.size() - 1 || x == grid[y].size() - 1)
          fill(grid, y, x);
      }
    }

    for (int y = 0; y < grid.size(); ++y) {
      for (int x = 0; x < grid[y].size(); ++x) {
        answer += fill(grid, y, x) > 0;
      }
    }
    return answer;
  }
};