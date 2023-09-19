# 1136. Parallel Courses

[링크](https://leetcode.com/problems/parallel-courses/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 갯수를 V, 간선의 갯수를 E라 하자. (단방향 간선)

각 강의마다 우선되는 강의들이 존재하므로 위상 정렬을 이용해 풀이할 수 있다.

이 경우 O(V + E)의 시간 복잡도를 사용한다.

### 공간 복잡도

간선 정보로 그래프를 생성하는데 O(V + E)의 공간 복잡도를 사용한다.

### 위상 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      40      |  O(V + E)   |  O(V + E)   |

간선 정보를 이용해 단방향 그래프를 생성한다.

이후 위상정렬을 수행하며 각 단계마다 step을 증가시킨다.

이 때 모든 노드를 방문하지 않은 경우 -1을 반환한다.

```cpp
int minimumSemesters(int n, vector<vector<int>> &relations) {
  vector<vector<int>> graph(n);

  vector<int> inDegrees(n, 0);

  for (auto &r : relations) {
    int from = r[0] - 1, to = r[1] - 1;
    graph[from].push_back(to);
    inDegrees[to]++;
  }

  queue<int> q;
  vector<bool> visited(n);
  int visitedCount = 0;
  for (int i = 0; i < n; i++) {
    if (inDegrees[i] == 0) q.push(i);
  }
  int answer = 0;

  while (!q.empty()) {
    int size = q.size();
    answer++;
    while (size--) {
      int cur = q.front();
      q.pop();

      if (visited[cur]) continue;
      visited[cur] = true;
      visitedCount++;

      for (int &next : graph[cur]) {
        inDegrees[next]--;

        if (inDegrees[next] == 0) q.push(next);
      }
    }
  }

  if (visitedCount < n) return -1;
  return answer;
}
```

## 고생한 점
