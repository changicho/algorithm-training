# 2395. Find Subarrays With Equal Sum

[링크](https://leetcode.com/problems/find-subarrays-with-equal-sum/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

원소의 갯수를 N이라 하자.

크기가 2인 N-1개의 subArray의 합이 같은 경우가 존재하는지 판단하기 위해 hash set을 이용한다.

이 경우 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash set에 O(N)의 공간 복잡도를 사용한다.

### 정리

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      11      |    O(N)     |    O(N)     |

연속된 두 수를 더해가며 이를 hash set에 저장한다.

이 때 기존에 해당 합이 존재할 경우 정답은 true가 된다.

```cpp
bool findSubarrays(vector<int>& nums) {
  int size = nums.size();

  unordered_set<int> appears;
  for (int i = 0; i < size - 1; i++) {
    int cur = nums[i] + nums[i + 1];

    if (appears.count(cur) > 0) return true;
    appears.insert(cur);
  }
  return false;
}
```

## 고생한 점
