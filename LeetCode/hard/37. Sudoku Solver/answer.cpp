#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

class Solution {
 public:
  bool row[9][10] = {
      false,
  };
  bool col[9][10] = {
      false,
  };
  bool field[9][10] = {
      false,
  };
  bool isOver = false;
  vector<Axis> blanks;

  void solveSudoku(vector<vector<char>>& board) {
    for (int y = 0; y < 9; y++) {
      for (int x = 0; x < 9; x++) {
        if (board[y][x] > '0') {
          col[x][board[y][x] - '0'] = true;
          row[y][board[y][x] - '0'] = true;
          field[getFieldIndex(y, x)][board[y][x] - '0'] = true;
        } else {
          blanks.push_back({y, x});
        }
      }
    }

    recursive(0, board);
  }

  void recursive(int depth, vector<vector<char>>& board) {
    if (isOver) return;

    if (depth == blanks.size()) {
      isOver = true;
      return;
    }

    Axis cur = blanks[depth];
    int y = cur.y;
    int x = cur.x;

    if (board[y][x] != '.' && board[y][x] > '0') {
      recursive(depth + 1, board);
      return;
    }

    for (int number = 1; number <= 9; number++) {
      if (!col[x][number] && !row[y][number] && !field[getFieldIndex(y, x)][number]) {
        board[y][x] = number + '0';
        col[x][number] = true;
        row[y][number] = true;
        field[getFieldIndex(y, x)][number] = true;

        recursive(depth + 1, board);
        if (isOver) return;

        board[y][x] = '.';
        col[x][number] = false;
        row[y][number] = false;
        field[getFieldIndex(y, x)][number] = false;
      }
    }
  }

  int getFieldIndex(int y, int x) {
    return (y / 3) * 3 + x / 3;
  }
};