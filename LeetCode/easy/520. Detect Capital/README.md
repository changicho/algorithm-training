# 520. Detect Capital

[링크](https://leetcode.com/problems/detect-capital/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

하나의 조건에서 각 문자열이 valid한지 검사하는데 O(N)의 시간 복잡도를 사용한다.

조건은 총 3가지이므로 이를 모두 탐색할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

valid한지 검사하는데 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

각 문자열을 순회하며 다음 3가지 경우를 탐색한다.

- 모두 대문자
- 모두 소문자
- 첫글자만 대문자 (CamelCase)

이를 구현하면 다음과 같다.

```cpp
bool isAllUpper(string &word) {
  for (char &c : word) {
    if (islower(c)) return false;
  }
  return true;
}

bool isAllLower(string &word) {
  for (char &c : word) {
    if (isupper(c)) return false;
  }
  return true;
}

bool isCamelCase(string &word) {
  int length = word.size();
  if (islower(word.front())) return false;

  for (int i = 1; i < length; i++) {
    if (isupper(word[i])) return false;
  }
  return true;
}

bool detectCapitalUse(string word) {
  if (isAllUpper(word)) return true;
  if (isAllLower(word)) return true;
  if (isCamelCase(word)) return true;

  return false;
}
```

## 고생한 점
