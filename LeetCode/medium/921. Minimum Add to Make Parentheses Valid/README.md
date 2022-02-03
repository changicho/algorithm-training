# 921. Minimum Add to Make Parentheses Valid

[링크](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

주어진 문자열의 길이를 L이라 하자.

각 문자열을 순회하며 valid 하지 않은 쌍의 갯수를 세면 된다.

이 경우 스택을 이용해 valid한 경우를 각 상황별로 알 수 있다.

이 경우 한번의 순회를 통해 판단할 수 있으므로 O(L)의 시간 복잡도를 사용한다.

### 공간 복잡도

스택에 O(L)의 공간 복잡도를 사용한다.

괄호의 종류가 한가지이므로 정수를 사용해 풀이할 수 있다.

이 경우 공간 복잡도는 O(1)이다.

### 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(L)     |    O(L)     |

각 문자열을 순서대로 순회하며 각 경우에 대해 다음 연산을 수행한다.

- 여는 괄호 : 스택에 push한다.
- 닫는 괄호 :
  - 스택이 비었을 경우 앞에 여는 괄호를 붙여야 하므로 정답을 증가시킨다.
  - 스택이 비지 않았을 경우 스택의 top을 pop한다.

순회를 끝낸 이후 스택이 비지 않았을 경우 그만큼 닫는 괄호쌍이 부족하므로 그 크기만큼 정답을 증가시킨다.

이를 구현하면 다음과 같다.

```cpp
int minAddToMakeValid(string s) {
  stack<char> stk;

  int answer = 0;
  for (char &c : s) {
    if (c == '(') {
      stk.push(c);
      continue;
    }

    if (stk.empty()) {
      answer += 1;
      continue;
    }

    stk.pop();
  }

  answer += stk.size();

  return answer;
}
```

### 카운터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(L)     |    O(1)     |

위 방법에서 stack의 push, pop대신에 정수를 이용한다.

```cpp
int minAddToMakeValid(string s) {
  int counter = 0;

  int answer = 0;
  for (char &c : s) {
    if (c == '(') {
      counter++;
      continue;
    }

    if (counter == 0) {
      answer += 1;
      continue;
    }

    counter--;
  }

  answer += counter;

  return answer;
}
```

## 고생한 점
