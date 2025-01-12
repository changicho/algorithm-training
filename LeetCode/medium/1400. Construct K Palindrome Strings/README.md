# 1400. Construct K Palindrome Strings

[링크](https://leetcode.com/problems/construct-k-palindrome-strings/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

모든 경우를 탐색할 경우 O(2^N)의 시간 복잡도가 소요되므로 제한시간 내에 불가능하다.

각 알파벳의 갯수를 세고 이 중 홀수의 갯수를 센다.

이 경우 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

문자열의 알파벳의 수를 세는 데 O(1)의 공간 복잡도가 필요하다.

### count

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(1)     |

K개의 팰린드롬으로 분할 가능하기 위해선 홀수인 문자의 갯수가 K 이하여야 한다.

따라서 문자열 s의 각 알파벳의 갯수를 세고, 홀수인 갯수를 센다.

또한 s의 길이가 K보다 작은 경우 불가능하므로 이 경우에 대해서 예외처리한다.

```cpp
bool canConstruct(string s, int k) {
  if (s.size() < k) return false;
  int count[26] = {
      0,
  };
  for (char &c : s) {
    count[c - 'a']++;
  }

  int oddCount = 0;
  for (int i = 0; i < 26; i++) {
    oddCount += count[i] % 2;
  }

  return oddCount <= k;
}
```

## 고생한 점
