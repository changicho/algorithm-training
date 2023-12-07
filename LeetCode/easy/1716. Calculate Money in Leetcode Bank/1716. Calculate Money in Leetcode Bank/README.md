# 1716. Calculate Money in Leetcode Bank

[링크](https://leetcode.com/problems/calculate-money-in-leetcode-bank/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

직접 시뮬레이션을 수행할 경우 O(log_7(N))의 시간 복잡도를 사용한다.

수학적으로 계산할 경우 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

계산에 O(1)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      2       | O(log_7(N)) |    O(1)     |

1 부터 N 까지의 합을 더하며 각 과정마다 문제 조건에 맞게 계산한다.

```cpp
int totalMoney(int n) {
  int answer = 0;
  for (int i = 0; i < n; i++) {
    answer += (i % 7) + 1;
    answer += i / 7;
  }
  return answer;
}
```

## 고생한 점
