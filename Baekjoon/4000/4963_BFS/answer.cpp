#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

Axis dirs[8] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

bool solution() {
  int W, H;
  bool board[50][50] = {
      false,
  };
  bool visited[50][50] = {
      false,
  };
  int count = 0;

  cin >> W >> H;

  if (W == 0 && H == 0) return false;

  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      cin >> board[y][x];
    }
  }

  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (visited[y][x]) continue;
      if (!board[y][x]) continue;

      queue<Axis> q;
      q.push({y, x});
      count += 1;

      while (!q.empty()) {
        Axis cur = q.front();
        q.pop();

        if (visited[cur.y][cur.x]) continue;
        visited[cur.y][cur.x] = true;

        for (Axis dir : dirs) {
          Axis next = cur;
          next.y += dir.y;
          next.x += dir.x;

          if (next.y < 0 || next.y >= H || next.x < 0 || next.x >= W) continue;
          if (!board[next.y][next.x]) continue;

          q.push(next);
        }
      }
    }
  }

  cout << count << "\n";
  return true;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  bool flag = true;
  while (flag) {
    flag = solution();
  }

  return 0;
}