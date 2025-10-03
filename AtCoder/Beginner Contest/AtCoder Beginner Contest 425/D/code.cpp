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
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

auto solution(int rows, int cols, vector<string> &board) {
  vector<vector<bool>> visited(rows, vector<bool>(cols, false));
  vector<vector<int>> counts(rows, vector<int>(cols, 0));

  queue<Axis> q;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[y][x] == '#') {
        q.push({y, x});
      }
    }
  }

  while (!q.empty()) {
    int size = q.size();

    vector<Axis> nexts;
    while (size--) {
      Axis cur = q.front();
      q.pop();

      for (auto &dir : dirs) {
        Axis next = {cur.y + dir.y, cur.x + dir.x};

        if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols) {
          continue;
        }
        if (board[next.y][next.x] == '#') {
          continue;
        }

        counts[next.y][next.x]++;

        if (visited[next.y][next.x]) {
          continue;
        }
        visited[next.y][next.x] = true;
        nexts.push_back({next.y, next.x});
      }
    }

    for (auto &next : nexts) {
      if (counts[next.y][next.x] == 1) {
        board[next.y][next.x] = '#';
        q.push(next);
      }
    }
  }

  int answer = 0;
  for (string &line : board) {
    for (char &c : line) {
      if (c == '#') answer++;
    }
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

  auto answer = solution(H, W, board);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}