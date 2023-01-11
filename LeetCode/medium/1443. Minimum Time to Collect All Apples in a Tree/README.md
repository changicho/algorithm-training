# 1443. Minimum Time to Collect All Apples in a Tree

[링크](https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 노드의 갯수를 N, 간선의 수를 E라 하자.

그래프를 생성하는 데 O(E)의 시간 복잡도를 사용한다.

각 노드마다 자식노드에 존재하는 사과의 갯수를 count한다. 이를 DFS로 구현할 경우 O(N)의 시간 복잡도를 사용한다.

이후 루트부터 탐색하며 그리디하게 탐색할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

그래프를 생성하는 데 O(E)의 공간 복잡도를 사용한다. 이후 각 노드마다의 사과의 수, 방문 여부등을 저장하는데 O(N)의 공간 복잡도를 사용한다.

### DFS & greedy

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     179      |  O(N + E)   |  O(N + E)   |

루트 노드에서부터 탐색할 때 만약 현재 노드 이후에 방문하는 모든 노드에 사과가 없는 경우 현재 노드를 방문하지 않아도 된다.

따라서 루트에서부터 순회하며 해당 노드 이후에 방문하는 노드들이 사과가 존재하는지를 탐색한다.

이후 루트에서부터 같은 방식으로 방문하며 사과가 존재하는 경우들만 방문한다.

이 과정에서 자식 노드로 방문할 때 한번, 자식 노드에서 현재 노드로 나올 때 한번 정답 count가 증가한다.

```cpp
vector<vector<int>> graph;
vector<bool> hasApple;
vector<bool> visited;
vector<int> countApple;

int answer = 0;

int recursiveCountApple(int node) {
  visited[node] = true;

  int ret = 0;
  if (hasApple[node]) ret += 1;

  for (int &next : graph[node]) {
    if (visited[next]) continue;

    ret += recursiveCountApple(next);
  }

  return countApple[node] = ret;
}

void recursive(int node) {
  visited[node] = true;

  if (countApple[node] == 0) {
    return;
  }

  for (int &next : graph[node]) {
    if (visited[next]) continue;
    if (countApple[next] == 0) continue;

    answer++;
    recursive(next);
    answer++;
  }
}

int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple) {
  this->hasApple = hasApple;

  graph.resize(n);
  visited.resize(n);
  countApple.resize(n);
  for (vector<int> &e : edges) {
    int a = e.front(), b = e.back();
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  recursiveCountApple(0);

  for (int i = 0; i < n; i++) {
    visited[i] = false;
  }
  recursive(0);

  return answer;
}
```

## 고생한 점
