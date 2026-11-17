# 4089. Count Subarrays With Loose Bounds

[링크](https://leetcode.com/problems/count-subarrays-with-loose-bounds/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

슬라이딩 윈도우를 사용할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

슬라이딩 윈도우에 O(1)의 공간 복잡도를 사용한다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      6       |    O(N)     |    O(1)     |

슬라이딩 윈도우를 사용해 현재 index를 right로 하는 가장 긴 길이의 윈도우를 관리한다.

매 경우마다 윈도우의 크기를 정답에 더한다.

이 때 현재 right값이 유효하지 않은 경우 윈도우의 크기를 0으로 바꾼다.

```cpp
long long countSubarrays(vector<int>& nums, int minK, int maxK) {
  int size = nums.size();
  long long answer = 0;

  for (int left = 0, right = 0; right < size; right++) {
    if (nums[right] < minK || maxK < nums[right]) {
      left = right + 1;
    }

    answer += right - left + 1;
  }
  return answer;
}
```

## 고생한 점
