# 322. Coin Change

[링크](https://leetcode.com/problems/coin-change/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

amount의 값을 N, 동전의 개수를 M이라 하자.

모든 경우를 시도할 경우, M에 대해서 모두 시도해 봐야 하므로 최악의 경우 시간 복잡도는 O(M^N)이 되며 이는 제한시간 내에 불가능하다.

따라서 동적 계획법을 이용한다.

이 경우 각 값 마다 최소값을 구하면 되며, 현재 값의 최소를 구할 때 M번 순회하고 이를 모든 값에 대해서 반복하므로 시간 복잡도는 O(N \* M)이 된다.

### 공간 복잡도

amount의 값에 대해서 dp값을 생성해야 하므로 O(N)의 공간 복잡도를 사용한다.

### 정리

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      68      |  O(N \* M)  |    O(N)     |

dp배열을 다음과 같이 설정한다.

```cpp
dp[amount]; // amount원이 될 때 까지 최소 동전의 개수
```

초기값은 다음과 같다.

```cpp
dp[i] = LIMIT; // 초기 특정 amount들은 몇개가 필요할 지 모름

// 해당 동전 하나로 amount를 만들 수 있으므로
for (int& coin : coins) {
  dp[coin] = 1;
}
```

점화식을 다음과 같이 표현할 수 있다.

```cpp
// 현재 i원에 대해서
for (int coin : coins) {
  dp[i] = min(dp[i], dp[i - coin] + 1);
}
```

여기서 index가 0 미만이 되지 않도록 예외처리를 추가한다.

이를 표현하면 다음과 같다.

```cpp
int coinChange(vector<int>& coins, int amount) {
  vector<int> dp(amount + 1, INT_MAX - 1);

  dp[0] = 0;
  for (int& coin : coins) {
    if (coin > amount) continue;
    dp[coin] = 1;
  }

  for (int i = 1; i <= amount; i++) {
    for (int coin : coins) {
      if (i - coin < 0) continue;

      dp[i] = min(dp[i], dp[i - coin] + 1);
    }
  }

  int answer = dp[amount];

  if (answer == INT_MAX - 1) return -1;
  return answer;
}
```

## 고생한 점
