# 2396. Strictly Palindromic Number

[링크](https://leetcode.com/problems/strictly-palindromic-number/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

N을 M 진수로 변환하는 데 O(log_M(N))의 시간 복잡도를 사용한다.

M은 1부터 N까지 이므로 이를 순회하는데 O(N)의 시간 복잡도를 사용한다.

해당 숫자를 M진수의 문자열로 변환하는데 필요한 모든 시간 복잡도는 O(N)이라 하자.

이 경우 시간 복잡도는 O(N^2)가 된다.

수학적 방법으로 답은 항상 false가 된다. 이 경우 시간 복잡도는 O(1)이다.

### 공간 복잡도

특정 숫자를 문자열로 변환하는 데 최대 O(N)의 공간 복잡도를 사용한다.

수학적 방법을 이용해 모두 false를 반환할 경우 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      2       |   O(N^2)    |    O(N)     |

해당 숫자에 대해 2부터 N-1까지 진수로 변환 후 팰린드롬 유무를 검사한다.

```cpp
string convert(int n, int base) {
  string ret = "";
  while (n > 0) {
    ret += (n % base) + '0';
    n /= base;
  }
  reverse(ret.begin(), ret.end());
  return ret;
}

bool isPalindrome(string &str) {
  int length = str.length();

  for (int i = 0; i < length / 2; i++) {
    int rI = length - 1 - i;
    if (str[i] != str[rI]) return false;
  }
  return true;
}

bool isStrictlyPalindromic(int n) {
  for (int base = 2; base <= n - 2; base++) {
    string num = convert(n, base);

    if (!isPalindrome(num)) return false;
  }
  return true;
}
```

### return false

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(1)     |    O(1)     |

특정 진수로 변환할 때 팰린드롬이 될 수 없는 경우가 반드시 존재한다.

따라서 항상 false를 반환한다.

```cpp
bool isStrictlyPalindromic(int n) { return false; }
```

## 고생한 점
