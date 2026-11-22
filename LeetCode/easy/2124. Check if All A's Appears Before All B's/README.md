# 2124. Check if All A's Appears Before All B's

[링크](https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

순회에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

```cpp
bool checkString(string s) {
  bool checkB = false;

  for (char& c : s) {
    if (c == 'b') {
      checkB = true;
    } else if (checkB) {
      return false;
    }
  }
  return true;
}
```

## 고생한 점
