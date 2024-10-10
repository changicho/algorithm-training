# 1963. Minimum Number of Swaps to Make the String Balanced

[링크](https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

스택을 사용할 경우 O(N)의 시간 복잡도로 해결이 가능하다.

괄호쌍의 종류가 하나이므로 한번의 순회로 풀이가 가능하다. 이에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

스택을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

열린괄호의 갯수만 셀 경우 O(1)의 공간 복잡도로 해결이 가능하다.

### 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     122      |    O(N)     |    O(N)     |

문자열 s의 여는 괄호와 닫는 괄호의 갯수는 같다.

스택을 이용해 쌍으로 맞춰지지 않는 괄호의 갯수를 구한다.

이 때 스택에 남는 괄호의 갯수가 쌍이 맞춰지지 않는 갯수이다.

이 갯수는 짝수이며 여는 괄호와 닫는 괄호의 갯수가 동일하다.

이 중 여는 괄호쌍의 갯수를 구하고 이 중 절반만 위치를 변경하면 유효한 괄호 쌍을 만들 수 있다.

이 때 갯수가 홀수인 경우는 한 쌍을 더 추가해야 한다.

```cpp
int minSwaps(string s) {
  stack<char> stk;

  for (char &c : s) {
    if (!stk.empty() && c == ']' && stk.top() == '[') {
      stk.pop();
      continue;
    }
    stk.push(c);
  }

  int count = stk.size() / 2;

  return (count + 1) / 2;
}
```

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     103      |    O(N)     |    O(1)     |

위 방법에서 남는 여는 괄호쌍의 갯수를 바로 세고, 이를 이용해 정답을 구할 수 있다.

```cpp
int minSwaps(string s) {
  int count = 0;

  for (char &c : s) {
    switch (c) {
      case '[': {
        count++;
        break;
      }
      case ']': {
        if (count > 0) count--;
        break;
      }
    }
  }

  return (count + 1) / 2;
}
```

## 고생한 점
