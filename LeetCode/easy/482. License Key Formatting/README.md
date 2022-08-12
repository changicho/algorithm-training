# 482. License Key Formatting

[링크](https://leetcode.com/problems/license-key-formatting/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

N을 순회하며 대문자로 변경하고 -를 조절한다.

이 경우 순회에 O(N)의 시간복잡도를 사용한다.

### 공간 복잡도

정답으로 새로운 문자열을 반환하는데 O(N)의 공간 복잡도를 사용한다.

### 정리

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      15      |    O(N)     |    O(N)     |

s를 뒤집어 순회하고 직전에 채워넣은 문자열의 갯수가 K개가 된 경우 -를 추가한다.

이 때 기존의 -는 무시한다.

이후 맨 마지막에 -가 추가된 경우 이를 pop하고 뒤집는다.

```cpp
string licenseKeyFormatting(string s, int k) {
  string filtered = "";
  for (char &c : s) {
    if (c == '-') continue;
    filtered += toupper(c);
  }

  reverse(filtered.begin(), filtered.end());
  string ret = "";
  int count = 0;
  for (char &c : filtered) {
    ret += c;
    count++;

    if (count == k) {
      ret += '-';
      count = 0;
    }
  }

  if (ret.back() == '-') ret.pop_back();
  reverse(ret.begin(), ret.end());
  return ret;
}
```

## 고생한 점
