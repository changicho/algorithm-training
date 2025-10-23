# 3100. Water Bottles II

[링크](https://leetcode.com/problems/water-bottles-ii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 두 수를 각각 N, M이라 하자.

매 경우 시뮬레이션을 사용할 경우 O(sqrt(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

O(1)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      2       | O(sqrt(N))  |    O(1)     |

```cpp
int maxBottlesDrunk(int numBottles, int numExchange) {
  int answer = 0;
  int drink = 0;
  while (numBottles > 0) {
    drink += numBottles;
    answer += numBottles;
    numBottles = 0;
    while (drink >= numExchange) {
      drink -= numExchange;
      numBottles++;
      numExchange++;
    }
  }
  return answer;
}
```

## 고생한 점
