# 856. Score of Parentheses

[링크](https://leetcode.com/problems/score-of-parentheses/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

stack을 이용할 경우 O(N)의 시간 복잡도를 사용한다.

순회하며 depth를 사용할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

stack을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

depth를 이용해 정답에 더할 경우 O(1)의 공간 복잡도를 사용한다.

### 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

스택을 사용해 괄호가 열릴 때마다의 점수를 저장후, 괄호가 닫힐 때 직전 점수에 2를 곱한 값과 스택에 저장한 값을 이용해 현재 값을 갱신한다.

```cpp
int scoreOfParentheses(string s) {
  stack<int> stk;

  int temp = 0;
  for (char& c : s) {
    if (c == '(') {
      stk.push(temp);

      temp = 0;
    } else {
      int before = temp == 0 ? 1 : temp * 2;
      temp = stk.top() + before;
      stk.pop();
    }
  }
  return temp;
}
```

### 순회 (깊이)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

`()`와 같이 여닫는 괄호쌍이 존재할 때 정답에 더해지는 점수는 2 * 깊이 만큼이다.

이를 이용해 정답해 더해지는 여닫는 괄호 모양에 현재까지 열려있는 깊이를 사용해 정답을 갱신한다.

```cpp
int scoreOfParentheses(string s) {
  int size = s.size();
  int depth = 1;
  int answer = 0;
  for (int i = 0; i < size; i++) {
    char& c = s[i];
    if (c == '(') {
      depth *= 2;
    } else {
      depth /= 2;
      if (s[i - 1] == '(') {
        answer += depth;
      }
    }
  }
  return answer;
}
```

## 고생한 점
