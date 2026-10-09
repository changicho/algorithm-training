# 1021. Remove Outermost Parentheses

[링크](https://leetcode.com/problems/remove-outermost-parentheses/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

순회하며 `(` 문자와 `)` 문자의 수를 센 뒤 차이를 비교하며 정답을 구할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답 문자열을 생성하는데 O(N)의 공간 복잡도를 사용한다.

### depth count

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

문자열을 순회하며 열린, 닫힌 문자의 수에 따라 count를 변화시킨다

- `(` : +1
- `)` : -1

이를 이용해 가장 depth가 낮은 괄호쌍을 제외한다.

이 때 `(` 문자의 경우 열린 문자의 수가 1 이상인 경우 해당 문자들은 정답에 더할 수 있고

`)` 문자의 경우 닫힌 문자의 수가 1 초과인 경우 정답에 더할 수 있다.

```cpp
string removeOuterParentheses(string s) {
  string answer = "";
  int depth = 0;

  for (char& c : s) {
    if (c == '(') {
      if (depth > 0) {
        answer += c;
      }
      depth++;
    } else {
      if (depth > 1) {
        answer += c;
      }
      depth--;
    }
  }
  return answer;
}
```

## 고생한 점
