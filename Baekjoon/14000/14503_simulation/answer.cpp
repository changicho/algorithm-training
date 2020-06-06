#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

struct Robot {
  int dir;
  Axis axis;
};

// 왼쪽 방향을 바라봐야 하므로 CCL 방향임에 유의
Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
Axis limit;
Robot robot;

bool wall[50][50];
bool visited[50][50];

void solution() {
  int answer = 0;

  cin >> limit.y >> limit.x;
  cin >> robot.axis.y >> robot.axis.x >> robot.dir;

  for (int y = 0; y < limit.y; y++) {
    for (int x = 0; x < limit.x; x++) {
      cin >> wall[y][x];
    }
  }

  int turnCount = 0;
  while (true) {
    // 청소
    if (!visited[robot.axis.y][robot.axis.x]) {
      visited[robot.axis.y][robot.axis.x] = 1;
      answer += 1;
    }

    // 판별
    Axis left = robot.axis;
    left.y += dirs[(4 + robot.dir - 1) % 4].y;
    left.x += dirs[(4 + robot.dir - 1) % 4].x;

    // 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음
    // 한 칸을 전진하고 1번부터 진행한다.
    if (!visited[left.y][left.x] && !wall[left.y][left.x]) {
      robot.dir = (4 + robot.dir - 1) % 4;
      turnCount = 0;
      robot.axis = left;
      continue;
    }

    // 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
    if ((visited[left.y][left.x] || wall[left.y][left.x]) && turnCount < 4) {
      robot.dir = (4 + robot.dir - 1) % 4;
      turnCount += 1;

      continue;
    }

    if (turnCount == 4) {
      Axis back = robot.axis;
      back.y += dirs[(robot.dir + 2) % 4].y;
      back.x += dirs[(robot.dir + 2) % 4].x;

      // 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도
      // 할 수 없는 경우에는 작동을 멈춘다.
      if (wall[back.y][back.x]) {
        break;
      }

      // 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을
      // 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
      turnCount = 0;
      robot.axis = back;

      continue;
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