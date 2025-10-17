# 656. Coin Path

[링크](https://leetcode.com/problems/coin-path/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

배열 coins의 크기를 N, maxJump를 M이라 하자.

동적 계획법을 사용할 수 있다. 각 경우마다 최소값과 path를 저장하는 경우 O(N^2 \* M)의 시간 복잡도를 사용한다.

각 경우마다 최소값과 다음 index를 저장하는 경우 O(N \* M)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 경우마다 최소값과 path를 저장하는 경우 O(N^2)의 공간 복잡도를 사용한다.

각 경우마다 최소값과 다음 index를 저장하는 경우 O(N)의 공간 복잡도를 사용한다.

### 동적 계획법 & 역순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N \* M)  |    O(N)     |

다음과 같은 dp 배열을 정의한다.

```cpp
// definition
int dp[i]; // i번째부터 시작했을 때 얻을 수 있는 최소 비용

// init
dp[size - 1] = coins[size - 1];

// update
for (int j = i + 1; j <= i + maxJump; j++) {
  if (coins[j] == -1) continue;

  dp[i] = min(dp[i], dp[j] + coins[i]);
}
```

배열을 오른쪽부터 순회하며 현재 index에서 점프할 수 있는 다음 index들을 확인하며 dp값을 갱신한다.

이 때 dp값이 갱신될 때 현재 index에서 점프할 수 있는 다음 index를 nexts 배열에 저장한다.

이 때 정답이 여러개인 경우 사전순으로 앞서는 것을 찾기 위해 다음 index는 작은 값부터 확인한다.

이후 완성된 nexts 배열을 이용해 실제 path를 복원한다.

이 때 정답의 조건을 만족하지 못하는 경우 빈 배열을 반환한다.

```cpp
vector<int> cheapestJump(vector<int>& coins, int maxJump) {
  int size = coins.size();

  vector<int> nexts(size, -1);
  vector<long> dp(size, INT_MAX);

  dp[size - 1] = coins[size - 1];
  for (int i = size - 1; i >= 0; i--) {
    for (int j = i + 1; j <= i + maxJump && j < size; j++) {
      if (coins[j] == -1) continue;

      int newCost = dp[j] + coins[i];

      if (dp[i] > newCost) {
        dp[i] = newCost;
        nexts[i] = j;
      }
    }
  }

  vector<int> answer;
  int i = 0;
  while (i != -1) {
    answer.push_back(i + 1);

    i = nexts[i];
  }
  if (answer.back() != size) return {};

  return answer;
}
```

## 고생한 점
