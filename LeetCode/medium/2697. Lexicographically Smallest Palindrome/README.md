# 2697. Lexicographically Smallest Palindrome

[링크](https://leetcode.com/problems/lexicographically-smallest-palindrome/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

문자열에서 해당 문자를 같게 만들어야 하는 위치들이 존재한다.

이 중에서 최소 횟수로 변경하며 가장 사전준으로 앞서게 하기 위해 변경해야 하는 부분만 둘 중 작은 값으로 변경한다.

이에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

입력받은 문자열을 그대로 사용할 경우 O(1)의 공간 복잡도를 사용한다.

### 순회 & 그리디

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      36      |    O(N)     |    O(1)     |

문자열을 팰린드롬으로 만들기 위해 최소 횟수만 변경한다.

이 때 변경해야 하는 두 문자중 사전순으로 앞서는 값으로 변경한다.

```cpp
string makeSmallestPalindrome(string s) {
  int size = s.size();

  for (int i = 0; i < size / 2; i++) {
    int rI = size - 1 - i;

    if (s[i] != s[rI]) {
      s[i] = s[rI] = min(s[i], s[rI]);
    }
  }

  return s;
}
```

## 고생한 점
