# 265. Paint House II

[링크](https://leetcode.com/problems/paint-house-ii/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

집의 갯수를 N, 색의 갯수를 K라 하자.

각 집에 대해서 특정 색을 칠했을 때 이전의 결과를 활용해 최소값을 갱신할 수 있다.

이를 위해 동적 계획법을 사용한다.

이 경우 현재 집에 대해 색을 갱신할 때 O(K^2)의 시간 복잡도를 사용한다.

이를 N번 반복하므로 O(N * K^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법에 O(N * K)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      19      | O(N * K^2)  |  O(N * K)   |

다음과 같은 dp 식을 생성한다.

```cpp
// definition
int dp[i][color]; // i번째 집이 color 색일 때의 최소 비용

// initial
int dp[0][color] = costs[0][color];

// update
dp[i][color] = min(dp[i-1][otherColor] + costs[i][color], dp[i][color]);
```

이를 이용해 구현하면 다음과 같다.

```cpp
int minCostII(vector<vector<int>>& costs) {
  int size = costs.size();
  int colors = costs[0].size();

  int dp[101][101] = {
      -1,
  };
  memset(dp, -1, sizeof(dp));

  for (int i = 0; i < colors; i++) {
    dp[0][i] = costs[0][i];
  }

  for (int i = 1; i < size; i++) {
    for (int curColor = 0; curColor < colors; curColor++) {
      dp[i][curColor] = INT_MAX;
      for (int beforeColor = 0; beforeColor < colors; beforeColor++) {
        if (curColor == beforeColor) continue;

        dp[i][curColor] =
            min(dp[i - 1][beforeColor] + costs[i][curColor], dp[i][curColor]);
      }
    }
  }

  int answer = INT_MAX;

  for (int i = 0; i < colors; i++) {
    answer = min(answer, dp[size - 1][i]);
  }
  return answer;
}
```

## 고생한 점
