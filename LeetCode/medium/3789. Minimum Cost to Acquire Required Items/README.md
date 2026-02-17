# 3789. Minimum Cost to Acquire Required Items

[링크](https://leetcode.com/problems/minimum-cost-to-acquire-required-items/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 값에 대해 그리디 알고리즘을 사용해 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

그리디 알고리즘에 O(1)의 공간 복잡도를 사용한다.

### 탐욕 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

1, 2번 아이템을 각각 필요한 개수만큼 구매하는 것과, 두 아이템이 포함된 아이템을 구매하는 것 중 더 저렴한 방법을 선택한다.

이후 남은 1, 2번 아이템에 대해 각각 필요한 개수만큼 구매하는 것과, 두 아이템이 포함된 아이템을 구매하는 것 중 더 저렴한 방법을 선택한다.

```cpp
long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
  long long answer = 0;

  int duplicated = min(need1, need2);
  if (costBoth <= cost1 + cost2) {
    answer += (long long)costBoth * duplicated;
  } else {
    answer += (long long)(cost1 + cost2) * duplicated;
  }
  need1 -= duplicated;
  need2 -= duplicated;

  if (need1 > 0) {
    answer += (long long)need1 * min(costBoth, cost1);
  }
  if (need2 > 0) {
    answer += (long long)need2 * min(costBoth, cost2);
  }
  return answer;
}
```

## 고생한 점
