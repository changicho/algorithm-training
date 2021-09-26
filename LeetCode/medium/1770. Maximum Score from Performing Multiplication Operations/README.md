# 1770. Maximum Score from Performing Multiplication Operations

[링크](https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

multipliers의 길이를 N이라 하자.

모든 경우에 대해서 탐색할 경우 각 경우마다 왼쪽, 오른쪽 중 하나를 고를 수 있으므로 시간 복잡도는 O(2^N)이 되며 이는 제한시간 내에 불가능하다.

여기서 중복을 제거하고 왼쪽, 오른쪽에 대해서 메모이제이션을 적용할 경우 경우의 수는 O(N^2)개가 나온다. 따라서 시간 복잡도는 O(N^2)가 된다.

### 공간 복잡도

모든 left, right에 대한 dp 배열을 생성할 경우, nums의 크기는 최대 10^5가 되므로 메모리 초과가 발생한다.

가능한 연산의 횟수는 N개 이내임이 정해져 있으므로 O(N^2)크기의 배열을 생성해 사용한다.

이 때 최악의 경우 N은 10^3이므로 제한시간 내에 가능하다.

### 메모이제이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     480      |   O(N^2)    |   O(N^2)    |

완전탐색을 이용해 풀이할 경우 재귀식을 다음과 같이 설정할 있다.

```cpp
int recursive(vector<int>& nums, vector<int>& multi, int index, int left,
              int right) {
  if (index == multi.size()) return 0;

  int fromLeft = multi[index] * nums[left] +
                  recursive(nums, multi, index + 1, left + 1, right);
  int fromRight = multi[index] * nums[right] +
                  recursive(nums, multi, index + 1, left, right - 1);

  return max(fromLeft, fromRight);
}
```

즉 현재 range에서 left, right 숫자를 선택하는 두가지 경우에 대해서 탐색하는 것이다.

여기서 각 연산마다 중복된 경우가 생기므로 메모이제이션을 통해 최적화 할 수 있다.

dp식을 다음과 같이 설정한다.

```cpp
dp[left][length]; // left에서 시작하는 길이 length의 subArray중 최대합
```

length를 이용하는 이유는 left, right로 생성할 경우 memory 초과가 발생하기 때문이다.

여기서 left는 N이하임이 보장된다. (multipliers의 최대 길이에 제한을 받으므로)

이전에 방문했는지 아닌지 체크하기 위해 초기값을 다음과 같이 설정한다.

```cpp
dp[left][length] = INT_MIN;
```

일반식은 다음과 같다.

```cpp
int fromLeft = multi[index] * nums[left] +
               recursive(nums, multi, index + 1, left + 1, right);
int fromRight = multi[index] * nums[right] +
                recursive(nums, multi, index + 1, left, right - 1);

dp[left][index] = max(fromLeft, fromRight);
```

이렇게 메모이제이션을 적용할 경우 다음과 같이 풀이할 수 있다.

```cpp
vector<vector<int>> dp;
int recursive(vector<int>& nums, vector<int>& multi, int index, int left,
              int right) {
  if (index == multi.size()) return 0;
  if (dp[left][index] != INT_MIN) return dp[left][index];

  int fromLeft = multi[index] * nums[left] +
                  recursive(nums, multi, index + 1, left + 1, right);
  int fromRight = multi[index] * nums[right] +
                  recursive(nums, multi, index + 1, left, right - 1);

  return dp[left][index] = max(fromLeft, fromRight);
}

int maximumScore(vector<int>& nums, vector<int>& multipliers) {
  int length = multipliers.size();
  dp.resize(length, vector<int>(length, INT_MIN));

  int size = nums.size();
  int left = 0, right = size - 1;

  int answer = recursive(nums, multipliers, 0, left, right);
  return answer;
}
```

### 동적 계획법 (bottom-up)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     280      |   O(N^2)    |    O(N)     |

```cpp
int maximumScore(vector<int>& nums, vector<int>& multipliers) {
  int n = nums.size();
  int m = multipliers.size();
  int diff = n - m;

  vector<int> dp(m, 0), before(m, 0);

  // initialize
  for (int left = 0; left < n - diff; left++) {
    int right = left;

    int fromLeft = nums[left] * multipliers[m - 1];
    int fromRight = nums[right + diff] * multipliers[m - 1];

    dp[right] = max(fromLeft, fromRight);
  }

  for (int length = 1; length < m; length++) {
    for (int left = 0; left < n - length - diff; left++) {
      int right = left + length;

      int fromLeft = dp[right] + nums[left] * multipliers[m - 1 - length];
      int fromRight =
          dp[right - 1] + nums[right + diff] * multipliers[m - 1 - length];

      before[right] = max(fromLeft, fromRight);
    }

    swap(dp, before);
  }

  return dp.back();
}
```

## 고생한 점
