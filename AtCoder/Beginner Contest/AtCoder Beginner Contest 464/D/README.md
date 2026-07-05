# D - Celester

[링크](https://atcoder.jp/contests/abc464/tasks/abc464_d)

| 난이도 |
| :----: |
|  400   |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

각 날짜마다 2가지 상태가 존재한다.

동적 계획법을 사용할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법에 직전값만 사용하면 되므로 O(1)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      23      |    O(N)     |    O(1)     |

각 날짜별로 상태는 2가지가 존재한다. (R, S)

다음과 같은 동적 계획법 배열을 선언한다.

```cpp
int dp[i][condition]; // until i, max happiness in condition (R, S)

// init
dp[0]['R'] = (isRainy) ? 0 : -x[0];
dp[0]['S'] = (!isRainy) ? 0 : -x[0];

// update
dp[i]['R'] = max(dp[i-1][condition]) + (isRainy) ? 0 : -x[i];
dp[i]['S'] = max(dp[i-1]['R'] + y[i-1], dp[i-1]['S']) + (!isRainy) ? 0 : -x[i];
```

즉 현재 날짜의 특정 날씨를 가지는 최대값을 매번 계산한다.

각 날짜별로 날씨를 변화하는 경우 cost를 추가하며, 전날 비가 오고 오늘 날씨가 화창한 경우에는 값을 증가시킬 수도 있다.

```cpp
long long solution(int size, string& s, vector<int>& x, vector<int>& y) {
  // 0 : rainy
  // 1 : sunny
  long long before[2] = {
      0,
  };

  before[0] = (s[0] == 'R') ? 0 : -x[0];
  before[1] = (s[0] == 'S') ? 0 : -x[0];

  for (int i = 1; i < size; i++) {
    long long dp[2];
    dp[0] = max(before[1], before[0]);
    dp[1] = max(before[1], before[0] + y[i - 1]);

    bool isRainy = s[i] == 'R';

    if (isRainy) {
      dp[1] -= x[i];
    } else {
      dp[0] -= x[i];
    }

    swap(before, dp);
  }

  return max(before[0], before[1]);
}
```

## 고생한 점
