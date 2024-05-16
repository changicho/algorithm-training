#include <algorithm>
#include <cmath>
#include <functional>
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

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int solution(int rows, int cols, vector<string> &board) {
  function<int(Axis)> convert = [&](Axis a) -> int { return a.y * cols + a.x; };
  vector<vector<int>> visited(rows, vector<int>(cols, -1));

  // find destination point (cannot move)
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[y][x] == '#') continue;

      for (Axis &dir : dirs) {
        int ny = y + dir.y;
        int nx = x + dir.x;

        if (ny < 0 || ny >= rows || nx < 0 || nx >= cols) continue;
        if (board[ny][nx] == '#') {
          board[y][x] = '-';
        }
      }
    }
  }

  function<int(Axis)> go = [&](Axis start) -> int {
    int count = 0;
    queue<Axis> q;

    q.push(start);
    visited[start.y][start.x] = convert(start);

    while (!q.empty()) {
      Axis cur = q.front();
      q.pop();

      count++;
      if (board[cur.y][cur.x] == '-') continue;

      for (Axis &dir : dirs) {
        Axis next = {cur.y + dir.y, cur.x + dir.x};

        if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
          continue;
        if (visited[next.y][next.x] == convert(start)) continue;

        visited[next.y][next.x] = convert(start);
        q.push(next);
      }
    }

    return count;
  };

  int answer = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (visited[y][x] != -1) continue;
      if (board[y][x] == '#') continue;
      int count = go({y, x});

      answer = max(answer, count);
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

  vector<string> S(H);
  for (int i = 0; i < H; i++) {
    cin >> S[i];
  }

  int answer = solution(H, W, S);

  cout << answer << endl;

  return 0;
}