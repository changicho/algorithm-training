# 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

[링크](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

매 경우마다 가장 큰 값과 가장 작은 값을 찾아 절대값의 차이가 limit 이하인지 확인해야 한다.

모노토닉 디큐를 이용해 풀이할 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

모노토닉 디큐에 최대 N개의 값이 들어갈 수 있으므로 공간 복잡도는 O(N)이다.

### 모노토닉 디큐

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      63      |    O(N)     |    O(N)     |

back으로 갈 수록 값이 작아지는 max dequeue, back으로 갈 수록 값이 커지는 min dequeue 생성한다.

right 포인터를 왼쪽부터 증가하며 max dequeue, min dequeue에 값을 삽입한다.

현 상황마다 두 dequeue의 맨 앞의 값 (최대값, 최소값)의 차이가 limit 초과인 경우 left 포인터를 증가시키며 두 dequeue의 맨 앞의 값을 제거한다.

이후 현재 두 dequeue의 front에 있는 값의 차이는 limit 이하이므로 현재 길이를 갱신한다.

```cpp
int longestSubarray(vector<int>& nums, int limit) {
  int size = nums.size();
  deque<int> maxDq, minDq;

  int answer = 0;
  for (int l = 0, r = 0; r < size; r++) {
    while (!maxDq.empty() && maxDq.back() < nums[r]) {
      maxDq.pop_back();
    }
    maxDq.push_back(nums[r]);

    while (!minDq.empty() && minDq.back() > nums[r]) {
      minDq.pop_back();
    }
    minDq.push_back(nums[r]);

    while (l < r && maxDq.front() - minDq.front() > limit) {
      if (maxDq.front() == nums[l]) {
        maxDq.pop_front();
      }
      if (minDq.front() == nums[l]) {
        minDq.pop_front();
      }
      l++;
    }

    answer = max(answer, r - l + 1);
  }

  return answer;
}
```

## 고생한 점
