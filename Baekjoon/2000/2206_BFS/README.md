# 2206. 벽 부수고 이동하기

[링크](https://www.acmicpc.net/problem/2206)

| 난이도  | 정답률(\_%) |
| :-----: | :---------: |
| Gold IV |   22.599    |

## 설계

### 시간 복잡도

N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 1,000)이다.

최단 경로를 구해야 하므로 너비우선탐색을 이용한다.

너비우선 탐색의 경우 시간복잡도는 인접 리스트로 구현시 O(|V|+|E|), 인접 행렬로 구현시에 O(|V|^2)가 된다.

정점의 개수는 최대 1,000^2 이며 방향은 최대 4개이므로 최악의 경우 시간 복잡도는

O(4,000,000) 이므로 제한시간내에 충분하다.

### 공간 복잡도

정답의 최대 값은 1000^2 이다. 이는 int형으로 충분하다.

### 벽을 부수는 여부

queue에 다음 상태를 나타내는 구조체를 선언한다.

```cpp
struct Axis {
  int y, x;
};

struct Status {
  Axis axis;
  int cost; // 이동 횟수
  bool useBreak; // 벽을 부섰는지 여부
};
```

### 너비우선 탐색

너비우선 탐색을 수행하는 경우, 목적지에 가장 먼저 도착하는 경우를 먼저 발견할 수 있다.

따라서 목적지에 도착한 경우 탐색을 중지한다.

```cpp
queue<Status> q;
q.push({{0, 0}, 1, false});

while (!q.empty()) {
  Status cur = q.front();
  q.pop();

  if (cur.axis.y == N - 1 && cur.axis.x == M - 1) {
    answer = cur.cost;
    break;
  }
  if (visited[cur.axis.y][cur.axis.x][cur.useBreak]) continue;
  visited[cur.axis.y][cur.axis.x][cur.useBreak] = true;
  costs[cur.axis.y][cur.axis.x][cur.useBreak] = cur.cost;

  for (Axis move : moves) {
    Status next = cur;
    next.axis.y += move.y;
    next.axis.x += move.x;
    next.cost += 1;

    if (next.axis.y < 0 || next.axis.y >= N || next.axis.x < 0 || next.axis.x >= M) continue;
    if (board[next.axis.y][next.axis.x]) {
      if (next.useBreak) continue;
      next.useBreak = true;
      q.push(next);
      continue;
    }

    q.push(next);
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      76      |       16       |

## 고생한 점
