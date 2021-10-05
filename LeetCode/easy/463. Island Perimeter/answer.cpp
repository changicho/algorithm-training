#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use 4 way detection

class Solution {
 private:
  struct Axis {
    int y, x;
  };

 public:
  int islandPerimeter(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid.front().size();

    vector<Axis> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int answer = 0;
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (grid[y][x] == 0) continue;

        for (Axis dir : dirs) {
          Axis next = {dir.y + y, dir.x + x};

          if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols) {
            answer += 1;
            continue;
          }
          if (grid[next.y][next.x] == 0) {
            answer += 1;
            continue;
          }
        }
      }
    }

    return answer;
  }
};

// use remove duplicate

class Solution {
 public:
  int islandPerimeter(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid.front().size();

    int count = 0, repeat = 0;
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (grid[y][x] != 1) continue;

        count++;
        if (y != 0 && grid[y - 1][x] == 1) repeat++;
        if (x != 0 && grid[y][x - 1] == 1) repeat++;
      }
    }
    return 4 * count - repeat * 2;
  }
};
