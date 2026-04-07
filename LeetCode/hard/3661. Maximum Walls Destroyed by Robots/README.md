# 3661. Maximum Walls Destroyed by Robots

[링크](https://leetcode.com/problems/maximum-walls-destroyed-by-robots/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

배열의 크기를 N, 벽의 갯수를 M이라 하자.

로봇과 벽을 정렬하기 위해 O(N \* log_2(N) + M \* log_2(M))의 시간 복잡도를 가진다.

동적 계획법을 사용해 각 로봇의 쏘는 방향에 대해서 최대 파괴할 수 있는 벽의 갯수를 구한다.

이 경우 각 경우마다 구간에 속하는 벽의 갯수를 구해야한다.

이에 이분 탐색을 사용할 경우 총 O((N + M) \* log_2(M) + N \* log_2(N))의 시간 복잡도를 가진다.

### 공간 복잡도

정렬과 동적 계획법에 O(N + M)의 공간 복잡도를 가진다.

### 정렬 & 동적 계획법

| 내 코드 (ms) |              시간 복잡도               | 공간 복잡도 |
| :----------: | :------------------------------------: | :---------: |
|     265      | O((N + M) \* log_2(M) + N \* log_2(N)) |  O(N + M)   |

다음과 같은 동적 계획법 배열을 정의할 수 있다.

```cpp
// index 번째 로봇이 direction 방향으로 쏠 때 최대 파괴할 수 있는 벽의 갯수
// direction : 0 -> left, 1 -> right
dp[index][direction];
```

이 경우 현재 로봇이 왼쪽, 오른쪽 방향으로 쏠 때 최대 파괴할 수 있는 벽의 갯수는 다음과 같이 구할 수 있다.

이 때 각 로봇이 총을 쏠 때 이전, 다음 로봇과 겹치는 경우 해당 겹치는 구간은 제외한다.

- 오른쪽으로 쏘는 경우
  - 이전 로봇이 왼쪽, 오른쪽으로 쏘는 경우 중 최대값 + 현재 로봇이 오른쪽으로 쏠 때 파괴할 수 있는 벽의 갯수
- 왼쪽으로 쏘는 경우
  - 이전 로봇이 왼쪽으로 쏘는 경우 + 현재 로봇이 왼쪽으로 쏘는 경우
  - 이전 로봇이 오른쪽으로 쏘는 경우 + 현재 로봇이 왼쪽으로 쏘는 경우 - 겹치는 벽의 갯수

위 방법에서 파괴하는 벽의 갯수를 빠르게 구하기 위해 동적 계획법을 사용할 수 있다. (구간에 속하는 벽의 갯수)

위 방법들을 이용해 정답을 갱신한다.

```cpp
struct Robot {
  int p;
  int d;
};

int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
  int size = robots.size();
  vector<Robot> arr(size);

  for (int i = 0; i < size; i++) {
    arr[i].p = robots[i];
    arr[i].d = distance[i];
  }

  sort(walls.begin(), walls.end());
  sort(arr.begin(), arr.end(),
        [](const Robot& a, const Robot& b) { return a.p < b.p; });

  arr.push_back({(int)1e9, 0});

  function<int(int, int)> getCount = [&](int left, int right) {
    if (left > right) return 0;
    auto it1 = upper_bound(walls.begin(), walls.end(), right);
    auto it2 = lower_bound(walls.begin(), walls.end(), left);
    int res = it1 - it2;
    return res;
  };

  // dp[index][direction]
  // 0 : left, 1 : right
  vector<vector<int>> dp(size, vector<int>(2));

  // base case
  dp[0][0] = getCount(arr[0].p - arr[0].d, arr[0].p);
  if (size > 1) {
    dp[0][1] = getCount(arr[0].p, min(arr[1].p - 1, arr[0].p + arr[0].d));
  } else {
    dp[0][1] = getCount(arr[0].p, arr[0].p + arr[0].d);
  }

  for (int i = 1; i < size; i++) {
    dp[i][1] = max(dp[i - 1][1], dp[i - 1][0]) +
                getCount(arr[i].p, min(arr[i + 1].p - 1, arr[i].p + arr[i].d));

    int curLeft = max(arr[i].p - arr[i].d, arr[i - 1].p + 1);
    int beforeRight = min(arr[i - 1].p + arr[i - 1].d, arr[i].p - 1);

    int left2left = dp[i - 1][0] + getCount(curLeft, arr[i].p);

    int right2left = dp[i - 1][1] + getCount(curLeft, arr[i].p) -
                      getCount(curLeft, beforeRight);

    dp[i][0] = max(right2left, left2left);
  }
  return max(dp[size - 1][0], dp[size - 1][1]);
}
```

## 고생한 점
