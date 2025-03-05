# 494. Target Sum

[링크](https://leetcode.com/problems/target-sum/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자. (N ≤ 20)

완전 탐색을 수행할 경우 O(2^N)의 시간 복잡도를 사용한다.

nums의 합을 M이라 하자.

동적 계획법을 사용할 경우 O(N \* M)의 시간 복잡도를 사용한다.

### 공간 복잡도

모든 경우를 DFS로 탐색할 경우 DFS에 O(N)의 공간 복잡도가 필요하다.

동적 계획법을 사용할 경우 O(N \* M)의 공간 복잡도가 필요하다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     766      |   O(2^N)    |    O(N)     |

각 index마다 현재 값을 빼는 경우, 더하는 경우 두 가지 경우가 존재한다.

이를 모두 탐색하며 target과 같은 경우를 찾는다.

```cpp
int answer = 0;

void recursive(vector<int>& nums, int i, int sum, int target) {
  int size = nums.size();
  if (i == size) {
    if (sum == target) answer++;
    return;
  }

  recursive(nums, i + 1, sum + nums[i], target);
  recursive(nums, i + 1, sum - nums[i], target);
};

int findTargetSumWays(vector<int>& nums, int target) {
  int size = nums.size();

  recursive(nums, 0, 0, target);

  return answer;
}
```

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      6       |  O(N \* M)  |  O(N \* M)  |

각 index마다 직전까지 만들 수 있는 값의 합에 대해서 탐색한다.

이 때 현재 index에서 더하거나 빼는 경우를 모두 탐색한다.

```cpp
int findTargetSumWays(vector<int>& nums, int target) {
  int size = nums.size();

  int center = 1000;
  int dp[20][2001] = {
      0,
  };

  dp[0][center + nums[0]] += 1;
  dp[0][center - nums[0]] += 1;

  for (int i = 1; i < size; i++) {
    for (int sum = -center; sum <= center; sum++) {
      if (dp[i - 1][sum + center] > 0) {
        int before = sum + center;

        dp[i][before + nums[i]] += dp[i - 1][before];
        dp[i][before - nums[i]] += dp[i - 1][before];
      }
    }
  }

  // if(center - abs(target) < 0) return 0;
  if (target + center < 0 || target + center > 2000) return 0;
  return dp[size - 1][target + center];
}
```

## 고생한 점
