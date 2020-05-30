#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int map[21][21];

struct axis {
  int y, x;
};

struct cube {
  int TOP, BOTTOM, LEFT, RIGHT, FRONT, BACK;
};

cube dice = {0, 0, 0, 0, 0, 0};
axis dirs[5] = {{0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0}};

void move_right() {
  // FRONT, BACK 은 움직이지 않음
  // top > right > bottom > left
  int temp = dice.LEFT;
  dice.LEFT = dice.BOTTOM;
  dice.BOTTOM = dice.RIGHT;
  dice.RIGHT = dice.TOP;
  dice.TOP = temp;
}

void move_left() {
  // FRONT, BACK 은 움직이지 않음
  // top > left > bottom > right
  int temp = dice.LEFT;
  dice.LEFT = dice.TOP;
  dice.TOP = dice.RIGHT;
  dice.RIGHT = dice.BOTTOM;
  dice.BOTTOM = temp;
}

void move_up() {
  // LEFT, RIGHT 는 움직이지 않음
  // top > back > bottom > front
  int temp = dice.TOP;
  dice.TOP = dice.FRONT;
  dice.FRONT = dice.BOTTOM;
  dice.BOTTOM = dice.BACK;
  dice.BACK = temp;
}

void move_down() {
  // LEFT, RIGHT 는 움직이지 않음
  // top > front > bottom > back
  int temp = dice.TOP;
  dice.TOP = dice.BACK;
  dice.BACK = dice.BOTTOM;
  dice.BOTTOM = dice.FRONT;
  dice.FRONT = temp;
}

bool limitCheck(axis cur, axis limit) {
  if (cur.x < 0 || cur.x >= limit.x) return false;
  if (cur.y < 0 || cur.y >= limit.y) return false;

  return true;
}

void printDice() {
  cout << dice.TOP << " " << dice.BOTTOM << " ";
  cout << dice.LEFT << " " << dice.RIGHT << " ";
  cout << dice.FRONT << " " << dice.BACK << "\n";
}

void solution() {
  int N, M, K;
  axis dice_axis, limit;
  vector<int> answers;

  cin >> N >> M >> dice_axis.y >> dice_axis.x >> K;

  limit.y = N;
  limit.x = M;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      cin >> map[y][x];
    }
  }

  int dir;
  for (int c = 0; c < K; c++) {
    cin >> dir;
    axis cur = dice_axis;
    cur.x += dirs[dir].x;
    cur.y += dirs[dir].y;

    if (!limitCheck(cur, limit)) {
      continue;
    }
    dice_axis = cur;

    switch (dir) {
      case 1: {
        move_right();
        break;
      }
      case 2: {
        move_left();
        break;
      }
      case 3: {
        move_up();
        break;
      }
      case 4: {
        move_down();
        break;
      }
    }

    if (map[cur.y][cur.x] == 0) {
      map[cur.y][cur.x] = dice.BOTTOM;
    } else {
      dice.BOTTOM = map[cur.y][cur.x];
      map[cur.y][cur.x] = 0;
    }

    answers.push_back(dice.TOP);
  }

  for (int answer : answers) {
    cout << answer << "\n";
  }
  cout << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}