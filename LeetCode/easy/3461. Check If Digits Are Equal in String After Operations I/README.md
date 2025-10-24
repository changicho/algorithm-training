# 3461. Check If Digits Are Equal in String After Operations I

[링크](https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

시뮬레이션을 이용해 정답을 구할 경우 N + (N-1) + (N-2) + ... + 2 = O(N^2)의 시간이 소요된다.

### 공간 복잡도

시뮬레이션을 이용해 정답을 구할 경우 새로운 문자열을 저장하기 위한 O(N)의 공간이 소요된다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      7       |   O(N^2)    |    O(N)     |

시뮬레이션을 이용해 매번 길이가 1 줄어든 새로운 문자열을 생성한다.

이후 문자열의 길이가 2일 때 두 문자가 같은지 확인한다.

```cpp
bool hasSameDigits(string s) {
  while (s.size() > 2) {
    string newS = "";

    int size = s.size();
    for (int i = 0; i < size - 1; i++) {
      int cur = (s[i] - '0') + (s[i + 1] - '0');
      cur %= 10;

      newS += cur + '0';
    }

    s = newS;
  }

  if (s.size() < 2) return false;
  return s[0] == s[1];
}
```

## 고생한 점
