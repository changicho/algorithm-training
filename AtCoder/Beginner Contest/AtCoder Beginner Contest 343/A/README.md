# A - Wrong Answer

[링크](https://atcoder.jp/contests/abc343/tasks/abc343_a)

| 난이도 |
| :----: |
|  100   |

## 설계

### 시간 복잡도

입력받은 두 수를 A, B라 하자.

A와 B의 합을 구하고 해당 합과 다른 수를 출력한다.

O(1)의 시간 복잡도로 풀이 가능하다.

### 공간 복잡도

O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(1)     |    O(1)     |

```cpp
int solution(int a, int b) {
  int sum = a + b;

  for (int i = 0; i <= 9; i++) {
    if (i != sum) return i;
  }

  return -1;
}
```

## 고생한 점
