# 2770. Maximum Number of Jumps to Reach the Last Index

[링크](https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

각 index에서 다음 index로 이동할 수 있는지 판별에 O(N^2)의 시간 복잡도를 사용한다.

이후 동적 계획법을 이용해 각 index별로 최대 이동 횟수를 구할 수 있다.

총 시간 복잡도는 O(N^2)이다.

### 공간 복잡도

동적 계획법에 O(N)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     228      |   O(N^2)    |    O(N)     |

다음과 같은 dp식을 생성한다.

```cpp
// definition
int dp[index]; // index까지 도달할 수 있는 최대 이동 횟수

// init
dp[0] = 0;

// update
dp[to] = max(dp[to], dp[from] + 1);
```

각 index마다 이동할 수 있는 다음 index는 두 값의 차이가 -target~target인 경우이다.

따라서 각 index마다 dp를 갱신하며 최대 이동 횟수를 구할 수 있다.

이 때 도달 불가능한 경우 -1을 반환한다.

```cpp
int maximumJumps(vector<int> &nums, int target) {
  int size = nums.size();

  vector<vector<int>> graph(size);
  for (int from = 0; from < size; from++) {
    for (int to = from + 1; to < size; to++) {
      int diff = nums[from] - nums[to];

      if (-target <= diff && diff <= target) {
        graph[from].push_back(to);
      }
    }
  }

  vector<int> dp(size, -1);
  dp[0] = 0;
  for (int from = 0; from < size; from++) {
    if (dp[from] == -1) continue;
    for (int &to : graph[from]) {
      dp[to] = max(dp[to], dp[from] + 1);
    }
  }

  if (dp[size - 1] == 0) return -1;
  return dp[size - 1];
}
```

## 고생한 점
