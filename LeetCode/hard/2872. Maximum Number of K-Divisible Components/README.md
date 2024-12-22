# 2872. Maximum Number of K-Divisible Components

[링크](https://leetcode.com/problems/maximum-number-of-k-divisible-components/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

그래프의 노드의 수를 V, 간선의 수를 E라 하자.

그래프를 생성하는데 O(E)의 시간 복잡도가 소요된다.

DFS를 이용해 풀이할 경우 O(V)의 시간 복잡도가 소요된다.

따라서 총 시간 복잡도는 O(V + E)이다.

### 공간 복잡도

그래프를 생성하는데 O(E)의 공간 복잡도가 필요하다.

DFS를 수행하는데 O(V)의 공간 복잡도가 필요하다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     228      |  O(V + E)   |  O(V + E)   |

재귀 호출을 이용해 현재 노드의 자식노드들을 탐색한다.

이 때 자식 노드들의 값들의 합들을 모두 더하며 이후 현재 값 까지 더해준다.

이 합이 k로 나누어 떨어지는 경우 해당 노드를 부모와 끊을 수 있다.

이를 재귀호출로 반복하며 k로 나누어 떨어지는 노드를 끊고 정답을 증가시킨다.

```cpp
int maxKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &values, int k) {
  vector<vector<int>> graph(n);
  for (vector<int> &edge : edges) {
    int a = edge[0];
    int b = edge[1];

    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  int answer = 0;

  function<int(int, int)> recursive = [&](int cur, int parent) {
    int sum = 0;

    for (int &next : graph[cur]) {
      if (next == parent) continue;

      sum += recursive(next, cur);
      sum %= k;
    }

    sum += values[cur];
    sum %= k;

    if (sum == 0) answer++;
    return sum;
  };

  recursive(0, -1);

  return answer;
}
```

## 고생한 점
