# 896. Monotonic Array


[링크](https://leetcode.com/problems/monotonic-array/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 길이를 N이라 하자.

각 원소는 -10^5 ~ 10^5 까지이다.

한번의 순회로 내림차순, 오름차순인지 판단할 수 있다. 이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

순회에 O(1)의 공간 복잡도를 사용한다.

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     133      |    O(N)     |    O(1)     |

연속된 두 값의 차이를 diff라고 하자.

현재 diff와 이전 diff의 부호가 다른 경우 모노토닉 하지 않다고 판단할 수 있다.

이 때 diff가 0인 경우는 무시한다.

diff를 매번 계산할 경우 int형으로 overflow가 발생할 수 있으므로 1, -1로 치환한다.

```cpp
bool isMonotonic(vector<int>& nums) {
  int size = nums.size();

  int diff = 0;

  for (int i = 1; i < size; i++) {
    if (nums[i] == nums[i - 1]) continue;

    if (diff * (nums[i] - nums[i - 1]) < 0) return false;
    diff = nums[i] - nums[i - 1] > 0 ? 1 : -1;
  }
  return true;
}
```

## 고생한 점
