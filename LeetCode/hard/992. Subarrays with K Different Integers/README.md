# 992. Subarrays with K Different Integers

[링크](https://leetcode.com/problems/subarrays-with-k-different-integers/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 배열 nums의 크기를 N이라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(N^2)이며 이는 제한시간 내에 불가능하다/

슬라이딩 윈도우를 사용할 경우 O(N)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

슬라이딩 윈도우를 사용할 겨웅 각 경우마다 수의 count를 해야하므로 O(K)의 공간 복잡도를 사용한다.

### 2 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     118      |    O(N)     |    O(K)     |

다음과 같은 슬라이딩 윈도우를 사용한다.

- K개의 숫자를 포함하는 subArray이의 길이들의 합을 구한다.
- K-1개의 숫자를 포함하는 subArray의 길이들의 합을 구한다.
- 두 경우의 차이를 구한다.

```cpp
int innerF(vector<int>& nums, int k) {
  int size = nums.size();
  unordered_map<int, int> counts;

  int answer = 0;
  for (int left = 0, right = 0; right < size; right++) {
    counts[nums[right]]++;

    while (counts.size() > k && left <= right) {
      int target = nums[left];
      counts[target]--;

      if (counts[target] == 0) {
        counts.erase(target);
      }
      left++;
    }

    answer += (right - left + 1);
  }
  return answer;
}

int subarraysWithKDistinct(vector<int>& nums, int k) {
  return innerF(nums, k) - innerF(nums, k - 1);
}
```

## 고생한 점
