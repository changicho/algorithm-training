# 1261. 알고스팟

[링크](https://www.acmicpc.net/problem/1261)

| 난이도  | 정답률(\_%) |
| :-----: | :---------: |
| Gold IV |   39.653    |

## 설계

### 시간 복잡도

N과 M은 최대 100 까지이다.

다익스트라 방법으로 시작점에서 끝 점까지 탐색을 한다고 했을 때, 최악의 경우

노드의 개수 : 10,000, 간선의 개수 : 20,000 이하이다. 따라서 시간 복잡도는 O(V+E log2(V)) 이다.

```cpp
(V + E) * log2(V) = 30,000 * 15 = 450,000
```

이므로 제한시간 1초 내에 충분하다.

### 공간 복잡도

N과 M은 최대 100 까지이므로 모든 칸이 벽으로 되어있을 때 최악의 경우 정답은 10,000 이하이다.

이는 초기에 거리배열을 초기화 할 때도 마찬가지이므로 10,000으로 초기화한다.

이는 모두 int형으로 충분하다.

### 다익스트라

상, 하, 좌, 우 네 방향으로 움직이면 되고 이는 y, x좌표의 이동으로 구현할 수 있다.

각 좌표에서 상, 하, 좌, 우 의 좌표들 까지의 거리를 비교하며,

자신을 거쳐 갔을 때 vs 기존 루트로 갔을 때 중 최소값으로 할당한다.

최소값이 변경되는 경우 우선순위 큐에 좌표를 집어넣는다. (갱신한 거리와 함께)

각 간선들의 cost는 벽을 부수는 횟수이며, 이는 입력받은 board에 벽의 유무로 계산할 수 있다.

```cpp
void dijkstra(Axis destination) {
  priority_queue<Status> pq;

  dist[0][0] = 0;
  pq.push({{0, 0}, dist[0][0]});

  while (!pq.empty()) {
    Status cur = pq.top();
    Axis axis = cur.axis;
    pq.pop();

    if (axis.y == destination.y && axis.x == destination.x) return;

    for (Axis move : moves) {
      Axis next = axis;
      next.y += move.y;
      next.x += move.x;

      if (next.y < 0 || next.y > destination.y || next.x < 0 || next.x > destination.x) continue;

      int new_dist = dist[axis.y][axis.x] + board[next.y][next.x];

      if (new_dist < dist[next.y][next.x]) {
        dist[next.y][next.x] = new_dist;
        pq.push({next, new_dist});
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
