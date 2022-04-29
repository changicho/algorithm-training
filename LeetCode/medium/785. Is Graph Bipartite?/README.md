# 785. Is Graph Bipartite?

[링크](https://leetcode.com/problems/is-graph-bipartite/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

그래프의 노드의 갯수를 V, 간선의 갯수를 E라 하자.

각 노드에 대해서 특정 노드를 시작점으로 연관된 노드를 색을 칠하며 탐색을 진행한다.

이 과정에 O(V + E)의 시간 복잡도를 사용한다.

이 과정에서 Bipartite가 아닌지 판단이 가능하다.

따라서 시간 복잡도는 O(V + E)이다.

### 공간 복잡도

색을 칠할 공간이 필요하므로 O(V)만큼의 공간 복잡도를 사용한다.

### BFS with colors

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      41      |  O(V + E)   |    O(V)     |

맨 처음 모든 노드의 색을 칠하지 않은 색 -1로 설정한다.

이후 각 노드를 순차적으로 방문하며 색을 칠하지 않은 노드인 경우 BFS를 이용해 연관된 노드 모두 색을 칠한다.

이 과정에서 현재 색을 칠하며 다음 단계에서 색을 변경한다.

만약 현재 노드의 색이 이미 칠해져있고, 현재 칠해야 하는 색과 반대되는 경우 Bipartite하지 않음을 알 수 있다.

이를 구현하면 다음과 같다.

```cpp
bool isBipartite(vector<vector<int>>& graph) {
  bool answer = true;
  int size = graph.size();

  vector<int> colors(size, -1);
  for (int i = 0; i < size; i++) {
    if (colors[i] != -1) continue;

    queue<int> q;
    int color = 0;
    q.push(i);

    while (!q.empty()) {
      int curSize = q.size();

      while (curSize--) {
        int cur = q.front();
        q.pop();

        if (colors[cur] != -1) {
          if (colors[cur] != color) answer = false;
          continue;
        }

        colors[cur] = color;

        for (int& next : graph[cur]) {
          q.push(next);
        }
      }

      color = color == 0 ? 1 : 0;
    }
  }

  return answer;
}
```

## 고생한 점
