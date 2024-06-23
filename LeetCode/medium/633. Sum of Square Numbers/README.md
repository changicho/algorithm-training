# 633. Sum of Square Numbers

[링크](https://leetcode.com/problems/sum-of-square-numbers/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 수를 C라 하자.

a를 sqrt(C)까지 순회하며 가능한 b쌍이 존재하는지 탐색한다.

이 때 sqrt함수에 O(log_2(C))의 시간 복잡도가 소요되며 이를 a에 대해 반복하므로 시간 복잡도는 O(log_2(C) \* sqrt(C))이다.

### 공간 복잡도

상수크기의 공간복잡도를 사용한다.

### sqrt 순회

| 내 코드 (ms) |      시간 복잡도      | 공간 복잡도 |
| :----------: | :-------------------: | :---------: |
|      3       | O(log_2(C) * sqrt(C)) |    O(1)     |

a를 0부터 sqrt(C)까지 순회하며 b를 찾는다.

```cpp
bool judgeSquareSum(int c) {
  for (int a = 0; a <= sqrt(c); a++) {
    double b = sqrt(c - a * a);
    if (b == (int)b) return true;
  }
  return false;
}
```

## 고생한 점
