# 2299. Strong Password Checker II

[링크](https://leetcode.com/problems/strong-password-checker-ii/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

password의 길이를 L이라 하자.

글자수, 해당 문자 포함 여부를 판단하는데 O(L)의 시간 복잡도를 사용한다.

이후 인접한 2글자가 같은지 검사하는데 O(L)의 시간 복잡도를 사용한다.

### 공간 복잡도

해당 문자 포함 여부, 인접 여부 등을 판단하는 flag 변수들에 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(L)     |    O(L)     |

각 문자들을 순회하며 다음 문자들을 포함하는 지 판단한다.

- 숫자
- 대문자
- 소문자
- 특수문자

이후 인접한 문자들이 같은 경우가 있는지 판단한다.

문자열의 길이가 8 이상인 경우 판단식을 모두 충족하는 지 flag변수들을 비교한다.

```cpp
bool strongPasswordCheckerII(string password) {
  bool hasDigit = false;
  bool hasUpper = false;
  bool hasLower = false;
  bool hasSameAdj = false;
  bool hasSpecial = false;

  string special = "!@#$%^&*()-+";
  unordered_set<char> specials;
  for (char &c : special) {
    specials.insert(c);
  }

  if (password.length() < 8) return false;
  for (char &c : password) {
    if (isdigit(c)) hasDigit = true;
    if (islower(c)) hasLower = true;
    if (isupper(c)) hasUpper = true;
    if (specials.count(c) > 0) hasSpecial = true;
  }

  int length = password.length();
  for (int i = 0; i < length - 1; i++) {
    if (password[i] == password[i + 1]) hasSameAdj = true;
  }

  return hasDigit && hasUpper && hasLower && hasSpecial && !hasSameAdj;
}
```

## 고생한 점
