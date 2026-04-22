# C - Straw Millionaire

[링크](https://atcoder.jp/contests/abc454/tasks/abc454_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

노드의 수를 V, 간선의 수를 E라 하자.

시작점부터 방문 가능한 최대 정점의 수를 BFS로 탐색할 경우 O(V + E)의 시간 복잡도를 사용한다.

### 공간 복잡도

그래프에 O(V + E)의 공간 복잡도를 사용한다.

BFS에 O(V)의 공간 복잡도를 사용한다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     121      |  O(V + E)   |  O(V + E)   |

입력받은 A, B의 정보를 토대로 그래프를 생성한다.

이후 1번 노드부터 탐색하며 hash set에 방문한 정점을 관리한다. (중복방문 제외)

이후 hash set의 갯수를 반환한다.

```cpp
int solution(int n, int m, vector<int> a, vector<int> b) {
  vector<vector<int>> graph(n + 1);
  for (int i = 0; i < m; i++) {
    graph[a[i]].push_back(b[i]);
  }

  queue<int> q;
  unordered_set<int> visited;

  q.push(1);
  visited.insert(1);

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (int next : graph[cur]) {
      if (next == -1) continue;
      if (visited.count(next) > 0) continue;
      visited.insert(next);
      q.push(next);
    }
  }

  return visited.size();
}
```

## 고생한 점
