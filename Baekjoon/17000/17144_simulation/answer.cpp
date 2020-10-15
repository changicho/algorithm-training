#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

struct AirCleaner {
  Axis upper, lower;
};

Axis dirs[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
Axis limit;
int board[50][50];

void ClockWise(Axis start) {
  for (int y = start.y + 1; y < limit.y - 1; y += 1) {
    board[y][start.x] = board[y + 1][start.x];
  }
  for (int x = 0; x < limit.x - 1; x += 1) {
    board[limit.y - 1][x] = board[limit.y - 1][x + 1];
  }
  for (int y = limit.y - 1; y > start.y; y -= 1) {
    board[y][limit.x - 1] = board[y - 1][limit.x - 1];
  }
  for (int x = limit.x - 1; x > start.x; x -= 1) {
    board[start.y][x] = board[start.y][x - 1];
  }
  board[start.y][start.x] = -1;
  board[start.y][start.x + 1] = 0;
}

void CounterClockWise(Axis start) {
  for (int y = start.y; y > 0; y -= 1) {
    board[y][start.x] = board[y - 1][start.x];
  }
  for (int x = start.x; x < limit.x - 1; x += 1) {
    board[0][x] = board[0][x + 1];
  }
  for (int y = 0; y < start.y; y += 1) {
    board[y][limit.x - 1] = board[y + 1][limit.x - 1];
  }
  for (int x = limit.x - 1; x > start.x + 1; x -= 1) {
    board[start.y][x] = board[start.y][x - 1];
  }
  board[start.y][start.x] = -1;
  board[start.y][start.x + 1] = 0;
}

void solution() {
  int R, C, T;
  int answer = 0;
  AirCleaner airCleaner = {{-1, -1}, {-1, -1}};

  cin >> R >> C >> T;
  limit = {R, C};

  for (int y = 0; y < R; y++) {
    for (int x = 0; x < C; x++) {
      cin >> board[y][x];

      if (board[y][x] == -1) {
        if (airCleaner.upper.y == -1) {
          airCleaner.upper = {y, x};
        } else {
          airCleaner.lower = {y, x};
        }
      }
    }
  }

  for (int time = 0; time < T; time++) {
    // 먼지의 확산
    vector<Axis> dusts;
    for (int y = 0; y < R; y++) {
      for (int x = 0; x < C; x++) {
        if (board[y][x] > 0) dusts.push_back({y, x});
      }
    }

    int diff[50][50] = {
        0,
    };
    for (Axis cur : dusts) {
      int count = board[cur.y][cur.x] / 5;
      if (count == 0) continue;

      for (Axis dir : dirs) {
        Axis next = cur;
        next.y += dir.y;
        next.x += dir.x;

        if (next.y < 0 || next.y >= R || next.x < 0 || next.x >= C) continue;
        if (board[next.y][next.x] == -1) continue;

        diff[next.y][next.x] += count;
        diff[cur.y][cur.x] -= count;
      }
    }

    for (int y = 0; y < R; y++) {
      for (int x = 0; x < C; x++) {
        board[y][x] += diff[y][x];
      }
    }

    // 공지청정기 회전
    CounterClockWise(airCleaner.upper);
    ClockWise(airCleaner.lower);
  }

  for (int y = 0; y < R; y++) {
    for (int x = 0; x < C; x++) {
      if (board[y][x] == -1) continue;
      answer += board[y][x];
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