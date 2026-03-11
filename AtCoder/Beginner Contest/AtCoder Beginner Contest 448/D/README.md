# D - Integer-duplicated Path

[링크](https://atcoder.jp/contests/abc448/tasks/abc448_d)

| 난이도 |
| :----: |
|  400   |

## 설계

### 시간 복잡도

그래프의 노드의 수를 V, 간선의 수를 E라 하자.

DFS를 이용해 1번 노드부터 그래프를 탐색하며 방문한 노드의 값들을 카운트해 중복된 값이 있는지 판단한다.

이 경우 DFS의 시간 복잡도는 O(V + E)이다.

### 공간 복잡도

그래프에 O(V + E), 방문 여부에 O(V), 값의 카운트에 O(V) 만큼의 공간이 필요하다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     233      |  O(V + E)   |  O(V + E)   |

1번 노드부터 다른 모든 노드를 방문할 때 방분한 노드들의 값을 같이 저장한다.

1번부터 DFS로 탐색하며 각 노드마다 방문한 노드들의 값이 중복되는지 확인한다.

DFS로 노드를 방문 후 복귀할 때 방문한 노드의 값을 카운트에서 제거한다.

```cpp
struct Edge {
  int from, to;
};

vector<bool> solution(int size, vector<int>& nums, vector<Edge>& edges) {
  vector<bool> answer(size);

  vector<vector<int>> graph(size + 1);
  for (Edge& e : edges) {
    graph[e.from].push_back(e.to);
    graph[e.to].push_back(e.from);
  }

  unordered_set<int> visited;
  multiset<int> values;
  unordered_map<int, int> counts;

  function<void(int, bool)> dfs = [&](int node, bool hasSame) {
    visited.insert(node);

    int val = nums[node - 1];
    counts[val]++;

    if (counts[val] >= 2) {
      hasSame |= true;
    }
    answer[node - 1] = hasSame;

    for (int next : graph[node]) {
      if (visited.count(next)) continue;
      dfs(next, hasSame || counts[val] >= 2);
    }

    counts[val]--;
  };

  dfs(1, false);

  return answer;
}
```

## 고생한 점
