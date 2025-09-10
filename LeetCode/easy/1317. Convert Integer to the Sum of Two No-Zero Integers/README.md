# 1317. Convert Integer to the Sum of Two No-Zero Integers

[링크](https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

모든 경우를 탐색하는 경우 O(N)이 소요된다.

이 때 각 수에 0이 포함되는지 검사해야 한다. 이에 O(log_10(N))이 소요된다.

따라서 총 시간 복잡도는 O(N \* log_10(N))이 된다.

### 공간 복잡도

각 수에 0이 있는지 판단하는데 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) |    시간 복잡도    | 공간 복잡도 |
| :----------: | :---------------: | :---------: |
|      0       | O(N \* log_10(N)) |    O(1)     |

두 수를 더해서 N이 되는 경우를 탐색한다.

각 수를 A, B라 하자. 해당 수에 0이 포함되는지 검사한다.

만약 두 수 모두 0이 포함되지 않는다면 해당 수를 반환한다.

```cpp
bool hasZero(int num) {
  while (num > 0) {
    if (num % 10 == 0) {
      return true;
    }
    num /= 10;
  }
  return false;
}

vector<int> getNoZeroIntegers(int n) {
  for (int i = 1; i <= n / 2; i++) {
    int a = i, b = n - i;

    if (!hasZero(a) && !hasZero(b)) {
      return {a, b};
    }
  }

  return {-1, -1};
}
```

## 고생한 점
