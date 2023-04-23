# 2218. Maximum Value of K Coins From Piles

[링크](https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

piles의 모든 pile의 갯수를 N 선택할 갯수를 K라 하자.

모든 경우를 탐색할 경우 제한 시간 내에 불가능하다.

따라서 동적 계획법을 이용한다.

이 경우 각 index마다 pile들을 순회하며 K에 대해 탐색하므로 O(N \* K)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법을 사용할 경우 O(N \* K)의 공간 복잡도를 사용한다.

### 정리

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     345      |  O(N \* K)  |  O(N \* K)  |

각 piles에는 여러개의 pile들이 존재한다.

이에 대해서 동적 계획법을 사용하지 않고, 위에서 부터 순차적으로 선택해야 하므로 piles의 index에 대해 dp 식을 구성한다.

다음과 같은 dp식을 사용한다.

```cpp
// definition
int dp[i][coins]; // i번째까지의 piles에서 coins개의 코인을 뽑았을 때의 최대값

// initialize
dp[0][0] = 0;

// update
for (int coins = 0; coins <= k; coins++) {
  int prefixSum = 0;
  for (int selected = 0; selected <= min(pilesSize, coins); selected++) {
    if (selected > 0) {
      // pick selected coins from piles[i]
      prefixSum += piles[i][selected - 1];
    }

    int prev = (i - 1) < 0 ? 0 : dp[i - 1][coins - selected];

    dp[i][coins] = max(dp[i][coins], prev + prefixSum);
  }
}
```

각 index마다 현재 piles에서 선택할 수 있는 pile의 갯수를 순회하며, 남은 pile은 이전 dp값에서 가져온다.

이를 구현하면 다음과 같다.

```cpp
int maxValueOfCoins(vector<vector<int>>& piles, int k) {
  int size = piles.size();

  // dp[i][coins] : i번째까지의 piles에서 coins개의 코인을 뽑았을 때의 최대값
  int dp[1001][2001] = {
      0,
  };
  for (int i = 0; i < size; i++) {
    for (int coins = 0; coins <= k; coins++) {
      int prefixSum = 0;

      int pilesSize = piles[i].size();
      int maximum = min(pilesSize, coins);
      for (int selected = 0; selected <= maximum; selected++) {
        if (selected > 0) {
          prefixSum += piles[i][selected - 1];
        }

        int prev = (i - 1) < 0 ? 0 : dp[i - 1][coins - selected];

        dp[i][coins] = max(dp[i][coins], prev + prefixSum);
      }
    }
  }

  return dp[size - 1][k];
}
```

## 고생한 점
