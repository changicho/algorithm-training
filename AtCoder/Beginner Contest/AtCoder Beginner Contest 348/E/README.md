# E - Minimize Sum of Distances

[링크](https://atcoder.jp/contests/abc348/tasks/abc348_e)

| 난이도 |
| :----: |
|  475   |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

서브트리마다의 합과 카운트를 이용해 풀이할 수 있다.

DFS를 두번 수행하므로 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

DFS에 O(N)의 공간 복잡도를 사용한다.

각 노드를 루트로 하는 서브트리 마다의 합을 저장해야 하므로 O(N)의 공간 복잡도를 사용한다.

### Subtree Sum and Count

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      42      |    O(N)     |    O(N)     |

```cpp
long long solution(int n, vector<Edge> &edges, vector<long long> &costs) {
  vector<vector<int>> graph(n);
  for (Edge &edge : edges) {
    int a = edge.a - 1, b = edge.b - 1;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  long long sum = accumulate(costs.begin(), costs.end(), 0LL);
  long long temp = 0;
  long long answer = 0;
  vector<long long> costSums(n, 0);

  function<void(int, int, int)> preprocess = [&](int node, int parent,
                                                 int depth) -> void {
    for (int &child : graph[node]) {
      if (child == parent) continue;

      preprocess(child, node, depth + 1);
      costSums[node] += costSums[child];
    }

    temp += costs[node] * depth;
    costSums[node] += costs[node];
  };

  function<void(int, int)> recursive = [&](int node, int parent) -> void {
    answer = min(answer, temp);

    for (int &child : graph[node]) {
      if (child == parent) continue;

      temp -= costSums[child];
      temp += sum - costSums[child];
      recursive(child, node);
      temp += costSums[child];
      temp -= sum - costSums[child];
    }
  };

  preprocess(0, 0, 0);
  answer = temp;
  recursive(0, 0);

  return answer;
}
```

## 메모

[834. Sum of Distances in Tree](https://leetcode.com/problems/sum-of-distances-in-tree/description/)와 유사한 문제

## 고생한 점
