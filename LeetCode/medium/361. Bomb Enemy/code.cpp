#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use brute force
// time : O(R * C * (R + C))
// space : O(1)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

 public:
  int maxKilledEnemies(vector<vector<char>> &grid) {
    int rows = grid.size(), cols = grid[0].size();

    auto check = [rows, cols, grid](Axis &a) {
      if (a.y < 0 || a.y >= rows || a.x < 0 || a.x >= cols) return false;
      if (grid[a.y][a.x] == 'W') return false;
      return true;
    };

    int answer = 0;
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (grid[y][x] != '0') continue;

        int count = 0;

        for (Axis &dir : dirs) {
          Axis next = {y + dir.y, x + dir.x};

          while (check(next)) {
            if (grid[next.y][next.x] == 'E') count++;

            next.y += dir.y;
            next.x += dir.x;
          }
        }

        answer = max(answer, count);
      }
    }

    return answer;
  }
};

// use dynamic programming
// time : O(R * C)
// space : O(C)
class Solution {
 public:
  int maxKilledEnemies(vector<vector<char>> &grid) {
    int rows = grid.size(), cols = grid[0].size();

    int answer = 0;

    vector<int> colHits(cols, 0);
    for (int y = 0; y < rows; y++) {
      int rowHits = 0;

      for (int x = 0; x < cols; x++) {
        if (x == 0 || grid[y][x - 1] == 'W') {
          rowHits = 0;

          for (int nx = x; nx < cols && grid[y][nx] != 'W'; nx++) {
            rowHits += grid[y][nx] == 'E';
          }
        }

        if (y == 0 || grid[y - 1][x] == 'W') {
          colHits[x] = 0;

          for (int ny = y; ny < rows && grid[ny][x] != 'W'; ny++) {
            colHits[x] += grid[ny][x] == 'E';
          }
        }

        if (grid[y][x] == '0') {
          answer = max(answer, rowHits + colHits[x]);
        }
      }
    }

    return answer;
  }
};