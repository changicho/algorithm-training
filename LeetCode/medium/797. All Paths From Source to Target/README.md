# 797. All Paths From Source to Target

[링크](https://leetcode.com/problems/all-paths-from-source-to-target/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 개수를 N이라 하자.

DFS를 이용해 경로를 방문할 경우 경우의 수는 O(N \* 2^N)가 된다.

### 공간 복잡도

call stack에 쌓일 수 있는 최대 개수는 O(N)이다.

정답의 가장 큰 길이는 O(N)이며 정답의 경우는 최대 O(2^N)개가 나올 수 있다.

따라서 공간 복잡도는 O(N \* 2^N)이다.

### DFS + backtracking

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      | O(N \* 2^N) | O(N \* 2^N) |

DFS를 이용해 경로를 탐색하며 이 때 이전에 방문한 경로는 skip한다.

매 경로마다 다음 노드를 탐색하며 방문을 갱신하며 cycle이 아닌 유일한 경로를 찾는다.

이를 위해 이전에 방문한 노드는 제외하며, 백트래킹을 사용한다.

이 때 경우의 수는 시작점에서 끝점 까지 특정 노드를 경로로 선택할지 말지의 문제가 된다.

따라서 경우의 수는 최대 2^(N-1) - 1 개가 된다. (시작 노드를 제외하므로 1을 뺌)

이 경우의 수 마다 현재 경우에서 다음 경우를 순회를 통해 탐색하므로

O(N)의 시간 복잡도를 사용한다.

따라서 최종 시간 복잡도는 O(N \* 2^N)이 된다.

이를 구현하면 다음과 같다.

```cpp
void recursive(int node, vector<int> &path, vector<bool> &visited,
                vector<vector<int>> &graph, vector<vector<int>> &answer) {
  int size = visited.size();

  path.push_back(node);

  if (visited[node]) return;
  visited[node] = true;

  if (node == size - 1) {
    answer.push_back(path);

    path.pop_back();
    visited[node] = false;
    return;
  }

  for (int next : graph[node]) {
    if (visited[next]) continue;

    recursive(next, path, visited, graph, answer);
  }

  visited[node] = false;
  path.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
  int size = graph.size();

  vector<vector<int>> answer;
  vector<bool> visited(size, false);
  vector<int> path;

  recursive(0, path, visited, graph, answer);

  return answer;
}
```

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      24      | O(N \* 2^N) | O(N \* 2^N) |

이력받은 그래프는 유향 비순환 그래프(Directed Acyclic Graph, DAG)이므로 사이클이 존재하지 않는다.

따라서 BFS를 이용해 탐색할 때 중복 방문 체크를 하지 않아도 된다.

이를 이용해 시작점부터 끝점까지의 모든 경로를 저장한다.

탐색 시에 현재 상태에서 방문한 노드와 경로를 함께 탐색해야 한다.

```cpp
struct Status {
  int node;
  vector<int> path;
};

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
  vector<vector<int>> answer;

  queue<Status> q;

  int size = graph.size();
  int from = 0, to = size - 1;
  q.push({from, {from}});

  while (!q.empty()) {
    Status cur = q.front();
    q.pop();

    if (cur.node == to) {
      answer.emplace_back(cur.path);
      continue;
    }

    for (int next : graph[cur.node]) {
      cur.path.emplace_back(next);
      q.push({next, cur.path});
      cur.path.pop_back();
    }
  }

  return answer;
}
```

## 고생한 점
