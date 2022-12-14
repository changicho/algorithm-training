# 1704. Determine if String Halves Are Alike

[링크](https://leetcode.com/problems/determine-if-string-halves-are-alike/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열 S의 길이를 L이라 하자.

문자열을 절반으로 나누고 각 문자열의 모음의 갯수를 센다.

이 경우 O(L)의 시간 복잡도를 사용한다.

### 공간 복잡도

별도로 분리한 문자열을 생성할 경우 O(L)의 공간 복잡도를 사용한다.

index만 순회할 경우 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(L)     |    O(L)     |

문자열을 절반으로 쪼개고 두 문자열의 모음의 갯수가 같은지 판단한다.

이 경우 대소문자 모음의 수를 세고 같은지 판단해야 한다.

```cpp
bool isVowel(char &c) {
  switch (tolower(c)) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
      return true;
  }
  return false;
}

int getVowelCount(string &s) {
  int count = 0;
  for (char &c : s) {
    if (isVowel(c)) count++;
  }
  return count;
}

bool halvesAreAlike(string s) {
  int length = s.size();
  string a = s.substr(0, length / 2), b = s.substr(length / 2);

  return getVowelCount(a) == getVowelCount(b);
}
```

## 고생한 점
