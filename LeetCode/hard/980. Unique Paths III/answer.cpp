#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use DFS & backtracking
// time : O(3^(R * C))
// space : O(R * C)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  bool visited[21][21] = {
      false,
  };
  int answer = 0;

  void recursive(Axis axis, int leftCount, vector<vector<int>> &grid) {
    if (leftCount == 0 && grid[axis.y][axis.x] == 2) {
      answer++;
      return;
    }

    if (grid[axis.y][axis.x] == 0) leftCount--;
    visited[axis.y][axis.x] = true;

    int rows = grid.size(), cols = grid.front().size();

    for (Axis &dir : dirs) {
      Axis next = {dir.y + axis.y, dir.x + axis.x};

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      if (grid[next.y][next.x] == -1) continue;
      if (visited[next.y][next.x]) continue;

      recursive(next, leftCount, grid);
    }

    visited[axis.y][axis.x] = false;
  }

 public:
  int uniquePathsIII(vector<vector<int>> &grid) {
    int leftCount = 0;
    int rows = grid.size(), cols = grid.front().size();

    Axis start = {-1, -1};
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (grid[y][x] == 0) leftCount++;
        if (grid[y][x] == 1) {
          start = {y, x};
        }
      }
    }

    recursive(start, leftCount, grid);

    return answer;
  }
};