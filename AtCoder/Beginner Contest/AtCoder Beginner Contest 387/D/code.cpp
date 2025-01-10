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
  int x, y;

  Axis operator+(const Axis &a) const { return {x + a.x, y + a.y}; }
};

struct Status {
  Axis a;
  int dir;
  int step = 0;
};

Axis dirs[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int solution(vector<string> &board, int rows, int cols) {
  vector<vector<vector<int>>> dp(
      rows, vector<vector<int>>(cols, vector<int>(4, INT_MAX)));

  Axis start = {-1, -1}, goal = {-1, -1};

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[y][x] == 'S') {
        start = {x, y};
      } else if (board[y][x] == 'G') {
        goal = {x, y};
      }
    }
  }

  queue<Status> q;
  for (int dir = 0; dir < 4; dir++) {
    q.push({start, dir, 0});
    dp[start.y][start.x][dir] = 0;
  }

  while (!q.empty()) {
    Status cur = q.front();
    q.pop();

    if (cur.a.x == goal.x && cur.a.y == goal.y) {
      dp[cur.a.y][cur.a.x][cur.dir] = cur.step;
      continue;
    }

    vector<int> nextDirs;
    if (cur.dir == 0 || cur.dir == 2) {
      nextDirs = {1, 3};
    } else {
      nextDirs = {0, 2};
    }

    for (int &dir : nextDirs) {
      Axis next = cur.a + dirs[dir];
      if (next.x < 0 || next.x >= cols || next.y < 0 || next.y >= rows)
        continue;
      if (board[next.y][next.x] == '#') continue;

      int nextStep = cur.step + 1;
      if (dp[next.y][next.x][dir] <= nextStep) {
        continue;
      }

      dp[next.y][next.x][dir] = nextStep;
      q.push({next, dir, nextStep});
    }
  }

  int answer = INT_MAX;
  for (int dir = 0; dir < 4; dir++) {
    answer = min(answer, dp[goal.y][goal.x][dir]);
  }
  return answer == INT_MAX ? -1 : answer;
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

  int answer = solution(board, H, W);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}