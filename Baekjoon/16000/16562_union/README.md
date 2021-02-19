# 16562. 친구비

[링크](https://www.acmicpc.net/problem/16562)

|  난이도  | 정답률(\_%) | 시간 제한(초) |
| :------: | :---------: | :-----------: |
| Gold III |   45.583    |       2       |

## 설계

### 시간 복잡도

친구의 수 (정점) N은 최대 10,000명이다.

관계의 수 (간선) M은 최대 10,000이다.

모든 경우를 탐색하는 경우 시간 복잡도는 N^2 가량 소요된다. (N명의 학생을 순회하며, 각 경우마다 DFS 등으로 탐색)

이는 제한시간 내에 불가능하다.

친구의 친구 관계로 그룹을 만들 수 있으므로 분리 집합을 이용한다.

이 경우 시간 복잡도는 O(a(N)) (애크만 상수) 이므로 거의 상수이다.

따라서 제한시간 2초 내에 충분하다.

### 공간 복잡도

최대 친구비는 10,000 \* 10,000 이며 이는 int형으로 충분하다.

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

### 가장 적은 친구비

분리 집합을 이용해 각 노드들이 어느 집합에 속해있는지 파악했다.

따라서 해당 집합에서 가장 친구비가 적은 학생들을 고르면 된다.

map을 이용해 다음과 같이 자료구조를 세팅한다

- key : 집합의 key
- value : 집합에서 가장 낮은 친구비

```cpp
map<int, int> costOfSet;

for (int node = 1; node < N + 1; node++) {
  int parent = ds.findNode(node);

  if (costOfSet[parent] == 0) {
    costOfSet[parent] = costs[node];
  } else {
    costOfSet[parent] = min(costOfSet[parent], costs[node]);
  }
}
```

이후 각 집합을 순회하며 친구비를 계산한다.

```cpp
int answer = 0;
for (pair<int, int> cur : costOfSet) {
  answer += cur.second;
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      4       |       0        |

## 고생한 점
