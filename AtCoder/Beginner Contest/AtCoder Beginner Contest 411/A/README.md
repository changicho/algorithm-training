# A - Required Length

[링크](https://atcoder.jp/contests/abc411/tasks/abc411_a)

| 난이도 |
| :----: |
|  100   |

## 설계

### 시간 복잡도

문자열 S의 길이를 N, 숫자의 길이를 L이라 하자.

N과 L을 비교하는데 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

길이 비교에 O(1)의 공간 복잡도를 사용한다.

### 길이 비교

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(1)     |    O(1)     |

```cpp
bool solution(string s, int length) {
  int size = s.size();

  return size >= length;
}
```

## 고생한 점
