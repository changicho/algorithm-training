# 3310. Remove Methods From Project

[링크](https://leetcode.com/problems/remove-methods-from-project/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 수를 N, 간선의 수를 M이라 하자.

간선을 이용해 그래프를 생성 후 문제가 있는 노드부터 탐색을 진행할 수 있다. 이에 O(N + M)의 시간 복잡도를 사용한다.

이 때 각 진입차수와 방문 여부를 이용해 삭제할 수 있는 노드들을 판단한다. 이후 정답을 생성하는데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

그래프와 방문 여부에 O(N + M)의 공간 복잡도를 사용한다.

### BFS & 진입차수

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     161      |  O(N + M)   |  O(N + M)   |

문제가 있는 노드부터 탐색을 진행하며 영향을 받는 노드들의 목록을 찾을 수 있다.

이 때 해당 영향을 받는 노드들 중에 정상 노드에서 진입차수가 존재하는 경우 해당 그룹은 삭제가 불가능하다.

만약 해당 노느들의 모두 정상 노드에서 진입차수가 없는 경우 해당 그룹은 삭제가 가능하다.

따라서 그래프를 생성시 진입차수를 증가시키고, 탐색을 진행하며 진입차수를 감소시킨다.

이후 각 노드의 방문 여부와 남은 진입차수를 이용해 정답을 생성한다.

```cpp
vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
  vector<vector<int>> edges(n);
  vector<int> inDegree(n, 0);

  bool visited[100001] = {
      false,
  };

  for (vector<int>& e : invocations) {
    int a = e[0], b = e[1];
    edges[a].push_back(b);
    inDegree[b]++;
  }

  queue<int> q;
  q.push(k);
  visited[k] = true;

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : edges[u]) {
      inDegree[v]--;

      if (!visited[v]) {
        q.push(v);
        visited[v] = true;
      }
    }
  }

  bool canRemoveAll = true;
  vector<int> answer;

  for (int i = 0; i < n; i++) {
    if (visited[i] && inDegree[i] > 0) {
      canRemoveAll = false;
      break;
    } else if (!visited[i]) {
      answer.push_back(i);
    }
  }

  if (!canRemoveAll) {
    vector<int> allNodes(n);
    iota(allNodes.begin(), allNodes.end(), 0);
    return allNodes;
  }

  return answer;
}
```

## 고생한 점
