# A - Leftrightarrow

[링크](https://atcoder.jp/contests/abc345/tasks/abc345_a)

| 난이도 |
| :----: |
|  100   |

## 설계

### 시간 복잡도

입력받은 문자열 S의 길이를 N이라 하자.

순회하며 각 위치에 올바른 문자가 있는지 확인한다. 이에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

순회에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(N)     |    O(1)     |

각 위치별로 올바른 문자가 존재하는지 확인한다.

```cpp
bool solution(string &s) {
  int size = s.size();

  if (s.front() != '<' || s.back() != '>') return false;
  for (int i = 1; i < size - 1; i++) {
    if (s[i] != '=') return false;
  }

  return true;
}
```

## 고생한 점
