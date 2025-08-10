# 3613. Minimize Maximum Component Cost

[링크](https://leetcode.com/problems/minimize-maximum-component-cost/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 수를 N, 간선의 수를 M이라 하자.

간선을 정렬 후 cost가 낮은 순으로 연결할 수 있다.

이 때 연결 후 각 컴포넌트의 갯수를 구하기 위해 유니온 파인드를 사용할 수 있다.

정렬에 O(M \* log_2(M))의 시간복잡도를 사용하며 유니온 파인드에 O(N)의 시간복잡도를 사용한다.

### 공간 복잡도

정렬과 유니온 파인드에 O(N + M)의 공간복잡도를 사용한다.

### 유니온 파인드 & 정렬

| 내 코드 (ms) |    시간 복잡도    | 공간 복잡도 |
| :----------: | :---------------: | :---------: |
|     263      | O(N + M * log(M)) |  O(N + M)   |

간선이 없는 모든 노드 상태에서 비용이 작은 간선부터 연결한다.

이 때 간선을 연결 후 컴포넌트의 수가 K 이하인 경우 나머지 간선을 연결하지 않는다.

만약 간선을 연결할 때 이미 연결된 노드일 경우 무시한다.

```cpp
int minCost(int n, vector<vector<int>> &edges, int k) {
  vector<int> parents(n);
  int components = n;
  for (int i = 0; i < n; i++) {
    parents[i] = i;
  }

  function<int(int)> find = [&](int node) {
    if (parents[node] == node) return node;
    return parents[node] = find(parents[node]);
  };

  function<void(int, int)> merge = [&](int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (a > b) swap(a, b);
    components--;

    parents[b] = a;
  };

  sort(edges.begin(), edges.end(),
        [](vector<int> &a, vector<int> &b) { return a[2] < b[2]; });

  int answer = 0;
  for (vector<int> &e : edges) {
    if (components <= k) break;
    int a = e[0], b = e[1], cost = e[2];

    if (find(a) == find(b)) continue;
    merge(a, b);

    answer = max(answer, cost);
  }

  return answer;
}
```

## 고생한 점
