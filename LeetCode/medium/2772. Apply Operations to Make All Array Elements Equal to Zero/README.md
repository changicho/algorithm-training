# 2772. Apply Operations to Make All Array Elements Equal to Zero

[링크](https://leetcode.com/problems/apply-operations-to-make-all-array-elements-equal-to-zero/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

모든 경우를 수행할 때 O(N \* K)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

크기가 K인 슬라이딩 윈도우를 이용해 줄여야 하는 값들을 줄이며 갱신할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

슬라이딩 윈도우에 O(1)의 공간 복잡도를 사용한다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     177      |    O(N)     |    O(1)     |

현재 index i의 값을 0으로 만들기 위해 i에서부터 k개의 원소에 현재 값을 빼야 한다.

왼쪽부터 순회하며 각 수마다 빼야하는 값들을 빼주며, 이 때 빼야하는 값에 영향을 주는 수가 윈도우에서 벗어난 경우 빼야하는 수에서 제거한다.

즉 윈도우마다 수를 0으로 만들기 위한 diff값을 갱신하며 실제 원소의 값도 갱신하며 탐색을 진행한다.

이 때 현재 값보다 diff가 큰 경우 값을 빼면 음수가 되므로 불가능한 경우이다.

```cpp
bool checkArray(vector<int>& nums, int k) {
  int size = nums.size();
  int diff = 0;
  for (int i = 0; i < size; i++) {
    if (diff > nums[i]) {
      return false;
    }

    nums[i] -= diff;
    diff += nums[i];

    if (i >= k - 1) {
      diff -= nums[i - k + 1];
    }
  }

  return diff == 0;
}
```

## 고생한 점
