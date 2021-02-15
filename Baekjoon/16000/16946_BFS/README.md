# 16946. 벽 부수고 이동하기 4

[링크](https://www.acmicpc.net/problem/16946)

| 난이도  | 정답률(\_%) | 시간 제한(초) |
| :-----: | :---------: | :-----------: |
| Gold II |   26.025    |       2       |

## 설계

### 시간 복잡도

판의 크기는 최대 1,000^2 이다.

각 벽마다 이동할 수 있는 횟수는 벽의 4분면에서 갈 수 있는 빈 공간의 개수 + 1 이다. (자기자신 포함)

매 경우마다 탐색을 통해 빈 공간의 개수를 찾는 경우 빈 공간의 묶음을 중복해서 계산하므로 미리 빈 공간의 묶음을 계산해놓는다.

이 떄 시간 복잡도는 O(N^2) 이내이며 이후 각 벽마다 탐색하는데에도 O(4 \* N^2) 정도 소요되므로 제한시간 2초 내에 풀이가 가능하다.

### 공간 복잡도

정답은 10 이하의 0을 포함한 자연수로 이루어졌으므로 int형으로 선언한다.

### 빈 공간의 묶음

각 빈 공간들을 계산할 때 다음과 같은 묶음을 만들어야 한다.

- key : 빈 공간 묶음의 index (구분할 숫자)
- value : 해당 묶음의 빈 공간 개수

이는 BFS로 탐색한다.

이때 해당 key, value를 어떻게 저장하는지에 따라 시간복잡도의 차이가 존재한다.

(map을 사용하는 경우보다 배열로 table을 이용하는 경우가 더 빠름)

```cpp
for (int y = 0; y < N; y++) {
  for (int x = 0; x < M; x++) {
    if (visited[y][x] || board[y][x]) continue;
    int color = color_counts.size();
    int count = 0;

    queue<Axis> q;
    q.push({y, x});

    while (!q.empty()) {
      Axis cur = q.front();
      q.pop();

      if (!isSafe(cur, N, M)) continue;
      if (visited[cur.y][cur.x] || board[cur.y][cur.x]) continue;

      visited[cur.y][cur.x] = true;
      colors[cur.y][cur.x] = color;
      count += 1;

      for (Axis dir : dirs) {
        Axis next = cur;
        next.y += dir.y;
        next.x += dir.x;

        q.push(next);
      }
    }

    color_counts[color] = count;
  }
}
```

### 각 벽을 부쉈을 때 계산

각 벽에서 상,하,좌,우로 연결된 빈 블록들의 덩어리가 존재하는지 판단한다.

총 개수들만큼 더해 계산.

```cpp
for (int y = 0; y < N; y++) {
  for (int x = 0; x < M; x++) {
    if (!board[y][x]) continue;

    Axis cur = {y, x};
    int count = 0;

    set<int> s;

    for (Axis dir : dirs) {
      Axis next = cur;
      next.y += dir.y;
      next.x += dir.x;

      if (!isSafe(next, N, M) | board[next.y][next.x]) continue;
      int color = colors[next.y][next.x];
      if (s.find(color) != s.end()) continue;

      s.insert(color);
      count += color_counts[color];
    }

    count = (count + 1) % 10;
    answers[y][x] = count;
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     116      |       48       |

## 고생한 점
