# 2771. Longest Non-decreasing Subarray From Two Arrays

[링크](https://leetcode.com/problems/longest-non-decreasing-subarray-from-two-arrays/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums1, nums2의 크기를 N이라 하자.

모든 경우를 탐색할 경우 O(2^N)의 시간 복잡도가 소요되며 이는 제한시간 내에 불가능하다.

동적 계획법을 이용해 각 index마다 nums1, nums2의 원소를 선택할 때의 최대값을 구할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법에 O(N)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     333      |    O(N)     |    O(N)     |

nums1, nums2 중에서 한가지 원소를 선택할 수 있으며 이 때마다의 subsequence에서 오름차순인 연속된 최대 갯수를 찾아야 한다.

현재 index에서 nums1, nums2를 선택하는 두 가지 경우가 존재한다.

따라서 이전에 선택한 값과 현재 값을 비교하며 dp식을 갱신할 수 있다.

이 때 하나의 수를 선택했을 때, 이전 index에서 nums1, nums2 중 하나를 선택하는 모든 경우에 대해 값을 갱신한다.

이를 구현하면 다음과 같다.

```cpp
int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
  int size = nums1.size();

  // dp[index][num];
  int dp[100001][2] = {
      0,
  };

  dp[0][0] = dp[0][1] = 1;
  for (int i = 1; i < size; i++) {
    // fill 1
    dp[i][0] = 1;
    if (nums1[i - 1] <= nums1[i]) {
      dp[i][0] = max(dp[i][0], dp[i - 1][0] + 1);
    }
    if (nums2[i - 1] <= nums1[i]) {
      dp[i][0] = max(dp[i][0], dp[i - 1][1] + 1);
    }

    // fill 2
    dp[i][1] = 1;
    if (nums1[i - 1] <= nums2[i]) {
      dp[i][1] = max(dp[i][1], dp[i - 1][0] + 1);
    }
    if (nums2[i - 1] <= nums2[i]) {
      dp[i][1] = max(dp[i][1], dp[i - 1][1] + 1);
    }
  }

  int answer = 0;
  for (int i = 0; i < size; i++) {
    answer = max({answer, dp[i][0], dp[i][1]});
  }

  return answer;
}
```

## 고생한 점
