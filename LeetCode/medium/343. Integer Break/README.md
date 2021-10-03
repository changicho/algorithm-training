# 343. Integer Break

[링크](https://leetcode.com/problems/integer-break/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 숫자를 N이라 하자.

모든 경우를 탐색할 경우 최악의 경우 O(N!)의 시간 복잡도가 소요되며 이는 제한시간 내에 불가능하다.

따라서 동적 계획법을 이용해 이전 계산 값을 이용한다.

이 경우 시간 복잡도는 O(N^2)가 소요된다.

### 공간 복잡도

N의 후보에 대해서 dp값을 선언한다. 따라서 O(N)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |   O(N^2)    |    O(N)     |

특정 숫자에 대해서, 양의 정수의 합으로 나타낸 뒤, 해당 숫자들의 곱의 최대값은 다음과 같이 나타낼 수 있다.

```cpp
maximum[n] = maximum[n - part] * maximum[part]
```

즉 모든 숫자에 대해서 n - part와 part까지의 최대값으로 나타낼 수 있다.

따라서 특정 숫자에 대한 곱의 최대값을 구할 경우 이를 이용해 n까지의 곱의 최대값을 구할 수 있다.

dp를 다음과 같이 설정한다.

```cpp
dp[i]; // i를 양의 정수의 합으로 나타냈을 때 해당 숫자들의 곱의 최대값
```

초기값은 다음과 같다.

```cpp
dp[1] = 1;
```

일반 식은 다음과 같다.

```cpp
dp[cur] = cur;
// 모든 pre값에 대해서 탐색
dp[cur] = cur;
for (int part = 1; part <= cur / 2; ++part) {
  int left = dp[cur - part];
  int right = dp[part];

  dp[cur] = max(dp[cur], left * right);
}
```

이를 이용해 모든 dp값을 구하고 정답을 구할 수 있다.

```cpp
// 직전에 구한 값들로 최대값을 구함
for (int part = 1; part < n; part++) {
  answer = max(answer, dp[part] * dp[n - part]);
}
```

이를 구현하면 다음과 같다.

```cpp
int integerBreak(int n) {
  vector<int> dp(n + 1, 0);

  dp[1] = 1;
  for (int cur = 2; cur <= n; ++cur) {
    dp[cur] = cur;
    for (int part = 1; part <= cur / 2; ++part) {
      int left = dp[cur - part];
      int right = dp[part];

      dp[cur] = max(dp[cur], left * right);
    }
  }

  int answer = 0;
  for (int i = 1; i < n; i++) {
    answer = max(answer, dp[i] * dp[n - i]);
  }
  return answer;
}
```

## 고생한 점
