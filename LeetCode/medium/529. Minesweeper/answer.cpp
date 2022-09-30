#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use simulation
// time : O(R * C)
// space : O(R * C)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  Axis dirs[8] = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                  {1, 0},  {1, -1}, {0, -1}, {-1, -1}};

  int countNearBomb(Axis &cur, vector<vector<char>> &board) {
    int rows = board.size();
    int cols = board.front().size();

    int count = 0;
    for (Axis &dir : dirs) {
      Axis next = {cur.y + dir.y, cur.x + dir.x};

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      if (board[next.y][next.x] == 'M') {
        count++;
      }
    }
    return count;
  }

 public:
  vector<vector<char>> updateBoard(vector<vector<char>> &board,
                                   vector<int> &click) {
    int rows = board.size();
    int cols = board.front().size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    if (board[click.front()][click.back()] == 'M') {
      board[click.front()][click.back()] = 'X';
      return board;
    }
    if (board[click.front()][click.back()] != 'E') {
      return board;
    }

    queue<Axis> q;
    q.push({click.front(), click.back()});
    visited[click.front()][click.back()] = true;

    while (!q.empty()) {
      Axis cur = q.front();
      q.pop();

      int bombCount = countNearBomb(cur, board);

      if (bombCount > 0) {
        board[cur.y][cur.x] = ('0' + bombCount);
        continue;
      }
      board[cur.y][cur.x] = 'B';

      for (Axis &dir : dirs) {
        Axis next = {cur.y + dir.y, cur.x + dir.x};

        if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
          continue;
        if (board[next.y][next.x] != 'E') continue;
        if (visited[next.y][next.x]) continue;

        visited[next.y][next.x] = true;
        q.push(next);
      }
    }

    return board;
  }
};