# 2050. Parallel Courses III

[링크](https://leetcode.com/problems/parallel-courses-iii/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

그래프의 노드의 갯수를 V, 간선의 갯수를 E이라 하자.

각 노드마다 선행하는 노드들이 존재하므로 위상정렬을 이용해 탐색할 수 있다.

이 경우 O(V + E)의 시간 복잡도를 사용한다.

### 공간 복잡도

위상 정렬에 O(V + E)의 공간 복잡도를 사용한다.

### 위상 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     292      |  O(V + E)   |  O(V + E)   |

각 코스들 별로 선행해야 하는 코스들이 존재하며 이를 모두 선행해야 코스를 진행할 수 있다.

따라서 위상 정렬을 이용해 각 코스들을 진행할 수 있는지 검사한다.

각 과정마다 해당 코스들을 방문한 최대 시간을 저장하고 갱신해나간다.

```cpp
int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
  vector<vector<int>> graph(n);
  vector<int> inDegrees = vector(n, 0);

  for (vector<int>& edge : relations) {
    int x = edge[0] - 1;
    int y = edge[1] - 1;
    graph[x].push_back(y);
    inDegrees[y]++;
  }

  queue<int> q;
  vector<int> maxTime = vector(n, 0);

  for (int node = 0; node < n; node++) {
    if (inDegrees[node] == 0) {
      q.push(node);
      maxTime[node] = time[node];
    }
  }

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    for (int& next : graph[node]) {
      maxTime[next] = max(maxTime[next], maxTime[node] + time[next]);
      inDegrees[next]--;

      if (inDegrees[next] == 0) {
        q.push(next);
      }
    }
  }

  int answer = 0;
  for (int node = 0; node < n; node++) {
    answer = max(answer, maxTime[node]);
  }

  return answer;
}
```

## 고생한 점
