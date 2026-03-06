# 1784. Check if Binary String Has at Most One Segment of Ones

[링크](https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

순회하며 1이 나오는 구간의 수를 셀 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

순회에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

```cpp
bool checkOnesSegment(string s) {
  int size = s.size();
  int count = 0;

  char before = '0';
  for (int i = 0; i < size; i++) {
    if (s[i] == '0' && before == '1') {
      count++;

      if (count > 1) return false;
    }
    before = s[i];
  }
  if (before == '1') count++;

  return count <= 1;
}
```

## 고생한 점
