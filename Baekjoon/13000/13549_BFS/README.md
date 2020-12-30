# 13549. 숨바꼭질 3

[링크](https://www.acmicpc.net/problem/13549)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
| Gold V |   26.899    |

## 설계

### 시간 복잡도

N(0 ≤ N ≤ 100,000) K(0 ≤ K ≤ 100,000)이다.

N에서 K까지 도달하는데 3가지 경우를 탐색해야한다. 이 때 N과 K의 차이는 최대 100,000 까지 이므로 모든 경우를 검사할 경우 최악의 경우 3^(100,000)의 시간 복잡도가 소요된다.

따라서 이전에 방문한 곳은 건너뛰어야한다.

### 공간 복잡도

N이 0이고, K가 99,999 인 경우 가장 빠른 경우는 99,998 에서 +1로 이동하는 경우이다.

N이 4이고 K가 7인 경우 가장 빠른 경우는 4 > 8 > 7 이다.

따라서 더이상 탐색하지 않는 좌표 (백트래킹) 은

```cpp
int limit = min(2 * max(N, K), 100000);
```

까지이다.

### BFS

탐색하는 좌표가 음수, limit를 초과할 수 있음에 유의한다.

N이 4이고 K가 7인 경우 가장 빠른 경우는 4 > 8 > 7 이다.

즉 K보다 높은 수에서 감소하며 탐색하는 경우가 최선이 될 수 있으므로 해당 경우 또한 고려한다.

```cpp
int dist[100001] = {
    0,
};
for (int i = 0; i <= 100000; i++) {
  dist[i] = -1;
}

int limit = min(2 * max(N, K), 100000);
```

```cpp
queue<Status> q;
q.push({N, 0});

int answer = abs(K - N);

while (!q.empty()) {
  Status cur = q.front();
  q.pop();

  if (cur.axis > limit || cur.axis < 0) continue;
  if (dist[cur.axis] != -1 && dist[cur.axis] <= cur.depth) continue;
  dist[cur.axis] = cur.depth;

  if (cur.axis == K) {
    answer = min(answer, cur.depth);
    continue;
  }

  q.push({cur.axis * 2, cur.depth});
  q.push({cur.axis + 1, cur.depth + 1});
  q.push({cur.axis - 1, cur.depth + 1});
}
```

### 우선순위 큐를 이용한 방법

depth가 낮은 순서대로 자동으로 탐색한다.

```cpp
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

q.push(make_pair(0, N));
visited[N] = true;

while (!q.empty()) {
  int depth = q.top().first;
  int axis = q.top().second;

  q.pop();

  if (axis == K) {
    answer = depth;
    break;
  }

  if (axis * 2 < MAX && !visited[axis * 2]) {
    q.push(make_pair(depth, axis * 2));

    visited[axis * 2] = true;
  }

  if (axis + 1 < MAX && !visited[axis + 1]) {
    q.push(make_pair(depth + 1, axis + 1));

    visited[axis + 1] = true;
  }

  if (axis - 1 >= 0 && !visited[axis - 1]) {
    q.push(make_pair(depth + 1, axis - 1));

    visited[axis - 1] = true;
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      4       |       0        |

## 고생한 점
