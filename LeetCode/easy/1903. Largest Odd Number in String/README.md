# 1903. Largest Odd Number in String

[링크](https://leetcode.com/problems/largest-odd-number-in-string/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열 S의 길이를 N이라 하자.

문자열을 왼쪽부터 순회하며 현재 문자가 홀수인 경우 이전까지의 문자열을 정답의 후보로 볼 수 있다.

이를 판단하는 데 순회해야 하므로 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

정답의 길이는 최대 N이다.

따라서 정답에 O(N)의 공간 복잡도가 필요하다.

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      34      |    O(N)     |    O(N)     |

문자열을 왼쪽부터 순회하며 현재 문자가 홀수인 경우 이전까지의 문자열을 정답의 후보로 볼 수 있다.

가장 숫자 값이 큰 문자열을 찾아야 하며, 이는 가장 긴 문자열을 찾으면 된다. (왼쪽부터 포함하는 부분 문자열을 사용하므로)

```cpp
string largestOddNumber(string num) {
  int size = num.size();

  int lastI = -1;
  for (int i = 0; i < size; i++) {
    char c = num[i];
    int digit = c - '0';

    if (digit % 2 == 1) {
      lastI = i;
    }
  }
  string answer = num.substr(0, lastI + 1);
  return answer;
}
```

## 고생한 점
