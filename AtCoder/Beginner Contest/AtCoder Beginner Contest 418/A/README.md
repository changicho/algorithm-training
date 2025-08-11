# A - I'm a teapot

[링크](https://atcoder.jp/contests/abc418/tasks/abc418_a)

| 난이도 |
| :----: |
|  100   |

## 설계

### 시간 복잡도

입력받은 문자열의 길이를 N이라 하자.

맨 끝 3자리만 확인하면 되므로 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

맨 끝 3자리만 비교하므로 O(1)의 공간 복잡도를 사용한다.

### 비교

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(1)     |    O(1)     |

```cpp
auto solution(int n, string &s) {
  int size = s.size();
  if (size < 3) return false;

  if (s[size - 3] != 't') return false;
  if (s[size - 2] != 'e') return false;
  if (s[size - 1] != 'a') return false;

  return true;
}
```

## 고생한 점
