# 416. Partition Equal Subset Sum

[링크](https://leetcode.com/problems/partition-equal-subset-sum/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N, 모든 원소의 합을 M이라 하자.

완전 탐색을 사용할 경우 O(2^N)의 시간 복잡도를 사용한다. 이는 제한시간 내에 불가능하다.

동적 계획법을 이용해 구현할 경우 O(N \* M)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법에 O(N \* M)의 공간 복잡도를 사용한다.

이 중 직전값만 사용하므로 O(M)으로 줄일 수 있다.

### 동적 계획법 (space optimization)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      47      |  O(N \* M)  |    O(M)     |

nums의 모든 원소의 합을 M이라 하자. (nums의 원소는 1이상 100이하의 값이다.)

nums의 원소를 모두 더한 값이 홀수일 경우, 두 부분집합의 합이 같을 수 없다.

nums의 index에 대해 순회하며 직전까지 만들었던 sum에 대해서 현재 만들 수 있는 sum들을 갱신한다.

이를 index를 이동하며 반복해 각 index마다 만들 수 있는 합들을 갱신한다.

이 중 M / 2를 만들 수 있는지 확인한다.

```cpp
bool canPartition(vector<int>& nums) {
  int size = nums.size();

  int sum = accumulate(nums.begin(), nums.end(), 0);

  if (sum % 2 == 1) return false;

  vector<bool> dp(sum + 1);
  vector<bool> newDp(sum + 1);

  dp[0] = true;

  for (int i = 1; i <= size; i++) {
    int cur = nums[i - 1];

    newDp.clear();
    for (int before = 0; before <= sum; before++) {
      if (dp[before] == false) continue;

      if (before == sum / 2) return true;
      newDp[before] = true;
      newDp[before + cur] = true;
    }

    swap(dp, newDp);
  }
  return dp[sum / 2];
}
```

## 고생한 점
