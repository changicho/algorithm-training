# 2492. Minimum Score of a Path Between Two Cities

[링크](https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

도시의 갯수를 N, 간선의 갯수를 E라 하자.

시작점에서 끝점까지는 꼭 연결되어있음이 보장된다.

연결된 경로 중 가장 cost가 낮은 간선을 찾으면 된다.

BFS를 이용해 시작점부터 끝점까지 비교하며 탐색할 경우 시간 복잡도는 O(N + E)이다.

유니온 파인드를 이용해 각 간선에 연결된 노드들을 연결하고 해당 간선의 코스트중 가장 작은 값을 찾을 수 있다.

이 경우 시간 복잡도는 O(N + E)이다.

### 공간 복잡도

BFS를 이용할 경우 큐를 이용해야 하므로 공간 복잡도는 O(N)이다. 그래프를 저장할 경우 O(E)의 공간 복잡도를 사용한다.

유니온 파인드를 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     453      |  O(N + E)   |  O(N + E)   |

시작점부터 끝점까지는 연결되어있음이 보장되므로, 시작점부터 BFS를 이용해 각 간선을 탐색한다.

이 때 연결된 간선들을 모두 탐색해야 함에 유의한다. (중복처리에서 간선 방문 전 건너뛰지 않아야함)

```cpp
struct Edge {
  int from, to, cost;
};

int minScore(int n, vector<vector<int>> &roads) {
  vector<vector<Edge>> graph(n + 1);
  vector<bool> visited(n + 1, false);
  int answer = INT_MAX;

  for (vector<int> &road : roads) {
    int a = road[0], b = road[1], dist = road[2];

    graph[a].push_back({a, b, dist});
    graph[b].push_back({b, a, dist});
  }

  queue<int> q;
  q.push(1);

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    if (visited[cur]) continue;
    visited[cur] = true;

    for (Edge &e : graph[cur]) {
      q.push(e.to);
      answer = min(answer, e.cost);
    }
  }

  return answer;
}
```

### 유니온 파인드

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     356      |  O(N + E)   |    O(N)     |

각 간선의 정보를 받고 노드들을 유니온 파인드를 이용해 연결한다.

이후 시작 노드와 연결된 간선들의 cost중 가장 작은 값을 찾는다.

```cpp
vector<int> parents;

int find(int node) {
  if (parents[node] == node) return node;
  return parents[node] = find(parents[node]);
}

void merge(int a, int b) {
  a = find(a), b = find(b);
  if (a == b) return;
  if (a > b) swap(a, b);

  parents[b] = a;
}

int minScore(int n, vector<vector<int>> &roads) {
  parents.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    parents[i] = i;
  }
  int answer = INT_MAX;
  for (vector<int> &road : roads) {
    int a = road[0], b = road[1], dist = road[2];

    merge(a, b);
  }

  for (vector<int> &road : roads) {
    int a = road[0], b = road[1], dist = road[2];
    if (find(a) == 1) {
      answer = min(answer, dist);
    }
  }
  return answer;
}
```

## 고생한 점
