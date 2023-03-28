# 2360. Longest Cycle in a Graph

[링크](https://leetcode.com/problems/longest-cycle-in-a-graph/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

그래프의 노드의 갯수를 N이라 하자. (N <= 10^5)

간선의 갯수는 노드의 갯수보다 작거나 같다.

위상 정렬을 사용할 경우 사이클이 존재하는 지 확인할 수 있다.

위상정렬을 수행 후, 방문하지 않은 정점들에 대해 탐색을 수행하며 이중 최대 길이를 반환한다.

위상정렬의 시간 복잡도는 O(N)이다. 이후 탐색을 수행하며 최대 길이를 구하는데 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

위상 정렬을 사용할 경우 O(N)의 공간 복잡도가 필요하다.

### 위상 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     175      |    O(N)     |    O(N)     |

간선을 순회하며 각 노드에 대해 진입 차수들을 구한다.

이 때 간선이 없는 경우가 존재함에 유의한다.

이후 진입차수가 0인 노드들 부터 위상 정렬을 수행한다.

각 과정마다 다음 노드를 방문하며 방문할 다음 노드의 진입 차수를 감소시킨다.

이 과정에서 사이클이 존재할 경우 모든 노드를 방문하지 않은 채 탐색이 종료된다.

이후 방문하지 않은 노드(사이클 존재)를 시작점으로 BFS, DFS 탐색을 수행해 최대 사이클의 길이를 구한다.

```cpp
int longestCycle(vector<int>& edges) {
  int size = edges.size();
  vector<bool> visit(size);
  vector<int> inDegrees(size);

  for (int edge : edges) {
    if (edge != -1) {
      inDegrees[edge]++;
    }
  }

  queue<int> q;
  for (int node = 0; node < size; node++) {
    if (inDegrees[node] == 0) {
      q.push(node);
    }
  }

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    visit[node] = true;
    int neighbor = edges[node];
    if (neighbor != -1) {
      inDegrees[neighbor]--;
      if (inDegrees[neighbor] == 0) {
        q.push(neighbor);
      }
    }
  }

  int answer = -1;
  for (int node = 0; node < size; node++) {
    if (!visit[node]) {
      int next = edges[node];
      int length = 1;
      visit[node] = true;

      while (next != node) {
        visit[next] = true;
        length++;
        next = edges[next];
      }
      answer = max(answer, length);
    }
  }

  return answer;
}
```

## 고생한 점
