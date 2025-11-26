# A - Candy Cookie Law

[링크](https://atcoder.jp/contests/abc430/tasks/abc430_a)

| 난이도 |
| :----: |
|  100   |

## 설계

### 시간 복잡도

입력받은 숫자 4개를 비교하는데 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

입력받은 숫자 4개를 저장하기 위한 O(1)의 공간 복잡도를 사용한다.

### 비교

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(1)     |    O(1)     |

```cpp
auto solution(int a, int b, int c, int d) {
  if (a <= c) {
    return b > d;
  }
  return false;
}
```

## 고생한 점
