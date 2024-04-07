# 1614. Maximum Nesting Depth of the Parentheses

[링크](https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

stack을 사용할 경우 순회를 한번만 하므로 시간 복잡도는 O(N)이다.

### 공간 복잡도

stack에 문자를 삽입할 경우 O(N)의 공간 복잡도가 필요하다.

count만 사용할 경우 별도의 공간이 필요하지 않으므로 O(1)의 공간 복잡도가 필요하다.

### stack count

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(1)     |

문자열을 순회하며 괄호의 개수를 센다.

이 때 s는 valid한 식이므로 현재 열린 괄호를 만나면 count를 증가시키고, 닫힌 괄호를 만나면 count를 감소시킨다.

각 과정에서 count의 최대값을 갱신한다.

```cpp
int maxDepth(string s) {
  int answer = 0;
  int depth = 0;
  for (char &c : s) {
    if (c == '(') {
      depth++;
    } else if (c == ')') {
      depth--;
    }
    answer = max(answer, depth);
  }
  return answer;
}
```

## 고생한 점
