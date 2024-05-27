# 552. Student Attendance Record II

[링크](https://leetcode.com/problems/student-attendance-record-ii/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

동적 계획법을 이용할 경우 현재 상황을 갱신하는데 O(1)의 시간 복잡도를 사용한다.

이를 모든 날짜에 대해 수행할 경우 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

모든 날짜에 대한 정보를 저장할 경우 O(N)의 공간 복잡도가 필요하다.

직전 날짜에 대한 정보만 저장할 경우 O(1)의 공간 복잡도가 필요하다.

### 동적 계획법 (space optimized)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      72      |    O(N)     |    O(1)     |

현재 출결 상황은 다음 3가지중 하나이다

- 결석
- 지각
- 출석

이 때 각 경우는 다음과 같이 나눌 수 있다.

- 오늘 결석하는 경우 : 이전까지 결석한 경우가 0인 경우의 합
- 오늘 지각하는 경우 : 이전까지 연속된 지각 횟수가 0,1인 경우의 합
- 오늘 출석하는 경우 : 이전까지 모든 경우의 합

따라서 위 경우를 이용해 현재 경우의 수들을 갱신한다.

정리하면 현재 연속지각횟수와 결석횟수의 경우의 수는 다음과 같다.

```cpp
int dp[late][absent];
// late : 0 ~ 2
// absent : 0 ~ 1
```

이를 이용해 구현하면 다음과 같다.

```cpp
const int MOD = 1e9 + 7;

int checkRecord(int n) {
  // [late][absent]
  int dp[3][2] = {
      0,
  };

  // Absent, Late, Present
  dp[0][1] = dp[1][0] = dp[0][0] = 1;
  for (int i = 2; i <= n; i++) {
    int newDp[3][2] = {
        0,
    };
    // Absent
    for (int late = 0; late <= 2; late++) {
      newDp[0][1] += dp[late][0];
      newDp[0][1] %= MOD;
    }

    // Late
    for (int late = 1; late <= 2; late++) {
      for (int a = 0; a <= 1; a++) {
        newDp[late][a] += dp[late - 1][a];
        newDp[late][a] %= MOD;
      }
    }

    // Present
    for (int late = 0; late <= 2; late++) {
      for (int a = 0; a <= 1; a++) {
        newDp[0][a] += dp[late][a];
        newDp[0][a] %= MOD;
      }
    }

    // copy
    swap(dp, newDp);
  }

  int answer = 0;
  for (int late = 0; late <= 2; late++) {
    for (int a = 0; a <= 1; a++) {
      answer += dp[late][a];
      answer %= MOD;
    }
  }
  return answer;
}
```

## 고생한 점
