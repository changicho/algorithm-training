# 2603. Collect Coins in a Tree

[링크](https://leetcode.com/problems/collect-coins-in-a-tree/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

coins의 크기를 N, 간선의 갯수 edges의 크기를 E라 하자.

우선 그래프를 만드는 데 O(E)의 시간 복잡도를 사용한다.

리프 노드를 지워가며 남은 노드의 수를 이용해 정답을 구할 수 있다.

이 경우 리프 노드를 지우는 데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

그래프를 표현하는 데 O(E)의 공간 복잡도를 사용한다.

각 노드마다의 이동 단계를 표현하는 데 O(N)의 공간 복잡도를 사용한다.

### 리프 지우기

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     789      |  O(N + E)   |  O(N + E)   |

그래프에서 필요 없는 노드들을 지우고 남은 노드에 대해 간선의 길이를 구할 수 있다.

이는 처음시작위치로 왕복해 돌아오기 위해 각 간선마다 2번씩 이동해야 하며, 각 간선은 남은 노드들의 수에 영향을 받기 때문이다.

리프 노드에서 부터 필요 없는 노드들을 지워나간다.

이 과정중에 coin의 값이 1인 노드들은 최대 1번의 이동만 가능하다. (coin이 1인 노드의 경우 상위 2번째 노드에서 접근 가능하므로 부모까지만 지울 수 있음)

연결된 간선의 갯수가 1개인 리프 노드부터 탐색을 진행하며, 각 과정마다 연결된 노드들의 이동 단계를 갱신하며 가능한 만큼만 이동한다.

```cpp
int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
  int size = coins.size();

  vector<vector<int>> graph(size);
  for (vector<int>& e : edges) {
    int from = e[0], to = e[1];

    graph[from].push_back(to);
    graph[to].push_back(from);
  }

  vector<int> neighbors(size), steps(size, INT_MAX);
  stack<int> stk;

  // find leaf nodes
  for (int node = 0; node < size; node++) {
    neighbors[node] = graph[node].size();

    if (neighbors[node] == 1) stk.push(node);
  }

  // erase leaf nodes 2 steps
  int remainNode = size;
  while (!stk.empty()) {
    int cur = stk.top();
    stk.pop();

    steps[cur]--;
    if (steps[cur] == 0) continue;
    remainNode--;

    for (int next : graph[cur]) {
      steps[next] =
          min({steps[next], steps[cur], coins[cur] == 1 ? 2 : INT_MAX});

      neighbors[next]--;
      if (neighbors[next] == 1) stk.push(next);
    }
  }

  return 2 * max(0, remainNode - 1);
}
```

## 고생한 점
