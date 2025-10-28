# 2048. Next Greater Numerically Balanced Number

[링크](https://leetcode.com/problems/next-greater-numerically-balanced-number/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

가능한 마지막 정답을 M이라 하자. 입력받은 수는 N, 10^6 이하이며 M은 10^7 미만임이 보장된다.

M까지 순회하며 정답을 만족하는지 확인할 수 있다. 이 때 O(log_10(M))의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(M \* log_10(M))이다.

### 공간 복잡도

숫자를 확인하는데 O(1)의 공간 복잡도를 사용한다.

### 완전탐색

| 내 코드 (ms) |    시간 복잡도    | 공간 복잡도 |
| :----------: | :---------------: | :---------: |
|      82      | O(M \* log_10(M)) |    O(1)     |

```cpp
bool check(int num) {
  int count[10] = {
      0,
  };
  while (num > 0) {
    count[num % 10]++;
    num /= 10;
  }

  if (count[0] > 0) return false;
  for (int i = 1; i <= 9; i++) {
    if (count[i] == 0) continue;
    if (count[i] != i) return false;
  }
  return true;
}

int nextBeautifulNumber(int n) {
  for (int i = n + 1; i <= 1e7; i++) {
    if (check(i)) return i;
  }
  return -1;
}
```

## 고생한 점
