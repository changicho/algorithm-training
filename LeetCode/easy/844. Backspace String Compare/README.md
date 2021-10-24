# 844. Backspace String Compare

[링크](https://leetcode.com/problems/backspace-string-compare/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

두 문자열의 길이를 각각 N, M이라 하자.

스택을 이용해서 연산에 따른 문자열을 새로 만드는 경우 O(N + M)의 시간 복잡도를 사용한다.

투 포인터를 사용하는 경우 또한 마찬가지이다.

### 공간 복잡도

스택을 사용할 경우는 O(N + M)의 공간 복잡도를 사용한다.

투 포인터를 사용하는 경우 index만 저장하면 되므로 O(1)의 공간 복잡도를 사용한다.

### 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N + M)   |  O(N + M)   |

문자열을 새로 만들어 두 문자열이 같은지 비교한다.

`#` 연산의 경우 backspace 연산이므로 문자열의 맨 끝을 삭제한다.

이를 이용해 삭제 연산을 수행하며 새로운 문자열을 만든다.

```cpp
string convert(string &s) {
  string ret;

  for (char c : s) {
    if (c == '#') {
      if (!ret.empty()) ret.pop_back();
      continue;
    }
    ret.push_back(c);
  }
  return ret;
}

bool backspaceCompare(string s, string t) {
  string first = convert(s), second = convert(t);

  return first == second;
}
```

### 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N + M)   |    O(1)     |

`#`이 삭제 연산이므로 맨 뒤 index부터 탐색을 시작한다.

맨 마지막 index부터 0까지 두 문자열의 index를 같이 탐색을 진행한다.

이 때 현재 문자가 `#`인 경우, 삭제한 만큼 더 이동해야 하는 경우만큼 더 이동한다. (어차피 삭제될 것이므로)

만약 이 과정중에서 현재 보고있는 문자열이 다른 경우는 두 문자열이 다른 경우이므로 삭제 한다.

한 index가 음수에 먼저 도달한 경우는 탐색을 중지하며,
탐색이 끝난 경우 두 index가 같은지 판별한다.

```cpp
bool backspaceCompare(string s, string t) {
  int first = s.length() - 1, second = t.length() - 1;
  int firstDeleted = 0, secondDeleted = 0;

  while (first >= 0 || second >= 0) {
    while (first >= 0 && (s[first] == '#' || firstDeleted > 0)) {
      firstDeleted += s[first] == '#' ? 1 : -1;
      first--;
    }

    while (second >= 0 && (t[second] == '#' || secondDeleted > 0)) {
      secondDeleted += t[second] == '#' ? 1 : -1;
      second--;
    }

    if (first < 0 || second < 0) break;
    if (s[first] != t[second]) return false;
    first--;
    second--;
  }

  return first == second;
}
```

## 고생한 점
