# 1047. Remove All Adjacent Duplicates In String

[링크](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열 S의 길이를 N이라 하자.

각 문자열을 순회하며 stack에 쌓을 경우 연속으로 중복된 문자열은 pop하는것으로 중복을 제거할 수 있다.

이 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

스택에 사용하는 공간 복잡도는 O(N)이다.

### 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      35      |    O(N)     |    O(N)     |

연속된 두개의 문자열을 삭제해야한다.

이 때 삭제 후에 또 연속된 문자열이 있는 경우 삭제를 수행해야 한다.

이를 스택을 이용해 구현하면 삭제 후에 연속된 문자열이 있는지 top만을 비교해 알 수 있다.

문자열들을 stack에 쌓으며 중복되는 경우 pop해 삭제시키는것을 반복한다.

이후 stack에 쌓인 문자들로 문자열을 만들고 뒤집어 정답을 생성한다.

```cpp
string removeDuplicates(string s) {
  stack<char> stk;

  // iterate char in s
  for (char &c : s) {
    // if c is same with before
    if (!stk.empty() && stk.top() == c) {
      stk.pop();
      continue;
    }
    stk.push(c);
  }

  // append char in stack
  string answer = "";
  while (!stk.empty()) {
    answer += stk.top();
    stk.pop();
  }

  // reverse answer
  reverse(answer.begin(), answer.end());
  return answer;
}
```

## 고생한 점
