# 14. Longest Common Prefix

[링크](https://leetcode.com/problems/longest-common-prefix/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열의 최대 개수는 200개이다. 각 문자열마다 최대 길이는 200이다.

각 문자열을 순회하며 이전에 구해놓은 prefix만 비교하는 방식으로 수행할 경우 모든 문자열을 순회하는 데 O(N)만 소요된다.

각 연산마다 길이만큼 순회하므로 O(N)

O(200^2)번 만에 수행이 가능하다.

### 공간 복잡도

문자열의 최대 길이는 200 이내이다. string으로 수행한다.

### prefix 찾기

두 문자열의 prefix를 찾기 위해 다음과 같은 함수를 사용한다.

```cpp
string getPrefix(string a, string b) {
  string prefix = "";
  int length = min(a.length(), b.length());

  for (int index = 0; index < length; index++) {
    if (a[index] != b[index]) break;
    prefix += a[index];
  }
  return prefix;
}
```

i번째 문자열과 j번째 문자열을 비교해 prefix를 찾았다고 하자.

이 prefix와 j+1번째 문자열을 비교해 prefix를 갱신한다.

갱신된 prefix와 다른 문자열을 계속해서 반복하며 prefix를 갱신한다.

최종 prefix는 모든 문자열에 해단 prefix가 된다.

이 때 문자열의 개수가 0개인경우와 문자열의 길이가 0인 경우를 고려한다.

## 정리

| 내 코드 (ms) |
| :----------: |
|      4       |

## 고생한 점
