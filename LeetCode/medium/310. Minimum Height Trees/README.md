# 310. Minimum Height Trees

[링크](https://leetcode.com/problems/minimum-height-trees/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 V, 간선의 갯수를 E라 하자.

위상 정렬을 이용해 리프 노드부터 제거하며 중앙 노드를 찾는다.

이 경우 O(V + E)의 시간 복잡도가 소요된다.

### 공간 복잡도

그래프에 O(V + E)의 공간 복잡도가 필요하다.

### 위상 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      86      |  O(V + E)   |  O(V + E)   |

트리의 중점들을 찾기 위해 위상 정렬을 이용한다.

리프 노드에서부터 단계별로 삭제하며, 모든 노드가 삭제 직전 큐에 남은 노드들이 정답이 된다.

따라서 단계별 위상 정렬을 수행한다.

```cpp
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
  if (n == 1) {
    return {0};
  }
  vector<vector<int>> graph(n);
  vector<int> inDegrees(n);

  for (vector<int>& e : edges) {
    int a = e[0], b = e[1];
    graph[a].push_back(b);
    graph[b].push_back(a);

    inDegrees[a]++;
    inDegrees[b]++;
  }

  queue<int> q;
  queue<int> temp;
  for (int node = 0; node < n; node++) {
    if (inDegrees[node] == 1) {
      q.push(node);
      inDegrees[node] = 0;
    }
  }

  int step = 0;
  vector<int> answer;
  while (!q.empty()) {
    int size = q.size();
    temp = q;

    while (size--) {
      int cur = q.front();
      q.pop();

      for (int& next : graph[cur]) {
        inDegrees[next]--;

        if (inDegrees[next] == 1) {
          q.push(next);
        }
      }
    }
  }

  while (!temp.empty()) {
    answer.push_back(temp.front());
    temp.pop();
  }

  return answer;
}
```

## 고생한 점
