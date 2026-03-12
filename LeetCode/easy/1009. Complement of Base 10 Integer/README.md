# 1009. Complement of Base 10 Integer

[링크](https://leetcode.com/problems/complement-of-base-10-integer/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

각 자리수별로 순회하며 수를 완성할 경우 O(log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

순회에 O(1)의 공간 복잡도를 사용한다.

### 비트 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       | O(log_2(N)) |    O(1)     |

각 자리수를 순회하며 현재 자리 비트가 0인 경우 answer에 해당 비트를 더해준다.

이 때 현재 비트가 N 이상인 경우는 순회하지 않는다.

```cpp
int bitwiseComplement(int n) {
  int answer = 0;
  if (n == 0) return 1;
  for (int i = 1; i < n; i <<= 1) {
    if ((n & i) == 0) {
      answer += i;
    }
  }
  return answer;
}
```

## 고생한 점
