#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define MAX 16

using namespace std;

struct axis {
  int y, x;
};

axis moves[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool isSafe(axis current) {
  if (current.x < 0 || current.x >= MAX || current.y < 0 || current.y >= MAX) {
    return false;
  }
  return true;
}

void solution(int test_case) {
  cin >> test_case;

  bool answer = 0;
  string line;
  int map[MAX][MAX];
  queue<axis> q;

  for (int y = 0; y < MAX; y++) {
    cin >> line;
    for (int x = 0; x < MAX; x++) {
      map[y][x] = line[x] - '0';
      if (map[y][x] == 2) {
        q.push(axis{y, x});
      }
    }
  }

  while (!q.empty() && answer == 0) {
    axis current = q.front();
    q.pop();

    map[current.y][current.x] = 1;

    for (int direction = 0; direction < 4; direction++) {
      axis next = current;

      next.x += moves[direction].x;
      next.y += moves[direction].y;

      if (!isSafe(next)) {
        continue;
      }
      if (map[next.y][next.x] == 0) {
        q.push(next);
      }
      if (map[next.y][next.x] == 3) {
        answer = 1;
        break;
      }
    }
  }

  cout << "#" << test_case << " " << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T = 10;

  for (int test_case = 1; test_case <= T; test_case++) {
    solution(test_case);
  }

  return 0;
}