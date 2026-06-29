# 3699. Number of ZigZag Arrays I

[링크](https://leetcode.com/problems/number-of-zigzag-arrays-i/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

만들 배열의 길이를 N, 값의 범위를 M이라 하자.

동적 계획법을 이용해 직전 index까지 특정 값으로 도달하는 하강,상승의 갯수를 관리한다.

이 경우 정답을 구하는데 O(NM)의 시간 복잡도를 사용한다.

### 공간 복잡도

직전값만 사용하므로 동적 계획법에 O(M)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     591      |    O(NM)    |    O(M)     |

index와 해당 값으로 끝나는 배열, 그리고 직전 상승,하강 방향 3가지에 대해서 dp식을 만들 수 있다.

이 때 직전값이 작은경우, 큰경우에 대해서 dp 값을 다음과 같이 갱신할 수 있다.

```cpp
dp[index][value][dir];

dp[0][val][dir] = 1;

dp[i][val][up] = dp[i-1][val-1][down];
dp[i][val][down] = dp[i-1][val+1][up];
```

이때 모든 직전값에 대해 하나하나 더할 경우 제한시간 내에 불가능하므로 dp식에 val부분을 prefix sum으로 관리한다.

```cpp
int zigZagArrays(int n, int l, int r) {
  const int MOD = 1e9 + 7;

  int beforeDp[2002][2] = {
      0,
  };
  int dp[2002][2] = {
      0,
  };

  for (int a = l; a <= r; a++) {
    beforeDp[a][0] = 1;
    beforeDp[a][1] = 1;
  }

  for (int i = 1; i < n; i++) {
    for (int a = l; a <= r; a++) {
      // b < a case

      dp[a][1] += beforeDp[a - 1][0];
      dp[a][1] %= MOD;

      beforeDp[a][0] += beforeDp[a - 1][0];
      beforeDp[a][0] %= MOD;
    }
    for (int a = r; a >= l; a--) {
      // b > a case

      dp[a][0] += beforeDp[a + 1][1];
      dp[a][0] %= MOD;

      beforeDp[a][1] += beforeDp[a + 1][1];
      beforeDp[a][1] %= MOD;
    }

    swap(dp, beforeDp);
    memset(dp, 0, sizeof(dp));
  }

  int answer = 0;
  for (int i = l; i <= r; i++) {
    answer += beforeDp[i][0];
    answer %= MOD;
    answer += beforeDp[i][1];
    answer %= MOD;
  }
  return answer;
}
```

## 고생한 점
