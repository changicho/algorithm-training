#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int map[51][51];
int N, M;
int answer = 1;

bool isSame(int y, int x, int length) {
  if (map[y][x] != map[y + length - 1][x]) return false;
  if (map[y][x] != map[y][x + length - 1]) return false;
  if (map[y][x] != map[y + length - 1][x + length - 1]) return false;

  return true;
}

void check(int length) {
  for (int y = 0; y < N - length + 1; y++) {
    for (int x = 0; x < M - length + 1; x++) {
      if (isSame(y, x, length)) {
        int newAnswer = (length) * (length);
        answer = max(newAnswer, answer);
        return;
      }
    }
  }
}

void solution() {
  cin >> N >> M;

  string line;

  for (int y = 0; y < N; y++) {
    cin >> line;

    for (int x = 0; x < M; x++) {
      map[y][x] = line[x] - '0';
    }
  }

  for (int length = min(N, M); length > 0; length -= 1) {
    check(length);
    if (answer != 1) {
      break;
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