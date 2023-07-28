# 486. Predict the Winner

[링크](https://leetcode.com/problems/predict-the-winner/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

각 경우마다 player1, 2가 선택할 수 있는 경우는 맨 앞, 맨 뒤 두가지 경우이다.

재귀 호출로 모든 경우를 탐색할 경우 O(2^N)의 시간 복잡도를 사용한다.

동적 계획법을 이용해 최적화 할 경우 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

재귀호출로 탐색에 O(N)의 공간 복잡도를 사용한다.

동적 계획법을 사용할 경우 O(N^2)의 공간 복잡도를 사용한다.

### 동적 계획법 (top-down)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |   O(N^2)    |   O(N^2)    |

현재 플레이어가 현재 상황에서 얻을 수 있는 최고점은 다음과 같이 계산할 수 있다.

- 왼쪽을 선택한 후 다른 플레이어가 최선의 선택을 했을 때
- 오른쪽을 선택한 후 다른 플레이어가 최선의 선택을 했을 때

만약 현재 상황에서 현재 플레이어가 최선의 선택을 하는 함수를 f라 하자.

이 경우 두 플레이어 모두 f를 이용해 현재 최선의 선택을 할 수 있다.

따라서 다음과 같이 함수를 구현할 수 있다.

```cpp
int maxDiff(vector<int>& nums, int left, int right) {
  if (left == right) {
    return nums[left];
  }

  int scoreByLeft = nums[left] - maxDiff(nums, left + 1, right);
  int scoreByRight = nums[right] - maxDiff(nums, left, right - 1);

  return max(scoreByLeft, scoreByRight);
}
```

여기서 메모이제이션을 이용해 호출을 최적화 한다.

```cpp
int memo[21][21] = {
    -1,
};

int maxDiff(vector<int>& nums, int left, int right) {
  if (memo[left][right] != -1) return memo[left][right];

  if (left == right) {
    return memo[left][right] = nums[left];
  }

  int scoreByLeft = nums[left] - maxDiff(nums, left + 1, right);
  int scoreByRight = nums[right] - maxDiff(nums, left, right - 1);

  return memo[left][right] = max(scoreByLeft, scoreByRight);
}

bool PredictTheWinner(vector<int>& nums) {
  memset(memo, -1, sizeof(memo));
  int size = nums.size();

  return maxDiff(nums, 0, size - 1) >= 0;
}
```

## 고생한 점
