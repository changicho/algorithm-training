# 2830. Maximize the Profit as the Salesman

[링크](https://leetcode.com/problems/maximize-the-profit-as-the-salesman/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

집의 갯수를 N, offers의 크기를 M이라 하자.

offers를 end time에 대해 정렬 후 동적 계획법을 이용해 문제를 풀이할 수 있다.

이 경우 정렬에 O(M \* log_2(M)), 동적 계획법 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법에 O(N)의 공간 복잡도를 사용한다.

### 정렬 & knapsack 동적 계획법

| 내 코드 (ms) |     시간 복잡도      | 공간 복잡도 |
| :----------: | :------------------: | :---------: |
|     387      | O(N + M \* log_2(M)) |    O(N)     |

각 offer마다 house를 판매할 수 있다. 최대한 많은 이익이 나도록 판매할 때의 이익을 구해야 한다.

각 offer마다의 house의 시작, 끝 좌표가 있으므로 해당 house까지를 판매할 때의 이익을 구할 수 있다.

house를 왼쪽부터 순회하며 각 house에 대해 이익을 갱신한다. 이 때 현재 유효한 offer를 찾기 위해 offers를 정렬할 수 있다.

끝 좌표에 대해 오름차순으로 정렬 시 이전에 방문한 offer들은 현재 offer보다 먼저 끝나는 offer임을 일 수 있다.

현재 index로 끝나는 offer들을 이용해 최대 이익을 갱신할 때 이전 dp값을 이용해 현재 offer의 시작점까지의 최대값을 이용한다.

만약 현재 offer로 끝나는 house가 없다면 이전 dp값을 이용한다.

```cpp
int maximizeTheProfit(int n, vector<vector<int>> &offers) {
  // offers[i] = [start_i, end_i, gold_i]

  // sort by end_i
  sort(offers.begin(), offers.end(),
        [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });

  vector<int> dp(n + 1, 0);

  for (int i = 0, j = 0; i <= n; i++) {
    dp[i] = max(dp[i], (i - 1) < 0 ? 0 : dp[i - 1]);

    while (j < offers.size() && offers[j][1] == i) {
      vector<int> offer = offers[j];
      j++;

      int left = offer[0], right = offer[1], gold = offer[2];

      dp[right] = max(dp[right], ((left - 1 < 0) ? 0 : dp[left - 1]) + gold);
    }
  }
  return dp.back();
}
```

## 고생한 점
