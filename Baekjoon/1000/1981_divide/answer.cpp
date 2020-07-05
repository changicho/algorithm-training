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

int N;
int map[101][101];
Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool visited[101][101];

bool canVisit(int from, int to) {
  if (map[0][0] < from || map[0][0] > to) return false;

  memset(visited, false, sizeof(visited));
  queue<Axis> q;
  q.push({0, 0});

  while (!q.empty()) {
    Axis cur = q.front();
    q.pop();

    if (cur.y == N - 1 && cur.x == N - 1) {
      return true;
    }

    if (visited[cur.y][cur.x]) continue;
    visited[cur.y][cur.x] = true;

    for (Axis dir : dirs) {
      Axis next = cur;
      next.y += dir.y;
      next.x += dir.x;

      if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= N) continue;
      if (map[next.y][next.x] < from || map[next.y][next.x] > to) continue;

      q.push(next);
    }
  }

  return false;
}

void solution() {
  int answer = 201;
  int start, end, mid;

  cin >> N;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      cin >> map[y][x];
    }
  }

  start = 0;
  end = 0;
  while (start < 201) {
    bool isPossible = canVisit(start, end);
    if (isPossible) {
      answer = min(answer, end - start);
      start++;
    } else if (end < 201) {
      end++;
    } else {
      break;
    }
  }

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./data/input.txt", "r", stdin);
  solution();

  return 0;
}