# 1518. Water Bottles

[링크](https://leetcode.com/problems/water-bottles/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 병의 갯수를 N, 교환하는 병의 갯수를 M이라 하자.

시뮬레이션을 수행할 경우 음료가 있는 병의 갯수가 0이 될 때까지 반복해야 한다.

이 때 새로 채워지는 병의 갯수는 빈 병 / M 이다.

이 경우 매 경우마다 M으로 나누게 되므로 시간 복잡도는 O(log_M(N))이다.

### 공간 복잡도

시뮬레이션을 사용할 경우 O(1)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       | O(log_M(N)) |    O(1)     |

매 경우마다 시뮬레이션을 수행하며 빈 병의 수를 M으로 나눈 만큼 새로운 병을 채운다.

이후 교환한 병을 제거한다.

이를 빈 병의 수가 M보다 작아질 때까지 반복한다.

```cpp
int numWaterBottles(int numBottles, int numExchange) {
  int full = numBottles, empty = 0;

  int answer = 0;

  while (full > 0 || empty > 0) {
    answer += full;
    empty += full;
    full = 0;

    if (empty < numExchange) break;

    int div = empty / numExchange;

    full += div;
    empty -= div * numExchange;
  }

  return answer;
}
```

## 고생한 점
