# 1043. 거짓말

[링크](https://www.acmicpc.net/problem/1043)

| 난이도  | 정답률(\_%) |
| :-----: | :---------: |
| Gold IV |   32.941    |

## 설계

분리 집합
서로소 집합
유니온 파인드

### 시간 복잡도

N, M은 50 이하의 자연수이다.

각 파티마다 오는 사람의 수는 0 ~ 50명 까지이다.

파티에서 만나는 사람들 끼리 집합을 생성해야 하므로 분리 집합(Disjoint Set)을 이용한다.

집합을 합치는경우의 시간복잡도는 최대 O(N)이다.

어느 집합에 속해있는지 찾는 쿼리에 시간복잡도는 O(N)이다.

따라서 최악의 경우 시간 복잡도는 O(M(N+N)) 이므로 이는 제한시간 내에 충분하다.

### 공간 복잡도

입력받는 수의 절대값은 전부 50 이내의 자연수이다. 따라서 int형으로 선언한다.

### 분리 집합 (Disjoint set)

Disjoint set은 서로 중복되지 않는 부분 집합들로 나누어진 원소들에 대한 정보를 저장하고 조작하는 자료구조이다.

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
|      0       |       0        |

## 고생한 점
