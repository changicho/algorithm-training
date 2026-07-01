# 3737. Count Subarrays With Majority Element I

[링크](https://leetcode.com/problems/count-subarrays-with-majority-element-i/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

미리 구간합을 구하는데 O(N)의 시간 복잡도를 사용한다.

각 subArray를 모두 탐색하는데 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

prefix sum에 O(N)의 시간 복잡도를 사용한다.

### prefix sum & 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      27      |   O(N^2)    |    O(N)     |

구간안의 target의 수를 구하기 위해 prefix sum을 사용한다.

이후 각 구간을 모두 탐색하며 구간안의 target의 수를 갱신한다.

```cpp
int countMajoritySubarrays(vector<int>& nums, int target) {
  int size = nums.size();
  int prefix[1002] = {
      0,
  };

  for (int i = 0; i < size; i++) {
    prefix[i + 1] = prefix[i] + (nums[i] == target);
  }

  int answer = 0;
  for (int i = 0; i < size; i++) {
    for (int j = i; j < size; j++) {
      int count = prefix[j + 1] - prefix[i];
      int length = j - i + 1;

      if (count > length / 2) {
        answer++;
      }
    }
  }
  return answer;
}
```

## 고생한 점
