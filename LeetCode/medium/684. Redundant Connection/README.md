# 684. Redundant Connection

[링크](https://leetcode.com/problems/redundant-connection/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

그래프의 노드의 수를 V, 간선의 수를 E라 하자.

유니온 파인드를 사용해 불필요한 간선을 찾을 수 있다.

이에 O(V + E \* a(V))의 시간 복잡도가 필요하다. (a(V)는 상수시간이다.)

### 공간 복잡도

유니온 파인드를 사용할 경우 O(V)의 공간 복잡도가 필요하다.

### 유니온 파인드

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      0       | O(V + E \* a(V)) |    O(V)     |

간선들에서 불필요한 간선 하나를 찾아야한다.

간선을 순회하며 노드들을 연결할 때, 두 노드가 이미 연결되어있는 경우 cycle이 발생한다.

해당 간선을 제거한다.

```cpp
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
  int size = edges.size();
  vector<int> parents(size + 1);
  for (int i = 1; i <= size; i++) {
    parents[i] = i;
  }

  function<int(int)> find = [&](int node) {
    if (parents[node] == node) return node;
    return parents[node] = find(parents[node]);
  };

  function<void(int, int)> merge = [&](int a, int b) {
    a = find(a), b = find(b);

    if (a == b) return;
    if (a > b) swap(a, b);
    parents[b] = a;
  };

  for (vector<int>& e : edges) {
    int a = e[0], b = e[1];

    if (find(a) == find(b)) return e;
    merge(a, b);
  }
  return {};
}
```

## 고생한 점
