# 2962. Count Subarrays Where Max Element Appears at Least K Times

[링크](https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(N^2)이므로 제한시간 내에 불가능하다.

슬라이딩 윈도우를 사용할 경우 O(N)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

가장 큰 원소의 수가 K개 이상인지만 판단하면 된다.

따라서 해당 갯수를 세는 데 O(1)의 시간 복잡도를 사용한다.

슬라이딩 윈도우에 O(1)의 공간 복잡도를 사용한다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     148      |    O(N)     |    O(1)     |

배열에서 가장 큰 원소를 M이라 하자.

슬라이딩 윈도우를 사용해 오른쪽으로 순회하며 현재 index에서 끝나는 M이 K개인 subArray를 찾는다.

이 경우 배열에서 subArray가 차지하지 않는 왼쪽 부분의 원소의 갯수를 C라 하자.

현재 subArray를 포함하는 M이 K개 이상인 subArray의 갯수는 C+1개 존재한다.

이를 반복하며 정답을 갱신한다.

```cpp
long long countSubarrays(vector<int>& nums, int k) {
  int size = nums.size();
  long long answer = 0;

  int maximum = *max_element(nums.begin(), nums.end());

  int count = 0;

  for (int left = 0, right = 0; right < size; right++) {
    int cur = nums[right];
    if (cur == maximum) {
      count++;
    }

    while (count >= k && left <= right) {
      if (nums[left] == maximum) {
        count--;
      }
      left++;
    }

    answer += left;
  }
  return answer;
}
```

## 고생한 점
