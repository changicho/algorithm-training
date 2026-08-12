# 4014. Minimum Total Price After Applying Discounts

[링크](https://leetcode.com/problems/minimum-total-price-after-applying-discounts/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

두 배열의 크기를 각각 N, M이라 하자.

정렬을 이용해 가장 큰 값에 가장 큰 할인을 적용하는 탐욕 알고리즘을 사용할 수 있다.

이 경우 O(N \* log_2(N) + M \* log_2(M))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(N + M)의 공간 복잡도를 사용한다.

### 정렬 & 그리디

| 내 코드 (ms) |           시간 복잡도            | 공간 복잡도 |
| :----------: | :------------------------------: | :---------: |
|      74      | O(N \* log_2(N) + M \* log_2(M)) |  O(N + M)   |

배열을 둘다 내림차순으로 정렬한다.

이후 값과 할인을 순차적으로 순회하며 할인된 가격을 정답에 더한다.

만약 남은 가격들이 존재하는 경우 그대로 정답에 더한다.

```cpp
double minPrice(vector<int>& prices, vector<int>& discounts) {
  sort(prices.begin(), prices.end(), greater<int>());
  sort(discounts.begin(), discounts.end(), greater<int>());

  int size1 = prices.size(), size2 = discounts.size();
  int limit = min(size1, size2);

  double answer = 0.0;
  for (int i = 0; i < limit; i++) {
    double cur = prices[i] * (100.0 - discounts[i]) / 100;

    answer += cur;
  }

  for (int i = limit; i < size1; i++) {
    answer += prices[i];
  }

  return answer;
}
```

## 고생한 점
