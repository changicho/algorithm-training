#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use simulation
// time : O(R * C)
// space : O(C)
class Solution {
 public:
  vector<int> findBall(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid.front().size();

    vector<int> answer(cols, -1);
    for (int start = 0; start < cols; start++) {
      int y = 0, x = start;

      while (y < rows) {
        int dir = grid[y][x];

        if (0 <= x + dir && x + dir < cols && grid[y][x + dir] == dir) {
          y++;
          x += dir;
        } else {
          break;
        }
      }

      if (y == rows) answer[start] = x;
    }
    return answer;
  }
};

// use simulation
// time : O(R * C)
// space : O(C)
class Solution {
 public:
  vector<int> findBall(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid.front().size();

    vector<int> answer(cols, -1);
    for (int start = 0; start < cols; start++) {
      int y = 0, x = start;

      while (y < rows) {
        if (grid[y][x] == 1 && x + 1 < cols && grid[y][x + 1] == 1) {
          y++;
          x += 1;
          continue;
        }
        if (grid[y][x] == -1 && x - 1 >= 0 && grid[y][x - 1] == -1) {
          y++;
          x -= 1;
          continue;
        }

        break;
      }

      if (y == rows) answer[start] = x;
    }
    return answer;
  }
};