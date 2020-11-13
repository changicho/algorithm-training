# 2178. 미로 탐색

[링크](https://www.acmicpc.net/problem/2178)

|  난이도  | 정답률(\_%) |
| :------: | :---------: |
| Silver I |   36.888    |

## 설계

### 시간 복잡도

지도의 크기는 최대 100^2 이다.

결국 모든 칸을 방문하는 경우 시간 복잡도는 100^2 이므로 제한시간 내에 충분하다.

### 공간 복잡도

지도의 정보가 한줄씩 입력되므로 string으로 관리한다.

정답의 수는 100^2 이내의 자연수이므로 int형으로 선언한다.

### 너비 우선 탐색

BFS를 진행하며 목적지에 도달한 경우 정답을 갱신하고 탐색을 중지한다.

```cpp
struct Axis {
  int y, x;
};

struct Status {
  Axis axis;
  int depth;
};
```

```cpp
queue<Status> q;
q.push({{0, 0}, 1});

while (!q.empty()) {
  Status cur = q.front();
  q.pop();

  if (visited[cur.axis.y][cur.axis.x]) continue;
  visited[cur.axis.y][cur.axis.x] = true;

  if (cur.axis.y == N - 1 && cur.axis.x == M - 1) {
    answer = cur.depth;
    break;
  }

  for (Axis dir : dirs) {
    Status next = {cur.axis, cur.depth + 1};
    next.axis.y += dir.y;
    next.axis.x += dir.x;

    if (!isSafe(next.axis)) continue;
    if (board[next.axis.y][next.axis.x] == '0') continue;

    q.push(next);
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
