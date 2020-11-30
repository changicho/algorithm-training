# 3176. 도로 네트워크

[링크](https://www.acmicpc.net/problem/3176)

|   난이도    | 정답률(\_%) |
| :---------: | :---------: |
| Platinum IV |   38.040    |

## 설계

### 시간 복잡도

노드의 수 N은 최대 2 ~ 100,000 까지의 자연수이다.

질의의 수 K는 최대 100,000개 까지 이다.

N개의 도시와 그 도시를 연결하는 N-1개의 도로로 이루어진 도로 네트워크가 존재한다.

모든 도시의 쌍에는 그 도시를 연결하는 유일한 경로가 있다.

여기서 도시를 연결하는 개수가 N-1개 까지 이므로 사이클이 발생하지 않는 트리 구조로 나타낼 수 있다.

따라서 각 질의마다 두 노드의 최소 공통조상을 찾아 그 최소 공통 조상까지의 거리를 출력한다.

### 공간 복잡도

도로의 길이는 1,000,000 이하의 양의 정수이다.

경로상의 가장 짧은 길이와 긴 거리를 구하는 것이므로 이는 int형으로 충분하다.

### 최소 공통 조상 (Lowest Common Ancestor)

모든 도시 쌍에는 그 도시를 연결하는 유일한 경로가 있다
따라서 주어진 그래프가 트리임을 유추할 수 있다.

두 노드의 길이를 구하기 위해 문제를 해결하기 위하여 LCA를 이용한다.

노드의 수는 최대 100,000 까지이며 이는 log_2(100,000) = 17 이하이므로 노드의 부모는 최대 20개 까지 가질 수 있다.

LCA를 수행하며 부모까지의 모든 간선중에 최솟값과 최댓값을 같이 저장할 수 있다.

최소값과 최대값을 갱신할 시점은 다음 3가지이다.

- 트리 생성
- 각 depth별 부모 초기화
- LCA

각 단계별 코드는 다음과 같다.

```cpp
// 트리 생성
void recursive(int from, int depth) {
  visited[from] = true;
  depths[from] = depth;

  for (Node cur : graph[from]) {
    if (visited[cur.to]) continue;

    recursive(cur.to, depth + 1);

    parents[cur.to][0] = from;
    min_distances[cur.to][0] = cur.cost;
    max_distances[cur.to][0] = cur.cost;
  }
}
```

```cpp
// 각 depth 별 부모 초기화
void LCA_init(int N) {
  for (int j = 1; j <= 20; j++) {
    for (int i = 1; i <= N; i++) {
      parents[i][j] = parents[parents[i][j - 1]][j - 1];
      min_distances[i][j] = min(min_distances[i][j - 1], min_distances[parents[i][j - 1]][j - 1]);
      max_distances[i][j] = max(max_distances[i][j - 1], max_distances[parents[i][j - 1]][j - 1]);
    }
  }
}
```

```cpp
// LCA 수행
pair<int, int> LCA_query(int x, int y) {
  // 최대 최소값 초기화
  int answer_min = LIMIT;
  int answer_max = -LIMIT;

  // 일정 기준에 맞춰 노드 순서를 정렬
  if (depths[x] > depths[y]) swap(x, y);

  // 노드의 높이를 맞춰줌 (부모를 탐색하며)
  for (int i = 20; i >= 0; i--) {
    if (depths[y] - depths[x] >= (1 << i)) {
      answer_min = min(answer_min, min_distances[y][i]);
      answer_max = max(answer_max, max_distances[y][i]);

      y = parents[y][i];
    }
  }

  // 만약 같은 노드인경우 return
  if (x == y) return {answer_min, answer_max};

  // 서로 한단계씩 올라가며 탐색
  for (int i = 20; i >= 0; i--) {
    if (parents[x][i] != parents[y][i]) {
      answer_min = min(answer_min, min(min_distances[x][i], min_distances[y][i]));
      answer_max = max(answer_max, max(max_distances[x][i], max_distances[y][i]));

      x = parents[x][i];
      y = parents[y][i];
    }
  }

  answer_min = min(answer_min, min(min_distances[x][0], min_distances[y][0]));
  answer_max = max(answer_max, max(max_distances[x][0], max_distances[y][0]));

  return {answer_min, answer_max};
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     244      |      100       |

## 고생한 점
