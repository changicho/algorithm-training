# 557. Reverse Words in a String III

[링크](https://leetcode.com/problems/reverse-words-in-a-string-iii/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

각 경우마다 문자열을 순회하며 뒤집어야 한다. 이에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

새로운 문자열을 반환할 경우 O(N)의 공간 복잡도를 사용한다.

기존 문자열을 뒤집어 활용할 경우 O(1)의 공간 복잡도를 사용한다.

### 문자열 뒤집기

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      14      |    O(N)     |    O(1)     |

```cpp
string reverseWords(string s) {
  int size = s.size();
  int left = -1, right = -1;

  for (int i = 0; i < size; i++) {
    if (s[i] == ' ') {
      reverse(s.begin() + left, s.begin() + right + 1);
      left = -1;
      right = -1;
    } else {
      if (left == -1) left = i;
      right = i;
    }
  }
  reverse(s.begin() + left, s.begin() + right + 1);

  return s;
}
```

## 고생한 점
