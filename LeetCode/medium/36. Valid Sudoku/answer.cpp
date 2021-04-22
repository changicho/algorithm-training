#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    bool row[9][10] = {
        false,
    };
    bool col[9][10] = {
        false,
    };
    bool field[9][10] = {
        false,
    };
    for (int y = 0; y < 9; y++) {
      for (int x = 0; x < 9; x++) {
        if (board[y][x] == '.') continue;

        if (col[x][board[y][x] - '0']) return false;
        if (row[y][board[y][x] - '0']) return false;
        if (field[getFieldIndex(y, x)][board[y][x] - '0']) return false;

        col[x][board[y][x] - '0'] = true;
        row[y][board[y][x] - '0'] = true;
        field[getFieldIndex(y, x)][board[y][x] - '0'] = true;
      }
    }

    return true;
  }

  int getFieldIndex(int y, int x) {
    return (y / 3) * 3 + x / 3;
  }
};