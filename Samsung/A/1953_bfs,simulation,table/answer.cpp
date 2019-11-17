#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int map[51][51];
bool visited[51][51];
int N, M, R, C, L;
int answer = 0;

struct axis {
  int x, y;
  int time;
};

// time 만들어줘야함
axis moves[4] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
// 각 파이프 별로 이동 가능한 경우 표시 (상, 우, 하, 좌)
// index의 간편화를 위해 처음엔 빈걸 넣어줌
bool canGo[8][4] = {{0, 0, 0, 0}, {1, 1, 1, 1}, {1, 0, 1, 0}, {0, 1, 0, 1},
                    {1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 1}, {1, 0, 0, 1}};

bool canEnter[8][4] = {{0, 0, 0, 0}, {1, 1, 1, 1}, {1, 0, 1, 0}, {0, 1, 0, 1},
                       {0, 0, 1, 1}, {1, 0, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 0}};

void clear() {
  answer = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      map[i][j] = 0;
      visited[i][j] = 0;
    }
  }
}

void solution(int test_case) {
  clear();
  queue<axis> q;
  cin >> N >> M >> R >> C >> L;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> map[i][j];
    }
  }

  q.push(axis{C, R, 1});
  visited[R][C] = true;

  while (!q.empty()) {
    axis current = q.front();
    q.pop();
    if (current.time == L) {
      break;
    }

    int current_pipe = map[current.y][current.x];

    for (int i = 0; i < 4; i++) {
      axis next;
      next.x = current.x + moves[i].x;
      next.y = current.y + moves[i].y;
      next.time = current.time + 1;
      int next_pipe = map[next.y][next.x];
      if (canGo[current_pipe][i] && !visited[next.y][next.x] &&
          map[next.y][next.x] != 0 && canEnter[next_pipe][i]) {
        // 이동시킴
        visited[next.y][next.x] = 1;
        q.push(next);
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (visited[i][j]) {
        answer++;
      }
    }
  }

  cout << "#" << test_case << " " << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  for (int test_case = 1; test_case <= T; test_case++) {
    solution(test_case);
  }

  return 0;
}