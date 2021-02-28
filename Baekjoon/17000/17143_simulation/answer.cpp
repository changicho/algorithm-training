#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

struct Shark {
  bool isExist;
  Axis axis, dir;
  int speed, size;
};

int R, C, M;
Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int board[100][100];
vector<Shark> sharks;

void clearBoard() {
  for (int y = 0; y < R; y++) {
    for (int x = 0; x < C; x++) {
      board[y][x] = -1;
    }
  }
}

void solution() {
  cin >> R >> C >> M;

  clearBoard();
  for (int i = 0; i < M; i++) {
    Shark shark;
    int dir;

    shark.isExist = true;
    cin >> shark.axis.y >> shark.axis.x >> shark.speed >> dir >> shark.size;
    shark.axis.y -= 1;
    shark.axis.x -= 1;
    // d가 1인 경우는 위, 2인 경우는 아래, 3인 경우는 오른쪽, 4인 경우는 왼쪽을 의미한다.
    switch (dir) {
      case 1: {
        shark.dir = dirs[0];
        break;
      }
      case 2: {
        shark.dir = dirs[2];
        break;
      }
      case 3: {
        shark.dir = dirs[1];
        break;
      }
      case 4: {
        shark.dir = dirs[3];
        break;
      }
    }
    if (shark.dir.y == 0) {
      shark.speed %= 2 * (C - 1);
    }
    if (shark.dir.x == 0) {
      shark.speed %= 2 * (R - 1);
    }
    board[shark.axis.y][shark.axis.x] = i;
    sharks.push_back(shark);
  }

  int answer = 0;
  for (int position = 0; position < C; position += 1) {
    // 상어 잡기
    for (int y = 0; y < R; y++) {
      if (board[y][position] != -1) {
        int delete_target = board[y][position];
        board[y][position] = -1;

        answer += sharks[delete_target].size;
        sharks[delete_target].isExist = false;
        break;
      }
    }

    // 상어 이동
    vector<Shark> new_sharks;
    for (Shark shark : sharks) {
      if (!shark.isExist) continue;

      for (int move = 0; move < shark.speed; move++) {
        if ((shark.axis.x == 0 && shark.dir.x == -1) || (shark.axis.x == C - 1 && shark.dir.x == 1)) {
          shark.dir.x *= -1;
        }
        if ((shark.axis.y == 0 && shark.dir.y == -1) || (shark.axis.y == R - 1 && shark.dir.y == 1)) {
          shark.dir.y *= -1;
        }

        shark.axis.x += shark.dir.x;
        shark.axis.y += shark.dir.y;
      }

      new_sharks.push_back(shark);
    }

    // 상어 잡아먹히기
    clearBoard();
    for (int index = 0; index < new_sharks.size(); index++) {
      Shark shark = new_sharks[index];
      Axis axis = shark.axis;

      if (board[axis.y][axis.x] == -1) {
        board[axis.y][axis.x] = index;
      } else {
        int target = board[axis.y][axis.x];
        if (new_sharks[target].size > shark.size) continue;

        board[axis.y][axis.x] = index;
      }
    }

    // 남은 상어 추출
    sharks.clear();
    sharks.resize(0);
    for (int y = 0; y < R; y++) {
      for (int x = 0; x < C; x++) {
        if (board[y][x] != -1) {
          int target = board[y][x];
          sharks.push_back(new_sharks[target]);
        }
      }
    }
    clearBoard();

    // 보드 갱신
    for (int index = 0; index < sharks.size(); index++) {
      Shark shark = sharks[index];
      Axis axis = shark.axis;

      board[axis.y][axis.x] = index;
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