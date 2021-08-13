# 256. Paint House

[링크](https://leetcode.com/problems/paint-house/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

cost들의 개수를 N이라 하자.

브루트 포스로 모든 경우를 탐색할 경우 시간 복잡도는 3^N이다. 이는 제한시간 내에 불가능하다.

동적 계획법을 이용해 이전에 계산한 값을 이용할 수 있다.

이 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

동적 계획법을 이용할 때 현재 값을 찾기 위해 직전의 값만 사용한다.

따라서 직전의 값과 현재 값만을 저장할 공간이 필요하며 이는 공간복잡도 O(1)이다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |    O(N)     |    O(1)     |

현재 color를 선택할 때 최소값은 다른 2개의 색상을 칠했을 때의 cost 중 가장 작은 cost에 현재 색을 고르는 경우이다.

dp배열을 다음과 같이 선언한다.

```cpp
dp[n][color]; // n번까지의 집을 색칠했을때 현재 n번 방에 color색을 칠할 경우 최소값
```

초기 값은 다음과 같다.

```cpp
dp[0][color] = costs[0][color]
```

일반식은 다음과 같다.

```cpp
for (int color = 0; color < 3; color++) {
  int before = (color + 2) % 3;
  int next = (color + 4) % 3;
  dp[n][color] = min(dp[n-1][before], dp[n-1][next]) + costs[i][color];
}
```

여기서 직전에 고른 색과 같은 색은 고르지 못하므로 현재 고른 색과 다른 2개의 색만 이용해 갱신한다.

여기서 dp배열 중 직전의 값만 필요하므로 다음과 같이 최적화가 가능하다.

```cpp
int minCost(vector<vector<int>>& costs) {
  int dp[3] = {costs[0][0], costs[0][1], costs[0][2]};
  int before[3] = {0, 0, 0};
  int size = costs.size();

  for (int i = 1; i < size; i++) {
    for (int color = 0; color < 3; color++) {
      before[color] = min(dp[(color + 2) % 3], dp[(color + 4) % 3]) + costs[i][color];
    }

    for (int color = 0; color < 3; color++) {
      dp[color] = before[color];
    }
  }

  int answer = dp[0];
  for (int color = 1; color < 3; color++) {
    answer = min(dp[color], answer);
  }
  return answer;
}
```

## 고생한 점
