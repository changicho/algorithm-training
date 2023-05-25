# 1857. Largest Color Value in a Directed Graph

[링크](https://leetcode.com/problems/largest-color-value-in-a-directed-graph/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

노드의 갯수를 N, 간선의 갯수를 E라 하자.

그래프를 생성하는 데 O(E)의 시간 복잡도를 사용한다.

이후 각 노드에 대해서 진입차수가 낮은 노드부터 탐색을 진행하며 각 경우마다 지나온 노드들의 색상을 카운트 해서 넘겨준다.

사이클이 존재하는 경우 -1을 반환하면 되므로 위상 정렬을 이용한다.

이 경우 시간 복잡도는 O(N + E)이다.

### 공간 복잡도

위상 정렬을 사용하는데 O(N)의 공간 복잡도를 사용한다. 그래프를 생성하는데 O(E)의 공간 복잡도를 사용한다.

### 위상 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     621      |  O(N + E)   |  O(N + E)   |

진입차수가 0인 노드부터 순회하며 BFS를 진행한다.

이 때 사이클이 존재하는 경우 모든 노드를 방문하지 않은 채로 탐색이 종료된다.

각 단계를 진행하며, 현재 노드의 색을 증가시킨다.

따라서 각 노드를 방문할 때마다 현재까지 노드를 방문했을 때 방문한 색의 갯수들을 갖고있다.

따라서 각 노드를 방문하며 정답을 갱신한다.

```cpp
int largestPathValue(string colors, vector<vector<int>>& edges) {
  int size = colors.size();
  vector<vector<int>> graph(size);
  vector<int> inDegree(size);

  for (vector<int>& edge : edges) {
    int from = edge[0], to = edge[1];
    graph[from].push_back(to);
    inDegree[to]++;
  }

  vector<vector<int>> counts(size, vector<int>(26, 0));
  queue<int> q;

  for (int node = 0; node < size; node++) {
    if (inDegree[node] == 0) {
      q.push(node);
    }
  }

  int answer = 0, nodesSeen = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    // increase current color
    int curColor = colors[cur] - 'a';
    counts[cur][curColor]++;
    answer = max(answer, counts[cur][curColor]);
    nodesSeen++;

    for (int& next : graph[cur]) {
      for (int color = 0; color < 26; color++) {
        counts[next][color] = max(counts[next][color], counts[cur][color]);
      }

      inDegree[next]--;
      if (inDegree[next] == 0) {
        q.push(next);
      }
    }
  }

  return nodesSeen < size ? -1 : answer;
}
```

## 고생한 점
