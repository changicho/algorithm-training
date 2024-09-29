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

// use BFS
// time : O(R * C)
// space : O(R * C)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

 public:
  int regionsBySlashes(vector<string>& grid) {
    int rows = grid.size(), cols = grid[0].size();

    vector<vector<bool>> board(rows * 3, vector<bool>(cols * 3, false));

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        int ny = y * 3, nx = x * 3;

        if (grid[y][x] == '\\') {
          board[ny][nx] = board[ny + 1][nx + 1] = board[ny + 2][nx + 2] = true;
        } else if (grid[y][x] == '/') {
          board[ny][nx + 2] = board[ny + 1][nx + 1] = board[ny + 2][nx] = true;
        }
      }
    }

    function<void(Axis)> check = [&](Axis a) {
      queue<Axis> q;
      q.push(a);
      board[a.y][a.x] = true;
      while (!q.empty()) {
        Axis cur = q.front();
        q.pop();

        for (Axis& dir : dirs) {
          Axis next = {cur.y + dir.y, cur.x + dir.x};

          if (next.y < 0 || next.y >= rows * 3 || next.x < 0 ||
              next.x >= cols * 3)
            continue;
          if (board[next.y][next.x]) continue;
          board[next.y][next.x] = true;
          q.push(next);
        }
      }
    };

    int answer = 0;

    for (int y = 0; y < rows * 3; y++) {
      for (int x = 0; x < cols * 3; x++) {
        if (board[y][x]) continue;

        answer++;
        check({y, x});
      }
    }
    return answer;
  }
};