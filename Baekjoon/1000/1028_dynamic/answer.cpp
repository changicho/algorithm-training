#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define LIMIT 751

using namespace std;

struct Axis {
  int y, x;
};

string board[LIMIT];
int leftDown[LIMIT][LIMIT];
int rightDown[LIMIT][LIMIT];
Axis limit;

bool isFine(int y, int x) {
  return !(y < 0 || y >= limit.y || x < 0 || x >= limit.x);
}

void solution() {
  int R, C;
  int answer = 0;
  cin >> R >> C;

  limit = {R, C};

  for (int y = 0; y < R; y++) {
    cin >> board[y];
  }

  for (int y = limit.y - 1; y >= 0; y--) {
    for (int x = 0; x < limit.x; x++) {
      if (board[y][x] == '1') {
        leftDown[y][x] = isFine(y + 1, x - 1) ? leftDown[y + 1][x - 1] + 1 : 1;
        rightDown[y][x] = isFine(y + 1, x + 1) ? rightDown[y + 1][x + 1] + 1 : 1;
      }
    }
  }

  for (int y = 0; y < limit.y; y++) {
    for (int x = 0; x < limit.x; x++) {
      int startLength = min(leftDown[y][x], rightDown[y][x]);

      for (int length = startLength; length > answer; length--) {
        int leftDownLength = isFine(y + (length - 1), x + (length - 1)) ? leftDown[y + (length - 1)][x + (length - 1)] : 0;
        int rightDownLength = isFine(y + (length - 1), x - (length - 1)) ? rightDown[y + (length - 1)][x - (length - 1)] : 0;

        if (leftDownLength >= length && rightDownLength >= length) {
          answer = max(answer, length);
          break;
        }
      }
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