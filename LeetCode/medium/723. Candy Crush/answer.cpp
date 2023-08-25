#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// use simulation
// time : O((R * C)^2)
// space : O(R * C)
class Solution {
 private:
  struct Axis {
    int y, x;
  };

  Axis dirs[2] = {{0, 1}, {1, 0}};

  vector<vector<int>> board;

  queue<Axis> needToCrush;

  void move(int x) {
    int rows = board.size(), cols = board[0].size();

    queue<int> vals;
    for (int y = rows - 1; y >= 0; y--) {
      if (board[y][x] != 0) vals.push(board[y][x]);
      board[y][x] = 0;
    }

    for (int y = rows - 1; y >= 0 && !vals.empty(); y--) {
      board[y][x] = vals.front();
      vals.pop();
    }
  }
  void move() {
    int rows = board.size(), cols = board[0].size();

    for (int x = 0; x < cols; x++) {
      move(x);
    }
  }

  bool hasCrashedCandy() {
    int rows = board.size(), cols = board[0].size();

    bool checked[51][51][2] = {
        false,
    };

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        int key = board[y][x];
        if (key == 0) continue;

        for (int dirIdx = 0; dirIdx < 2; dirIdx++) {
          Axis &dir = dirs[dirIdx];

          if (checked[y][x][dirIdx]) continue;
          queue<Axis> q;
          vector<Axis> targets;

          q.push({y, x});

          while (!q.empty()) {
            Axis cur = q.front();
            q.pop();

            targets.push_back(cur);

            Axis next = {cur.y + dir.y, cur.x + dir.x};

            if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
              continue;
            if (board[next.y][next.x] != key) continue;

            q.push(next);
          }

          if (targets.size() < 3) continue;
          for (Axis &a : targets) {
            checked[a.y][a.x][dirIdx] = true;
          }
        }
      }
    }
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (checked[y][x][0] || checked[y][x][1]) {
          needToCrush.push({y, x});
        }
      }
    }

    return needToCrush.size() > 0;
  }

  void crush() {
    while (!needToCrush.empty()) {
      Axis a = needToCrush.front();
      needToCrush.pop();
      board[a.y][a.x] = 0;
    }
  }

 public:
  vector<vector<int>> candyCrush(vector<vector<int>> &board) {
    this->board = board;

    while (hasCrashedCandy()) {
      crush();
      move();
    }

    return this->board;
  }
};
