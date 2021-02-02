#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

int board[9][9];
bool row[9][10];
bool col[9][10];
bool field[9][10];
bool isOver = false;

vector<Axis> blanks;

// 해당하는 분면으로 변화
int getFieldIndex(int y, int x) {
  return (y / 3) * 3 + x / 3;
}

void recursive(int depth) {
  if (isOver) return;

  if (depth == blanks.size()) {
    isOver = true;
    return;
  }

  Axis cur = blanks[depth];
  int y = cur.y;
  int x = cur.x;

  if (board[y][x] > 0) {
    recursive(depth + 1);
    return;
  }

  for (int number = 1; number <= 9; number++) {
    if (!col[x][number] && !row[y][number] && !field[getFieldIndex(y, x)][number]) {
      board[y][x] = number;
      col[x][number] = true;
      row[y][number] = true;
      field[getFieldIndex(y, x)][number] = true;

      recursive(depth + 1);
      if (isOver) return;

      board[y][x] = 0;
      col[x][number] = false;
      row[y][number] = false;
      field[getFieldIndex(y, x)][number] = false;
    }
  }
}

void solution() {
  for (int y = 0; y < 9; y++) {
    for (int x = 0; x < 9; x++) {
      cin >> board[y][x];

      if (board[y][x] > 0) {
        col[x][board[y][x]] = true;
        row[y][board[y][x]] = true;
        field[getFieldIndex(y, x)][board[y][x]] = true;
      } else {
        blanks.push_back({y, x});
      }
    }
  }

  recursive(0);

  for (int y = 0; y < 9; y++) {
    for (int x = 0; x < 9; x++) {
      cout << board[y][x] << " ";
    }
    cout << "\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}