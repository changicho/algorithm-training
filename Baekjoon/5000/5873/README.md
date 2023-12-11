# 5873. Distant Pastures

[링크](https://www.acmicpc.net/problem/5873)

| 난이도 | 정답률(\_%) | 시간 제한(초) |
| :----: | :---------: | :-----------: |
| 골드 3 |   50.355    |       1       |

## 설계

### 시간 복잡도

2차원 정방 배열의 한 길이를 N이라 하자. 총 좌표의 갯수는 N^2이다. 이를 V라 하자.

각 노드마다 다른 노드로 이동하는 간선은 총 E개이며 이는 2 \* V개 이하 이므로 V라 하자.

한 좌표에서 다른 모든 좌표들까지 최단거리를 구하는 데 다이크스트라 알고리즘을 사용할 수 있다.

이에 O(E \* log_2(V))를 사용한다.

이를 모든 노드에 대해 반복하므로 O(V \* E \* log_2(V))의 시간 복잡도를 사용한다.

### 공간 복잡도

다이크스트라 알고리즘을 사용하는 데 O(V + E)의 공간 복잡도를 사용한다.

## 다이크스트라 알고리즘

|      시간 복잡도      | 공간 복잡도 |
| :-------------------: | :---------: |
| O(V \* E \* log_2(V)) |  O(V + E)   |

한 점에서 다른 점들까지의 길이를 구한 후 이 중 최대값을 구한다.

이를 모든 시작점에 대해 반복해 해당 최대값 중 가장 큰 값을 선택해야 한다.

다이크스트라 알고리즘을 이용해 각 점에서 다른 점들까지의 최단거리를 구할 수 있다.

이를 모든 점에 대해 반복한다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct Status {
  Axis axis;
  long long cost;

  bool operator<(const Status &other) const { return cost > other.cost; }
};

long long getMaxDist(vector<string> &board, Axis start, int same, int diff) {
  int size = board.size();
  vector<vector<long long>> dist(size, vector<long long>(size, -1));

  dist[start.y][start.x] = 0;

  priority_queue<Status> pq;
  pq.push({start, 0});

  while (!pq.empty()) {
    Status cur = pq.top();
    pq.pop();

    if (dist[cur.axis.y][cur.axis.x] < cur.cost) {
      continue;
    }

    for (Axis &dir : dirs) {
      Axis next = {cur.axis.y + dir.y, cur.axis.x + dir.x};

      if (next.y < 0 || next.y >= size || next.x < 0 || next.x >= size) {
        continue;
      }

      char curBlock = board[cur.axis.y][cur.axis.x];
      char nextBlock = board[next.y][next.x];

      long long nextCost = cur.cost + (curBlock == nextBlock ? same : diff);

      if (dist[next.y][next.x] == -1 || dist[next.y][next.x] > nextCost) {
        dist[next.y][next.x] = nextCost;
        pq.push({next, nextCost});
      }
    }
  }

  long long ret = 0;
  for (int y = 0; y < size; y++) {
    for (int x = 0; x < size; x++) {
      ret = max(ret, dist[y][x]);
    }
  }
  return ret;
}

long long solution(vector<string> &board, int same, int diff) {
  int size = board.size();
  long long answer = 0;

  for (int y = 0; y < size; y++) {
    for (int x = 0; x < size; x++) {
      long long cur = getMaxDist(board, {y, x}, same, diff);

      answer = max(answer, cur);
    }
  }
  return answer;
}
```

## 고생한 점
