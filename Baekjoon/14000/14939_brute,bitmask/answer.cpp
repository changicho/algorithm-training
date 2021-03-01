#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool board[10][10];
bool temp_board[10][10];

void toggle(Axis axis) {
  int y = axis.y, x = axis.x;

  temp_board[y][x] = !temp_board[y][x];

  for (Axis dir : dirs) {
    Axis next = axis;
    next.y += dir.y;
    next.x += dir.x;

    if (next.y < 0 || next.y >= 10 || next.x < 0 || next.x >= 10) continue;
    temp_board[next.y][next.x] = !temp_board[next.y][next.x];
  }
}

void solution() {
  string line;
  for (int y = 0; y < 10; y++) {
    cin >> line;
    for (int x = 0; x < 10; x++) {
      board[y][x] = line[x] == 'O' ? true : false;
    }
  }

  int answer = -1;

  for (int bitMask = (1 << 10) - 1; bitMask >= 0; bitMask--) {
    int count = 0;

    for (int y = 0; y < 10; y++) {
      for (int x = 0; x < 10; x++) {
        temp_board[y][x] = board[y][x];
      }
    }

    // y == 0 인 경우
    for (int x = 0; x < 10; x++) {
      if (bitMask & (1 << (10 - x - 1))) {
        toggle({0, x});

        count++;
      }
    }

    for (int y = 1; y < 10; y++) {
      for (int x = 0; x < 10; x++) {
        // {y - 1, x} 좌표의 전구가 불이 켜져있을때
        if (temp_board[y - 1][x]) {
          toggle({y, x});

          count++;
        }
      }
    }

    int onCount = 0;
    for (int x = 0; x < 10; x++) {
      if (temp_board[10 - 1][x]) {
        onCount += 1;
      }
    }

    if (onCount == 0) {
      if (answer == -1) {
        answer = count;
      } else {
        answer = min(answer, count);
      }
    }
  }

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}