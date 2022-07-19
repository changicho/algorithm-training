# 464. Can I Win

[링크](https://leetcode.com/problems/can-i-win/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 숫자를 N이라 하자.

N개의 수를 고른 현재 상황의 총 경우의 수는 2^N개 이다.

이를 동적 계획법을 이용해 중복을 줄일 경우 모든 경우의 탐색에 O(2^N)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법을 이용할 경우 O(2^N)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     108      |   O(2^N)    |   O(2^N)    |

DFS를 이용해 현재 남은숫자중 특정 수를 선택했을 때 이길 수 있는지를 판단한다.

이 때 현재 선택하지 않은 수를 (선택 가능한 남은 수) 인자로 넘기며 현재까지의 합이 total로 도달 가능한지 판별한다.

만약 total이 0 이하인 경우는 이미 이전에 모든 수를 선택한 상황이므로 이길 수 없다.

만약 현재 경우에서 특정 수를 선택했을 때 상대방이 이길 수 없는 결과를 받은 경우, 무조건 해당 수를 선택하면 자신은 이길 수 있다.

이 과정에서 동적 계획법을 이용해 연산을 줄인다.

```cpp
int dp[1 << 20] = {};
// digit : current game state
bool dfs(int m, int total, int digit) {
  if (dp[digit] != 0) return dp[digit] > 0;
  if (total <= 0) return false;

  for (int i = 0; i < m; ++i) {
    if (digit & (1 << i)) continue;

    int next = digit | (1 << i);
    // if (i+1) is available to pick and my opponent can't win after I picked
    if (!dfs(m, total - i - 1, next)) {
      // win
      dp[digit] = 1;
      return true;
    }
  }

  dp[digit] = -1;
  return false;
}

bool canIWin(int maxChoosableInteger, int desiredTotal) {
  int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;

  if (desiredTotal < 2) return true;
  if (sum < desiredTotal) return false;

  if (sum == desiredTotal) {
    return maxChoosableInteger % 2;
  }
  return dfs(maxChoosableInteger, desiredTotal, 0);
}
```

## 고생한 점
