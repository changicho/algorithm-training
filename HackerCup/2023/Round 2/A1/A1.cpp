#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
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
};

Axis dirs[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool hasCaptured(vector<vector<char>> &board, int y, int x) {
  int rows = board.size(), cols = board[0].size();

  queue<Axis> q;

  q.push({y, x});

  unordered_map<char, int> border;

  bool visited[21][21] = {false};
  bool borderCheck[21][21] = {false};
  visited[y][x] = true;

  while (!q.empty()) {
    Axis cur = q.front();
    q.pop();

    for (Axis &dir : dirs) {
      Axis next = {cur.y + dir.y, cur.x + dir.x};

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      if (visited[next.y][next.x]) continue;

      if (!borderCheck[next.y][next.x]) {
        borderCheck[next.y][next.x] = true;
        border[board[next.y][next.x]]++;
      }

      if (board[next.y][next.x] != 'W') continue;
      visited[next.y][next.x] = true;

      q.push(next);
    }
  }

  return border['.'] <= 1;
}

bool solution(vector<vector<char>> &board) {
  int rows = board.size(), cols = board[0].size();

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[y][x] != 'W') continue;

      bool isPossible = hasCaptured(board, y, x);
      if (isPossible) return true;
    }
  }

  return false;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);
  freopen("./ready_go_part_1_input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int R, C;
    cin >> R >> C;

    vector<vector<char>> board(R, vector<char>(C));

    for (int y = 0; y < R; y++) {
      for (int x = 0; x < C; x++) {
        cin >> board[y][x];
      }
    }
    auto answer = solution(board);

    cout << "Case #" << testCase << ": ";
    cout << (answer ? "YES" : "NO") << "\n";
  }

  return 0;
}