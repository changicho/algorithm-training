# 1406. Stone Game III

[링크](https://leetcode.com/problems/stone-game-iii/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 stoneValue의 길이를 N이라 하자. (5 * 10^4)

모든 경우를 시뮬레이션 할 경우 제한시간 내에 불가능하다.

따라서 동적 계획법을 이용해 이전에 구한 값을 이용해 문제를 풀이한다.

이 경우 현재 밥, 앨리스 인지 여부와 index에 대해 모두 탐색해야 하므로 시간 복잡도는 O(N) 이다.

### 공간 복잡도

동적 계획법에 O(N)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     330      |    O(N)     |    O(N)     |

Stone Game II 문제와 유사하게 풀이한다.

재귀호출을 이용해 각 경우 (alice, bob), (index)에 대해서 탐색을 진행한다.

이 때 현재 고를 수 있는 갯수는 1~3개이다.

현재 index에서 재귀호출 이후 반환받는 값은 오른쪽 모든 경우를 탐색한 이후의 값이다.

따라서 왼쪽부터 오른쪽으로 탐색하며 호출이 반환될 때 마다 값이 갱신되며 왼쪽으로 반환한다.

이 때 최적의 값을 찾을 때 stoneValue의 값이 음수도 올 수 있음에 유의한다.

```cpp
int size;
long dp[2][50001];
vector<int> stoneValue;

int recursive(bool isAlice, int index) {
  if (index == size) {
    return 0;
  }

  if (dp[isAlice][index] != INT_MIN) {
    return dp[isAlice][index];
  }

  int res = isAlice ? INT_MIN : INT_MAX;
  int selected = 0;
  for (int next = index; next < size && (next - index + 1) <= 3; next++) {
    selected += stoneValue[next];

    if (isAlice) {
      res = max(res, selected + recursive(false, next + 1));
    } else {
      res = min(res, recursive(true, next + 1));
    }
  }
  return dp[isAlice][index] = res;
};

string stoneGameIII(vector<int>& stoneValue) {
  this->stoneValue = stoneValue;
  this->size = stoneValue.size();

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 50001; j++) {
      dp[i][j] = INT_MIN;
    }
  }
  recursive(true, 0);

  long sum = accumulate(stoneValue.begin(), stoneValue.end(), 0);

  long aliceScore = dp[true][0];
  long bobScore = sum - aliceScore;

  if (aliceScore > bobScore) {
    return "Alice";
  } else if (aliceScore < bobScore) {
    return "Bob";
  } else {
    return "Tie";
  }
}
```

## 고생한 점
