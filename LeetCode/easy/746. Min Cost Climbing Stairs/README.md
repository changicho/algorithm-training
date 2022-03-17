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

매 index마다의 dp값을 선언할 경우 O(N)의 시간 복잡도를 사용한다.

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

이를 구현하면 다음과 같다.

```cpp
int minCostClimbingStairs(vector<int>& cost) {
  int size = cost.size();
  vector<int> dp(size, INT_MAX);

  dp[0] = cost[0];
  dp[1] = cost[1];

  for (int i = 2; i < size; i++) {
    dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
  }

  return min(dp[size - 1], dp[size - 2]);
}
```

여기서 2개의 값만을 사용하므로 공간 복잡도를 O(1)로 줄일 수 있다.

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

### 동적 계획법 (다른 일반식)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      13      |    O(N)     |    O(N)     |

dp식을 다음과 같이 생각할 수 있다.

```cpp
dp[index]; // minimum cost to be able to reach index
```

즉 index까지 도달 가능한 최소값을 저장하는 dp배열을 이용할 수 있다.

여기서 0번째와 1번째의 경우 시작점에서 바로 도달이 가능하므로 비용이 0으로 도달할 수 있다. (초기값)

일반식은 다음과 같다.

```cpp
dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
// pick between one ago, two ago
```

이를 이용해 구현할 경우 다음과 같다.

```cpp
int minCostClimbingStairs(vector<int>& cost) {
  int size = cost.size();
  // dp[index]; minimum cost to reach index
  vector<int> dp(size + 1);

  dp[0] = 0;
  dp[1] = 0;

  for (int i = 2; i <= size; i++) {
    dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
  }

  return dp[size];
}
```

## 고생한 점
