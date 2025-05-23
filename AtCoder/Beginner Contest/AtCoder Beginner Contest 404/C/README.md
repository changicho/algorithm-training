# C - Cycle Graph?

[링크](https://atcoder.jp/contests/abc404/tasks/abc404_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

그래프의 노드의 수를 V, 간선의 수를 E라 하자.

각 노드마다 2개의 간선만 연결되어있어야 하며, 모두 하나의 사이클에 연결되어있어야 한다.

유니온 파인드를 사용할 경우 O(V + E)의 시간 복잡도를 사용한다.

### 공간 복잡도

유니온 파인드에 O(V)의 공간 복잡도를 사용한다.

### 유니온 파인드

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      29      |  O(V + E)   |    O(V)     |

문제 조건을 만족하기 위해서 간선의 수는 노드의 수와 동일해야 한다.

또한 각 노드마다 2개의 간선이 연결되어 있어야 한다.

이후 각 노드들이 모두 연결되어있는지를 유니온 파인드를 사용해 확인한다.

```cpp
struct Edge {
  int from, to;
};

bool solution(int n, int m, vector<Edge> &edges) {
  if (m != n) return false;

  vector<int> inDegrees(n, 0);

  for (auto &edge : edges) {
    inDegrees[edge.to - 1]++;
    inDegrees[edge.from - 1]++;
  }

  for (int i = 0; i < n; i++) {
    if (inDegrees[i] != 2) {
      return false;
    }
  }

  // check graph count
  vector<int> parents(n);
  for (int i = 0; i < n; i++) {
    parents[i] = i;
  }
  int group = n;
  function<int(int)> find = [&](int x) {
    if (parents[x] == x) {
      return x;
    }
    return parents[x] = find(parents[x]);
  };

  function<void(int, int)> merge = [&](int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      return;
    }
    if (x > y) {
      swap(x, y);
    }
    group--;
    parents[y] = x;
  };

  for (auto &edge : edges) {
    int x = edge.from - 1;
    int y = edge.to - 1;
    merge(x, y);
  }

  if (group != 1) return false;

  return true;
}
```

## 고생한 점
