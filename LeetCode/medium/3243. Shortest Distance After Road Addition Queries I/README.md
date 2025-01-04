# 3243. Shortest Distance After Road Addition Queries I

[링크](https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 갯수를 N, 쿼리의 갯수를 Q라 하자.

각 상황마다 동적 계획법을 사용해 최단 거리를 구할 경우 시간 복잡도는 O(N)이다.

이를 모든 쿼리에 대해 반복하며, 쿼리가 그래프에 추가되므로 시간 복잡도는 O(Q \* (N + Q))이다.

### 공간 복잡도

동적 계획법과 그래프에 O(N + Q)의 공간 복잡도가 필요하다.

### 동적 계획법

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|      48      | O(Q \* (N + Q)) |  O(N + Q)   |

현재 그래프 상태에 대해서 최단거리를 동적 계획법을 이용해 구할 수 있다.

노드를 끝점부터 시작점까지 순서대로 탐색하며 각 노드에 대해서 최단거리를 갱신한다.

이를 모든 쿼리에 대해 수행하며, 쿼리가 그래프에 추가될 때마다 최단거리를 갱신한다.

```cpp
int calc(vector<vector<int>> &graph, int n) {
  vector<int> dp(n);
  dp[n - 1] = 0;

  for (int cur = n - 2; cur >= 0; cur--) {
    int minimum = n;

    for (int &next : graph[cur]) {
      minimum = min(minimum, dp[next] + 1);
    }
    dp[cur] = minimum;
  }
  return dp[0];
}

vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries) {
  vector<int> answer;
  vector<vector<int>> graph(n);

  for (int i = 0; i < n - 1; i++) {
    graph[i].push_back(i + 1);
  }

  for (vector<int> &query : queries) {
    int a = query[0];
    int b = query[1];
    graph[a].push_back(b);

    answer.push_back(calc(graph, n));
  }
  return answer;
}
```

## 고생한 점
