# 2401. Longest Nice Subarray

[링크](https://leetcode.com/problems/longest-nice-subarray/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

슬라이딩 윈도우를 사용할 경우 O(N)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

슬라이딩 윈도우에 O(1)의 공간 복잡도가 필요하다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

슬라이딩 윈도우를 사용해 현재 윈도우에 포함된 비트들을 저장한다.

이후 각 값을 순회하며, 현재 값과 윈도우의 비트가 겹치는 경우 윈도우의 left를 이동시키며 비트를 감소시킨다.

```cpp
int longestNiceSubarray(vector<int>& nums) {
  int size = nums.size();

  int bit = 0;
  int answer = 0;
  for (int left = 0, right = 0; right < size; right++) {
    while ((bit & nums[right]) > 0) {
      bit ^= nums[left];
      left++;
    }

    bit |= nums[right];

    answer = max(answer, right - left + 1);
  }
  return answer;
}
```

## 고생한 점
