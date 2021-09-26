# 300. Longest Increasing Subsequence

[링크](https://leetcode.com/problems/longest-increasing-subsequence/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

LIS를 구할 때 동적 계획법을 이용할 경우 O(N^2)의 시간 복잡도가, 이분 탐색을 이용할 경우 O(N \* log_2(N))의 시간 복잡도가 소요된다.

### 공간 복잡도

동적 계획법을 이용할 경우 O(N)의 공간 복잡도를 사용한다.

이분 탐색을 사용할 경우 O(N) 크기의 공간 복잡도를 사용한다.

### LIS (이분탐색)

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      14      | O(N \* log_2(N)) |    O(N)     |

LIS 배열을 생성하며 문제를 풀이할 수 있다.

index들을 저장하는 공간을 만든다.

nums를 순회하면서 LIS 배열의 맨 뒤 원소와 현재 보고있는 수를 비교한다.

현재 원소가 더 클 시 LIS 배열에 현재 값을 추가하면 되므로 현재 원소의 인덱스와 값을 저장한다.

현재 원소가 작을 경우 기존 LIS 배열을 갱신한다.

lower_bound를 이용하여 최적의 자리를 찾은 뒤 그 자리의 값을 해당 수열의 원소로 교체한다.

LIS 배열을 구하기 위해선 각 index별로 어떤 값이 있는지 같이 저장해야 한다.

여기서 index의 값이 결과적으로 가장 긴 부분 증가 수열의 길이가 된다.

```cpp
int lengthOfLIS(vector<int>& nums) {
  int size = nums.size();
  vector<LIS> lis;
  vector<int> indexes(size, 0);
  int lastIndex = 0;

  indexes[lastIndex] = nums[0];
  lis.push_back({0, nums[0]});

  for (int i = 1; i < size; i++) {
    if (indexes[lastIndex] < nums[i]) {
      lastIndex++;
      indexes[lastIndex] = nums[i];
      lis.push_back({lastIndex, nums[i]});
    } else {
      int new_index =
          lower_bound(indexes.begin(), indexes.begin() + lastIndex, nums[i]) -
          indexes.begin();

      indexes[new_index] = nums[i];
      lis.push_back({new_index, nums[i]});
    }
  }

  return lastIndex + 1;
}
```

짧게 구현한 경우 다음과 같다.

```cpp
int lengthOfLIS(vector<int>& nums) {
  int size = nums.size();
  vector<int> lis;

  for (int i = 0; i < size; i++) {
    int target = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();

    if (target == lis.size()) {
      lis.push_back(nums[i]);
    } else {
      lis[target] = nums[i];
    }
  }

  return lis.size();
}
```

### LIS (동적 계획법)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     276      |   O(N^2)    |    O(N)     |

dp식을 다음과 같이 설정 한다.

```cpp
dp[index]; // index번째 까지 최대의 LIS 길이
```

초기값은 다음과 같다.

```cpp
dp[index] = 1; // 모든 글자들은 최소 1인 길이의 LIS들을 가진다.
```

점화식은 다음과 같다.

```cpp
// right : 1 ~ (size - 1)
// left : 0 ~ (right - 1)
if (nums[left] < nums[right]) {
  dp[right] = max(dp[left] + 1, dp[right]);
}
```

여기서 dp의 갱신은 왼쪽부터 일어나야 한다. (짧은 길이부터 갱신해야함)

따라서 구현하면 다음과 같다.

```cpp
int lengthOfLIS(vector<int>& nums) {
  int size = nums.size();

  vector<int> dp(size, 1);
  int answer = 1;

  for (int right = 1; right < size; right++) {
    for (int left = 0; left < right; left++) {
      if (nums[left] < nums[right]) {
        dp[right] = max(dp[left] + 1, dp[right]);
      }
    }

    answer = max(answer, dp[right]);
  }

  return answer;
}
```

## 고생한 점
