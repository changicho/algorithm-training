# 1059. All Paths from Source Lead to Destination

[링크](https://leetcode.com/problems/all-paths-from-source-lead-to-destination/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 개수를 V, 간선의 개수를 E라고 하자.

DFS를 이용해 사이클을 제외하고 탐색할 경우 O(V + E)의 시간 복잡도를 사용한다.

### 공간 복잡도

그래프 관계를 표현하는데 O(E)의 공간 복잡도를 사용한다.

call stack에는 최대 V개 까지 쌓일 수 있으므로 O(V)의 공간 복잡도를 사용한다.

따라서 공간 복잡도는 O(V + E)가 된다.

### DFS with color

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      64      |  O(V + E)   |  O(V + E)   |

유향 비순환 그래프(Directed Acyclic Graph, DAG)를 찾는 문제이다.

사이클이 없는 유향 그래프를 찾는다.

이 때 노드는 다음 3가지 상태를 가진다.

- WHITE : 방문하지 않은 노드
- GRAY : 이웃 노드들 중에서 WHITE 노드가 존재하는 노드
- BLACK : 이웃 노드들 중에서 WHITE 노드가 존재하지 않는 노드

DFS를 진행하며 각 노드들의 현재 상태를 call stack에서 이용하고 이를 갱신하다.

path가 source ~ destination 인지 검사해야 하므로 만약 destination 노드에서 outgoing( 나가는) edge가 존재하는 경우 정답이 나올 수 없다.

따라서 from ~ to 구간이 DAG인지 여부를 다음과 같이 판단할 수 있다.

- outgoing 간선이 없는 경우 현재 노드가 도착점인지

현재 노드의 상태에 따라서 다음 상태들이 존재한다.

- BLACK : 이미 이전에 해당 노드에 대해서 모두 노드이므로 아무것도 하지 않는다.
- WHITE : GRAY 색으로 채우고 이웃 노드들에 대해서 DAG인지 판별한다.
- GRAY : false를 반환한다. 이는 이전에 방문한 노드를 재방문 했으므로 사이클이 존재하기 때문이다.

따라서 DFS로 탐색할 때 현재 구간에서 이웃 노드들에 사이클이 있는지 여부를 판별하며 DAG인지를 판단한다.

이를 구현하면 다음과 같다.

```cpp
enum Color {
  WHITE,  // never visited
  GRAY,   // there are white neighber
  BLACK   // there are no white neighber
};
vector<Color> colors;
vector<vector<int>> graph;

bool isAcyclic(int from, int to) {
  if (colors[from] == Color::BLACK) return true;
  if (colors[from] == Color::GRAY) return false;
  if (graph[from].empty()) return from == to;

  colors[from] = Color::GRAY;

  for (const int &next : graph[from]) {
    bool hasCycle = !isAcyclic(next, to);
    if (hasCycle) return false;
  }

  colors[from] = Color::BLACK;
  return true;
}

bool leadsToDestination(int n, vector<vector<int>> &edges, int source, int destination) {
  colors.resize(n, Color::WHITE);

  graph.assign(n, vector<int>());
  for (const vector<int> &edge : edges) {
    graph[edge[0]].push_back(edge[1]);
  }

  return isAcyclic(source, destination);
}
```

## 고생한 점
