# A - Closed interval

[링크](https://atcoder.jp/contests/abc454/tasks/abc454_a)

| 난이도 |
| :----: |
|  100   |

## 설계

### 시간 복잡도

두 수를 입력받아 그 사이 정수의 수를 구하는데 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

계산에 O(1)의 공간 복잡도를 사용한다.

### 계산

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(1)     |    O(1)     |

```cpp
int solution(int left, int right) { return right - left + 1; }
```

## 고생한 점
