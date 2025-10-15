# 3349. Adjacent Increasing Subarrays Detection I

[링크](https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N, 입력받은 수를 K라 하자.

완전 탐색을 수행할 경우 O(N \* K)의 시간 복잡도를 사용한다.

스택을 사용하는 경우 O(N)의 시간 복잡도를 사용한다.

직전 값만 비교하므로 순회시 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

스택에 O(N)의 공간 복잡도를 사용한다.

직전 값만 비교할 경우 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(1)     |

현재 index i와 i+k를 두 시작점으로 순회를 시작한다.

이 때 직전값과 비교하며 증가하는 수를 각각 카운트한다.

만약 두 카운트 모두 K이상인 경우 정답을 만족한다.

그 외의 경우 정답을 만족하지 않는다.

```cpp
bool hasIncreasingSubarrays(vector<int>& nums, int k) {
  int size = nums.size();

  int count1 = 1, count2 = 1;
  if (count1 >= k && count2 >= k) return true;
  for (int i = 1, j = k + 1; j < size; i++, j++) {
    if (nums[i - 1] >= nums[i]) {
      count1 = 0;
    }

    if (nums[j - 1] >= nums[j]) {
      count2 = 0;
    }

    count1++;
    count2++;

    if (count1 >= k && count2 >= k) return true;
  }

  return false;
}
```

### 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      17      |    O(N)     |    O(N)     |

두 스택을 사용해 순회하는 값을 저장한다.

이 때 직전값보다 현재값이 작거나 같은 경우 스택을 초기화한다.

순회를 진행하며 두 스택의 크기가 모두 K이상인 경우 정답을 만족한다.

```cpp
bool hasIncreasingSubarrays(vector<int>& nums, int k) {
  int size = nums.size();

  vector<int> stk1, stk2;
  for (int i = 0, j = k; j < size; i++, j++) {
    if (!stk1.empty() && stk1.back() >= nums[i]) {
      stk1.clear();
    }

    if (!stk2.empty() && stk2.back() >= nums[j]) {
      stk2.clear();
    }

    stk1.push_back(nums[i]);
    stk2.push_back(nums[j]);

    if (stk1.size() >= k && stk2.size() >= k) return true;
  }

  return false;
}
```

## 고생한 점
