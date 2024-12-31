# 1746. Maximum Subarray Sum After One Operation

[링크](https://leetcode.com/problems/maximum-subarray-sum-after-one-operation/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

모든 경우를 수행할 경우 O(N^2)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

동적 계획법을 사용할 경우 O(N)의 시간 복잡도로 해결이 가능하다.

현재 index까지 left, right의 최대값을 이용해 구할 경우 O(N)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

동적 계획법에 O(N)의 공간 복잡도를 사용한다.

각 index마다의 최대값을 사용하는데 O(N)의 공간 복잡도가 필요하다.

### left, right maximum

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      81      |    O(N)     |    O(N)     |

정답은 아래와 같은 부분으로 생각할 수 있다.

```javascript
[...leftPart, nums[i] * nums[i], ...rightPart]
```

여기서 left, right part는 없을 수도 있다.

각 index마다 왼쪽, 오른쪽 부분의 최대값을 구해놓고 모든 index를 순회하며 최대값을 갱신한다.

이 때 left, right part의 최대값을 구할 때 순회를 이용하며 0 이하가 되는 경우 버린다.

```cpp
int maxSumAfterOperation(vector<int>& nums) {
  int size = nums.size();

  vector<int> maxRights(size);
  vector<int> maxLefts(size);

  maxLefts[0] = maxRights[size - 1] = 0;
  for (int left = 1, right = size - 2; left < size; left++, right--) {
    maxLefts[left] = max(maxLefts[left - 1] + nums[left - 1], 0);
    maxRights[right] = max(maxRights[right + 1] + nums[right + 1], 0);
  }

  int answer = 0;
  for (int i = 0; i < size; i++) {
    int cur = nums[i];
    int subArraySum = maxLefts[i] + cur * cur + maxRights[i];

    answer = max(answer, subArraySum);
  }
  return answer;
}
```

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     176      |    O(N)     |    O(N)     |

각 index마다 다음 2가지 상태를 가진다.

- 이전에 제곱을 사용한 경우
- 이전에 제곱을 사용하지 않은 경우

각 index마다 왼쪽 부분의 최대값을 구한다.

이후 이전값들을 이용해 현재 최대값을 갱신한다.

- 현재 number만 사용하는 경우 (제곱으로)
- 이전에 제곱을 사용하지 않은 경우 + 현재 number를 제곱한 경우
- 이전에 제곱을 사용한 경우 + 현재 number를 더한 경우

```cpp
int maxSumAfterOperation(vector<int>& nums) {
  int size = nums.size();

  vector<vector<int>> dp(size, vector<int>(2, 0));

  dp[0][0] = nums[0];
  dp[0][1] = nums[0] * nums[0];

  int maxSum = nums[0] * nums[0];

  for (int i = 1; i < size; i++) {
    dp[i][0] = max(nums[i], dp[i - 1][0] + nums[i]);

    // three case
    // use nums[i]^2 only
    // use nums[i]^2 and prev normal sum
    // use prev square sum and nums[i]
    dp[i][1] = max({nums[i] * nums[i], dp[i - 1][0] + nums[i] * nums[i],
                    dp[i - 1][1] + nums[i]});

    maxSum = max(maxSum, dp[i][1]);
  }

  return maxSum;
}
```

## 고생한 점
