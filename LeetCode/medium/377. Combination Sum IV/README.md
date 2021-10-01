# 377. Combination Sum IV

[링크](https://leetcode.com/problems/combination-sum-iv/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

target의 값을 N, 숫자의 개수를 M이라 하자.

모든 경우를 탐색할 경우 최악의 경우 시간 복잡도는 O(M^N)이 된다.

이는 제한시간 내에 불가능하다.

따라서 동적 계획법을 이용해 시간복잡도를 최적화한다.

중복 방문을 제거할 경우 1 ~ target까지의 값을 순회한다.

각 순회마다 숫자에 대해서 한번 더 순회를 진행하므로 시간 복잡도는 O(N \* M)이 된다.

### 공간 복잡도

결국 target까지의 값을 저장할 배열이 필요하며 이는 O(N)의 공간 복잡도를 사용한다.

재귀 호출로 풀이할 경우 call stack에 최대 O(N)의 공간을 사용한다.

### 동적 계획법 (메모이제이션)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |  O(N \* M)  |    O(N)     |

재귀호출로 모든 경우를 탐색할 경우 다음과 같은 재귀식으로 풀이할 수 있다.

```cpp
int recursive(vector<int> nums, int target) {
  int res = 0;
  int size = nums.size();

  for (int i = 0; i < size; i++) {
    if (target - nums[i] < 0) continue;

    res += recursive(nums, target - nums[i]);
  }

  return res;
}
```

현재 단계에서 답을 구할 때 target - num에 대해서 탐색을 이어나가는 방법이다.

top-down방식으로 문제를 풀이한다.

여기서 target이 낮은 순서부터 가능한 모든 경우를 구하게 되고, 이를 이용해 정답을 구한다.

여기서 이전에 방문했던 값을 저장해 사용할 경우 중복되는 호출을 줄일 수 있다.

이를 이용할 경우 다음과 같이 풀이할 수 있다.

```cpp
int recursive(vector<int> nums, int target, vector<int>& dp) {
  if (dp[target] != -1) return dp[target];

  int res = 0;
  int size = nums.size();

  for (int i = 0; i < size; i++) {
    if (target - nums[i] < 0) continue;

    res += recursive(nums, target - nums[i], dp);
  }

  dp[target] = res;

  return res;
}

int combinationSum4(vector<int>& nums, int target) {
  vector<int> dp(target + 1, -1);
  dp[0] = 1;

  int answer = recursive(nums, target, dp);

  return answer;
}
```

### 동적 계획법 (bottom-up)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      5       |  O(N \* M)  |    O(N)     |

위 식에서 target이 낮은 순서부터 가능한 경우의 수를 구하면, 이후 target에 대한 값을 구할 때 사용할 수 있다.

dp식을 다음과 같이 설정한다.

```cpp
dp[target]; // target값을 만드는 경우의 수
```

초기값은 다음과 같다.

```cpp
dp[0]; // 아무것도 선택하지 않는 경우는 한가지밖에없음
```

일반 식은 다음과 같다.

```cpp
dp[target] = 0;
for (int num : nums) {
  dp[target] += dp[target - num];
}
```

즉 이전에 구한 dp값을 이용해 모든 경우를 더한다.

여기서 정답의 크기는 overflow가 일어날 수 있으므로 unsigned int를 이용한다.

unsigned int를 이용하는 이유는 overflow가 발생할 시 0으로 초기화 해주기 때문이다.

정답은 int형임이 보장되므로 overflow가 일어나는 경우는 정답에 포함되지 않는다.

이를 이용해 구현할 경우 다음과 같다.

```cpp
int combinationSum4(vector<int>& nums, int target) {
  vector<unsigned int> dp(target + 1, 0);
  dp[0] = 1;

  for (int value = 1; value <= target; ++value) {
    for (int num : nums) {
      if (value - num < 0) continue;

      dp[value] += dp[value - num];
    }
  }

  return (int)dp[target];
}
```

## 고생한 점
