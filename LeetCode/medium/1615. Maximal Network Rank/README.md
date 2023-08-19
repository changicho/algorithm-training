# 1615. Maximal Network Rank

[링크](https://leetcode.com/problems/maximal-network-rank/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

주어진 그래프의 노드의 갯수를 N, 간선의 갯수를 E라 하자.

간선정보로 그래프를 생성하는데 O(E)의 시간 복잡도를 사용한다.

그래프에서 두 개의 노드를 골라 network rank를 구한다. 이 때 미리 간선정보를 이용해 O(1)의 시간 복잡도로 구할 수 있다.

이를 모든 노드 쌍에 반복하는데 O(N^2)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N^2 + E)이다.

### 공간 복잡도

그래프에 O(E)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      84      | O(N^2 + E)  |    O(E)     |

간선 정보를 이용해 그래프를 구성한다.

두 노드의 network rank는 다음과 같이 구할 수 있다.

- 두 노드가 끊어져 있는 경우 : 두 노드의 간선의 갯수의 합
- 두 노드가 연결되어 있는 경우 : 두 노드의 간선의 갯수의 합 - 1

이 때 하나의 노드에 다른 노드가 연결되어있는지 빠르게 구하기 위해 hash set을 사용한다.

이후 각 노드쌍에 대해 network rank를 구하고 이를 갱신한다.

```cpp
int maximalNetworkRank(int n, vector<vector<int>>& roads) {
  vector<unordered_set<int>> graph(n);

  for (vector<int>& e : roads) {
    int from = e[0], to = e[1];

    graph[from].insert(to);
    graph[to].insert(from);
  }

  int answer = 0;
  for (int node = 0; node < n; node++) {
    for (int next = node + 1; next < n; next++) {

      int count = graph[node].size() + graph[next].size();

      if (graph[node].count(next)) count--;

      answer = max(answer, count);
    }
  }
  return answer;
}
```

## 고생한 점
