# 2831. Find the Longest Equal Subarray

[링크](https://leetcode.com/problems/find-the-longest-equal-subarray/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

모든 경우에 대해 탐색할 경우 시간 복잡도는 O(N^2)이다. 이는 제한시간 내에 불가능하다.

슬라이딩 윈도우를 이용해 풀이할 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

각 숫자들의 count를 세기 위해 O(N)의 공간 복잡도를 사용한다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     295      |    O(N)     |    O(N)     |

모든 구간을 탐색할 경우 제한시간 내에 불가능하므로 슬라이딩 윈도우를 이용해 시간을 최적화한다.

이 때 현재 범위에서 가장 count가 많은 수를 다음과 같이 설정한다.

- 현재 범위를 left ~ right라 하자
- right를 증가시키며 count를 증가시킨다.
- 각 경우마다 right에 있는 수를 기준으로 정답과 슬라이딩 윈도우를 갱신한다.

이를 이용해 각 경우마다 정답을 구할 수 있다.

```cpp
int longestEqualSubarray(vector<int>& nums, int k) {
  int size = nums.size();

  unordered_map<int, int> counts;

  int maxFreq = 0;
  for (int left = 0, right = 0; right < size; right++) {
    counts[nums[right]]++;
    maxFreq = max(maxFreq, counts[nums[right]]);

    if (right - left + 1 - maxFreq > k) {
      counts[nums[left]]--;
      left++;
    }
  }

  return maxFreq;
}
```

## 고생한 점
