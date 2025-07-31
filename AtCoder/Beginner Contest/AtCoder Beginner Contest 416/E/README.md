# E - Development

[링크](https://atcoder.jp/contests/abc416/tasks/abc416_e)

| 난이도 |
| :----: |
|  450   |

## 설계

### 시간 복잡도

노드의 수를 N, 간선의 수를 M, 쿼리의 수를 Q라 하자.

각 노드에서 다른 노드까지 최소 거리를 구하는 데 플로이드 와샬 알고리즘을 사용할 경우 O(N^3)의 시간 복잡도를 사용한다.

각 쿼리마다 특정 노드들의 경로가 갱신된다. 이를 갱신하는데 O(N^2)의 시간 복잡도를 사용한다.

공항이 설치되는 경우를 별도 노드에 연결하는것으로 처리할 경우 동일하게 O(N^2)의 시간 복잡도를 사용한다.

따라서 총 O(N^3 + Q \* N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

그래프에 O(N^2)의 공간 복잡도를 사용한다.

### 프로이드 와샬 & 동적 그래프 업데이트

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     1333     | O(N^3 + Q * N^2) |   O(N^2)    |

초기 상태에서 플로이드 와샬 알고리즘을 사용해 모든 노드에서 다른 노드까지의 최소 거리를 구한다.

이 때 공항이 설치되는 경우는 별도 노드에 연결되는것으로 판단하며, 이륙시와 착륙시 비용의 합이 T가 되게 설정한다.

- 이륙 비용 T
- 착륙 비용 0

이후 각 쿼리마다 다음을 수행한다.

새 간선이 추가되는 경우 해당 간선에 연결된 노드들의 최소 거리를 갱신한다.

이후 두 노드와 다른 노드들에 대한 최소 비용을 갱신한다.

공항이 설치되는 경우 해당 노드와 공항 노드(0번 노드) 사이의 최소 거리를 갱신한다.

이후 공항과 현재 노드에 대해 다른 노드들에 대한 최소 거리를 갱신한다.

```cpp
const long long INF = 1e18;

struct Edge {
  int a, b, c;
};

long long getTotal(vector<vector<long long>> &dp, int n) {
  long long total = 0;
  for (int from = 1; from <= n; from++) {
    for (int to = 1; to <= n; to++) {
      if (from == to) continue;

      if (dp[from][to] != INF) {
        total += dp[from][to];
      }
    }
  }
  return total;
}

void update(vector<vector<long long>> &dp, int n, int a) {
  for (int through = 0; through <= n; through++) {
    for (int to = 0; to <= n; to++) {
      dp[a][to] = min(dp[a][to], dp[a][through] + dp[through][to]);
      dp[to][a] = min(dp[to][a], dp[to][through] + dp[through][a]);
    }
  }
  for (int from = 0; from <= n; from++) {
    for (int to = 0; to <= n; to++) {
      dp[from][to] = min(dp[from][to], dp[from][a] + dp[a][to]);
      dp[to][from] = min(dp[to][from], dp[to][a] + dp[a][from]);
    }
  }
}

vector<long long> solution(int n, vector<Edge> &edges, vector<int> &airports,
                           long long T, vector<vector<int>> &queries) {
  vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, INF));
  // sky is 0
  for (int i = 1; i <= n; i++) {
    dp[i][i] = 0;
  }

  for (int &a : airports) {
    // cost when landing at airport
    dp[a][0] = min(dp[a][0], T);
    dp[0][a] = min(dp[0][a], 0LL);
  }

  for (Edge &e : edges) {
    int from = e.a, to = e.b;
    long long cost = e.c;

    dp[from][to] = min(dp[from][to], cost);
    dp[to][from] = min(dp[to][from], cost);
  }

  // use floyd
  for (int through = 0; through <= n; through++) {
    for (int from = 0; from <= n; from++) {
      for (int to = 0; to <= n; to++) {
        dp[from][to] = min(dp[from][to], dp[from][through] + dp[through][to]);
      }
    }
  }

  vector<long long> answer;

  for (vector<int> &query : queries) {
    int command = query[0];

    if (command == 1) {
      int a = query[1], b = query[2];
      long long cost = query[3];

      dp[a][b] = min(dp[a][b], cost);
      dp[b][a] = min(dp[b][a], cost);

      update(dp, n, a);
      update(dp, n, b);

    } else if (command == 2) {
      int x = query[1];

      dp[x][0] = min(dp[x][0], T);
      dp[0][x] = min(dp[0][x], 0LL);

      update(dp, n, x);
      update(dp, n, 0);

    } else if (command == 3) {
      long long total = getTotal(dp, n);
      answer.push_back(total);
    }
  }

  return answer;
}
```

## 고생한 점
