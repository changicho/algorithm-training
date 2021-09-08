# 213. House Robber II

[링크](https://leetcode.com/problems/house-robber-ii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

집의 개수를 N이라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(2^N)이 된다.

이는 제한 시간 내에 불가능하므로 동적 계획법을 이용한다.

이 때 첫번째 집을 선택하는 경우 맨 마지막 집을 선택할 수 없으므로 첫번째 집을 선택하는 경우, 선택하지 않는 경우 두가지 경우에 대해 탐색을 진행한다.

이 때의 시간 복잡도는 O(N)이다.

### 공간 복잡도

현재 값을 갱신하는 데 1번째 전 값과 2번째 전 값 두개의 값만 필요하다.

이를 두 경우에 대해 찾아야 한다.

결국 공간 복잡도는 O(1)이다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

맨 마지막 값을 선택할 수 있는 경우는 첫번째 값을 선택하지 않은 경우이다.

따라서 다음 2가지 경우에 대해서 값을 갱신한다.

- 첫번째 집을 선택하는 경우
- 첫번째 집을 선택하지 않는 경우

두가지 경우에 대해서 동적 계획법으로 탐색을 진행한다.

일반식은 다음과 같다.

```cpp
dp[i]; // i번째 집 까지 방문했을 때 가질 수 있는 최대값

dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
```

초기값은 다음과 같다.

```cpp
// 첫번째 집을 선택하는 경우의 초기값.
robFirstDp[0] = nums[0];
robFirstDp[1] = max(nums[0], nums[1]);

// 첫번째 집을 선택하지 않은 경우의 초기값.
robSecondDp[0] = 0;
robSecondDp[1] = nums[1];
```

이를 이용해 값을 갱신한다.

```cpp
int rob(vector<int>& nums) {
  int size = nums.size();
  if (size < 2) {
    return nums[0];
  }

  vector<int> robFirstDp(2, 0);
  vector<int> robSecondDp(2, 0);

  robFirstDp[0] = nums[0];
  robFirstDp[1] = max(nums[0], nums[1]);
  robSecondDp[0] = 0;
  robSecondDp[1] = nums[1];

  for (int i = 2; i < size; i++) {
    int first = max(robFirstDp[1], nums[i] + robFirstDp[0]);
    robFirstDp[0] = robFirstDp[1];
    robFirstDp[1] = first;

    int second = max(robSecondDp[1], nums[i] + robSecondDp[0]);
    robSecondDp[0] = robSecondDp[1];
    robSecondDp[1] = second;
  }

  return max(robSecondDp[1], robFirstDp[0]);
}
```

## 고생한 점
