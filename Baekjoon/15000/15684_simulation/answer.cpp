#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, H, M;
int answer = 4;
int board[31][11];

int goDown(int start) {
  int cur = start;
  for (int h = 1; h <= H; h++) {
    if (board[h][cur] != 0) {
      cur = board[h][cur];
    }
  }
  return cur;
}

bool isFine() {
  for (int x = 1; x <= N; x++) {
    if (goDown(x) != x) return false;
  }
  return true;
}

void recursive(int y, int x, int count) {
  if (count > 3) return;
  if (count >= answer) return;

  if (isFine()) {
    answer = min(count, answer);
  }

  for (int i = y; i <= H; i++, x = 1) {
    for (int j = x; j < N; j++) {
      if (board[i][j] != 0 || board[i][j + 1] != 0) {
        continue;
      }

      board[i][j] = j + 1;
      board[i][j + 1] = j;
      recursive(i, j, count + 1);
      board[i][j] = 0;
      board[i][j + 1] = 0;
    }
  }
}

void solution() {
  cin >> N >> M >> H;

  if (M == 0) {
    cout << "0\n";
    return;
  }

  for (int i = 0; i < M; i++) {
    int h, n;
    cin >> h >> n;

    board[h][n] = n + 1;
    board[h][n + 1] = n;
  }

  recursive(1, 1, 0);

  if (answer == 4) answer = -1;
  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}