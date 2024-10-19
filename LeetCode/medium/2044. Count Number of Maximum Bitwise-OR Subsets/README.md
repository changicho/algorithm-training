# 2044. Count Number of Maximum Bitwise-OR Subsets

[링크](https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자. nums의 모든 원소의 or 연산을 수행한 값을 M이라 하자.

완전 탐색을 사용할 경우 O(2^N)의 시간 복잡도를 사용한다.

동적 계획법을 사용할 경우 O(N \* M)의 시간 복잡도를 사용한다.

### 공간 복잡도

완전 탐색에 DFS를 사용할 경우 O(N)의 공간 복잡도를 사용한다.

동적 계획법을 사용할 경우 O(N \* M)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |   O(2^N)    |    O(N)     |

subArray의 모든 경우를 탐색하며 포함된 요소들의 or 값이 nums의 모든 요소의 or 값과 같은 경우를 찾는다.

```cpp
int answer = 0;
int target = 0;

void recursive(int index, vector<int> &nums, int bit) {
  int size = nums.size();
  if (index == size) {
    if (target == bit) answer++;
    return;
  }

  recursive(index + 1, nums, bit);
  recursive(index + 1, nums, bit | nums[index]);
}

int countMaxOrSubsets(vector<int> &nums) {
  for (int &num : nums) {
    target |= num;
  }
  recursive(0, nums, 0);

  return answer;
}
```

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     114      |  O(N \* M)  |  O(N \* M)  |

위 방법에서 각 index마다 bit의 상태에 따라 중복되는 경우가 발생한다.

이를 동적 계획법을 이용해 최적화한다.

```cpp
int target = 0;

vector<vector<int>> dp;

int recursive(int index, vector<int> &nums, int bit) {
  int size = nums.size();
  if (index == size) {
    return target == bit;
  }

  if (dp[index][bit] != -1) return dp[index][bit];

  int without = recursive(index + 1, nums, bit);
  int within = recursive(index + 1, nums, bit | nums[index]);

  return dp[index][bit] = without + within;
}

int countMaxOrSubsets(vector<int> &nums) {
  for (int &num : nums) {
    target |= num;
  }

  dp.resize(nums.size(), vector<int>(target + 1, -1));

  return recursive(0, nums, 0);
}
```

## 고생한 점
