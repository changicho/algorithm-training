# 4030. Check ASCII Palindromic

[링크](https://leetcode.com/problems/check-ascii-palindromic/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

각 자리를 순회하며 비트 비교 연산을 수행한다. 이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 자리수 순회에 O(1)의 공간 복잡도를 사용한다.

### 비트 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

각 자리별로 비트를 비교해가며 다른지 판단한다.

이 때 정 중앙의 자리도 비트가 palindrome인지 검사해야한다.

```cpp
bool check(char a, char b) {
  for (int bit = 7; bit >= 0; bit--) {
    int left = (a >> bit) & 1;
    int right = (b >> (7 - bit)) & 1;

    if (left != right) return false;
  }
  return true;
}

bool isPalindromic(string s) {
  int size = s.size();

  for (int i = 0; i <= size / 2; i++) {
    char l = s[i], r = s[size - 1 - i];

    if (check(l, r) == false) return false;
  }

  return true;
}
```

## 고생한 점
