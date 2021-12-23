# 886. Possible Bipartition

[링크](https://leetcode.com/problems/possible-bipartition/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 개수를 V, 각 노드마다 싫어하는 다른 노드의 연결 관계를 E라고 하자.

이 노드와 엣지를 그래프 관계로 볼 수 있다.

그래프를 순회하면서 2그룹으로만 나누면 되므로, 각 그래프마다 색을 칠하며 탐색을 진행한다. (두 가지 색)

이 경우 O(V + E)의 시간 복잡도로 풀이가 가능하다.

### 공간 복잡도

그래프의 방문여부와 색을 표현하기 위해 O(V)의 공간 복잡도를 사용한다.

그래프 연결관계를 표현하기 위해 O(V + E)의 공간 복잡도를 사용한다.

### DFS with color

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     168      |  O(V + E)   |  O(V + E)   |

한 노드와 다른 노드가 싫어하는 경우를 연결 관계로 볼 수 있다.

이를 이용해 그래프를 생성한다.

DFS로 탐색을 진행하며 현재 색을 칠하고, 다음 탐색 노드에는 다른 색을 칠한다. (두 가지 색만)

만약 현재 노드에 색이 이미 칠해져있고, 칠하려는 색과 다른 색인경우 팀으로 분할할 수 없으므로 정답은 false가 된다.

만약 이 방법으로 모든 노드를 방문할 수 있는 경우 모든 노드를 2구역으로 나눌 수 있게 된다.

```cpp
vector<vector<int>> graph;
vector<int> visited;  // key:node, value:color
bool answer = true;

void recursive(int node, int color) {
  if (node > graph.size()) return;
  if (visited[node] != 0) {
    if (visited[node] == color) return;
    answer = false;
    return;
  }

  visited[node] = color;
  for (int next : graph[node]) {
    recursive(next, color * -1);
  }
}

bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
  graph.resize(n + 1);
  visited.resize(n + 1);

  for (vector<int>& edge : dislikes) {
    int a = edge[0], b = edge[1];
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for (int i = 1; i <= n; i++) {
    if (visited[i] == 0) {
      recursive(i, 1);
    }
  }

  return answer;
}
```

## 고생한 점
