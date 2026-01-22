# D - Paid Walk

[링크](https://atcoder.jp/contests/abc441/tasks/abc441_d)

| 난이도 |
| :----: |
|  400   |

## 설계

### 시간 복잡도

노드의 수를 V, 간선의 수를 E, 탐색할 path의 수를 L이라 하자.

각 노드별 out degree는 최대 4이다.

모든 경로를 탐색하며 백트래킹을 이용해 가능한 경로를 탐색한다.

노드의 중복방문이 가능한 깊이가 제한된 탐색이므로 시간 복잡도는 O(4^L)이다.

그래프를 생성하는데 O(V + E)의 시간이 필요하다.

이후 정답 집합을 정렬하는데 O(V log V)의 시간이 필요하다.

따라서 총 시간 복잡도는 O(V \* log_2(V) + E + 4^L)이다.

### 공간 복잡도

DFS 탐색에 O(L)의 스택 공간이 필요하다.

그래프에 O(V + E)의 공간이 필요하다.

따라서 전체 공간 복잡도는 O(V + E + L)이다.

### 완전 탐색 & DFS

| 내 코드 (ms) |        시간 복잡도         | 공간 복잡도  |
| :----------: | :------------------------: | :----------: |
|     134      | O(V \* log_2(V) + E + 4^L) | O(V + E + L) |

그래프를 생성한 뒤 1번 노드부터 탐색을 진행한다.

이 때 지나온 간선의 합이 가능한 정답의 범위를 넘어서는 경우 탐색을 중단한다.

L개의 간선을 지나온 뒤 비용이 가능한 범위에 속하는 경우 정답 집합에 노드를 추가한다.

이후 정답 집합을 정렬하여 반환한다.

```cpp
struct Edge {
  int from, to, cost;
};

void dfs(int node, int passed, int limit, const vector<vector<Edge>>& graph,
         long long cost, long long s, long long t, set<int>& answer) {
  if (passed == limit) {
    if (s <= cost && cost <= t) {
      answer.insert(node);
    }
    return;
  }

  for (const Edge& e : graph[node]) {
    if (cost + e.cost > t) {
      continue;
    }

    dfs(e.to, passed + 1, limit, graph, cost + e.cost, s, t, answer);
  }
}

vector<int> solution(int n, int size, int limit, long long s, long long t, vector<Edge>& edges) {
  vector<int> answer;
  set<int> answerSet;

  vector<vector<Edge>> graph(n + 1);
  for (Edge& e : edges) {
    graph[e.from].push_back(e);
  }

  dfs(1, 0, limit, graph, 0, s, t, answerSet);

  for (int node : answerSet) {
    answer.push_back(node);
  }

  return answer;
}
```

## 고생한 점
