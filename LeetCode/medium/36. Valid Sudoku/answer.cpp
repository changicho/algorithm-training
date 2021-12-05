#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use duplicate check

class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    // we check colFine[index][number], rowFine[index][number],
    // sectionFine[y][y][number]
    bool colFine[10][10] =
        {
            false,
        },
         rowFine[10][10] =
             {
                 false,
             },
         sectionFine[3][3][10] = {
             false,
         };

    // fill fine check array's
    for (int y = 0; y < 9; y++) {
      for (int x = 0; x < 9; x++) {
        if (board[y][x] == '.') continue;
        int num = board[y][x] - '0';

        if (colFine[x][num] || rowFine[y][num] ||
            sectionFine[y / 3][x / 3][num]) {
          return false;
        }

        colFine[x][num] = true;
        rowFine[y][num] = true;
        sectionFine[y / 3][x / 3][num] = true;
      }
    }

    return true;
  }
};

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

  int getFieldIndex(int y, int x) { return (y / 3) * 3 + x / 3; }
};
