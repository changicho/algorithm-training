# 207. Course Schedule

[링크](https://leetcode.com/problems/course-schedule/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드(과목)들의 개수를 N, 간선(선행)의 개수를 M라고 하자.

위상 정렬을 이용할 경우 O(N + M)의 시간 복잡도로 과목의 순서를 알 수 있다.

이 때 사이클이 발생하는 경우 모든 과목을 순서대로 듣는것이 불가능함에 유의한다.

### 공간 복잡도

각 노드들에 대해 연결 관계를 표현할 그래프가 필요하다.

이에 O(N + M)의 공간 복잡도가 필요하다.

진입 차수를 이용해 풀이하는 경우 각 노드에 대해서 진입차수를 알아야 하므로 O(N)의 공간 복잡도가 필요하다.

DFS를 이용하는 경우 각 방문에 대해서 상태를 표시할 공간이 필요하므로 O(N)의 공간 복잡도가 필요하다.

### 위상 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      20      |  O(N + M)   |  O(N + M)   |

위상 정렬은 순서가 정해져있는 작업 차례로 수행해야 할 때, 그 순서를 결정해주는 알고리즘이다.

위상정렬을 이용해 순서대로 학습할 수 있는 방법을 찾을 수 있다.

이 때 사이클이 존재하는 경우는 순서대로 학습할 수 있는 방법이 없으므로 빈 vector를 반환한다.

진입 차수를 이용한 BFS방법은 다음과 같다.

```cpp
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
  int size = numCourses;
  vector<vector<int>> graph(size);
  vector<int> inDegrees(size, 0);
  vector<int> path;

  for (vector<int>& prerequisite : prerequisites) {
    int from = prerequisite[1], to = prerequisite[0];

    graph[from].emplace_back(to);
    inDegrees[to] += 1;
  }

  queue<int> q;
  for (int node = 0; node < size; node++) {
    if (inDegrees[node] == 0) q.push(node);
  }

  for (int index = 0; index < size; index++) {
    if (q.empty()) return false;
    int node = q.front();
    q.pop();

    path.emplace_back(node);
    for (int next : graph[node]) {
      inDegrees[next] -= 1;
      if (inDegrees[next] == 0) q.push(next);
    }
  }

  return true;
}
```

재귀호출을 이용한 DFS 방법은 다음과 같다.

각 노드에 대해서 다음 3가지 상태를 나타내는 공간을 선언한다.

- 'w' : white or unvisited
- 'g' : gray or visiting
- 'b' : black or visited

```cpp
// w : unvisited, g : visiting, b : visited
bool recursive(int node, vector<vector<int>>& graph, vector<char>& color, vector<int>& answer) {
  if (color[node] == 'g') return false;
  color[node] = 'g';

  for (int next : graph[node]) {
    if (color[next] == 'w') {
      if (!recursive(next, graph, color, answer))
        return false;
    }

    if (color[next] == 'g') return false;
  }

  color[node] = 'b';
  answer.emplace_back(node);
  return true;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
  int size = numCourses;
  vector<vector<int>> graph(size);
  vector<int> answer;
  vector<char> color(size, 'w');

  for (vector<int>& cur : prerequisites) {
    int from = cur[1], to = cur[0];
    graph[to].emplace_back(from);
  }

  for (int node = 0; node < numCourses; ++node) {
    if (color[node] == 'w') {
      bool isFine = recursive(node, graph, color, answer);

      if (!isFine) return false;
    }
  }
  return true;
}
```

## 고생한 점
