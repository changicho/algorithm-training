# 3884. First Matching Character From Both Ends

[링크](https://leetcode.com/problems/first-matching-character-from-both-ends/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

순회에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

```cpp
int firstMatchingIndex(string s) {
  int size = s.size();

  for (int i = 0; i <= size / 2; i++) {
    if (s[i] == s[size - 1 - i]) return i;
  }
  return -1;
}
```

## 고생한 점
