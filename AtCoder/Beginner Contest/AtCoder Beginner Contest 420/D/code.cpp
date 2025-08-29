#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Axis {
  int y, x;

  Axis operator+(const Axis &a) const { return {y + a.y, x + a.x}; }
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct Status {
  Axis a;
  bool isOn = false;
  int step = 0;
};

auto solution(int rows, int cols, vector<string> &board) {
  // . : Empty cell.
  // # : Obstacle cell.
  // S : Start cell.
  // G : Goal cell.
  // o : Open door cell.
  // x : Closed door cell.
  // ? : Switch cell.

  Axis start, goal;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[y][x] == 'S') {
        start = {y, x};
      } else if (board[y][x] == 'G') {
        goal = {y, x};
      }
    }
  }

  // 0: off, 1: on
  vector<vector<vector<int>>> visited(
      2, vector<vector<int>>(rows, vector<int>(cols, INT_MAX)));

  queue<Status> q;
  q.push({start, false, 0});
  visited[0][start.y][start.x] = 0;

  while (!q.empty()) {
    Status s = q.front();
    q.pop();
    visited[s.isOn][s.a.y][s.a.x] = s.step;

    for (Axis &dir : dirs) {
      Axis next = s.a + dir;
      bool nextIsOn = s.isOn;

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols) {
        continue;
      }

      char cur = board[next.y][next.x];
      if (cur == '#') {
        continue;
      }
      if (cur == 'x' && !s.isOn || cur == 'o' && s.isOn) {
        continue;
      }
      if (cur == '?') {
        nextIsOn = !s.isOn;
      }
      if (visited[nextIsOn][next.y][next.x] != INT_MAX) {
        continue;
      }
      visited[nextIsOn][next.y][next.x] = s.step + 1;

      q.push({next, nextIsOn, s.step + 1});
    }
  }

  int answer = min(visited[0][goal.y][goal.x], visited[1][goal.y][goal.x]);
  if (answer == INT_MAX) {
    answer = -1;
  }
  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int H, W;
  cin >> H >> W;

  vector<string> board(H);
  for (int i = 0; i < H; i++) {
    cin >> board[i];
  }

  int answer = solution(H, W, board);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}