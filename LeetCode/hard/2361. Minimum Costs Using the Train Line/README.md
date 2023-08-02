# 2361. Minimum Costs Using the Train Line

[링크](https://leetcode.com/problems/minimum-costs-using-the-train-line/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

도시의 갯수를 N이라 하자. (N <= 10^5)

모든 경우를 탐색할 경우 O(2^N)의 시간 복잡도를 사용하므로 제한시간 내에 불가능하다.

따라서 동적 계획법을 이용한다.

이 경우 각 도시까지에 대해 동적 계획법을 수행할 수 있다.

따라서 시간 복잡도는 O(N)이다.

### 공간 복잡도

모든 도시에 대해 동적 계획법을 수행할 경우 O(N)의 공간 복잡도를 사용한다.

직전값만 사용하므로 이를 최적화 할 경우 O(1)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     193      |    O(N)     |    O(N)     |

각 도시까지 일반열차로 이동하는경우와 고속열차로 이동하는 경우를 생각해보자.

만약 고속열차로 이동한 이후 일반열차의 승강장으로 이동하는 비용은 0이다.

따라서 해당 도시까지 최소값은 다음 두가지 경우 중 최소값이다.

현재 도시의 일반열차승강장을 방문하는 경우와 고속열차승강장을 방문하는 경우 두 경우가 존재한다.

일반 열차 승강장의 경우 다음과 같은 경우이다.

- 직전 도시 일반열차 승강장에서 오는 경우
- 직전 도시 고속열차 승강장에서 이동 후 일반열차 승강장으로 오는 경우

고속 열차 승강장의 경우 다음과 같은 경우이다.

- 직전 도시 고속열차 승강장에서 오는 경우
- 현재 도시 일반열차 승강장에서 고속열차 승강장으로 오는 경우

즉 일반 열차 승강장은 이전값으로만 갱신이 가능하지만, 고속 열차 승강장은 현재값도 갱신에 포함된다.

이를 이용해 동적 계획법을 적용하면 아래와 같다.

```cpp
vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
  int size = regular.size();
  long long dp[100002][2];

  dp[0][0] = 0;
  dp[0][1] = expressCost;

  for (int i = 1; i <= size; i++) {
    dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + regular[i - 1];
    dp[i][1] = min(dp[i][0] + expressCost, dp[i - 1][1] + express[i - 1]);
  }

  vector<long long> answer;
  for (int i = 1; i <= size; i++) {
    answer.push_back(min(dp[i][0], dp[i][1]));
  }
  return answer;
}
```

## 고생한 점
