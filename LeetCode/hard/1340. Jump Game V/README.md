# 1340. Jump Game V

[링크](https://leetcode.com/problems/jump-game-v/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

배열의 크기를 N, 거리를 D라 하자.

동적 계획법을 사용할 경우 O(ND)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법에 O(N)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      7       |    O(ND)    |    O(N)     |

각 index별로 가능한 이동을 모두 계산하는 DFS함수를 사용한다.

이 때 이미 방문한 경우 이전 결과를 재사용한다.

각 노드의 방문마다 도달 가능한 최대 깊이를 반환한다.

```cpp
vector<int> dp;

int dfs(vector<int>& arr, int node, int d) {
  int size = arr.size();

  if (dp[node] != -1) {
    return dp[node];
  }
  dp[node] = 1;

  for (int i = 1; i <= d; i++) {
    if (node - i < 0 || arr[node] <= arr[node - i]) break;

    int cur = dfs(arr, node - i, d);
    dp[node] = max(dp[node], cur + 1);
  }

  for (int i = 1; i <= d; i++) {
    if (node + i >= size || arr[node] <= arr[node + i]) break;

    int cur = dfs(arr, node + i, d);
    dp[node] = max(dp[node], cur + 1);
  }

  return dp[node];
}

int maxJumps(vector<int>& arr, int d) {
  int size = arr.size();
  dp.resize(size, -1);

  int answer = 0;
  for (int i = 0; i < size; ++i) {
    int cur = dfs(arr, i, d);
    answer = max(answer, cur);
  }
  return answer;
}
```

## 고생한 점
