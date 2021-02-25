# 11438. LCA 2

[링크](https://www.acmicpc.net/problem/11438)

|   난이도   | 정답률(\_%) | 시간 제한(초) |
| :--------: | :---------: | :-----------: |
| Platinum V |   32.698    |      1.5      |

## 설계

### 시간 복잡도

트리의 노드의 개수는 N은 최대 100,000개 이다.

두 노드의 공통조상을 알아보고 싶은 질의의 개수 M은 100,000개 까지이다.

최소 공통 조상(Lowest Common Ancestor)을 이용해 문제를 해결할 수 있다.

LCA 쿼리 한번에 시간 복잡도는 O(log(N)) 이며 최악의 경우 O(M \* log(N)) 에도 제한시간 1.5초 내에 해결이 가능하다.

### 공간 복잡도

노드의 개수는 최대 100,000 개 이다.

LCA를 구할 때 2^level번째 조상노드의 개수를 100,000번 까지 가지고 있어야 한다.

2^30 = 1,073,741,824 이므로 최악의 경우도 조상노드까지 도달 가능하다.

따라서 100,000 \* 31 크기의 int배열을 선언한다.

### 최소 공통 조상

LCA를 이용하면 각 트리들의 최소 공통 조상을 구할 수 있다.

노드 A와 B의 높이를 맞춰준 뒤, 한단계씩 올라가며 조상을 찾는 방식이다.

이전에 재귀함수를 이용해 각 노드들의 부모를 갱신해야 하는데, 이를 위해서 다음과 같은 배열들이 필요하다.

```cpp
// node : 노드의 최대 개수 (MAX)
// level : log_w(MAX) + 1 (MAX_LEVEL)

bool visited[node];  // 노드 방문 여부
int parents[node][level]; // 배열(node: 정점번호 level: 2^level번째 조상을 의미)
int depths[node]; // node의 높이가 몇인지
int distArray[node];   // 루트부터 각 노드들 까지의 거리
```

여기서 각 노드까지의 거리는 1이므로 distArray는 무시한다.

```cpp
void recursive(int current, int depth) {
  visited[current] = true;
  depths[current] = depth;

  for (int next : graph[current]) {
    if (visited[next]) continue;

    parents[next][0] = current;
    dfs(next, depth + 1);
  }
}
```

```cpp
int lowestCommonAncestor(int first, int second) {
  // 첫번째가 자식 노드 높이를 더 낮도록 설정
  if (depths[first] > depths[second]) {
    swap(first, second);
  }

  // 높이를 맞춰줌
  for (int level = 30; level >= 0; level--) {
    if (depths[second] - depths[first] >= (1 << level)) {
      second = parents[second][level];
    }
  }

  if (first == second) {
    return first;
  }
  for (int level = 30; level >= 0; level--) {
    if (parents[first][level] != parents[second][level]) {
      first = parents[first][level];
      second = parents[second][level];
    }
  }

  return parents[first][0];
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     128      |       24       |

## 고생한 점
