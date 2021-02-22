# 2887. 행성 터널

[링크](https://www.acmicpc.net/problem/2887)

| 난이도  | 정답률(\_%) | 시간 제한(초) |
| :-----: | :---------: | :-----------: |
| Gold II |   36.122    |       1       |

## 설계

### 시간 복잡도

행성의 개수 N은 최대 100,000 까지이다. 모든 행성을 연결하는 MST를 생성하는 문제이다.

각 행성마다 연결하는 모든 간선을 구할 경우 그래프를 생성하는데 O(N^2) 만큼 소요되므로 제한시간 내에 불가능하다.

따라서 간선들 중 후보만 추려 생성해야한다.

MST를 생성하는 알고리즘은 다음 2가지이다.

- 크루스칼 : O(E \* log(E))
- 프림 : O(E \* lob(V))

### 공간 복잡도

하나의 경로의 최대 cost는 2 \* 10^9 이다.

다만 이 경로의 경우 중간에 모든 별들을 이어서 만들 수 있는 최대 길이이다.

(MST를 구성한 경우 끝점에서 끝점까지 가능한 거리이므로)

따라서 int형으로 충분하다.

### 간선의 생성

간선을 모든 별에서 모든 별까지 생성하지 않고 가장 인접한 별들 끼리만 생성한다.

이 경우 오름차순으로 정렬한 뒤 i, i+1 번째의 좌표를 비교하면 된다.

이 때 문제에서 cost는 x, y, z 좌표의 차이중 최소 이므로, 이 3 좌표를 각각 따로 계산한다.

```cpp
struct Axis {
  int axis;
  int index;

  bool operator<(const Axis &b) const {
    return axis < b.axis;
  }
};

struct Edge {
  int cost, from, to;

  bool const operator<(const Edge &b) const {
    return cost < b.cost;
  }
};
```

```cpp
vector<Axis> x_axis(N);
vector<Axis> y_axis(N);
vector<Axis> z_axis(N);

for (int i = 0; i < N; i++) {
  cin >> x_axis[i].axis >> y_axis[i].axis >> z_axis[i].axis;
  x_axis[i].index = y_axis[i].index = z_axis[i].index = i;
}

sort(x_axis.begin(), x_axis.end());
sort(y_axis.begin(), y_axis.end());
sort(z_axis.begin(), z_axis.end());

vector<Edge> edges;

for (int i = 0; i < N - 1; i++) {
  edges.push_back({x_axis[i + 1].axis - x_axis[i].axis, x_axis[i].index, x_axis[i + 1].index});
  edges.push_back({y_axis[i + 1].axis - y_axis[i].axis, y_axis[i].index, y_axis[i + 1].index});
  edges.push_back({z_axis[i + 1].axis - z_axis[i].axis, z_axis[i].index, z_axis[i + 1].index});
}
```

### 프림의 알고리즘

> 시간 복잡도 O(E \* log(V)) 220ms

우선 순위 큐를 이용해 간선의 가중치가 낮은 간선부터 순회한다.

이때 해당 간선의 목적지를 이미 방문한 경우 이를 건너 뛴다.

이전에 목적지를 이미 방문했다는 것은 현재 간선보다 가중치가 낮다는 것을 의미하기 때문이다.

즉 가중치가 낮은 간선들부터 순회해 MST를 생성한다.

따라서 처음에는 임의의 점에 속해있는 간선들을 전부 우선순위 큐에 넣고 탐색해야 한다.

```cpp
struct Edge {
  int to, cost;

  bool const operator<(const Edge &b) const {
    return cost < b.cost;
  }
};

struct Status {
  Edge edge;

  bool operator<(const Status &b) const {
    return edge.cost > b.edge.cost;
  }
};
```

다음과 같이 그래프를 생성해야 한다.

```cpp
for (int i = 0; i < N - 1; i++) {
  graph[x_axis[i].index].push_back({x_axis[i + 1].index, x_axis[i + 1].axis - x_axis[i].axis});
  graph[x_axis[i + 1].index].push_back({x_axis[i].index, x_axis[i + 1].axis - x_axis[i].axis});

  graph[y_axis[i].index].push_back({y_axis[i + 1].index, y_axis[i + 1].axis - y_axis[i].axis});
  graph[y_axis[i + 1].index].push_back({y_axis[i].index, y_axis[i + 1].axis - y_axis[i].axis});

  graph[z_axis[i].index].push_back({z_axis[i + 1].index, z_axis[i + 1].axis - z_axis[i].axis});
  graph[z_axis[i + 1].index].push_back({z_axis[i].index, z_axis[i + 1].axis - z_axis[i].axis});
}
```

이후 우선순위 큐를 이용해 MST를 생성한다.

```cpp
priority_queue<Status> pq;
vector<bool> visited(N + 1, false);

// 한 정점에서 시작하는 모든 간선을 우선순위 큐에 집어넣음
visited[1] = true;
for (Edge cur : graph[1]) {
  pq.push({cur});
}

int answer = 0;

while (!pq.empty()) {
  Status cur = pq.top();
  pq.pop();
  Edge edge = cur.edge;

  if (visited[edge.to]) continue;
  visited[edge.to] = true;

  answer += edge.cost;

  for (Edge next : graph[edge.to]) {
    pq.push({next});
  }
}
```

### 크루스칼 알고리즘

> 시간 복잡도 O(E \* log(E)) 96ms

무향 연결 가중 그래프에서 간선의 가중치의 합이 최소인 트리를 구하는 것이다.

MST에는 사이클이 없음에 유의한다.

모든 간선의 연결 상태를, 가중치에 따라 오름차순으로 정렬한다.

1. 모든 간선들을 순회하며 탐색한다.
2. MST에 현재 간선을 포함했을 때 사이클이 생기는지 확인한다.
3. 사이클이 생기는 경우 포함하지 않는다.
4. 사이클이 생기지 않는 경우 MST에 해당 간선을 추가한다.

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

```cpp
sort(edges.begin(), edges.end());
UnionFind unionFind(N);
int answer = 0;

for (Edge cur : edges) {
  int from = cur.from;
  int to = cur.to;
  int cost = cur.cost;

  if (unionFind.findParent(from) == unionFind.findParent(to)) continue;

  unionFind.merge(from, to);
  answer += cost;
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      56      |       96       |

## 고생한 점
