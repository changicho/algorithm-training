# 10775. 공항

[링크](https://www.acmicpc.net/problem/10775)

| 난이도 | 정답률(\_%) | 시간 제한(초) |
| :----: | :---------: | :-----------: |
| Gold I |   38.439    |       1       |

## 설계

### 시간 복잡도

게이트의 수 G는 최대 10^5, 비행기의 수 P는 최대 10^5이다.

원하는 게이트에 도달하지 못한 경우 다른 게이트로 이동할 수 있도록 다음 게이트를 알아야 한다.

이를 위해 분리 집합을 사용한다.

이 경우 시간 복잡도는 O(N) 이므로 제한시간 내에 충분하다.

### 공간 복잡도

정답의 최대치는 10^5 이므로 int형으로 선언한다.

### 분리 집합

현재 비행기가 원하는 게이트를 g라고 하자.

g번째 게이트부터 도킹을 시키며, 만약 g번째 게이트가 이미 도킹이 완료된 경우 다음 게이트를 찾아야 한다.

다음 게이트를 찾기 위해 Disjoint Set을 이용한다.

만약 g게이트에 도킹이 될 경우, 다음번에 다시 g게이트를 확인 할 때 g-1게이트를 확인 하도록 parent를 설정한다.

만약 현재 g번째 게이트에서 다음게이트를 확인했을 때 0번째를 볼 경우 (1 - 1 = 0번째) 게이트가 포화상태임을 알 수 있다.

```cpp
DisjointSet ds(G + 1);
for (int goal : goals) {
  int airport = ds.findNode(goal);
  if (airport != 0) {
    ds.merge(airport, airport - 1);
    answer += 1;
  } else {
    break;
  }
}
```

```cpp
struct DisjointSet {
  vector<int> parents;
  vector<int> counts;

  DisjointSet(int size) {
    parents.resize(size);
    counts.resize(size);

    for (int i = 0; i < size; i++) {
      parents[i] = i;
      counts[i] = 1;
    }
  }

  int findNode(int node) {
    if (parents[node] == node) return node;

    return parents[node] = findNode(parents[node]);
  }

  bool isLinked(int nodeA, int nodeB) {
    return findNode(nodeA) == findNode(nodeB);
  }

  void merge(int nodeA, int nodeB) {
    if (nodeA > nodeB) swap(nodeA, nodeB);

    nodeA = findNode(nodeA);
    nodeB = findNode(nodeB);

    if (nodeA == nodeB) return;
    if (counts[nodeA] < counts[nodeB]) swap(nodeA, nodeB);

    parents[nodeB] = nodeA;
    if (counts[nodeA] == counts[nodeB]) counts[nodeB]++;
  }
};
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      12      |       0        |

## 고생한 점
