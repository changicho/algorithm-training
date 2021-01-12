# 12851. 숨바꼭질 2

[링크](https://www.acmicpc.net/problem/12851)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
| Gold V |   25.716    |

## 설계

### 시간 복잡도

N ≤ 100,000, K ≤ 100,000 이다.

탐색할 수 있는 경우의 수는 다음 3가지이다.

- 더하기 1
- 빼기 1
- 곱하기 2

최단 경로와 그 갯수를 구해야 하므로 BFS를 이용해 풀이한다.

이 때 이미 방문한 좌표는 탐색을 중지해 시간 복잡도를 줄인다.

### 공간 복잡도

정답은 100,000 이하이므로 int형으로 선언한다.

### 너비 우선 탐색

최단 경로의 개수 또한 구해야 한다.

따라서 현재 좌표가 이전에 방문한 좌표임을 확인하지 않고, 다음번에 방문할 좌표가 이전에 방문했는지를 판별한다.

이는 현재 좌표가 정답일 경우 중복되어 나타날 수 있기 때문이다.

```cpp
queue<Status> q;
q.push({N, 0});

while (!q.empty()) {
  Status cur = q.front();
  q.pop();
  visited[cur.axis] = true;

  if (cur.axis == K && cur.depth <= answer) {
    answer = cur.depth;
    answerCount += 1;
    continue;
  }

  if (cur.axis + 1 < LIMIT && !visited[cur.axis + 1]) q.push({cur.axis + 1, cur.depth + 1});
  if (cur.axis - 1 >= 0 && !visited[cur.axis - 1]) q.push({cur.axis - 1, cur.depth + 1});
  if (cur.axis * 2 < LIMIT && !visited[cur.axis * 2]) q.push({cur.axis * 2, cur.depth + 1});
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      24      |       0        |

## 고생한 점
