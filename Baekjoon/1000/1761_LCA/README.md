# 1761. 정점들의 거리

[링크](https://www.acmicpc.net/problem/1761)

|   난이도   | 정답률(\_%) |
| :--------: | :---------: |
| Platinum V |   38.486    |

## 설계

### 시간 복잡도

정점의 개수는 최대 40,000개이고, 쿼리(질의)는 최대 10,000개 까지이다.

직접 브루트 포스 방법으로 구할 경우, 시간 복잡도는 최악의 경우 N^2 이며 이는 160,0000,000 번으로 제한시간 내에 불가능하다.

LCA를 이용하는 경우 전처리 과정에 들어가는 시간 복잡도는 NlogN이다.

### 공간 복잡도

노드의 개수는 최대 40,000개 이므로, 최대 log_2(40000) = 16개 정도의 부모를 가질 수 있다.

따라서 각각 단계별 부모를 만들어야 하므로 40,000 16 정도의 크기의 2차원 배열을 선언해야한다.

두 점 사이의 거리는 최대 10,000 까지이고, 최악의 경우 400,000,000 까지 될 수 있으므로 int형으로 충분하다.

### 최소 공통 조상 (Lowest Common Ancestor)

LCA를 이용하면 각 트리들의 최소 공통 조상을 구할 수 있다.

노드 A와 B의 높이를 맞춰준 뒤, 한단계씩 올라가며 조상을 찾는 방식이다.

이전에 재귀함수를 이용해 각 노드들의 부모를 갱신해야 하는데, 이를 위해서 다음과 같은 배열들이 필요하다.

```cpp
struct Node {
  int to, weight;
};

bool visited[MAX + 1];  // 노드 방문 여부
int depths[MAX + 1];    // 각 노드들의 단계 (루트로부터 깊이)
int distArr[MAX + 1];   // 루트부터 각 노드들 까지의 거리
int parents[MAX + 1][20];  // 각 단계별 부모의 index
```

재귀 함수를 이용해 각 배열들을 갱신한다.

```cpp
void recursive(Node node, int dist) {
  visited[node.to] = true;
  depths[node.to] = node.weight;
  distArr[node.to] = dist;

  for (Node u : graph[node.to]) {
    if (visited[u.to]) continue;

    recursive({u.to, node.weight + 1}, dist + u.weight);
    parents[u.to][0] = node.to;
  }
}
```

최소 공통 조상을 찾는 법은 다음과 같다.

```cpp
int lowestCommonAncestor(int x, int y) {
  if (depths[x] > depths[y]) swap(x, y);

  // 높이를 맞춰줌
  for (int i = 19; i >= 0; i--) {
    if (depths[y] - depths[x] >= (1 << i)) {
      y = parents[y][i];
    }
  }

  if (x == y) return x;
  for (int i = 19; i >= 0; i--) {
    if (parents[x][i] != parents[y][i]) {
      x = parents[x][i];
      y = parents[y][i];
    }
  }

  return parents[x][0];
}
``

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      28      |       12       |

## 고생한 점
```
