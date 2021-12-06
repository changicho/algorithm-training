#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use DFS with backtracking

class Solution {
 private:
  // use backtracking with DFS
  // we check colFine[index][number], rowFine[index][number],
  // sectionFine[y][y][number]
  bool colFine[10][10], rowFine[10][10], sectionFine[3][3][10];
  // cause we check in a col, there are no duplicated number in same line
  // same with row, section (3*3)
  // make answer boolean value
  bool answer = false;

  // make function DFS(index)
  void DFS(int index, vector<vector<char>>& board) {
    // if axis is over than range
    // that means there are answer
    // we can make y, x axis using index
    int y = index / 9, x = index % 9;

    if (index >= 81) {
      answer = true;
      return;
    }

    // if board[y][x] is already filled, increase axis and DFS it
    if (board[y][x] != '.') {
      DFS(index + 1, board);
      return;
    }

    // in y,x iterate 1 ~ 9 to check it
    // if can increase axis
    for (int num = 1; num <= 9; num++) {
      if (colFine[x][num] == true) continue;
      if (rowFine[y][num] == true) continue;
      if (sectionFine[y / 3][x / 3][num] == true) continue;

      colFine[x][num] = true;
      rowFine[y][num] = true;
      sectionFine[y / 3][x / 3][num] = true;

      board[y][x] = num + '0';
      DFS(index + 1, board);

      if (answer) return;

      board[y][x] = '.';
      colFine[x][num] = false;
      rowFine[y][num] = false;
      sectionFine[y / 3][x / 3][num] = false;
    }
  }

 public:
  void solveSudoku(vector<vector<char>>& board) {
    for (int y = 0; y < 9; y++) {
      for (int x = 0; x < 9; x++) {
        if (board[y][x] == '.') continue;

        int num = board[y][x] - '0';
        colFine[x][num] = true;
        rowFine[y][num] = true;
        sectionFine[y / 3][x / 3][num] = true;
      }
    }

    DFS(0, board);
  }
};

// legacy code

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
      if (!col[x][number] && !row[y][number] &&
          !field[getFieldIndex(y, x)][number]) {
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

  int getFieldIndex(int y, int x) { return (y / 3) * 3 + x / 3; }
};