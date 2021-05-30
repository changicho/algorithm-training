# 205. Isomorphic Strings

[링크](https://leetcode.com/problems/isomorphic-strings/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

두 문자열을 비교하기 위해 두 문자열을 동시에 한번의 순회한다.

한번의 순회를 하므로 outer iteration의 시간 복잡도는 O(N)이다.

내부적으로 비교를 위해 글자를 비교하기 위해 hash를 사용할 경우 O(1)의 시간 복잡도를 사용한다.

따라서 최종 시간 복잡도는 O(N)이다.

### 공간 복잡도

모든 ascii 문자들에 대해 각 글자들에 치환하는 값들을 알아야 한다.

이는 총 256 글자이므로 O(256)만큼의 공간 복잡도가 필요하다.

총 2개의 table이 필요하므로 이는 O(512)이며 상수공간만큼이므로 공간 복잡도는 O(1)이다.

### 변환

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(1)     |

각 문자를 순회하며 다른 문자가 나올 때마다 그 문자를 숫자로 치환한다.

이 문자를 숫자로 치환한 table을 두 문자열 모두 생성한다.

원본 문자를 숫자로 치환한 문자열을 생성하고 비교한다.

혹은 각 자리수별로 변환할 때 서로 table에 맛지 않는경우 두 문자열을 convert 해도 다른 문자열이다.

```cpp
bool isIsomorphic(string s, string t) {
  int m1[256] = {0}, m2[256] = {0};
  int length = s.length();

  for (int i = 0; i < length; i++) {
    if (m1[s[i]] != m2[t[i]]) {
      return false;
    }

    m1[s[i]] = i + 1;
    m2[t[i]] = i + 1;
  }
  return true;
}
```

```cpp
bool isIsomorphic(string s, string t) {
  string first = convert(s);
  string second = convert(t);
  return first == second;
}

string convert(string& s) {
  int count = 1;
  unordered_map<char, char> m;

  m[s[0]] = '0';
  string ret = {m[s[0]]};

  for (int i = 1; i < s.length(); i++) {
    if (m[s[i]] != 0) {
      ret += m[s[i]];
      continue;
    }

    m[s[i]] = count + '0';
    count += 1;
    ret += m[s[i]];
  }

  return ret;
}
```

## 고생한 점
