#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

bool isSafe(Axis cur) {
  if (cur.x < 0 || cur.x > 10 || cur.y < 0 || cur.y > 10) return false;
  return true;
}

int solution(string dirs) {
  int answer = 0;

  bool map[11][11][11][11] = {
      false,
  };

  Axis cur = {5, 5};

  for (char dir : dirs) {
    Axis next = cur;

    switch (dir) {
      case 'U': {
        next.y -= 1;
        break;
      }
      case 'D': {
        next.y += 1;
        break;
      }
      case 'L': {
        next.x -= 1;
        break;
      }
      case 'R': {
        next.x += 1;
        break;
      }
    }

    if (isSafe(next)) {
      if (!map[cur.y][cur.x][next.y][next.x] &&
          !map[next.y][next.x][cur.y][cur.x])
        answer += 1;
      map[cur.y][cur.x][next.y][next.x] = true;
      map[next.y][next.x][cur.y][cur.x] = true;
      cur = next;
    }
  }

  return answer;
}

struct TestCase {
  string dirs;
  int answer;
};

int main() {
  vector<TestCase> tcs = {{"ULURRDLLU", 7}, {"LULLLLLLU", 7}

  };

  for (TestCase tc : tcs) {
    int answer = solution(tc.dirs);

    cout << "answer : " << tc.answer << ", myAnswer : " << answer << "\n";
  }

  return 0;
}