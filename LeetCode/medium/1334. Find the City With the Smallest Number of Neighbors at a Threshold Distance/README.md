# 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance

[링크](https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 갯수를 V, 엣지의 갯수를 E라 하자.

모든 노드마다 다른 노드까지의 거리를 구해야한다.

이를 플로이드 와샬 알고리즘을 이용할 경우 O(N^3)의 시간 복잡도로 구할 수 있다.

이후 정답을 갱신할 때 각 노드에서 다른 노드로 가는 모든 경우들을 파악해야 한다. 이 과정에 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 노드마다 다른노드까지의 cost를 사용하므로 O(N^2)의 공간 복잡도를 사용한다.

### 프롤이드 와샬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      72      |   O(N^3)    |   O(N^2)    |

먼저 플로이드 와샬 알고리즘을 이용해 하나의 노드에서 다른 모든 노드까지의 최소 비용을 갱신한다.

이 때 다른노드를 거쳐가는 경우에 대한 탐색을 최상단 루프에 놓아야한다.

1. through
2. from
3. to

이는 from ~ to까지의 최소비용을 미리 구해놓아야 이후에 through를 증가시킨 후 갱신할 때 이전 데이터를 이용할 수 있기 때문이다.

이후 cost를 모두 구한 뒤에 각 노드마다 순회하며 정답을 갱신한다.

```cpp
int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
  // we can calculate INT_MAX + INT_MAX case when we update
  // so value must not overflow
  vector<vector<int>> costs(n, vector<int>(n, INT_MAX / 10));

  // initialize costs
  for (vector<int>& edge : edges) {
    int from = edge[0], to = edge[1], cost = edge[2];

    costs[from][to] = cost;
    costs[to][from] = cost;
  }
  for (int node = 0; node < n; node++) {
    costs[node][node] = 0;
  }

  // use floyd warshall
  for (int through = 0; through < n; through++) {
    for (int from = 0; from < n; from++) {
      for (int to = 0; to < n; to++) {
        costs[from][to] =
            min(costs[from][to], costs[from][through] + costs[through][to]);
      }
    }
  }

  // update answer

  int neighbors = n;
  int answer = -1;
  for (int from = 0; from < n; from++) {
    int count = 0;
    for (int to = 0; to < n; to++) {
      if (from == to) continue;

      if (costs[from][to] <= distanceThreshold) count++;
    }

    if (count <= neighbors) {
      neighbors = min(neighbors, count);
      answer = from;
    }
  }

  return answer;
}
```

## 고생한 점
