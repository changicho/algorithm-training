# 20. Valid Parentheses

[링크](https://leetcode.com/problems/valid-parentheses/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열의 길이는 10^4 까지이다.

각 문자열별로 순회하며 해결할 수 있으므로 시간 복잡도는 O(N) 이며 제한시간 내에 충분하다.

### 공간 복잡도

입력받는 문자의 형태는 다음과 같다.

```cpp
"()[]{}"
```

따라서 stack의 타입은 char로 설정한다.

### 스택

문자열을 차례대로 순회하며 스택을 이용해 계산한다.

- 여는 경우 : 스택에 push
- 닫는 경우 : 스택의 top이 자기자신과 쌍인지 구분

아스키 코드는 0 ~ 127 이므로 128 크기의 배열을 생성한다.

```cpp
char table[128];
table['('] = ')';
table['['] = ']';
table['{'] = '}';
```

이후 문자열의 각 문자를 순회하며 스택을 이용해 올바른지 여부를 판별한다.

이 때 순회 이후에 스택이 비어져있지 않은경우 올바르지 않음에 유의한다.

```cpp
bool answer = true;
stack<char> bracket;

for (char c : s) {
  switch (c) {
    case '(':
    case '[':
    case '{': {
      bracket.push(c);
      break;
    }
    case ')':
    case ']':
    case '}': {
      if (bracket.empty() || table[bracket.top()] != c) {
        answer = false;
        break;
      }
      bracket.pop();
      break;
    }
  }
}

if (!bracket.empty()) {
  answer = false;
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      0       |

## 고생한 점
