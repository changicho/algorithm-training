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

임의의 노드를 루트로 지정하고 트리를 루트부터 탐색하며 각 노드가 루트인 서브트리의 아래 2가지 값을 구한다.

- 서브트리의 자식 노드들의 cost들의 합
- 루트 노드부터 다른 노드들까지 distance와 각 cost만큼 가중치의 합

이를 완료하면 지정한 임의의 루트 노드를 기준으로 다른 노드들까지의 거리와 cost의 합을 구할 수 있다. (정답의 후보 중 하나)

이후 다시 임의의 루트 노드에서부터 DFS로 탐색을 진행하며 각 노드가 루트가 되었을 때의 정답을 구한다.

각 노드가 새로운 루트가 되었을 때 다음과 같은 변동사항이 발생한다.

- 새로운 루트와 가까워진 노드들은 depth(거리)가 1씩 줄어든다.
- 새로운 루트와 멀어진 노드들은 depth(거리)가 1씩 증가한다.

거리가 1씩 증가하는 경우 멀어지는 costs 만큼 증가시켜야 하며 거리가 1씩 줄어드는 경우 가까워지는 costs 만큼 감소시켜야 한다.

여기서 가까워지는 노드들은 해당 노드를 subTree의 루트로 하는 자식 노드들로, 멀어지는 노드들은 그 외 노드들로 생각할 수 있다.

따라서 감소하는 costs들과 증가하는 costs들은 이미 구해놨으므로 바로 계산이 가능하다.

```cpp
long long solution(int n, vector<Edge> &edges, vector<long long> &costs) {
  vector<vector<int>> graph(n);
  for (Edge &edge : edges) {
    int a = edge.a - 1, b = edge.b - 1;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  long long costSum = accumulate(costs.begin(), costs.end(), 0LL);
  long long costsFromRoot = 0;
  long long answer = LLONG_MAX;
  vector<long long> subTreeCostSums(n, 0);

  function<void(int, int, int)> preProcess = [&](int node, int parent, int depth) -> void {
    costsFromRoot += costs[node] * depth;
    subTreeCostSums[node] += costs[node];

    for (int &child : graph[node]) {
      if (child == parent) continue;

      preProcess(child, node, depth + 1);
      subTreeCostSums[node] += subTreeCostSums[child];
    }
  };

  function<void(int, int, long long)> recursive =
      [&](int node, int parent, long long curCost) -> void {
    answer = min(answer, curCost);

    for (int &child : graph[node]) {
      if (child == parent) continue;

      long long curPartSum = subTreeCostSums[child];
      long long otherPartSum = costSum - subTreeCostSums[child];

      long long nextCost = curCost - curPartSum + otherPartSum;
      recursive(child, node, nextCost);
    }
  };

  preProcess(0, -1, 0);
  recursive(0, 0, costsFromRoot);

  return answer;
}
```

## 메모

[834. Sum of Distances in Tree](https://leetcode.com/problems/sum-of-distances-in-tree/description/)와 유사한 문제

## 고생한 점
