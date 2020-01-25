#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#define SONIC 1
#define WATER -2

struct axis {
  int y, x;
};
// WATER : 물
struct axis_type {
  int y, x, type;
};
axis moves[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

// 비어있는 곳은 '.'로 표시되어 있고, 물이 차있는 지역은 '*', 돌은 'X'로
// 표시되어 있다. 비버의 굴은 'D'로, 고슴도치의 위치는 'S'로 나타내어져 있다.

void solution() {
  int R, C, answer = 0;
  int map[50][50] = {
      0,
  };
  string line;
  queue<axis_type> q;
  axis_type sonic, water, goal;

  cin >> R >> C;

  for (int y = 0; y < R; y++) {
    cin >> line;
    for (int x = 0; x < C; x++) {
      switch (line[x]) {
        case 'D':
          goal.y = y;
          goal.x = x;
          map[y][x] = 1;
          break;
        case '*':
          water.y = y;
          water.x = x;
          water.type = WATER;
          q.push(water);
          map[y][x] = 1;
          break;
        case 'S':
          sonic.y = y;
          sonic.x = x;
          sonic.type = 0;
          map[y][x] = 1;
          break;
        case 'X':
          map[y][x] = 1;
          break;
        default:
          break;
      }
    }
  }

  q.push(sonic);

  while (!q.empty()) {
    axis_type current = q.front();
    q.pop();

    for (int dir = 0; dir < 4; dir++) {
      axis_type next = current;
      next.x += moves[dir].x;
      next.y += moves[dir].y;

      if (next.x < 0 || next.x >= C || next.y < 0 || next.y >= R) {
        continue;
      }
      if (next.type == WATER) {
        if (map[next.y][next.x] == 0) {
          map[next.y][next.x] = WATER;
          q.push(next);
        }
      } else {
        if (map[next.y][next.x] == 0) {
          map[next.y][next.x] = next.type + 1;
          next.type++;
          q.push(next);
        } else if (next.y == goal.y && next.x == goal.x) {
          answer = next.type + 1;
          cout << answer << "\n";
          exit(0);
        }
      }
    }
  }

  cout << "KAKTUS\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}