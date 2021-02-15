#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool board[1000][1000];
int answers[1000][1000];
bool visited[1000][1000];
int colors[1000][1000];
vector<int> color_counts = {
    0,
};

bool isSafe(Axis cur, int y_limit, int x_limit) {
  return !(cur.y < 0 || cur.y >= y_limit || cur.x < 0 || cur.x >= x_limit);
}

void solution() {
  int N, M;
  cin >> N >> M;

  string line;
  for (int y = 0; y < N; y++) {
    cin >> line;
    for (int x = 0; x < M; x++) {
      board[y][x] = line[x] == '1' ? 1 : 0;
    }
  }

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      if (visited[y][x] || board[y][x]) continue;
      int color = color_counts.size();
      int count = 0;

      queue<Axis> q;
      q.push({y, x});

      while (!q.empty()) {
        Axis cur = q.front();
        q.pop();

        if (!isSafe(cur, N, M)) continue;
        if (visited[cur.y][cur.x] || board[cur.y][cur.x]) continue;

        visited[cur.y][cur.x] = true;
        colors[cur.y][cur.x] = color;
        count += 1;

        for (Axis dir : dirs) {
          Axis next = cur;
          next.y += dir.y;
          next.x += dir.x;

          q.push(next);
        }
      }

      color_counts.push_back(count);
    }
  }

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      if (!board[y][x]) continue;

      Axis cur = {y, x};
      int count = 0;

      set<int> s;

      for (Axis dir : dirs) {
        Axis next = cur;
        next.y += dir.y;
        next.x += dir.x;

        if (!isSafe(next, N, M) | board[next.y][next.x]) continue;
        int color = colors[next.y][next.x];
        if (s.find(color) != s.end()) continue;

        s.insert(color);
        count += color_counts[color];
      }

      count = (count + 1) % 10;
      answers[y][x] = count;
    }
  }

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      cout << answers[y][x];
    }
    cout << "\n";
  }
  cout << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}