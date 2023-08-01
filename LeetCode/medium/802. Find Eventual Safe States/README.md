# 802. Find Eventual Safe States

[링크](https://leetcode.com/problems/find-eventual-safe-states/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

그래프의 노드의 갯수를 N, 간선의 갯수를 M이라 하자.

간선을 순회하며 역방향 그래프를 생성한다. 이에 O(M)의 시간 복잡도를 사용한다.

이후 위상정렬 혹은 DFS를 이용해 사이클이 존재하는 노드와 존재하지 않는 노드를 판별할 수 있다.

이에 O(N + M)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N + M)이다.

### 공간 복잡도

역방향 그래프를 생성할 때 O(M)의 공간 복잡도를 사용한다.

진입차수, 방문여부등을 체크하는데 O(N)의 공간 복잡도를 사용한다.

### 위상 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     215      |  O(N + M)   |  O(N + M)   |

terminal node는 해당 노드에서 나가는 간선이 없는 노드이다.

특정 노드에서의 모든 경로가 terminal node에 해당하는 경우는 해당 노드에서 시작하는 경로중에 사이클이 없는 경우이다.

따라서 반대로 말하면 사이클을 생성하는, 연결된 노드들을 제외한 노드들을 정답으로 반환할 수 있다.

이 때 사이클에 연결된 노드들을 판단하기 위해 그래프의 방향을 뒤집은 역그래프를 사용한다.

터미널노드에서부터 탐색을 시작해 진입차수를 줄여나가며 진입차수가 0인 노드들을 정답에 추가한다.

만약 사이클, 사이클에 연결된 노드인 경우 진입차수가 끝까지 줄어들지 않는다.

이를 구현하면 다음과 같다.

```cpp
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
  int size = graph.size();
  vector<int> inDegrees(size);
  vector<vector<int>> reverseGraph(size);

  for (int node = 0; node < size; node++) {
    for (int& next : graph[node]) {
      reverseGraph[next].push_back(node);
      inDegrees[node]++;
    }
  }

  queue<int> q;
  for (int node = 0; node < size; node++) {
    if (inDegrees[node] == 0) {
      q.push(node);
    }
  }

  vector<bool> isSafe(size);
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    isSafe[node] = true;

    for (int& next : reverseGraph[node]) {
      inDegrees[next]--;
      if (inDegrees[next] == 0) {
        q.push(next);
      }
    }
  }

  vector<int> safeNodes;
  for (int node = 0; node < size; node++) {
    if (isSafe[node]) {
      safeNodes.push_back(node);
    }
  }
  return safeNodes;
}
```

## 고생한 점
