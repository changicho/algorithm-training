# 2958. Length of Longest Subarray With at Most K Frequency

[링크](https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(N^2)이다.

슬라이딩 윈도우를 이용해 풀이할 경우 O(N)의 시간 복잡도로 풀이가 가능하다.

### 공간 복잡도

각 경우마다 빈도수를 저장하는 데 O(N)의 공간 복잡도가 필요하다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     222      |    O(N)     |    O(N)     |

슬라이딩 윈도우를 이용해 빈도수에 따른 배열의 길이를 관리한다.

이 때 빈도수가 증가하는 경우는 현재 방문한 숫자에 대해서만이므로 valid한 배열을 만들 때 해당 경우만 관리한다.

```cpp
int maxSubarrayLength(vector<int>& nums, int k) {
  int size = nums.size();
  unordered_map<int, int> counts;

  int answer = 0;
  for (int left = 0, right = 0; right < size; right++) {
    counts[nums[right]]++;

    while (counts[nums[right]] > k && left < right) {
      counts[nums[left]]--;
      if (counts[nums[left]] == 0) {
        counts.erase(nums[left]);
      }
      left++;
    }

    answer = max(answer, right - left + 1);
  }
  return answer;
}
```

## 고생한 점
