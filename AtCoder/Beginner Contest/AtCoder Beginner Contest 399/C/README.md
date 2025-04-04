# C - Make it Forest

[링크](https://atcoder.jp/contests/abc399/tasks/abc399_c)

| 난이도 |
| :----: |
|  350   |

## 설계

### 시간 복잡도

그래프의 노드의 수를 V, 간선의 수를 E라 하자.

유니온 파인드를 사용해 사이클이 생기는 간선을 제외할 수 있다.

이 경우 O(V + E)의 시간 복잡도를 사용한다.

### 공간 복잡도

유니온 파인드에 O(V)의 공간 복잡도를 사용한다.

### 유니온 파인드

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      27      |  O(V + E)   |    O(V)     |

각 간선을 순회하며 사이클이 생기는 간선을 제외한다.

이 때 간선끼리의 연결을 유니온 파인드를 사용해 사이클이 생기는지 확인한다.

```cpp
int solution(int n, int m, vector<pair<int, int>> &edges) {
  vector<int> parents(n + 1);
  for (int i = 1; i <= n; i++) {
    parents[i] = i;
  }

  function<int(int)> find = [&](int x) {
    if (parents[x] != x) {
      parents[x] = find(parents[x]);
    }
    return parents[x];
  };
  function<void(int, int)> merge = [&](int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) {
      return;
    }

    if (a > b) swap(a, b);

    parents[b] = a;
  };

  int answer = 0;
  for (auto &edge : edges) {
    int a = edge.first;
    int b = edge.second;

    if (find(a) == find(b)) {
      answer++;
      continue;
    }

    merge(a, b);
  }

  return answer;
}
```

## 고생한 점
