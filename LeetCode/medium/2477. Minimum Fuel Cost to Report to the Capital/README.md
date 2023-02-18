# 2477. Minimum Fuel Cost to Report to the Capital

[링크](https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자. (N <= 10^5)

최소 연료 용량을 찾아야 하며, 연결된 간선을 여러대의 자동차로 환승하며 이동하나 한대의 차로 이동하나 사용한 연료의 양은 같다.

따라서 각 간선마다 필요한 최소 차량 수를 구하고 이를 더할 수 있다.

여기서 DFS로 자식의 수를 count하며 올라올 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

그래프에 O(N)의 공간 복잡도를 사용한다.

DFS를 이용할 경우 트리의 높이만큼 공간 복잡도를 사용하며 이는 최대 O(N)이다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     600      |    O(N)     |    O(N)     |

연결된 간선을 여러대의 자동차로 환승하며 이동하나 한대의 차로 이동하나 사용한 연료의 양은 같다.

따라서 엣지 노드에서부터 루트까지 하나의 차로 이동하지 말고, 각 간선에 대해 필요한 최소 차량수를 구해가며 더한다.

이 때 현재 노드 및 현재노드 아래에 있는 자식노드의 수가 이동해야 하는 인원이며,

이를 자동차의 좌석 수로 나눈 값을 올림 처리해 필요한 차의 수를 구할 수 있다.

이를 구현하면 다음과 같다.

```cpp
vector<vector<int>> graph;
vector<bool> visited;

long long answer = 0;

int recursive(int node, int seats) {
  visited[node] = true;

  int children = 1;
  for (int &next : graph[node]) {
    if (visited[next]) continue;

    children += recursive(next, seats);
  }

  if (node != 0) {
    answer += ceil((double)children / seats);
  }
  return children;
}

long long minimumFuelCost(vector<vector<int>> &roads, int seats) {
  int size = roads.size();

  graph.resize(size + 1);
  visited.resize(size + 1, false);

  for (vector<int> &r : roads) {
    int a = r[0], b = r[1];

    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  recursive(0, seats);

  return answer;
}
```

## 고생한 점
