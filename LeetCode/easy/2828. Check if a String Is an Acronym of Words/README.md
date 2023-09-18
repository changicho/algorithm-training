# 2828. Check if a String Is an Acronym of Words

[링크](https://leetcode.com/problems/check-if-a-string-is-an-acronym-of-words/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 words의 크기를 N이라 하자.

각 첫글자들을 묶어 새로운 문자열을 생성하는 데 O(N)의 시간 복잡도를 사용한다.

이를 비교하는데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

새로운 문자열을 생성할 경우 O(N)의 시간 복잡도를 사용한다.

### 문자열 생성

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |    O(N)     |    O(N)     |

각 단어의 첫글자를 따서 새로운 문자열을 생성 후 s와 비교한다.

```cpp
bool isAcronym(vector<string>& words, string s) {
  string cur = "";
  for (string& w : words) {
    cur += w.front();
  }
  return cur == s;
}
```

## 고생한 점
