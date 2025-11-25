# E - Hit and Away

[링크](https://atcoder.jp/contests/abc429/tasks/abc429_e)

| 난이도 |
| :----: |
|  450   |

## 설계

### 시간 복잡도

노드의 수를 N, 간선의 수를 N-1 이라 하자.

그래프를 생성하는데 O(N)의 시간 복잡도를 사용한다.

안전한 공간부터 BFS를 순차적으로 실행하며 각 D 위치에 대한 최소 도달 거리를 구할 수 있다.

이 때 2번째 최소 도달 거리와, 중복된 시작 위치를 구분해야 한다.

중복된 시작 위치를 관리하기 위해 hash set을 사용할 경우 O(1)의 시간 복잡도를 사용한다.

BFS를 수행하는데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

그래프에 O(N)의 공간 복잡도를 사용한다.

BFS에 O(N)의 공간 복잡도를 사용한다.

중복 방문을 제거하기 위한 hash set에 O(N)의 공간 복잡도를 사용한다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     251      |    O(N)     |    O(N)     |

각 D의 위치에 대해서 매번 BFS로 탐색하지 않고, 모든 S인 시작점에 대해서 BFS를 동시에 진행한다.

이 과정에서 각 D에 대해서 가장 작은 2개의 cost를 저장한다.

이 때 현재 진행중인 BFS탐색이 어느 시작 S에서 왔는지 저장하며, 이미 이전에 S에서 시작한 탐색이 존재하는 경우 값을 갱신하지 않는다.

이후 D인 위치에 대해 정답을 갱신한다.

```cpp
struct Edge {
  int from, to;
};

struct Status {
  int from;
  int node;
  int step;
};

auto solution(int n, int m, vector<Edge>& edges, string& status) {
  // 1st closest safe cost, 2nd closest safe cost
  vector<vector<int>> minCosts(n);
  vector<unordered_set<int>> visited(n);

  vector<vector<int>> graph(n);

  for (Edge& e : edges) {
    int a = e.from - 1, b = e.to - 1;

    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  // BFS step
  queue<Status> q;
  for (int i = 0; i < n; i++) {
    if (status[i] == 'S') {
      q.push({i, i, 0});
      minCosts[i].push_back(0);
      visited[i].insert(i);
    }
  }

  int step = 0;
  while (!q.empty()) {
    int size = q.size();
    step++;

    while (size--) {
      Status cur = q.front();
      q.pop();

      for (int& next : graph[cur.node]) {
        if (minCosts[next].size() == 2) continue;
        if (visited[next].count(cur.from)) continue;

        visited[next].insert(cur.from);
        minCosts[next].push_back(step);

        q.push({cur.from, next, step});
      }
    }
  }

  vector<long long> answer;
  for (int i = 0; i < n; i++) {
    if (status[i] == 'D') {
      long long cur = minCosts[i][0] + minCosts[i][1];
      answer.push_back(cur);
    }
  }

  return answer;
}
```

## 고생한 점

```plain_text
7 6
1 2
2 3
3 4
4 5
5 6
6 7
SDDDDDS
```

어느 S에서 방문했는지 체크하지 않으면 위 케이스에서 같은 S에서 시작한 path로 중복 방문된다.