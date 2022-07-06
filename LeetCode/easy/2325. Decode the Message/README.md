# 2325. Decode the Message

[링크](https://leetcode.com/problems/decode-the-message/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

key의 길이를 N, message의 길이를 M이라 하자.

key를 순회하며 table을 채우고, 이후 message를 순회하며 해독한다.

이 경우 각각 순회에 O(N), O(M)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N + M)이다.

### 공간 복잡도

정답으로 해석된 message를 반환해야 하므로 O(M)의 공간 복잡도를 사용한다.

### table

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      11      |  O(N + M)   |    O(M)     |

key의 각 알파벳이 나오는 순서대로 'a'부터 할당한다.

이 때 공백은 넘어간다.

이후 message를 해석한다.

이를 구현하면 다음과 같다.

```cpp
string decodeMessage(string key, string message) {
  char cur = 'a';
  unordered_map<char, char> table;
  for (char &c : key) {
    if (c == ' ') continue;
    if (table.count(c) > 0) continue;

    table[c] = cur;
    cur++;
  }

  table[' '] = ' ';
  string converted = "";
  for (char &c : message) {
    converted += table[c];
  }
  return converted;
}
```

## 고생한 점
