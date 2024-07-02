# 1579. Remove Max Number of Edges to Keep Graph Fully Traversable

[링크](https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 노드의 갯수를 V, 간선의 갯수를 E라 하자.

유니온 파인드를 이용해 각 노드들이 연결되어 있는지 판별할 수 있다.

alice와 bob의 유니온 파인드를 각각 생성하고, 각각의 유니온 파인드에 대해서 간선을 추가하며 연결되어 있는지 판별한다.

이 경우 O(V + E)의 시간 복잡도가 소요된다.

### 공간 복잡도

유니온 파인드를 사용할 경우 O(V)의 공간 복잡도가 필요하다.

### 유니온 파인드

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     342      |  O(V + E)   |    O(V)     |

각 간선은 무방향이므로 유니온 파인드를 이용해 모든 노드가 연결되어 있는지 판단할 수 있다.

alice와 bob 각각 유니온 파인드를 생성하고, 각 유니온 파인드에 대해서 간선을 추가하며 연결되어 있는지 판단한다.

alice와 bob이 둘다 사용하는 간선을 우선 연결한다.

이후 각각 사용하는 간선에 대해서 필요한 경우 연결한다.

이 때 연결하는 간선들은 제거되면 안되는 간선이므로 이후 남긴다.

마지막으로 alice와 bob의 유니온 파인드가 각각 하나의 집합으로 이루어져 있는지 확인한다.

```cpp
struct UnionFind {
  vector<int> parents;
  int unique = 0;

  UnionFind(int size) {
    parents.resize(size + 1);
    for (int i = 1; i <= size; i++) {
      parents[i] = i;
    }
    unique = size;
  }

  int find(int node) {
    if (parents[node] == node) return node;
    return parents[node] = find(parents[node]);
  }

  bool merge(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    unique--;

    if (a > b) swap(a, b);
    parents[b] = a;
    return true;
  }
};

int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
  UnionFind alice(n), bob(n);

  int required = 0;
  for (vector<int>& e : edges) {
    int type = e[0], a = e[1], b = e[2];
    if (type == 3) {
      required += (alice.merge(a, b) | bob.merge(a, b));
    }
  }

  for (vector<int>& e : edges) {
    int type = e[0], a = e[1], b = e[2];
    if (type == 1) {
      required += alice.merge(a, b);
    } else if (type == 2) {
      required += bob.merge(a, b);
    }
  }

  if (alice.unique > 1 || bob.unique > 1) return -1;
  return edges.size() - required;
}
```

## 고생한 점
