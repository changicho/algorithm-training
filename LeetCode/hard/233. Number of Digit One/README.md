# 233. Number of Digit One

[링크](https://leetcode.com/problems/number-of-digit-one/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 숫자를 N이라 하자.

0 ~ N까지 모든 숫자에 대해서 1을 셀 경우 시간 복잡도는 다음과 같다. O(N \* log_10(N))

이는 N이 매우 크므로 제한시간 내에 불가능하다.

각 자리수 중에서 1을 세기 위해서 digit별로 문제를 풀이할 수 있다.

이를 위해 다음 2가지 방법을 사용한다.

- digit별로 순회하며 해당 경우마다 count를 구하기 (math)
- 최상위 digit부터 재귀호출로 구하기

각 자리수별로 순회하며 count를 구하는 경우 O(log_10(N))의 시간 복잡도를 사용한다.

최상위 digit부터 재귀호출로 구할 경우 O(2^log_10(N))의 시간 복잡도를 사용한다.

여기서 동적 계획법을 사용할 경우 O(log_10(N))의 시간 복잡도로 풀이가 가능하다.

### 공간 복잡도

math를 이용해 각 자리수별로 count를 구할 수 있다.

이 경우 각 자리수만 순회하며 나온 숫자로 정답을 갱신하므로 O(1)의 공간 복잡도를 사용한다.

재귀 호출을 이용할 경우 함수 호출에 최대 O(log_10(N))의 공간 복잡도를 사용하며, 미리 구한 값을 사용할 경우 O(log_10(N))의 공간 복잡도를 사용한다.

### 재귀 호출

| 내 코드 (ms) | 시간 복잡도  | 공간 복잡도  |
| :----------: | :----------: | :----------: |
|      0       | O(log_10(N)) | O(log_10(N)) |

주어진 숫자 N을 다음 부분으로 나눌 수 있다.

- 제일 왼쪽에 있는 숫자 외에 모두 0인 수 : A
- 제일 왼쪽에 있는 숫자를 제거했을 때 남은 수 : B

A인 경우를 생각해보자

이 경우 해당 자리수를 L이라 할때 L-1 크기의 전부 9로 구성된 숫자의 count를 이용해 1부터 해당 자리수까지의 반복되는 수를 구할 수 있다.

예시로 4XXX에 대해서 다음의 경우에 대해 구하면 된다.

- 1000
- 2000
- 3000
- 4000

즉 L-1 길이의 9로만 구성된 count를 4번 반복해 구할 수 있다.

여기서 앞자리가 1인 경우는 모든 숫자가 가장 왼쪽에 있는 1을 count한다.

여기서 N의 맨 앞자리가 1인 경우는 9로만 구성된 count를 온전하게 모두 가져갈 수 없으므로 맨 앞자리가 1이 나오는 경우는 (B + 1)개가 된다.

그 외의 경우는 1인 경우를 포함하므로 L의 길이를 가지는 10^L을 더한다.

이제 남은 B에 대해서 count하기 위해 재귀호출을 이용해 이를 구해준다.

여기서 모든 숫자가 9인 길이 L에 대한 count는 자주 사용하며 이를 다음과 같이 구할 수 있다.

```cpp
dp[i]; // count of 999... that length is i

dp[1] = 1;

for(int digit = 0; digit < 10; digit++){
  if(digit == 1){
    dp[i] += pow(10, i - 1);
  }else{
    dp[digit - 1];
  }
}
```

따라서 다음과 같이 구현할 수 있다.

```cpp
int countDigitOne(int n) {
  if (n < 1) return 0;
  if (n >= 1 && n < 10) return 1;

  int divider = 1, firstDigit = n;
  int length = 0;
  while (firstDigit >= 10) {
    firstDigit /= 10;
    divider *= 10;
    length++;
  }

  // count of 0 <= ~ < divider count. (0 ~ 999...)
  int dividerCount = firstDigit * memoization[length];
  // most left 1 count
  int firstCount = firstDigit == 1 ? n - divider + 1 : divider;
  // last part count
  int lastCount = countDigitOne(n % divider);

  return firstCount + dividerCount + lastCount;
}
```

### 수학

| 내 코드 (ms) | 시간 복잡도  | 공간 복잡도 |
| :----------: | :----------: | :---------: |
|      0       | O(log_10(N)) |    O(1)     |

각 자리수별로 순회하며 현재 해당하는 숫자에 대해서 다음과 같이 구할 수 있다.

```cpp
int countDigitOne(int n) {
  int answer = 0;

  for (long long digit = 1; digit <= n; digit *= 10) {
    long long divider = digit * 10;

    int curPartCount = (n / divider) * digit;
    int leftPartCount =
        min(max(n % divider - digit + 1, (long long)0), digit);

    answer += curPartCount + leftPartCount;
  }

  return answer;
}
```

## 고생한 점
