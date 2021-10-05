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

### 동적 계획법 - dp only

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |   O(N^2)    |    O(N)     |

위 식에서 초기값을 설정하기 위해 다음 식을 추가한다.

```cpp
dp[cur] = max(dp[cur], max(part * (cur - part), part * dp[cur - part]));
// part * (cur - part)를 추가함.
```

이는 2개의 숫자로만 이루어지는 경우와 2개 이상의 숫자로 구성되는 경우 모두 탐색하기 위함이다.

```cpp
int integerBreak(int n) {
  if (n <= 2) return 1;

  vector<int> dp(n + 1, 0);

  dp[1] = 0;
  dp[2] = 1;

  for (int cur = 3; cur <= n; cur++) {
    for (int part = 1; part < cur; part++) {
      dp[cur] = max(dp[cur], max(part * (cur - part), part * dp[cur - part]));
    }
  }
  return dp[n];
}
```

### 수학

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       | O(log_2(N)) |    O(1)     |

[풀이 링크](<https://leetcode.com/problems/integer-break/discuss/80785/O(log(n))-Time-solution-with-explanation>)

```cpp
int integerBreak(int n) {
  if (n <= 3) {
    return n - 1;
  }

  if (n % 3 == 0) {
    return (int)pow(3, n / 3);
  } else if (n % 3 == 1) {
    return 2 * 2 * (int)pow(3, (n - 4) / 3);
  }

  return 2 * (int)pow(3, n / 3);
}
```

## 고생한 점
