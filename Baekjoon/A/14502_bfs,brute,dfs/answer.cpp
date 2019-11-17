#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct axis {
  int y, x;
};

axis moves[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int N, M;
int map[8][8];
int answer = 0;

vector<axis> bacterias;
queue<axis> q;

void print(int current_map[][8]) {
  cout << "\n### print map ###\n";
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      cout << current_map[y][x];
    }
    cout << "\n";
  }
}

int bacteriaExpend() {
  int temp_map[8][8], count = 0;
  queue<axis> q;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      temp_map[y][x] = map[y][x];
    }
  }

  for (axis a : bacterias) {
    q.push(a);
  }

  while (!q.empty()) {
    axis current = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      axis next = current;
      next.x += moves[i].x;
      next.y += moves[i].y;

      // 범위가 넘쳤으면 이동하지 않음
      if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= M) {
        continue;
      }
      // 빈 공간이 아니면 증식 안함
      if (temp_map[next.y][next.x] == 0) {
        temp_map[next.y][next.x] = 2;
        q.push(next);
      }
    }
  }

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      if (temp_map[y][x] == 0) {
        count++;
      }
    }
  }

  return count;
}

void dfs(int depth, int start_y, int start_x) {
  if (depth == 3) {
    int temp = answer;
    answer = max(bacteriaExpend(), answer);
    return;
  }

  // 진행 중이던 상황부터 진행
  for (int x = start_x; x < M; x++) {
    // 같은 y인덱스를 가진 것 탐색
    // 비어있어야 기둥을 놓을 수 있음
    if (map[start_y][x] == 0) {
      map[start_y][x] = 3;
      dfs(depth + 1, start_y, x);
      map[start_y][x] = 0;
    }
  }

  // y번째 일 때 탐색 완료했으므로 y+1부터
  for (int y = start_y + 1; y < N; y++) {
    for (int x = 0; x < M; x++) {
      // 비어있어야 기둥을 놓을 수 있음
      if (map[y][x] == 0) {
        map[y][x] = 3;
        dfs(depth + 1, y, x);
        map[y][x] = 0;
      }
    }
  }

  return;
}

void solution() {
  cin >> N >> M;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      cin >> map[y][x];
      if (map[y][x] == 2) {
        bacterias.push_back(axis{y, x});
      }
    }
  }

  dfs(0, 0, 0);
  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}