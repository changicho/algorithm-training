# 3517. Smallest Palindromic Rearrangement I

[링크](https://leetcode.com/problems/smallest-palindromic-rearrangement-i/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

정렬순으로 가장 앞서는 정답을 찾기 위해 카운팅 정렬을 사용한다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답 문자열 생성에 O(N)의 공간 복잡도를 사용한다. 각 글자의 카운팅에 O(1)의 공간 복잡도를 사용한다.

### 카운팅 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      25      |    O(N)     |    O(N)     |

팰린드롬으로 변환 가능한 문자열 s가 주어지므로, 각 알파벳의 갯수를 센 뒤 'a'부터 앞에 추가해 정답을 생성한다.

이 때 중앙에 하나의 문자만 들어올 수도 있으므로 이를 별도로 체크한다.

```cpp
string smallestPalindrome(string s) {
  int count[26] = {
      0,
  };
  for (char& c : s) {
    count[c - 'a']++;
  }

  string a = "";
  string b = "";

  char center = 0;

  for (int i = 0; i < 26; i++) {
    int half = count[i] / 2;

    a += string(half, 'a' + i);
    b += string(half, 'a' + i);

    if (count[i] % 2 == 1) {
      center = ('a' + i);
    }
  }

  if (center) {
    a += center;
  }

  reverse(b.begin(), b.end());
  return a + b;
}
```

## 고생한 점
