# 2461. Maximum Sum of Distinct Subarrays With Length K

[링크](https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 길이를 N, 수를 K라 하자.

완전 탐색을 수행할 경우 시간 복잡도는 O(N \* K) 이다.

슬라이딩 윈도우를 사용할 경우 O(N)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

슬라이딩 윈도우에 O(K)의 공간 복잡도가 필요하다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     111      |    O(N)     |    O(K)     |

subArray에서 중복된 수의 갯수를 세기 위해 count 맵을 사용한다.

이 때 중복된 수의 갯수를 별도로 관리하기 위해 duplicateCount를 사용한다.

count 맵의 현재 증가하는 숫자가 2개가 되었을 때 duplicateCount를 증가시키고, 1개가 되었을 때 감소시킨다.

```cpp
long long maximumSubarraySum(vector<int>& nums, int k) {
  int size = nums.size();

  unordered_map<int, int> count;
  int duplicateCount = 0;
  long long sum = 0;
  long long answer = 0;
  for (int right = 0; right < size; right++) {
    int left = right - k;
    count[nums[right]]++;

    if (count[nums[right]] == 2) {
      duplicateCount++;
    }
    sum += nums[right];
    if (left >= 0) {
      count[nums[left]]--;
      if (count[nums[left]] == 1) {
        duplicateCount--;
      } else if (count[nums[left]] == 0) {
        count.erase(nums[left]);
      }
      sum -= nums[left];
    }

    if (duplicateCount == 0 && (right + 1 >= k)) {
      answer = max(answer, sum);
    }
  }
  return answer;
}
```

## 고생한 점
