# 2468. 안전 영역

[링크](https://www.acmicpc.net/problem/2468)

|  난이도  | 정답률(\_%) |
| :------: | :---------: |
| Silver I |   34.626    |

## 설계

### 시간 복잡도

N의 최대 크기는 100이며 수의 범위는 0 ~ 100 이다.

범위를 0부터 100까지 증가시키며 잠기게 하고, 그 때 잠기지 않는 곳들을 count한다고 했을 때 시간 복잡도는

BFS로 잠기지 않는 곳을 count 하는데 100^2 + 100^2 (100^2개의 좌표를 탐색하며, 모든 좌표를 BFS로 탐색할 때도 100^2번이 최종 소요되므로)

따라서 최악의 경우 시간 복잡도는

```cpp
100 * 2 * 100^2 = 2,000,000
```

### 공간 복잡도

수의 범위는 0 ~ 100 이므로 int형으로 충분하다.

### 모든 경우를 탐색

입력받은 수 중에서 최소값 ~ 최대값 사이만 측정하면 된다.

```cpp
for (int level = minimum; level <= maximum; level++) {
  bool visited[100][100] = {
      false,
  };
  int count = 0;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      visited[y][x] = board[y][x] >= level ? 0 : 1;
    }
  }

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      if (visited[y][x]) continue;
      count += 1;

      queue<Axis> q;
      q.push({y, x});

      while (!q.empty()) {
        Axis cur = q.front();
        q.pop();

        if (visited[cur.y][cur.x]) continue;
        visited[cur.y][cur.x] = true;

        for (Axis dir : dirs) {
          Axis next = cur;
          next.x += dir.x;
          next.y += dir.y;

          if (next.x < 0 || next.x >= N || next.y < 0 || next.y >= N) continue;

          q.push(next);
        }
      }
    }
  }

  answer = max(answer, count);
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      28      |       0        |

## 고생한 점
