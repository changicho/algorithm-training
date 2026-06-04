# 2144. Minimum Cost of Buying Candies With Discount

[링크](https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

배열을 정렬 후 가장 큰 값부터 정답에 더하며 매번 3번째 원소의 경우 정답에서 제거한다.

이에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      0       | O(N \* log_2(N)) |    O(N)     |

문제 조건에 따라 3번째 값을 0으로 만들기 위해선 앞서 선택한 2개의 값보다 작은 값을 선택해야 한다.

해당 3번째 값을 가장 큰 값으로 선택하기 위해선 1,2번째 값을 가장 큰 값으로 선택하고 남은 값들 중 가장 큰 값을 3번째 값으로 선택한다.

이를 반복하며 정답을 구한다.

```cpp
int minimumCost(vector<int>& cost) {
  int answer = 0;
  int size = cost.size();

  sort(cost.begin(), cost.end());

  for (int i = size - 1; i >= 0; i--) {
    answer += cost[i];
    i--;
    if (i < 0) break;
    answer += cost[i];
    i--;
  }

  return answer;
}
```

## 고생한 점
