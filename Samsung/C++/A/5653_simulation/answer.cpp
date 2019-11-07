#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct range {
  int min;
  int max;
};
struct axis {
  int x;
  int y;
};
struct cell {
  int timer;
  int power;
  bool isActivated;
  bool isAlive;
  bool isNew;
};
axis moves[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
range Y;
range X;
cell cells[400][400];

void print() {
  cout << "\n###print status###\n";
  for (int y = Y.min; y < Y.max; y++) {
    for (int x = X.min; x < X.max; x++) {
      if (!cells[y][x].isAlive && cells[y][x].isActivated) {
        cout << "D";
      } else {
        if (cells[y][x].isActivated) {
          cout << "A";
        } else {
          cout << cells[y][x].power;
        }
      }
    }
    cout << "\n";
  }
}

void copyCells(int x_start, int y_start) {
  int current_power = cells[y_start][x_start].power;

  for (int i = 0; i < 4; i++) {
    int x = x_start + moves[i].x;
    int y = y_start + moves[i].y;

    if (cells[y][x].power == 0) {
      cells[y][x].power = current_power;
      cells[y][x].timer = current_power;
      cells[y][x].isAlive = true;
      cells[y][x].isActivated = false;
      cells[y][x].isNew = true;

      // range 갱신
      if (y == Y.max) {
        Y.max++;
      } else if (y < Y.min) {
        Y.min--;
      }
      if (x == X.max) {
        X.max++;
      } else if (x < X.min) {
        X.min--;
      }
    }
    if (cells[y][x].power < current_power && cells[y][x].isNew) {
      cells[y][x].power = current_power;
      cells[y][x].timer = current_power;
    }
  }
}

void timeFly() {
  for (int y = Y.min; y < Y.max; y++) {
    for (int x = X.min; x < X.max; x++) {
      // 활성 상태인 경우 복제를 수행
      if (cells[y][x].isActivated && cells[y][x].power == cells[y][x].timer) {
        copyCells(x, y);
      }
      if (!cells[y][x].isNew) {
        cells[y][x].timer--;
      }

      // 비활성 상태의 셀을 시간이 지날때마다 활성상태인지 확인 후 변경
      if (cells[y][x].timer == 0) {
        // 비활성 상태면 활성상태로 바꿈
        if (!cells[y][x].isActivated && cells[y][x].isAlive) {
          cells[y][x].isActivated = true;
          cells[y][x].timer = cells[y][x].power;
        } else if (cells[y][x].isActivated) {
          // 활성 상태에서 시간이 끝나면 죽여버림
          cells[y][x].isAlive = false;
        }
      }
    }
  }

  for (int y = Y.min; y < Y.max; y++) {
    for (int x = X.min; x < X.max; x++) {
      cells[y][x].isNew = false;
    }
  }
}

int countLive() {
  int count = 0;
  for (int y = Y.min; y < Y.max; y++) {
    for (int x = X.min; x < X.max; x++) {
      if (cells[y][x].isAlive) {
        count++;
      }
    }
  }
  return count;
}

void solution(int test_case) {
  // 비커 초기화
  for (int y = 0; y < 400; y++) {
    for (int x = 0; x < 400; x++) {
      cells[y][x].timer = 0;
      cells[y][x].power = 0;
      cells[y][x].isActivated = false;
      cells[y][x].isAlive = false;
    }
  }

  int N, M, K;
  cin >> N >> M >> K;

  Y = {200, 200 + N};
  X = {200, 200 + M};

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      cin >> cells[200 + y][200 + x].power;
      cells[200 + y][200 + x].timer = cells[200 + y][200 + x].power;
      if (cells[200 + y][200 + x].power != 0) {
        cells[200 + y][200 + x].isAlive = true;
      }
    }
  }

  for (int second = 0; second < K; second++) {
    timeFly();
  }
  cout << "#" << test_case << " " << countLive() << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  for (int test_case = 1; test_case <= T; test_case++) {
    solution(test_case);
  }

  return 0;
}