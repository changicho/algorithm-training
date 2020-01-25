#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

#define MAX_SIZE 15

using namespace std;

int board[MAX_SIZE][MAX_SIZE];
int N, answer = 0;

struct axis {
  int y, x;
};

axis moves[4] = {{1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

bool is_safe(axis current) {
  if (current.x < 0 || current.x >= N || current.y < 0 || current.y >= N)
    return false;
  return true;
}

bool can_locate(int y, int x) {
  for (int i = 0; i < N; i++) {
    if (board[i][x] != 0) return false;
  }

  for (int dir = 0; dir < 4; dir++) {
    axis current = {y, x};

    for (int i = 0; i < N; i++) {
      current.y += moves[dir].y;
      current.x += moves[dir].x;

      if (!is_safe(current)) break;
      if (board[current.y][current.x] != 0) return false;
    }
  }

  return true;
}

void dfs(int y, int x) {
  if (y == N) {
    answer++;
  } else {
    for (int x = 0; x < N; x++) {
      if (board[y][x] == 0 && can_locate(y, x)) {
        board[y][x] = 1;
        dfs(y + 1, x);
        board[y][x] = 0;
      }
    }
  }
}

void solution() {
  cin >> N;

  dfs(0, 0);

  cout << answer << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}