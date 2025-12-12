# 1437. Check If All 1's Are at Least Length K Places Away

[링크](https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

순회하며 이전 1의 위치를 저장하고, 현재 1의 위치와 이전 1의 위치의 차이가 k 이하인지 확인한다.

이에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

이전 1의 위치를 저장하는데 O(1)의 공간 복잡도를 사용한다.

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(1)     |    O(1)     |

i=0부터 순회하며 1이 나온 경우 직전에 나온 1과 현재 1의 위치 차이를 확인한다.

이 때 해당 차이가 k 이하인 경우 false를 반환한다.

초기값은 -1e6으로 설정하여 첫 번째 1이 나오는 경우에도 문제없이 동작하도록 한다.

```cpp
bool kLengthApart(vector<int>& nums, int k) {
  int size = nums.size();
  int before = -1e6;

  for (int i = 0; i < size; i++) {
    if (nums[i] == 0) continue;

    if (i - before <= k) return false;
    before = i;
  }

  return true;
}
```

## 고생한 점
