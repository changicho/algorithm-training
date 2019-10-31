# 1181. 단어 정렬

[링크](https://www.acmicpc.net/problem/1181)

난이도\_37%

## 정리

내 코드 : 40 ms;

두 string "aaaa" 와 "bbbb"를 비교해보자

1. "aaaa" > "bbbb" = 0
2. "aaaa" < "bbbb" = 1

string은 자체 비교연산을 가지고 있다.

따라서 문제에 주어진 조건대로 우선순위를 부여해 compare 함수를 만들었다.

```cpp
bool compare(string a, string b) {
  if (a.length() > b.length()) {
    return false;
  }

  if (a.length() == b.length()) {
    return a < b;
  }
  return true;
}
```
