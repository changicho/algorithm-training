# 11437. LCA

[링크](https://www.acmicpc.net/problem/11437)

|  난이도  | 정답률(\_%) | 시간 제한(초) |
| :------: | :---------: | :-----------: |
| Gold III |   44.348    |       3       |

## 설계

### 시간 복잡도

N은 최대 500,000 까지이다. 쿼리의 수 M은 최대 10,000까지이다.

트리의 최소 공통 조상을 매번 DFS를 탐색하며 찾을 경우 시간 복잡도는 O(N \* M) 이므로 제한시간 3초 내에 불가능하다.

따라서 각 노드마다 i번째 부모를 미리 저장하고 이를 이용해 탐색을 진행한다.

LCA 알고리즘을 이용할 경우 각 쿼리마다 O(log_2(N)) 번 만에 수행할 수 있으므로 제한 시간 3초 내에 가능하다.

### 공간 복잡도

노드의 범위는 1 ~ 500,000 까지이다. LCA 알고리즘을 이용할 경우 2^i 번째의 부모 노드를 저장하므로, 최악의 경우 i는 log_2(500,000) 까지 가능해야 한다.

이는 16 미만의 소수이므로 16까지 설정한다.

### LCA

각 정점의 2^i 번째의 부모 노드를 저장하는 배열을 생성한다.

```cpp
int parents[node][level]; // 배열(node: 정점번호 level: 2^level번째 조상을 의미)
```

또한 각 노드마다 높이를 저장하는 배열을 설정한다.

```cpp
int depths[node]; // node의 높이가 몇인지
```

재귀함수와 반복문을 이용해 초기값을 설정한다.

```cpp
void recursive(int current, int depth) {
  visited[current] = true;
  depths[current] = depth;

  for (int next : graph[current]) {
    if (visited[next]) continue;

    parents[next][0] = current;
    recursive(next, depth + 1);
  }
}
```

```cpp
recursive(rootNode, 0); // 루트노드, 0
for (int level = 1; level <= MAX_LEVEL; level++) {
  for (int node = 1; node <= N; node++) {
    int parent = parents[node][level - 1];
    parents[node][level] = parents[parent][level - 1];
  }
}
```

다음으로 아래 함수를 이용해 최소 공통 조상을 찾는다.

노드 A와 B의 높이를 맞춰준 뒤, 한단계씩 올라가며 조상을 찾는 방식이다.

```cpp
// MAX : 노드의 최대 개수
// MAX_LEVEL : log_w(MAX) + 1

int lowestCommonAncestor(int first, int second) {
  // 첫번째가 자식 노드 높이를 더 낮도록 설정
  if (depths[first] > depths[second]) {
    swap(first, second);
  }

  // 높이를 맞춰줌
  for (int level = MAX_LEVEL; level >= 0; level--) {
    if (depths[second] - depths[first] >= (1 << level)) {
      second = parents[second][level];
    }
  }

  if (first == second) {
    return first;
  }
  for (int level = MAX_LEVEL; level >= 0; level--) {
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
|      32      |       16       |

## 고생한 점
