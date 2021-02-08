#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool compareKeys(int keys, int key) {
  return keys & (1 << key);
}

void solution() {
  vector<Axis> doors['z' - 'a' + 1];
  char board[100 + 2][100 + 2];
  bool visited[100 + 2][100 + 2] = {
      false,
  };
  int H, W;
  int answer = 0;
  string line;

  cin >> H >> W;

  for (int x = 0; x < W + 2; x++) {
    board[0][x] = board[H + 1][x] = '.';
  }
  for (int y = 0; y < H + 2; y++) {
    board[y][0] = board[y][W + 1] = '.';
  }
  for (int y = 1; y <= H; y++) {
    cin >> line;
    for (int x = 1; x <= W; x++) {
      board[y][x] = line[x - 1];

      if ('A' <= board[y][x] && board[y][x] <= 'Z') {
        doors[board[y][x] - 'A'].push_back({y, x});
      }
    }
  }

  string keys_line;
  cin >> keys_line;

  int keys = 0;
  if (keys_line != "0") {
    for (char key : keys_line) {
      keys |= 1 << (key - 'a');

      for (Axis cur : doors[key - 'a']) {
        board[cur.y][cur.x] = '.';
      }
    }
  }

  queue<Axis> q;
  q.push({0, 0});

  while (!q.empty()) {
    Axis cur = q.front();
    q.pop();

    if (cur.y < 0 || cur.y >= H + 2 || cur.x < 0 || cur.x >= W + 2) continue;
    if (visited[cur.y][cur.x]) continue;
    if (board[cur.y][cur.x] == '*') continue;
    if ('A' <= board[cur.y][cur.x] && board[cur.y][cur.x] <= 'Z' && !compareKeys(keys, board[cur.y][cur.x] - 'A')) continue;

    visited[cur.y][cur.x] = true;

    if (board[cur.y][cur.x] == '$') {
      board[cur.y][cur.x] = '.';
      answer += 1;
    }
    if ('a' <= board[cur.y][cur.x] && board[cur.y][cur.x] <= 'z') {
      int key = board[cur.y][cur.x];
      board[cur.y][cur.x] = '.';
      keys |= 1 << (key - 'a');

      memset(visited, false, sizeof(visited));
      for (Axis door : doors[key - 'a']) {
        board[door.y][door.x] = '.';
      }

      while (!q.empty()) {
        q.pop();
      }
      q.push(cur);

      continue;
    }

    for (Axis dir : dirs) {
      Axis next = cur;
      next.y += dir.y;
      next.x += dir.x;

      q.push(next);
    }
  }

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  while (T--) {
    solution();
  }

  return 0;
}