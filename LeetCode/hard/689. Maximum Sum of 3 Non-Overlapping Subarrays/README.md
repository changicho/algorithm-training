# 689. Maximum Sum of 3 Non-Overlapping Subarrays

[링크](https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

배열 nums의 길이를 N이라 하자.

모든 경우를 탐색할 경우 O(2^N)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

동적계획법을 사용할 경우 O(N)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

동적 계획법에 O(N)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

각 index와 이전에 사용한 subarray의 갯수에 대해 dp를 생성한다.

```cpp
struct Subarray {
  int sum;
  int startI;
};

// count개의 subarray를 사용했을 때, index까지의 최대 합과 시작 index
Subarray dp[count][index];

// initialize
dp[0][index] = {0,0};

// update
int curSum = prefixSum[index] - prefixSum[index - k];
int totalSum = curSum + dp[count - 1][index - k].sum;

if (totalSum > dp[count][index - 1].sum) {
  dp[count][index] = {totalSum, index - k};
} else {
  dp[count][index] = dp[count][index - 1];
}
```

각 count와 index에 대해서 이전 값을 이용해 현재 값을 갱신한다.

이후 dp의 값들 중 해당 최대값을 사용한 subarray의 시작 index를 이용해 정답을 생성한다. (3개의 subarray들의 시작 index들)

```cpp
struct Subarray {
  int sum;
  int startI;
};

vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
  int size = nums.size();

  vector<int> prefixSum(size + 1, 0);
  for (int i = 1; i <= size; i++) {
    prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
  }

  vector<vector<Subarray>> dp(4, vector<Subarray>(size + 1, {0, 0}));

  for (int count = 1; count <= 3; count++) {
    for (int endI = k * count; endI <= size; endI++) {
      int startI = endI - k;

      int curSum = prefixSum[endI] - prefixSum[startI];
      int totalSum = curSum + dp[count - 1][startI].sum;

      if (totalSum > dp[count][endI - 1].sum) {
        dp[count][endI] = {totalSum, startI};
      } else {
        dp[count][endI] = dp[count][endI - 1];
      }
    }
  }

  vector<int> answer(3, 0);
  for (int count = 3, endI = size; count >= 1; count--) {
    answer[count - 1] = dp[count][endI].startI;
    endI = answer[count - 1];
  }

  return answer;
}
```

## 고생한 점
