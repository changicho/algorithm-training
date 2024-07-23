# 678. Valid Parenthesis String

[링크](https://leetcode.com/problems/valid-parenthesis-string/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

동적 계획법을 사용할 경우 시간 복잡도는 O(N^2)이다.

한번의 순회로 가능한 openBracket의 최대, 최소값을 갱신하며 정답을 찾을 경우 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

one pass로 openBracket의 최대, 최소값을 갱신하며 정답을 찾을 경우 별도의 공간이 필요하지 않다.

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

왼쪽부터 문자열을 순회하며 wildcard *을 만날 때 마다 openBracket의 최대, 최소값을 갱신한다.

최대값은 와일드 카드를 전부 openBracket으로 간주하는 경우이며, 최소값은 와일드 카드를 가능한만큼 closeBracket으로 간주하는 경우이다.

이 경우 현재까지 순회했을 때 closeBracket의 소가 더 많은 경우 정답이 될 수 없다.

마지막 까지 순회했을 때 openBracket의 개수가 0인 경우가 가능한지 판단하고 정답을 반환한다.

```cpp
bool checkValidString(string s) {
  int openMin = 0;  // counts the minimum open parenthesis
  int openMax = 0;  // counts the maximum open parenthesis

  for (char &c : s) {
    switch (c) {
      case '(':
        openMin++;
        openMax++;
        break;
      case ')':
        openMin = max(openMin - 1, 0);
        openMax--;
        break;
      case '*':
        openMin = max(openMin - 1, 0);
        openMax++;
        break;
    }

    if (openMax < 0) return false;
  }

  return openMin == 0;
}
```

## 고생한 점
