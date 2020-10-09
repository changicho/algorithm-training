# 1012. 유기농 배추

[링크](https://www.acmicpc.net/problem/1012)

|  난이도   | 정답률(\_%) |
| :-------: | :---------: |
| Silver II |   35.143    |

## 설계

### 시간 복잡도

최대 50^2 사이즈의 배추밭을 전부 순회하며 배추인경우 연결 배추또한 탐색해야 한다.

배추밭을 탐색하는데 최종으로 들어가는 시간 복잡도는 50^2 이므로 시간복잡도는

```cpp
50^2 + 50^2 = 5,000
```

이므로 제한시간 내에 충분하다

### 공간 복잡도

배추밭에서 배추가 있거나 없는 두가지 경우만 나타내면 되므로 boolean 형식으로 선언한다.

또한 정답의 수는 최악의 경우라도 2,500 이내이므로 int형으로 선언한다.

### 너비 우선 탐색

현재 방문한 곳이 배추이며, 이전에 방문하지 않았을 경우 너비우선탐색을 통해 탐색을 이어나간다.

```cpp
for (int y = 0; y < N; y++) {
  for (int x = 0; x < M; x++) {
    if (!board[y][x] || visited[y][x]) continue;

    answer += 1;
    queue<Axis> q;

    q.push({y, x});

    while (!q.empty()) {
      Axis cur = q.front();
      q.pop();

      if (visited[cur.y][cur.x]) continue;
      visited[cur.y][cur.x] = true;

      for (Axis dir : dirs) {
        Axis next = cur;
        next.y += dir.y;
        next.x += dir.x;

        if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= M) continue;
        if (!board[next.y][next.x]) continue;

        q.push(next);
      }
    }
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
