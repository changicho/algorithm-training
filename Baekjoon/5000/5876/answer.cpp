#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

Axis dirs[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int answer = 0;

bool visited[5][5] = {false};
vector<string> board;

void recursive(Axis axis, int open, int closed) {
  int size = board.size();

  visited[axis.y][axis.x] = true;

  if (open == closed) {
    answer = max(answer, open + closed);
    visited[axis.y][axis.x] = false;
    return;
  }

  char cur = board[axis.y][axis.x];

  // check open
  if (closed == 0 && cur == '(') {
    for (Axis &dir : dirs) {
      Axis next = {axis.y + dir.y, axis.x + dir.x};
      if (next.y < 0 || next.y >= size || next.x < 0 || next.x >= size)
        continue;
      if (visited[next.y][next.x]) continue;
      if (board[next.y][next.x] == ')') continue;

      recursive(next, open + 1, closed);
    }
  }

  // check closed
  for (Axis &dir : dirs) {
    Axis next = {axis.y + dir.y, axis.x + dir.x};
    if (next.y < 0 || next.y >= size || next.x < 0 || next.x >= size) continue;
    if (visited[next.y][next.x]) continue;
    if (board[next.y][next.x] == '(') continue;

    recursive(next, open, closed + 1);
  }

  visited[axis.y][axis.x] = false;
}

int solution() {
  int size = board.size();
  if (board[0][0] == ')') return 0;
  recursive({0, 0}, 1, 0);

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("input.txt", "r", stdin);

  int N;
  cin >> N;
  board.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> board[i];
  }

  int answer = solution();

  cout << answer << endl;
  return 0;
}