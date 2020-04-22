#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// up right down left

struct axis {
  int y, x;
};

axis directions[4] = {{-1, 0}, {0, +1}, {+1, 0}, {0, -1}};
int map[1000][1000];

void solution() {
  int N, target;
  cin >> N >> target;

  int center = N / 2;
  int dir = 3;
  axis current = {center, center};
  axis answer = {center, center};
  map[current.y][current.x] = 1;
  int number = 1;

  while (number != N * N) {
    axis next = current;

    int next_dir = (dir + 1) % 4;
    next.x += directions[next_dir].x;
    next.y += directions[next_dir].y;

    if (map[next.y][next.x] == 0) {
      map[next.y][next.x] = number + 1;
      number += 1;
      current = next;
      dir = (dir + 1) % 4;

      if (number == target) {
        answer.y = next.y + 1;
        answer.x = next.x + 1;
      }
      continue;
    }

    next = current;
    next.x += directions[dir].x;
    next.y += directions[dir].y;

    if (map[next.y][next.x] == 0) {
      map[next.y][next.x] = number + 1;
      number += 1;
      current = next;

      if (number == target) {
        answer.y = next.y + 1;
        answer.x = next.x + 1;
      }
      continue;
    }

    break;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << map[i][j] << " ";
    }
    cout << "\n";
  }

  cout << answer.y << " " << answer.x << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}