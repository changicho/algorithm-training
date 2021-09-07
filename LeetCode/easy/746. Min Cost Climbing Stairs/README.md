# 746. Min Cost Climbing Stairs

[링크](https://leetcode.com/problems/min-cost-climbing-stairs/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

계단의 개수를 N이라 하자.

현재 계단으로 올 수 있는 경우는 다음 2가지이다.

- 1번째 전 계단
- 2번째 전 계단

모든 경우를 탐색할 경우 시간 복잡도는 O(2^N)이 되며 이는 제한시간 내에 불가능하다.

따라서 동적 계획법을 이용해 각 경우마다 최선의 값을 갱신하다.

이 때의 시간 복잡도는 O(N)이다.

### 공간 복잡도

직전값, 2번째 전 값을 현재 값을 구할 때 필요하다.

두개의 값만을 저장하면 되므로 공간 복잡도는 O(1)이다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(1)     |

현재 계단으로 올 수 있는 경우는 다음 2가지이다.

- 1번째 전 계단
- 2번째 전 계단

dp배열을 다음과 같이 정의 할 수 있다.

```cpp
dp[i]; // i번째 계단까지 도달하는 데 들어가는 최소 비용

dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
```

초기값은 다음과 같다.

```cpp
dp[0] = cost[0];
dp[1] = cost[1];
```

이를 이용해 정답을 구한다.

정답은 계단을 전부 오르는 경우이므로 결국 맨 마지막값, 맨 마지막 직전 값 두 값중 하나가 된다.

```cpp
int minCostClimbingStairs(vector<int>& cost) {
  int size = cost.size();
  vector<int> dp(2, 0);
  dp[0] = cost[0];
  dp[1] = cost[1];

  for (int i = 2; i < size; i++) {
    int temp = cost[i] + min(dp[0], dp[1]);
    dp[0] = dp[1];
    dp[1] = temp;
  }

  return min(dp[0], dp[1]);
}
```

## 고생한 점
