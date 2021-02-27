# 16724. 피리 부는 사나이

[링크](https://www.acmicpc.net/problem/16724)

| 난이도  | 정답률(\_%) | 시간 제한(초) |
| :-----: | :---------: | :-----------: |
| Gold II |   41.592    |       1       |

## 설계

### 시간 복잡도

지도의 크기는 최대 1,000^2 이다.

각 지도별로 탐색을 진행하며 사이클을 찾는다.

사이클의 개수만큼 Safe Zone을 만들어야 한다.

이를 위해 모든 경우를 탐색할 경우 시간 복잡도는 모든 좌표를 탐색하는데 1,000^2가 소요된다.

각 좌표마다 사이클을 탐색하는데 들어가는 비용 또한 모든 경우를 합쳐 4 \* 1,000^2 정도이다.

이는 모두 합쳐도 O(N^2) 정도이며 제한시간 내에 충분하다.

### 공간 복잡도

정답의 개수는 최악의 경우도 1,000^2 이내임이 보장된다.

따라서 int형으로 선언한다.

### 분리 집합

분리 집합을 이용해 좌표들의 집합을 생성한다.

이 집합의 개수만큼 Safe Zone을 생성하면 된다.

이 때 y, x좌표를 이용해 분리집합을 생성해야 하므로 주의해야한다.

```cpp
struct Axis {
  int y, x;
};

bool compare(Axis a, Axis b) {
  if (a.y != b.y) {
    return a.y > b.y;
  }
  return a.x > b.x;
}
```

분리 집합은 다음과 같이 생성한다.

```cpp
struct DisjointSet {
  vector<vector<Axis>> parents;
  vector<vector<int>> counts;

  DisjointSet(int row, int col) {
    parents.resize(row, vector<Axis>(col));
    counts.resize(row, vector<int>(col));

    for (int y = 0; y < row; y++) {
      for (int x = 0; x < col; x++) {
        parents[y][x] = {y, x};
        counts[y][x] = 1;
      }
    }
  }

  Axis findNode(Axis node) {
    Axis parent = parents[node.y][node.x];
    if (parent.y == node.y && parent.x == node.x) {
      return node;
    }

    return parents[node.y][node.x] = findNode(parent);
  }

  bool isLinked(Axis nodeA, Axis nodeB) {
    Axis parentA = findNode(nodeA), parentB = findNode(nodeB);
    return (parentA.y == parentB.y && parentA.x == parentB.x);
  }

  void merge(Axis nodeA, Axis nodeB) {
    if (compare(nodeA, nodeB)) {
      swap(nodeA, nodeB);
    }

    nodeA = findNode(nodeA);
    nodeB = findNode(nodeB);

    if (nodeA.y == nodeB.y && nodeA.x == nodeB.x) return;
    if (counts[nodeA.y][nodeA.x] < counts[nodeB.y][nodeB.x]) {
      swap(nodeA, nodeB);
    }

    parents[nodeB.y][nodeB.x] = nodeA;
    if (counts[nodeA.y][nodeA.x] == counts[nodeB.y][nodeB.x]) {
      counts[nodeB.y][nodeB.x]++;
    }
  }
};
```

그리고 모든 좌표를 탐색하며 분리집합을 생성한다.

이 때 처음에 모든 좌표들의 개수를 설정하고, 분리 집합에서 기존 집합에 속해지는 좌표들의 개수만 뺄 경우, 분리 집합의 parent들의 개수만 남길 수 있다.

```cpp
int answer = N * M;
for (int y = 0; y < N; y++) {
  for (int x = 0; x < M; x++) {
    Axis dir = getDir(board[y][x]);
    Axis cur = {y, x}, next = {y + dir.y, x + dir.x};

    if (!ds.isLinked(cur, next)) {
      ds.merge(cur, next);
      answer -= 1;
    }
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      56      |       16       |

## 고생한 점
