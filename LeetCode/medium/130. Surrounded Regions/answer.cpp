#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use BFS

class Solution {
  struct Axis {
    int y, x;
  };
  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

 public:
  void solve(vector<vector<char>>& board) {
    int m = board.size();
    int n = board.front().size();

    vector<vector<bool>> visited(m, vector<bool>(n, false));

    queue<Axis> q;
    for (int y = 0; y < m; y++) {
      if (board[y][0] == 'O') q.push({y, 0});
      if (board[y][n - 1] == 'O') q.push({y, n - 1});
    }
    for (int x = 1; x < n - 1; x++) {
      if (board[0][x] == 'O') q.push({0, x});
      if (board[m - 1][x] == 'O') q.push({m - 1, x});
    }

    while (!q.empty()) {
      Axis cur = q.front();
      q.pop();

      if (visited[cur.y][cur.x]) continue;
      visited[cur.y][cur.x] = true;

      for (Axis dir : dirs) {
        Axis next = cur;
        next.y += dir.y;
        next.x += dir.x;

        if (next.y < 0 || next.y >= m || next.x < 0 || next.x >= n) continue;
        if (board[next.y][next.x] == 'X') continue;

        q.push(next);
      }
    }

    for (int y = 1; y < m - 1; y++) {
      for (int x = 1; x < n - 1; x++) {
        if (board[y][x] == 'X') continue;
        if (visited[y][x]) continue;

        q.push({y, x});

        while (!q.empty()) {
          Axis cur = q.front();
          q.pop();

          if (visited[cur.y][cur.x]) continue;
          visited[cur.y][cur.x] = true;
          board[cur.y][cur.x] = 'X';

          for (Axis dir : dirs) {
            Axis next = cur;
            next.y += dir.y;
            next.x += dir.x;

            if (next.y < 0 || next.y >= m || next.x < 0 || next.x >= n)
              continue;
            if (board[next.y][next.x] == 'X') continue;

            q.push(next);
          }
        }
      }
    }
  }
};