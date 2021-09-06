# 1137. N-th Tribonacci Number

[링크](https://leetcode.com/problems/n-th-tribonacci-number/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

매 경우마다 직전의 피보나치 수를 구할 경우 시간 초과가 발생할 수 있다.

따라서 직전의 연산결과를 저장해 이용한다.

이 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

n-1, n-2, n-3 3개의 값만을 저장해 풀이할 수 있으며 이 경우 공간 복잡도는 O(1)이다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

문제에서 주어진 일반식은 다음과 같다.

```cpp
dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
```

이전의 연산 결과를 이용한다고 가정했을 때 결국 우리는 연속된 3개의 값만을 이용해 문제를 해결할 수 있다.

```cpp
int tribonacci(int n) {
  vector<int> dp = {1, 1, 0};

  if (n < 3) {
    return dp[2 - n];
  }

  for (int i = 2; i < n; i++) {
    int temp = dp[0] + dp[1] + dp[2];

    dp[2] = dp[1];
    dp[1] = dp[0];
    dp[0] = temp;
  }

  return dp.front();
}
```

## 고생한 점
