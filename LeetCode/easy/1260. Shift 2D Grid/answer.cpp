#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use make new grid
// time : O(R * C)
// space : O(R * C)
class Solution {
 public:
  vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    int rows = grid.size();
    int cols = grid.front().size();

    int size = rows * cols;
    vector<vector<int>> newGrid(rows, vector<int>(cols));

    k %= size;

    for (int i = 0; i < size; i++) {
      int y = i / cols, x = i % cols;
      int nextIdx = (i + k) % size;
      int ny = nextIdx / cols, nx = nextIdx % cols;

      newGrid[ny][nx] = grid[y][x];
    }

    return newGrid;
  }
};

// use grid reverse
// time : O(R * C)
// space : O(1)
class Solution {
 private:
  void reverse(vector<vector<int>>& grid, int from, int to) {
    int rows = grid.size();
    int cols = grid.front().size();

    while (from < to) {
      int y1 = from / cols, x1 = from % cols, y2 = to / cols, x2 = to % cols;

      swap(grid[y1][x1], grid[y2][x2]);

      from++, to--;
    }
  }

 public:
  vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    int rows = grid.size();
    int cols = grid.front().size();

    int size = rows * cols;
    k %= size;

    reverse(grid, 0, size - 1);
    reverse(grid, 0, k - 1);
    reverse(grid, k, size - 1);

    return grid;
  }
};
