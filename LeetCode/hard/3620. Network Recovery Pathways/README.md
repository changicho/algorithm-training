# 3620. Network Recovery Pathways

[링크](https://leetcode.com/problems/network-recovery-pathways/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

그래프의 노드의 수를 V, 간선의 수를 E, 비용의 최대값을 C라 하자.

가능한 경로의 최소비용을 이분탐색으로 탐색하며 가능한지 그래프를 탐색할 수 있다.

이분 탐색에 O(log_2(C))의 시간 복잡도를 사용한다.

탐색에 다이크스트라를 사용할 경우 O((E + V) \* log_2(V))의 시간 복잡도를 사용한다.

방문배열을 사용한 DFS를 사용할 경우 O(E + V)의 시간 복잡도를 사용한다.

### 공간 복잡도

그래프 및 탐색에 O(V + E)의 공간 복잡도를 사용한다.

### 이분 탐색 & DFS

| 내 코드 (ms) |      시간 복잡도       | 공간 복잡도 |
| :----------: | :--------------------: | :---------: |
|     106      | O((V + E) \* log_2(C)) |  O(V + E)   |

주어진 문제 조건에 맞는 `가능한 경로에서 각 cost들 중 최소값이 X 이상` 인지 확인하는 함수를 만든다.

해당 함수는 DFS로 0번 노드부터 탐색을 진행하며 top-down 방식으로 반환시 해당 노드가 시작점으로 마지막 노드까지 도달하는 최소 비용을 갖는다.

해당 비용을 저장 후 중복방문시 이미 값이 있으면 재사용한다.

이후 X를 이분 탐색으로 구하며 정답을 갱신한다.

```cpp
struct Edge {
  int a, b;
  long long c;

  bool operator<(const Edge& b) const { return c > b.c; }
};

bool check(vector<vector<Edge>>& graph, vector<bool>& online, int limit, long long k) {
  int size = online.size();

  vector<long long> dp(size + 1, -1);

  auto recursive = [&](this auto&& recursive, int u) -> long long {
    if (u == size - 1) {
      return 0;
    }
    if (dp[u] != -1) {
      return dp[u];
    }
    long long ret = LLONG_MAX / 2;
    for (auto& [a, b, c] : graph[u]) {
      if (c < limit) continue;

      long long newCost = recursive(b) + c;
      ret = min(ret, newCost);
    }
    return dp[u] = ret;
  };

  return recursive(0) <= k;
}

int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
  int size = online.size();
  vector<vector<Edge>> graph(size + 1);

  int left = INT_MAX, right = 0;

  for (vector<int>& e : edges) {
    int a = e[0], b = e[1], c = e[2];

    if (!online[a] || !online[b]) continue;

    left = min(left, c);
    right = max(right, c);

    graph[a].push_back({a, b, c});
  }

  if (!check(graph, online, left, k)) return -1;

  int answer = -1;
  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (check(graph, online, mid, k)) {
      left = mid + 1;
      answer = max(answer, mid);
    } else {
      right = mid - 1;
    }
  }

  return answer;
}
```

## 고생한 점
