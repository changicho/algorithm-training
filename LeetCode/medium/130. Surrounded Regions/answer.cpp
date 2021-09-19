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

// use BFS with update fast

class Solution {
 private:
  struct Axis {
    int y, x;
  };
  Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  void BFS(vector<vector<char>>& board, Axis axis, char skip, char newValue) {
    if (board[axis.y][axis.x] != skip) return;

    int rows = board.size();
    int cols = board.front().size();

    queue<Axis> q;
    q.push(axis);
    board[axis.y][axis.x] = newValue;

    while (!q.empty()) {
      Axis cur = q.front();
      q.pop();

      for (Axis dir : dirs) {
        Axis next = {cur.y + dir.y, cur.x + dir.x};

        if (next.x < 0 || next.x >= cols || next.y < 0 || next.y >= rows)
          continue;
        if (board[next.y][next.x] != skip) continue;

        board[next.y][next.x] = newValue;
        q.push(next);
      }
    }
  }

 public:
  void solve(vector<vector<char>>& board) {
    int rows = board.size();
    int cols = board.front().size();

    vector<Axis> edges;
    for (int y = 0; y < rows; y++) {
      if (board[y][0] == 'O') edges.push_back({y, 0});
      if (board[y][cols - 1] == 'O') edges.push_back({y, cols - 1});
    }
    for (int x = 0; x < cols; x++) {
      if (board[0][x] == 'O') edges.push_back({0, x});
      if (board[rows - 1][x] == 'O') edges.push_back({rows - 1, x});
    }

    for (Axis edge : edges) {
      BFS(board, edge, 'O', 'E');
    }

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (board[y][x] == 'O') {
          board[y][x] = 'X';
        } else if (board[y][x] == 'E') {
          board[y][x] = 'O';
        }
      }
    }
  }
};