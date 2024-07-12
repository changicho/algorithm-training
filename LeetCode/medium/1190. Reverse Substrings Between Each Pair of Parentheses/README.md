# 1190. Reverse Substrings Between Each Pair of Parentheses

[링크](https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

스택을 이용해 매번 괄호 부분을 뒤집을 수 있다. 이 경우 순회에 O(N), 뒤집는 데 O(N)의 시간 복잡도가 필요하다.

따라서 총 O(N^2)의 시간 복잡도가 필요하다.

각 괄호쌍 별로 이동해야 하는 방향을 찾고 순회하며 정답을 구할 수 있다.

이 경우 두번의 순회를 하므로 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답 문자열에 O(N)의 공간 복잡도가 필요하다.

### 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |   O(N^2)    |    O(N)     |

스택을 이용해 상황을 저장하며 직접 문자열을 뒤집는다.

이때 괄호는 무시한다.

```cpp
string reverseParentheses(string s) {
  string temp = "";

  stack<string> stk;

  for (char &c : s) {
    if (c == '(') {
      stk.push(temp);
      temp = "";
    } else if (c == ')') {
      reverse(temp.begin(), temp.end());
      temp = stk.top() + temp;
      stk.pop();
    } else {
      temp += c;
    }
  }

  return temp;
}
```

### two pass (wormhole transport)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

각 괄호쌍의 index들을 저장할 수 있다.

이후 index를 0부터 순회하며 괄호쌍을 만난 경우 현재 방향의 반대방향으로 이동해야 한다.

이 때 시작 위치는 괄호쌍의 다른 index 이므로 이를 사용해 순회한다.

```cpp
string reverseParentheses(string s) {
  int size = s.length();
  stack<int> stk;
  vector<int> pairs(size, -1);

  for (int from = 0; from < size; ++from) {
    if (s[from] == '(') {
      stk.push(from);
    }
    if (s[from] == ')') {
      int to = stk.top();
      stk.pop();
      pairs[from] = to;
      pairs[to] = from;
    }
  }

  string answer = "";
  for (int i = 0, dir = 1; i < size; i += dir) {
    if (s[i] == '(' || s[i] == ')') {
      i = pairs[i];
      dir *= -1;
    } else {
      answer += s[i];
    }
  }
  return answer;
}
```

## 고생한 점
