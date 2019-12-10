#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int directions[2] = {-1, +1};
struct axis {
  int y, x;
};

void solution(int test_case) {
  bool map[100][100];
  axis start = {98, 0};

  cin >> test_case;

  for (int y = 0; y < 99; y += 1) {
    for (int x = 0; x < 100; x += 1) {
      cin >> map[y][x];
    }
  }
  for (int x = 0; x < 100; x += 1) {
    int temp;
    cin >> temp;
    if (temp == 2) {
      start.x = x;
    }
  }

  while (start.y != 0) {
    for (int dir : directions) {
      if (start.x + dir < 0 || start.x + dir >= 100) {
        continue;
      }
      if (map[start.y][start.x + dir]) {
        int next_x = start.x;
        while (map[start.y][next_x + dir]) {
          next_x += dir;
          if (next_x == 0 || next_x == 99) {
            break;
          }
        }

        start.x = next_x;
        break;
      }
    }
    start.y -= 1;
  }

  cout << "#" << test_case << " " << start.x << "\n";
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