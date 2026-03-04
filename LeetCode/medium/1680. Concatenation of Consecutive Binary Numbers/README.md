# 1680. Concatenation of Consecutive Binary Numbers

[링크](https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

각 수를 2진수 변환하는데 O(log_2(N))의 시간 복잡도를 사용하며 

각 과정에서 정답을 더할 때 N개의 수를 변환하므로 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

직접 수를 변환해 사용할 경우 정답에 O(1)의 공간 복잡도를 사용한다.

### 진수 변환

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     342      | O(N \* log_2(N)) |    O(1)     |

맨 마지막에 위치하는 수부터 2진수로 변환하여 정답에 더하는 방식으로 구현한다.

```cpp
int concatenatedBinary(int n) {
  const int MOD = 1e9 + 7;

  int answer = 0;
  int digit = 1;

  for (int i = n; i >= 1; i--) {
    int num = i;
    while (num > 0) {
      if ((num % 2) == 1) {
        answer += digit;
        answer %= MOD;
      }

      num /= 2;
      digit *= 2;
      digit %= MOD;
    }
  }

  return answer;
}
```

## 고생한 점
