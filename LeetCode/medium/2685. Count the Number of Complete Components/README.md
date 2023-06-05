# 2685. Count the Number of Complete Components

[링크](https://leetcode.com/problems/count-the-number-of-complete-components/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

그래프의 노드의 갯수를 V, 간선의 갯수를 E라 하자.

connected component를 구하기 위해 해당 서브 그래프의 간선의 수와 정점의 수를 이용할 수 있다.

이 경우 DFS를 이용해 탐색할 때 시간 복잡도는 O(V + E)이다.

### 공간 복잡도

그래프를 생성하는 데 O(E)의 공간 복잡도를 사용한다.

정점의 방문 여부를 판단하기 위해 O(V)의 공간 복잡도가 필요하다.

### DFS & connected component

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     253      |  O(V + E)   |  O(V + E)   |

하나의 서브 그래프가 connected component인지 정의는 다음과 같다.

- 한 정점에서 다른 정점으로 가는 간선이 모두 존재
- 외부 서브그래프와 연결되지 않음

서브 그래프의 노드의 수와 간선의 수를 이용해 connected component인지 판단할 수 있다.

- 한 노드에서 다른 노드로 가는 간선들만 존재한다.
- 이는 각 노드에 연결된 간선의 수의 합이 (노드의 수) * (노드의 수 - 1)인 경우이다.
- 한 노드에서 다른 노드로 가는 간선의 수 = (노드의 수 - 1)
- 이를 모든 노드에 대해 구하므로

따라서 이를 이용해 방문하지 않은 정점들을 방문하며, 해당 노드를 시작점으로 서브 그래프를 탐색함과 동시에 connected component인지 판단할 수 있다.

```cpp
bool visited[51] = {
    false,
};

vector<vector<int>> graph;
int answer = 0;

void recursive(int node, int &nodeCount, int &edgeCount) {
  if (visited[node]) {
    return;
  }
  visited[node] = true;

  nodeCount++;
  edgeCount += graph[node].size();

  for (int &next : graph[node]) {
    recursive(next, nodeCount, edgeCount);
  }
}

int countCompleteComponents(int n, vector<vector<int>> &edges) {
  graph.resize(n);

  for (vector<int> &e : edges) {
    int from = e[0], to = e[1];

    graph[from].push_back(to);
    graph[to].push_back(from);
  }

  int answer = 0;
  for (int node = 0; node < n; node++) {
    if (visited[node]) continue;

    int nodeCount = 0, edgeCount = 0;
    recursive(node, nodeCount, edgeCount);
    if (nodeCount * (nodeCount - 1) == edgeCount) {
      answer++;
    }
  }
  return answer;
}
```

## 고생한 점
