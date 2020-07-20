#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

int N;
int answer = 0;
Axis moves[4] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

bool canVisit[10][10];
bool board[10][10];
bool color[10][10];

bool isSafe(Axis axis) {
  return !(axis.x < 0 || axis.x >= N || axis.y < 0 || axis.y >= N);
}

bool canLocate(Axis axis) {
  for (Axis dir : moves) {
    Axis next = axis;

    while (isSafe(next)) {
      if (board[next.y][next.x]) {
        return false;
      }
      next.y += dir.y;
      next.x += dir.x;
    }
  }
  return true;
}

void dfs(Axis axis, int count, bool color_target) {
  if (axis.y == N) {
    answer = max(count, answer);
    return;
  }

  Axis next = axis;
  next.x += 1;
  if (next.x == N) {
    next.x = 0;
    next.y += 1;
  }

  if (canVisit[axis.y][axis.x] && color[axis.y][axis.x] == color_target && canLocate(axis)) {
    board[axis.y][axis.x] = true;
    dfs(next, count + 1, color_target);
    board[axis.y][axis.x] = false;
  }

  dfs(next, count, color_target);
}

void solution() {
  cin >> N;
  int answerT = 0;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      cin >> canVisit[y][x];
      if ((y + x) % 2 == 0) {
        color[y][x] = true;
      }
    }
  }

  dfs({0, 0}, 0, true);
  answerT += answer;
  answer = 0;
  dfs({0, 0}, 0, false);
  answerT += answer;

  cout << answerT << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // freopen("./data/input.txt", "r", stdin);
  solution();

  return 0;
}