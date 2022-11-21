# 224. Basic Calculator

[링크](https://leetcode.com/problems/basic-calculator/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

스택을 이용해 괄호식의 식을 묶고 계산할 수 있다.

이 경우 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

스택을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      10      |    O(N)     |    O(N)     |

각 문자열을 순차적으로 순회하며 각 숫자마다 다음을 진행한다.

- 숫자 : 현재까지 숫자들 뒤에 숫자를 붙임
- 부호 : 현재까지 순회한 숫자에 지전 부호 연산을 정답에 수행하고, 초기화함. 현재 부호로 변경
- 여는 괄호 : 현재 계산 결과와 부호를 스택에 삽입. 계산값과 부호를 초기화
- 닫는 괄호 : 계산 결과와 부호를 정답에 수행. 초기화 후 스택의 top을 pop하며 연산.

즉 괄호가 열릴 때마다 스택에 쌓고, 괄호가 닫힐 때마다 스택에서 뺀다.

이를 구현하면 다음과 같다.

```cpp
int calculate(string s) {
  stack<int> nums;
  stack<int> signs;

  int answer = 0;

  int cur = 0;
  int sign = 1;
  for (char &c : s) {
    if (isdigit(c)) {
      cur *= 10;
      cur += c - '0';
    } else if (c == '+' || c == '-') {
      answer += cur * sign;
      cur = 0;

      sign = c == '+' ? +1 : -1;
    } else if (c == '(') {
      nums.push(answer);
      signs.push(sign);

      answer = 0;
      sign = 1;
    } else if (c == ')') {
      answer += cur * sign;
      cur = 0;

      answer = answer * signs.top();
      answer = answer + nums.top();

      signs.pop();
      nums.pop();
    }
  }

  answer += cur * sign;
  return answer;
}
```

## 고생한 점
