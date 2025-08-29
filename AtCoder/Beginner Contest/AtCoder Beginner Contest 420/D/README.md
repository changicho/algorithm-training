# D - Toggle Maze

[링크](https://atcoder.jp/contests/abc420/tasks/abc420_d)

| 난이도 |
| :----: |
|  400   |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

스위치의 상태에 따라 중복방문을 제거한 BFS를 수행할 경우 O(R \* C) 의 시간 복잡도를 가진다.

### 공간 복잡도

중복방문을 제거하기 위해 2차원 배열을 2개 사용하므로 O(R \* C) 의 공간 복잡도를 가진다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      30      |  O(R \* C)  |  O(R \* C)  |

스위치가 켜진 상태와 켜지지 않은 상태 2가지가 존재한다.

시작점부터 BFS를 수행하며 현재 스위치의 상태에 따라 BFS를 수행한다.

이 때 스위치를 만나는 경우 스위치의 상태가 변화함에 유의한다.

이 과정에서 중복방문과 불가능한 경우를 제거한 뒤 모든 탐색을 수행한다.

이후 도착점에 도달한 최소 이동 횟수를 구한다.

```cpp
struct Axis {
  int y, x;

  Axis operator+(const Axis &a) const { return {y + a.y, x + a.x}; }
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct Status {
  Axis a;
  bool isOn = false;
  int step = 0;
};

auto solution(int rows, int cols, vector<string> &board) {
  // . : Empty cell.
  // # : Obstacle cell.
  // S : Start cell.
  // G : Goal cell.
  // o : Open door cell.
  // x : Closed door cell.
  // ? : Switch cell.

  Axis start, goal;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[y][x] == 'S') {
        start = {y, x};
      } else if (board[y][x] == 'G') {
        goal = {y, x};
      }
    }
  }

  // 0: off, 1: on
  vector<vector<vector<int>>> visited(2, vector<vector<int>>(rows, vector<int>(cols, INT_MAX)));

  queue<Status> q;
  q.push({start, false, 0});
  visited[0][start.y][start.x] = 0;

  while (!q.empty()) {
    Status s = q.front();
    q.pop();
    visited[s.isOn][s.a.y][s.a.x] = s.step;

    for (Axis &dir : dirs) {
      Axis next = s.a + dir;
      bool nextIsOn = s.isOn;

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols) {
        continue;
      }

      char cur = board[next.y][next.x];
      if (cur == '#') {
        continue;
      }
      if (cur == 'x' && !s.isOn || cur == 'o' && s.isOn) {
        continue;
      }
      if (cur == '?') {
        nextIsOn = !s.isOn;
      }
      if (visited[nextIsOn][next.y][next.x] != INT_MAX) {
        continue;
      }
      visited[nextIsOn][next.y][next.x] = s.step + 1;

      q.push({next, nextIsOn, s.step + 1});
    }
  }

  int answer = min(visited[0][goal.y][goal.x], visited[1][goal.y][goal.x]);
  if (answer == INT_MAX) {
    answer = -1;
  }
  return answer;
}
```

## 고생한 점
