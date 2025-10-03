# D - Ulam-Warburton Automaton

[링크](https://atcoder.jp/contests/abc425/tasks/abc425_d)

| 난이도 |
| :----: |
|  425   |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

BFS를 이용해 가능한 경우만 탐색하는데 O(R \* C)의 시간 복잡도를 사용한다.

이 때 직접 매번 다음번 색칠할 board를 만들경우 각 단계마다 O(R \* C)의 시간 복잡도가 추가로 사용해 제한시간 내에 불가능하다.

각 좌표마다 인접한 검은색 좌표를 세는 배열을 만들어 관리할 경우 각 단계마다 O(1)의 시간 복잡도로 다음번 색칠할 좌표를 찾을 수 있다.

### 공간 복잡도

BFS를 위한 큐와 방문 배열을 이용하는데 O(R \* C)의 공간 복잡도를 사용한다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      20      |  O(R \* C)  |  O(R \* C)  |

단계별 BFS를 수행하며 검은 좌표를 큐에 넣는다.

각 좌표마다 인접한 검은 좌표의 갯수를 세는 배열을 만들어 관리한다.

이 때 현재 검은색 좌표에서 인접한 좌표들에 검은 색의 수를 증가시키며, 현재 단계에서 방문한 검은 좌표들의 인접 좌표들 중, 검은 좌표가 1개인 좌표들만 큐에 넣어 다음 단계에서 탐색한다.

이를 큐가 빌 때까지 반복하며 이후 검은 좌표의 갯수를 센다.

```cpp
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
```

## 고생한 점
