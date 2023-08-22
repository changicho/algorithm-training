# 459. Repeated Substring Pattern

[링크](https://leetcode.com/problems/repeated-substring-pattern/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

주어진 문자열 s의 길이를 N이라 하자.

문자열의 subString을 패턴으로 모든 문자열을 생성 가능한지 판별해야 한다.

이를 brute force 방법으로 구현할 경우 시간 복잡도는 O(N^2)이다.

여기서 가능한 pattern의 갯수는 최대 2 \* sqrt(N)개 까지이다. (N/2보다 작은 약수의 갯수)

따라서 시간 복잡도는 O(N \* sqrt(N)) 이다.

혹은 문자열을 두번 이어 붙인 문자열에서 첫번째 문자와 마지막 문자를 제거한 문자열이 s에 존재하는지 판별할 수 있다.

이 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

pattern을 사용하는 데 O(N)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      41      |   O(N^2)    |    O(N)     |

패턴 문자열을 직접 생성하며, s를 패턴문자열로 만들 수 있는지 검사한다.

```cpp
bool isRepeated(string &s, string &pattern) {
  if (s.size() % pattern.size() != 0) return false;

  int index = 0;
  while (index < s.size() && s.find(pattern, index) == index) {
    index += pattern.size();
  }

  if (index == s.size()) return true;
  return false;
}

bool repeatedSubstringPattern(string s) {
  string pattern = "";

  for (char &c : s) {
    pattern += c;
    if (pattern.size() > s.size() / 2) return false;

    if (isRepeated(s, pattern)) return true;
  }
  return false;
}
```

### 문자열 합치기

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      36      |    O(N)     |    O(N)     |

s를 두번 이어 붙인 문자열 t를 생성한다.

만약 t의 일부분에서 s를 찾을 수 있다면 s는 패턴으로 생성 가능한 문자열이다.

(s의 일부분이 맨 처음, 맨 끝과 연결되지 않는 경우)

여기서 t에서 s를 찾기 위해 KMP 알고리즘을 사용할 수 있다. 이 경우 O(N)의 시간 복잡도로 해결이 가능하다.

```cpp
bool repeatedSubstringPattern(string s) {
  string t = s + s;
  if (t.substr(1, t.size() - 2).find(s) != -1) return true;
  return false;
}
```

## 고생한 점
