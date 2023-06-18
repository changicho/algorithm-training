#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(N)
// space : O(N^2)
class TicTacToe {
 private:
  vector<vector<int>> board;
  bool hasWinner = false;

  bool checkDiagonal(int player) {
    int size = board.size();
    bool lToR = true, rToL = true;
    for (int i = 0; i < size; i++) {
      int rX = size - 1 - i;
      if (board[i][i] != player) {
        lToR = false;
      }
      if (board[i][rX] != player) {
        rToL = false;
      }
    }
    return lToR || rToL;
  }

  bool checkHorizontal(int player, int y) {
    int size = board.size();
    for (int x = 0; x < size; x++) {
      if (board[y][x] != player) return false;
    }
    return true;
  }
  bool checkHorizontal(int player) {
    int size = board.size();
    for (int y = 0; y < size; y++) {
      if (checkHorizontal(player, y)) return true;
    }
    return false;
  }

  bool checkVertical(int player, int x) {
    int size = board.size();
    for (int y = 0; y < size; y++) {
      if (board[y][x] != player) return false;
    }
    return true;
  }
  bool checkVertical(int player) {
    int size = board.size();
    for (int x = 0; x < size; x++) {
      if (checkVertical(player, x)) return true;
    }
    return false;
  }

  int checkWinner(int row, int col, int player) {
    int size = board.size();

    if (checkDiagonal(player) || checkHorizontal(player, row) ||
        checkVertical(player, col)) {
      return player;
    }
    return 0;
  }

 public:
  TicTacToe(int n) { board.resize(n, vector<int>(n, 0)); }

  int move(int row, int col, int player) {
    if (!hasWinner) {
      board[row][col] = player;
    }

    int ret = checkWinner(row, col, player);
    if (ret != 0) {
      hasWinner = true;
    }
    return ret;
  }
};

// use brute force optimized
// time : O(1)
// space : O(N)
class TicTacToe {
 private:
  int size;
  int rowCounts[101] = {
      0,
  };
  int colCounts[101] = {
      0,
  };
  int diagonalCount = 0;
  int reverseDiagonalCount = 0;

 public:
  TicTacToe(int n) { size = n; }

  int move(int row, int col, int player) {
    int currentPlayer = (player == 1) ? 1 : -1;

    // update row and col
    rowCounts[row] += currentPlayer;
    colCounts[col] += currentPlayer;

    // update diagonal
    if (row == col) {
      diagonalCount += currentPlayer;
    }
    if (col == (size - row - 1)) {
      reverseDiagonalCount += currentPlayer;
    }

    if (abs(rowCounts[row]) == size || abs(colCounts[col]) == size ||
        abs(diagonalCount) == size || abs(reverseDiagonalCount) == size) {
      return player;
    }

    return 0;
  }
};