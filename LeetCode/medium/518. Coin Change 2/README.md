# 518. Coin Change 2

[링크](https://leetcode.com/problems/coin-change-2/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

코인의 개수를 N, 값을 M이라고 하자.

모든 경우에 대해서 탐색할 경우 최악의 경우 O(N^M)의 시간 복잡도를 사용한다.

이는 시간초과가 발생하므로 동적 계획법을 이용한다.

이 문제는 knapsack 문제이므로 coin과 amount에 대해서 탐색해 풀이할 수 있다.

이 때의 시간 복잡도는 O(N \* M)이 된다.

### 공간 복잡도

coin과 amount에 대해서 dp배열을 생성할 경우 O(N \* M)의 공간 복잡도를 사용한다.

이 때 직전 값만을 사용하므로 O(M) 크기의 dp배열로 풀이가 가능하다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      79      |  O(N \* M)  |  O(N \* M)  |

현재 코인을 현재 cost에서 사용했을 때의 값을 이용해 더한다.

dp식을 다음과 같이 정의한다.

```cpp
dp[count][cost]; // count 개의 코인을 사용해서 cost 값을 만들 때의 조합의 개수
```

초기값은 다음과 같다.

```cpp
// cost 가 0인 경우는 1가지 밖에 없으므로
dp[coin][0] = 1;
```

일반식은 다음과 같다.

```cpp
dp[coin][cost] = dp[coin - 1][cost];

// 현재 cost가 이전 coin보다 큰 경우 (직전 coin에 대한 dp값을 적용 가능)
if (cost - coins[coin - 1] >= 0) {
  // 이전 단계에서 오는 조합의 개수
  dp[coin][cost] += dp[coin][cost - coins[coin - 1]];
}
```

즉 현재 coin에 대해서 cost를 순회하며, 이전의 조합의 개수를 더해간다.

이를 구현하면 다음과 같다.

```cpp
int change(int amount, vector<int>& coins) {
  int size = coins.size();
  vector<vector<int>> dp(size + 1, vector<int>(amount + 1, 0));
  dp[0][0] = 1;

  for (int count = 1; count <= size; count++) {
    dp[count][0] = 1;
    for (int cost = 1; cost <= amount; cost++) {
      dp[count][cost] = dp[count - 1][cost];

      // if can use to make before value
      if (cost >= coins[count - 1]) {
        dp[count][cost] += dp[count][cost - coins[count - 1]];
      }
    }
  }

  return dp.back().back();
}
```

### 동적 계획법 (space optimized)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      14      |  O(N \* M)  |    O(M)     |

위 식에서 직전값에 대한 dp만을 이용하므로 하나의 O(M)의 공간만 사용해 문제를 풀이할 수 있다.

```cpp
int change(int amount, vector<int>& coins) {
  vector<int> dp(amount + 1, 0);
  dp[0] = 1;

  for (int coin : coins) {
    for (int cost = coin; cost <= amount; cost++) {
      dp[cost] += dp[cost - coin];
    }
  }

  return dp.back();
}
```

## 고생한 점
