# 1197. 최소 스패닝 트리

[링크](https://www.acmicpc.net/problem/1197)

| 난이도  | 정답률(\_%) | 시간 제한(초) |
| :-----: | :---------: | :-----------: |
| Gold IV |   39.708    |       2       |

## 설계

유사한 문제

- [백준.1922.네트워크 연결](https://www.acmicpc.net/problem/1922)

### 시간 복잡도

정점의 개수 V(1 ≤ V ≤ 10,000)와 간선의 개수 E(1 ≤ E ≤ 100,000)

최소 신장 트리를 구하기 위해선 크루스칼 알고리즘과, 프림 알고리즘이 존재한다.

각 경우 시간 복잡도는 다음과 같다.

크루스칼 : O(E*log_2(E))
프림 : O(E*lob_2(V))

두 경우 모두 제한시간 2초 내에 충분하다.

### 공간 복잡도

가중치 C는 음수일 수도 있으며, 절댓값이 1,000,000을 넘지 않는다.

최소 스패닝 트리의 가중치가 -2,147,483,648보다 크거나 같고, 2,147,483,647보다 작거나 같은 데이터만 입력으로 주어지며 이는 int형으로 충분하다.

### 최소 스패닝 트리 (Minimum Spanning Tree, MST)

최소 스패닝 트리의 정의는 그래프에서 그래프의 모든 정점을 연결하는 트리이다.

이 때 사이클이 존재하지 않도록 모든 정점을 간선으로 연결한다.

또한 모든 간선의 가중치는 최소값이 되어야 한다.

### 프림의 알고리즘

> 시간 복잡도 O(E\*log_2(V))

우선 순위 큐를 이용해 간선의 가중치가 낮은 간선부터 순회한다.

이때 해당 간선의 목적지를 이미 방문한 경우 이를 건너 뛴다.

이전에 목적지를 이미 방문했다는 것은 현재 간선보다 가중치가 낮다는 것을 의미하기 때문이다.

즉 가중치가 낮은 간선들부터 순회해 MST를 생성한다.

따라서 처음에는 임의의 점에 속해있는 간선들을 전부 우선순위 큐에 넣고 탐색해야 한다.

```cpp
struct Edge {
  int vertex, cost;
};

struct Status {
  Edge edge;

  bool operator<(const Status &b) const {
    return edge.cost > b.edge.cost;
  }
};
```

```cpp
priority_queue<Status> pq;
vector<bool> visited(V + 1, false);

// 한 정점에서 시작하는 모든 간선을 우선순위 큐에 집어넣음
visited[1] = true;
for (Edge cur : graph[1]) {
  pq.push({cur});
}

long long answer = 0;

while (!pq.empty()) {
  Status cur = pq.top();
  pq.pop();
  Edge edge = cur.edge;

  if (visited[edge.vertex]) continue;
  visited[edge.vertex] = true;

  answer += edge.cost;

  for (Edge next : graph[edge.vertex]) {
    pq.push({next});
  }
}
```

### 크루스칼 알고리즘

> 시간 복잡도 O(E\*log_2(E))

무향 연결 가중 그래프에서 간선의 가중치의 합이 최소인 트리를 구하는 것이다.

MST에는 사이클이 없음에 유의한다.

1. 모든 간선의 연결 상태를, 가중치에 따라 오름차순으로 정렬한다.
2. 모든 간선들을 순회하며 탐색한다.
3. MST에 현재 간선을 포함했을 때 사이클이 생기는지 확인한다.
4. 사이클이 생기는 경우 포함하지 않는다.
5. 사이클이 생기지 않는 경우 MST에 해당 간선을 추가한다.

이 경우 자동적으로 cost가 낮은 간선들로만 이루어진 MST를 생성할 수 있다.

여기서 사이클이 생기는지의 여부는 union find (disjoint set)을 이용해 구현하다.

트리의 정점이 낮은쪽을 부모로 한다고 했을 때, 두 정점에서 찾은 부모가 같은 경우 사이클이 있다고 판단한다.

```cpp
struct UnionFind {
  vector<int> cycleTable;

  UnionFind(int size) {
    cycleTable.resize(size + 1);

    for (int i = 1; i <= size; i++) {
      cycleTable[i] = i;
    }
  }

  int findParent(int index) {
    if (cycleTable[index] == index) {
      return index;
    } else {
      int p = findParent(cycleTable[index]);
      cycleTable[index] = p;

      return cycleTable[index];
    }
  }

  void merge(int a, int b) {
    int aRoot = findParent(a);
    int bRoot = findParent(b);

    if (a < b) swap(aRoot, bRoot);
    cycleTable[aRoot] = bRoot;
  }
};
```

간선은 자동으로 오름차순으로 정렬되어야 하며, 다음과 같은 형태이다.

```cpp
struct Edge {
  int from, to, weight;

  bool const operator<(const Edge &b) const {
    return weight < b.weight;
  }
};

sort(edges.begin(), edges.end());

for (Edge l : edges) {
  if (unionfind.findParent(l.from) == unionfind.findParent(l.to)) continue;

  unionfind.merge(l.from, l.to);
  sum += l.weight;
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      68      |       12       |

## 고생한 점

V와 E를 입력받고, 간선들을 입력 받을 때 V의 크기만큼 입력받도록 잘못 로직을 구성했었음
