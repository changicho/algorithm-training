# 1071. Greatest Common Divisor of Strings

[링크](https://leetcode.com/problems/greatest-common-divisor-of-strings/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 두 문자열의 길이를 각각 N, M이라 하자.

모든 경우를 직접 탐색할 경우 특정 토큰 문자열에 대해 O(N + M)의 시간 복잡도를 사용한다.

이를 가능한 토큰 문자열의 쌍에 대해 반복하므로 O((N + M) \* min(N, M))의 시간 복잡도를 사용한다.

GCD를 이용할 경우 O(N + M)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 과정마다 문자열을 생성하고 비교하므로 O(N + M)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) |       시간 복잡도       | 공간 복잡도 |
| :----------: | :---------------------: | :---------: |
|      26      | O((N + M) \* min(N, M)) |  O(N + M)   |

나누어 떨어질 수 있는 토큰 문자열은 두 문자열 중 최소 길이 까지 가능하다.

따라서 길이가 적은 문자열의 앞에서부터 토큰 문자열을 증가시키며 나누어 떨어지는지 판단한다.

```cpp
bool canDivide(string base, string token) {
  int length = base.size();

  if (length % token.length() != 0) return false;
  int div = length / token.length();

  string temp = "";
  for (int i = 0; i < div; i++) {
    temp += token;
  }

  return temp == base;
}

string gcdOfStrings(string str1, string str2) {
  if (str2.length() > str1.length()) swap(str1, str2);

  string token = "";
  string answer = "";
  for (int i = 0; i < str2.size(); i++) {
    token += str2[i];

    if (canDivide(str1, token) && canDivide(str2, token)) {
      answer = token;
    }
  }
  return answer;
}
```

### gcd

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N + M)   |  O(N + M)   |

```cpp
string gcdOfStrings(string str1, string str2) {
  if (str1 + str2 != str2 + str1) {
    return "";
  }

  int gcdLength = gcd(str1.size(), str2.size());
  return str1.substr(0, gcdLength);
}
```

## 고생한 점
