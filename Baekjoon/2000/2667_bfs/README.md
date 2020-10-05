# 2667. 단지번호붙이기

[링크](https://www.acmicpc.net/problem/2667)

|  난이도  | 정답률(\_%) |
| :------: | :---------: |
| Silver I |   38.468    |

## 설계

### 시간 복잡도

N의 최대 값은 25이다. 25^2 번만큼 탐색을 진행하며, 이때 연결되어있는 부분을 전부 탐색해야한다.

탐색할 때 최대 시간 복잡도는 25^2 번에 상하좌우 4번을 비교해야한다.

따라서 최악의 경우 시간 복잡도는

```cpp
25^2 * (25^2 * 4) = 1,562,500
```

번으로 제한시간 내에 충분하다.

### 공간 복잡도

입력받는 값의 종류는 1, 0밖에 없으므로 boolean 값으로 충분하다.

### 너비 우선 탐색

모든 y,x 좌표에 대해서 너비우선 탐색을 진행한다.

이 때 각 경우마다 방문하는 좌표의 개수를 count하고 정답 vector에 넣는다.

이후 정답 vector를 오름차순 정렬 후 출력

```cpp
for (int y = 0; y < N; y++) {
  for (int x = 0; x < N; x++) {
    if (visited[y][x] || board[y][x] == 0) continue;
    int count = 0;

    queue<Axis> q;
    q.push({y, x});

    while (!q.empty()) {
      Axis cur = q.front();
      q.pop();

      if (visited[cur.y][cur.x]) continue;
      visited[cur.y][cur.x] = true;
      count += 1;

      for (Axis dir : dirs) {
        Axis next = cur;
        next.y += dir.y;
        next.x += dir.x;

        if (!isFine(next, {N, N})) continue;
        if (board[next.y][next.x] == 0) continue;

        q.push(next);
      }
    }

    answers.push_back(count);
  }
}
```

탐색할 때 visited의 비교를 어느 시점에서 할 지가 중요하다.

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
