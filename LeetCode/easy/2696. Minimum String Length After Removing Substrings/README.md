# 2696. Minimum String Length After Removing Substrings

[링크](https://leetcode.com/problems/minimum-string-length-after-removing-substrings/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 문자열 s의 길이를 N이라 하자.

각 문자열을 왼쪽부터 순회하며 스택을 이용해 지울 수 있는 문자열을 지울 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

스택에 O(N)의 공간 복잡도를 사용한다.

### 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

문자열을 왼쪽부터 스택에 쌓아나간다.

이 때 현재 문자와 스택의 top 문자를 합쳐서 삭제할 수 있는 경우 삭제한다.

이후 스택의 크기가 남은 문자의 갯수가 된다.

```cpp
int minLength(string s) {
  stack<char> stk;

  for (char &c : s) {
    if (!stk.empty()) {
      if (c == 'B' && stk.top() == 'A') {
        stk.pop();
        continue;
      }
      if (c == 'D' && stk.top() == 'C') {
        stk.pop();
        continue;
      }
    }
    stk.push(c);
  }
  return stk.size();
}
```

## 고생한 점
