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
bool board[5][5];
int answer = 0;

bool isLinked(vector<Axis> choose) {
  bool checked[5][5] = {
      false,
  };
  bool visited[5][5] = {
      false,
  };
  int visited_count = 0;

  for (Axis cur : choose) {
    checked[cur.y][cur.x] = true;
  }

  queue<Axis> q;
  q.push(choose.front());

  while (!q.empty()) {
    Axis cur = q.front();
    q.pop();

    if (visited[cur.y][cur.x]) continue;
    visited_count += 1;
    visited[cur.y][cur.x] = true;

    for (Axis dir : dirs) {
      Axis next = cur;
      next.x += dir.x;
      next.y += dir.y;
      if (0 > next.x || 5 <= next.x || 0 > next.y || 5 <= next.y) continue;
      if (!checked[next.y][next.x]) continue;

      q.push(next);
    }
  }

  if (visited_count == 7) return true;
  return false;
}

void dfs(int index, vector<Axis> choose, int enemy) {
  if (enemy > 3) return;
  if (choose.size() == 7) {
    if (isLinked(choose)) {
      answer += 1;
    }
    return;
  }
  if (index == 25) return;

  Axis cur = {index / 5, index % 5};
  index += 1;

  dfs(index, choose, enemy);
  choose.push_back(cur);
  dfs(index, choose, board[cur.y][cur.x] ? enemy : enemy + 1);
}

void solution() {
  string line;

  for (int y = 0; y < 5; y++) {
    cin >> line;
    for (int x = 0; x < 5; x++) {
      board[y][x] = line[x] == 'S' ? true : false;
    }
  }

  vector<Axis> choose;
  dfs(0, choose, 0);

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}