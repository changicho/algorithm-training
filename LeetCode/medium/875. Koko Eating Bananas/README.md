# 875. Koko Eating Bananas

[링크](https://leetcode.com/problems/koko-eating-bananas/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

모든 pile의 개수를 N, pile 중 가장 큰 값을 K라고 하자.

k를 임의로 선택했을 때 가능한지 여부를 판단하기 위해선 모든 pile을 한번씩 순회해야 하므로 inner 시간 복잡도는 O(N)이다.

k의 경우는 이진 탐색을 이용해 탐색할 수 있으며, outer 시간 복잡도는 O(log_2(K))이다.

따라서 최종 시간 복잡도는 O(N \* log_2(K))이다.

### 공간 복잡도

연산 과정중에 별도의 공간 복잡도가 필요하지 않다. 따라서 O(1)이다.

### 정리

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      56      | O(N \* log_2(K)) |    O(1)     |

k가 주어졌을 때 h시간 이내에 해결이 가능한지 아닌지 판별하는 일반 식은 다음과 같다.

pile을 k로 나눈 값의 올림이 하나의 pile을 정리하는데 들어가는 시간이다.

각 pile의 값들을 순회하며 현재 k일때 걸리는 시간을 구하고, 기존 h와 비교한다.

k의 값을 다음과 같은 조건으로 변화시킬 수 있다.

- h시간 이내에 해결이 가능함 : k의 값을 낮춰봄
- h시간 이내에 해결이 불가능함 : k의 값을 높여봄

이에 최적화된 k값을 찾기 위해 이분 탐색을 사용한다.

```cpp
int calculateHour(vector<int>& piles, int k) {
  int curH = 0;
  for (int pile : piles) {
    curH += ceil((double)pile / k);
  }
  return curH;
}

int minEatingSpeed(vector<int>& piles, int h) {
  int left = 1;
  int right = *max_element(piles.begin(), piles.end());
  int answer = 0;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (calculateHour(piles, mid) <= h) {
      answer = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return answer;
  }
```

## 고생한 점
