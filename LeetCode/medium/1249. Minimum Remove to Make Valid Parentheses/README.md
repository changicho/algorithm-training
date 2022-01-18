# 1249. Minimum Remove to Make Valid Parentheses

[링크](https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 S의 길이를 L이라 하자.

문자열을 순회하며 valid한 괄호쌍을 구현해야 한다.

이를 위해 stack을 이용한다.

문자열을 순회하며 괄호쌍에 대해 stack을 이용한다. 이후 삭제해야할 괄호들에 따로 표시를 한다.

이후 이를 순회하며 삭제할 문자열을 삭제한다.

이에 시간 복잡도는 O(L)이 소요된다.

### 공간 복잡도

스택에 최대 O(L)의 공간 복잡도를 사용한다.

### 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      27      |    O(L)     |    O(L)     |

문자열을 순회하며 스택을 이용해 valid한 괄호쌍만을 찾는다.

이후 스택에 남아있는 여는 괄호, 쌍이 없는 닫는 괄호를 삭제하기 위해 '-' 문자로 치환한다.

이후 문자열을 순회하며 삭제해야 할 문자 외에 정답으로 추가한다.

이를 구현하면 다음과 같다.

```cpp
string minRemoveToMakeValid(string s) {
  int length = s.length();

  stack<int> stk;

  // find valid
  for (int i = 0; i < length; i++) {
    char &c = s[i];
    if (c == '(') {
      stk.push(i);
      continue;
    } else if (c == ')') {
      if (stk.empty()) {
        s[i] = '-';
        continue;
      }

      stk.pop();
      continue;
    }
    continue;
  }

  // check to remove
  while (!stk.empty()) {
    s[stk.top()] = '-';
    stk.pop();
  }

  // convert
  string answer = "";
  for (char &c : s) {
    if (c == '-') continue;
    answer += c;
  }

  return answer;
}
```

## 고생한 점
