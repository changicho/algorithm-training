#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct axis {
  int y, x;
};

axis dir[4] = {{-1, 0}, {0, +1}, {+1, 0}, {0, -1}};

int map[12][6];
bool visited[12][6];

bool check(int y, int x) {
  if (visited[y][x]) {
    false;
  }

  int pattern = map[y][x];
  if (pattern == 0) {
    return false;
  }
  int count = 1;

  queue<axis> q;
  q.push({y, x});
  visited[y][x] = true;

  while (!q.empty()) {
    if (count >= 4) {
      break;
    }

    axis cur = q.front();
    q.pop();

    for (axis d : dir) {
      axis next = cur;
      next.y += d.y;
      next.x += d.x;

      if (next.y < 0 || next.y >= 12 || next.x < 0 || next.x >= 6) {
        continue;
      }

      if (map[next.y][next.x] == pattern && !visited[next.y][next.x]) {
        q.push(next);
        count += 1;
        visited[next.y][next.x] = true;
      }
    }
  }

  if (count >= 4) {
    return true;
  }
  return false;
}

void boom(int y, int x) {
  int pattern = map[y][x];
  if (pattern == -1) {
    return;
  }

  map[y][x] = -1;

  queue<axis> q;
  q.push({y, x});

  while (!q.empty()) {
    axis cur = q.front();
    q.pop();

    for (axis d : dir) {
      axis next = cur;
      next.y += d.y;
      next.x += d.x;

      if (next.y < 0 || next.y >= 12 || next.x < 0 || next.x >= 6) {
        continue;
      }

      if (map[next.y][next.x] == pattern && map[next.y][next.x] != -1) {
        q.push(next);
        map[next.y][next.x] = -1;
      }
    }
  }
}

void pull() {
  for (int x = 0; x < 6; x++) {
    int y = 11;

    while (y >= 0) {
      if (map[y][x] == -1) {
        for (int j = y; j >= 1; j -= 1) {
          map[j][x] = map[j - 1][x];
        }
        map[0][x] = 0;
      } else {
        y -= 1;
      }
    }
  }
}

void print() {
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 6; j++) {
      cout << map[i][j];
    }
    cout << endl;
  }
}

void solution() {
  int answer = 0;

  for (int y = 0; y < 12; y++) {
    string line;
    cin >> line;
    for (int x = 0; x < 6; x++) {
      if (line[x] == '.') {
        map[y][x] = 0;
      } else {
        map[y][x] = line[x];
      }
    }
  }

  while (true) {
    bool flag = true;
    vector<axis> booms;
    memset(visited, false, sizeof(visited));

    for (int y = 0; y < 12; y++) {
      for (int x = 0; x < 6; x++) {
        if (check(y, x)) {
          booms.push_back({y, x});
          flag = false;
        }
      }
    }

    for (axis a : booms) {
      boom(a.y, a.x);
    }
    pull();
    if (flag) {
      break;
    }
    answer += 1;
  }

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}