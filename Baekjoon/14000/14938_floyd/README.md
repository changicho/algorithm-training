# 14938. 서강그라운드

[링크](https://www.acmicpc.net/problem/14938)

| 난이도  | 정답률(\_%) | 제한시간 |
| :-----: | :---------: | :------: |
| Gold IV |   50.232    |   1초    |

## 설계

### 시간 복잡도

N은 최대 100 까지이다.

각 노드에서 시작했을 때 도달할 수 있는 노드들 찾아야 하므로 각 노드마다 다이크스트라를 이용해 다른 노드 까지의 거리를 계산할 수 있다.

그러나 모든 노드에 대해서 거리들을 계산해야 하므로 플로이드 와샬 알고리즘을 이용해 한번에 모두 구할 수 있다.

이 때 시간 복잡도는 O(N^3) 이므로 제한시간 1초 내에 충분하다.

### 공간 복잡도

각 엣지마다 거리의 값은 15 이하이므로 최악의 경우 거리는 1,500 이하이다.

또한 각 노드별 점수는 30 이하이므로 최악의 경우 점수는 3,000 이다.

이는 전부 int형으로 표현 가능하다.

### 플로이드 와셜 알고리즘

N이 작을 때 모든 정점에 대해서 다른 정점까지의 최소 거리를 구할 수 있는 방법

먼저 그래프의 초기화를 수행한다.

```cpp
for (int y = 1; y <= N; y++) {
  for (int x = 1; x <= N; x++) {
    graph[y][x] = y == x ? 0 : MAX;
  }
}
```

그래프 좌표를 업데이트 한 뒤 3중 반복문을 이용해 최소 거리들을 갱신한다.

```cpp
for (int through = 1; through <= N; through++) {
  for (int from = 1; from <= N; from++) {
    for (int to = 1; to <= N; to++) {
      graph[from][to] = min(graph[from][to], graph[from][through] + graph[through][to]);
    }
  }
}
```

### 갈 수 있는 정점의 탐색

한 노드에서 다음 노드까지의 거리가 M이내인 경우에만 진행이 가능하므로, 이 경우에만 더한다.

```cpp
int answer = 0;
for (int node = 1; node <= N; node++) {
  int score = 0;

  for (int next = 1; next <= N; next++) {
    if (graph[node][next] <= M) {
      score += scores[next];
    }
  }

  answer = max(answer, score);
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
