# 2309. Greatest English Letter in Upper and Lower Case

[링크](https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

각 문자열을 순회하며 소문자, 대문자 알파벳이 나오는 경우 체크한다.

여기에 O(N)의 시간 복잡도를 사용한다.

이후 각 알파벳을 순회하며 소문자, 대문자가 모두 나온 경우를 찾는다.

이 과정에 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 알파벳 범위는 'A' ~ 'Z' 까지 이므로 O(1)의 공간 복잡도를 사용한다.

### 정리

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      9       |    O(N)     |    O(1)     |

문자열의 모든 문자를 순회하며 upper, lower 인 경우 나타났는지 체크한다.

이후 알파벳을 순회하며 lower, upper가 모두 나타난 경우 체크한다.

이 때 가장 큰 값을 반환해야 하므로 'Z' 부터 순회한다.

```cpp
string greatestLetter(string s) {
  bool upper[26] = {
      0,
  };
  bool lower[26] = {
      0,
  };

  for (char &c : s) {
    if (islower(c)) {
      lower[c - 'a'] = true;
    } else if (isupper(c)) {
      upper[c - 'A'] = true;
    }
  }

  for (char c = 'Z'; c >= 'A'; c--) {
    if (upper[c - 'A'] && lower[c - 'A']) {
      return {
          c,
      };
    }
  }
  return "";
}
```

## 고생한 점

lower, upper를 동시에 1 이상 나타나는 만족하는 알파벳을 찾아야한다.
