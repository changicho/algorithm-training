# 1230. Toss Strange Coins

[링크](https://leetcode.com/problems/toss-strange-coins/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

prob의 크기를 N, 입력받은 수를 target이라 하자. (N <= 1,000)

N번 던져 동전에서 앞면에 target번 나온 확률을 구해야 한다.

모든 경우의 수를 탐색할 경우 O(2^N)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

동적 계획법을 사용할 경우 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법에 O(N^2)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      37      |   O(N^2)    |   O(N^2)    |

다음과 같은 dp식을 선언한다.

```cpp
// index번 까지 던져서 count개의 앞면이 나온 경우
double dp[index][count];
```

이를 이용해 index번째 까지 던져 나온 경우마다의 확률을 구할 수 있다.

```cpp
// init
dp[0][0] = 1 - prob[0]; // 처음 동전을 던져 뒷면이 나와야함
dp[0][1] = prob[0]; // 처음 동전을 던져 앞면이 나와야함

// update
dp[i][0] = dp[i - 1][0] * zero; // 계속 뒷면이 나와야함
for (int count = 1; count <= target && count <= (i + 1); count++) {
  dp[i][count] += dp[i - 1][count - 1] * one;
  dp[i][count] += dp[i - 1][count] * zero;
}
```

이를 이용해 다음과 같이 구현할 수 있다.

```cpp
double probabilityOfHeads(vector<double>& prob, int target) {
  int size = prob.size();

  // dp[index][count]
  double dp[1001][1001] = {
      0.0,
  };

  dp[0][0] = 1 - prob[0];
  dp[0][1] = prob[0];

  for (int i = 1; i < size; i++) {
    double one = prob[i], zero = 1 - prob[i];

    dp[i][0] = dp[i - 1][0] * zero;
    for (int count = 1; count <= target && count <= (i + 1); count++) {
      dp[i][count] += dp[i - 1][count - 1] * one;
      dp[i][count] += dp[i - 1][count] * zero;
    }
  }

  return dp[size - 1][target];
}
```

## 고생한 점
