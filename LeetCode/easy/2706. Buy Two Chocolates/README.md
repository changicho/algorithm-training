# 2706. Buy Two Chocolates

[링크](https://leetcode.com/problems/buy-two-chocolates/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 prices의 크기를 N이라 하자.

정답을 구하기 위해 가장 작은 값 2개를 구해야 한다.

이를 위해 정렬을 사용할 경우 O(N \* log_2(N))의 시간 복잡도가 소요된다.

한번의 순회로 가장 작은 값 2개를 구한다. 이에 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

값 2가지를 저장하면 되므로 O(1)의 공간 복잡도가 필요하다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |    O(N)     |    O(1)     |

가장 작은 값 2개를 구해 더할 경우 남는 돈을 제일 많이 남길 수 있다.

순회를 이용해 가장 작은 값과 그 다음 값을 구한다.

```cpp
int buyChoco(vector<int>& prices, int money) {
  int first = INT_MAX, second = INT_MAX;
  for (int& p : prices) {
    if (p < first) {
      second = first;
      first = p;
    } else if (p < second) {
      second = p;
    }
  }

  if (first + second > money) return money;
  return money - (first + second);
}
```

## 고생한 점
