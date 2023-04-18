# 983. Minimum Cost For Tickets

[링크](https://leetcode.com/problems/minimum-cost-for-tickets/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

days의 크기를 N이라 하자. (N <= 365)

각 day는 1부터 365까지의 겹치지 않는 정수이다.

동적 계획법을 이용해 현재 day까지의 최소 비용을 구할 수 있다.

이 경우 days의 순회에 O(N)의 시간 복잡도를 사용한다.

각 day마다 이전값에서 정답을 갱신하는 데 이분 탐색을 사용할 경우 O(log_2(N)), 직접 이동할 경우 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법을 사용할 경우 O(N)의 시간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(N)     |

다음과 같은 dp식을 선언한다.

```cpp
// definition
int dp[day]; // until day, minimum cost

// init
dp[0] = costs[0]; // 1 day

// update
dp[day] = min({oneDay, oneWeek, oneMonth});
```

각 과정마다 현재 1일권, 1주일권, 1달권을 끊었을 때의 최소값을 구하고 이 중 가장 작은 값으로 갱신한다.

이 때 1주일, 1달권을 끊었을 때 이전 day를 찾는데 순회를 이용할 수 있다.

(현재 일 - 1주일, 1달) 이전의 day를 찾는다.

이후 현재 값을 갱신한다.

```cpp
int mincostTickets(vector<int> &days, vector<int> &costs) {
  int size = days.size();
  vector<int> dp(size, INT_MAX);

  for (int i = 0; i < size; i++) {
    int oneDay = (i - 1 < 0 ? 0 : dp[i - 1]) + costs[0];

    int before = i - 1;
    while (before >= 0 && days[i] - days[before] < 7) {
      before--;
    }
    int oneWeek = (before < 0 ? 0 : dp[before]) + costs[1];

    before = i - 1;
    while (before >= 0 && days[i] - days[before] < 30) {
      before--;
    }
    int oneMonth = (before < 0 ? 0 : dp[before]) + costs[2];

    dp[i] = min({oneDay, oneWeek, oneMonth});
  }

  return dp[size - 1];
}
```

## 고생한 점
