# 1197. Minimum Knight Moves

[링크](https://leetcode.com/problems/minimum-knight-moves/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 좌표를 각각 Y, X라 하자. 이 중 최대값을 N이라 하자. (Y + X <= 300)

이차원 좌표에서 최소 이동 횟수를 구해야 하므로 BFS를 이용한다.

이 때 중복된 경우와 범위를 벗어나는 경우는 더이상 탐색하지 않도록 백트래킹을 사용한다.

이 경우 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

좌표를 저장할 공간이 필요하므로 O(N^2)의 공간 복잡도를 사용한다.

### BFS with memoization

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     121      |   O(N^2)    |   O(N^2)    |

최소 이동 횟수를 구해야 하므로 단계별 BFS를 수행한다.

이 때 이미 방문한 좌표는 더이상 탐색하지 않기 위해 visited 배열을 사용한다.

시작 좌표는 0,0 이므로 좌표가 음수가 될 수도 있어 visited 배열의 index를 300씩 이동시켜 사용한다.

이후 BFS 탐색을 진행하며 원하는 좌표에 도달한 경우 탐색을 중지하고 이동 단계를 반환한다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[8] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

int minKnightMoves(int x, int y) {
  const int HALF = 302;
  bool visited[604][604] = {false};
  visited[0 + HALF][0 + HALF] = true;

  queue<Axis> q;
  q.push({0, 0});

  int step = 0;
  while (!q.empty()) {
    int size = q.size();
    while (size--) {
      Axis cur = q.front();
      q.pop();

      if (abs(cur.y) + abs(cur.x) > 300) continue;
      if (cur.y == y && cur.x == x) return step;

      for (Axis &dir : dirs) {
        Axis next = {cur.y + dir.y, cur.x + dir.x};

        if (visited[next.y + HALF][next.x + HALF]) continue;
        visited[next.y + HALF][next.x + HALF] = true;
        q.push(next);
      }
    }
    step++;
  }

  return -1;
}
```

## 고생한 점
