# A - Not Acceptable

[링크](https://atcoder.jp/contests/abc406/tasks/abc406_a)

| 난이도 |
| :----: |
|  100   |

## 설계

### 시간 복잡도

입력받은 네 숫자를 비교하는데 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

입력받은 네 숫자를 저장하는데 O(1)의 공간 복잡도를 사용한다.

### 변환

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(1)     |    O(1)     |

```cpp
bool solution(int a, int b, int c, int d) {
  int deadline = a * 60 + b;
  int submission = c * 60 + d;

  return submission <= deadline;
}
```

## 고생한 점
