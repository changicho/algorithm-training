# 1129. Shortest Path with Alternating Colors

[링크](https://leetcode.com/problems/shortest-path-with-alternating-colors/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 갯수를 N, 간선의 갯수를 E라 하자.

BFS를 이용해 각 단계별로 색을 변경해가며 이동할 수 있다.

이 경우 각 노드와 간선의 순회에 O(N + E)의 시간 복잡도를 사용한다.

### 공간 복잡도

간선을 그래프로 표현하는 데 O(E) BFS를 수행하는데 O(N)의 공간 복잡도를 사용한다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      16      |  O(N + E)   |  O(N + E)   |

시작 노드에서부터 현재 방문할 수 있는 간선의 색이 red, blue인 경우에 대해서 BFS를 수행한다.

이 때 각 정점까지의 거리중 최소가 되는 경우에 대해 순회를 지속하며, 각 정점을 어떤 색으로 방문했는지에 따라 2가지 값이 존재할 수 있다.

이를 구현하면 다음과 같다.

```cpp
vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges) {
  vector<vector<int>> graphRed(n), graphBlue(n);

  for (vector<int> &e : redEdges) {
    int from = e[0], to = e[1];
    graphRed[from].push_back(to);
  }
  for (vector<int> &e : blueEdges) {
    int from = e[0], to = e[1];
    graphBlue[from].push_back(to);
  }

  vector<vector<int>> dists(2, vector<int>(n, INT_MAX));
  queue<pair<int, int>> q;  // node, color
  q.push({0, 0});           // 0 : red
  q.push({0, 1});           // 1 : blue

  int step = 0;
  while (!q.empty()) {
    int size = q.size();
    while (size--) {
      pair<int, int> cur = q.front();

      int node = cur.first, color = cur.second;
      q.pop();
      if (dists[color][node] < step) continue;
      dists[color][node] = step;

      if (color % 2 == 0) {
        // pick blue
        for (int &next : graphBlue[node]) {
          q.push({next, 1});
        }
      } else {
        // pick red
        for (int &next : graphRed[node]) {
          q.push({next, 0});
        }
      }
    }
    step++;
  }

  vector<int> answer(n);
  for (int i = 0; i < n; i++) {
    answer[i] = min(dists[0][i], dists[1][i]);
    if (answer[i] == INT_MAX) answer[i] = -1;
  }
  return answer;
}
```

## 고생한 점
