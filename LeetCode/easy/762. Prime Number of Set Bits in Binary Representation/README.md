# 762. Prime Number of Set Bits in Binary Representation

[링크](https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 수의 범위를 N이라 하자.

각 경우마다 비트의 수가 소수인지 판단해야 한다. 비트는 최대 32개 이므로 이를 O(1)로 판단할 수 있다.

따라서 시간 복잡도는 O(N)이다.

### 공간 복잡도

비트를 판단하는데 O(1)의 공간이 필요하다.

### 완전탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

각 수의 범위는 최대 10^6이며 비트의 수는 최대 20개이므로, 20개 이하의 소수만 판단하면 된다.

이를 각 범위마다 모두 판단하는 방식으로 풀이할 수 있다.

```cpp
bool check(int x) {
  return (x == 2 || x == 3 || x == 5 || x == 7 || x == 11 || x == 13 || x == 17 || x == 19);
}

int countPrimeSetBits(int left, int right) {
  int answer = 0;
  for (int i = left; i <= right; i++) {
    int count = __builtin_popcount(i);

    if (check(count)) answer++;
  }
  return answer;
}
```

## 고생한 점
