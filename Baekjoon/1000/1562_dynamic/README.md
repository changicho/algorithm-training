# 1562. 계단 수

[링크](https://www.acmicpc.net/problem/1562)

| 난이도 | 정답률(\_%) | 시간 제한(초) |
| :----: | :---------: | :-----------: |
| Gold I |   46.731    |       2       |

## 설계

### 시간 복잡도

N은 1보다 크거나 같고, 100보자 작은 자연수이다.

모든 경우의 수를 탐색하는 경우 제한 시간 내에 불가능하다. 각 경우마다 대략 2^100 개의 가지 수가 존재하며, 이는 중복되는 경우또한 포함이기 때문이다.

따라서 동적 계획법을 이용해 이전 값을 이용해 계산한다.

### 공간 복잡도

정답을 1,000,000,000으로 나눈 나머지를 출력해야 한다. 정답을 구하는 덧셈 연산에서 두 값은 1,000,000,000 이내로 주어지므로 최악의 경우에도 int형 범위로 충분하다.

따라서 int형으로 선언한다.

### 동적 계획법

0부터 9까지 숫자를 사용하는 것을 고려하지 않았을 때 일반식은 다음과 같이 나타낼 수 있다.

```cpp
// depth : 문자열의 길이
// number : 현재 끝자리 숫자
dp[depth][number] = dp[depth-1][number-1] + dp[depth-1][number+1];
// number가 0이거나 9인 경우는 둘 중 하나만 더한다.
```

정답은 0부터 9까지 모든 수를 사용한 문자열만 count해야 한다.

따라서 배열에 인자로 0부터 9까지 사용했는지 여부를 인자로 사용한다.

0부터 9까지 총 10가지가 존재하고 경우의 수는 2^10 이므로 비트마스킹을 이용할 수 있다.

```cpp
// or연산을 통해 비트 추가
new_digit = digit | 1 << number;

// new_digit을 순회하며 바꾼다.
dp[depth][number][new_digit] += dp[depth - 1][number - 1][digit];
dp[depth][number][new_digit] += dp[depth - 1][number + 1][digit];
```

초기값은 각 숫자로 이루어진 1, 2, 3, 4 ... 와 같은 경우이므로 다음과 같다.

(0으로 시작할 수는 없음에 유의한다.)

```cpp
for (int number = 1; number <= 9; ++number) {
  dp[1][number][1 << number] = 1;
}
```

위 일반항을 이용해 각 변수들의 수를 증가시키며 경우의 수를 모두 구한다.

이 때 시간 복잡도는 O(N \* 10 \* 2^10) 이며 이는 N이 최악의 경우라도 1,000^2 정도이므로 제한시간 내에 충분하다.

```cpp
for (int depth = 2; depth <= N; depth++) {
  for (int number = 0; number <= 9; number++) {
    for (int digit = 0; digit <= (1 << 10) - 1; digit++) {
      if (number != 0) {
        dp[depth][number][digit | (1 << number)] += dp[depth - 1][number - 1][digit];
        dp[depth][number][digit | (1 << number)] %= MOD;
      }

      if (number != 9) {
        dp[depth][number][digit | (1 << number)] += dp[depth - 1][number + 1][digit];
        dp[depth][number][digit | (1 << number)] %= MOD;
      }
    }
  }
}

for (int number = 0; number <= 9; number++) {
  answer = (answer + dp[N][number][(1 << 10) - 1]) % MOD;
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      8       |       0        |

## 고생한 점
