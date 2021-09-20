# 1314. Matrix Block Sum

[링크](https://leetcode.com/problems/matrix-block-sum/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 개수를 N, 열의 개수를 M이라 하자.

각 행마다 범위의 합을 구하는데 들어가는 시간 복잡도는 O(N \* M)이다.

이를 모든 좌표에 대해 반복할 경우 시간 복잡도는 O(N^2 \* M^2)가 되며 이는 제한시간 내에 불가능하다.

따라서 동적 계획법을 이용해 구간 합을 미리 구하고 이를 이용한다.

이 경우 구간 합을 구할 때 O(N \* M)의 시간 복잡도가 필요하고

이 구간 합을 이용해 정답 배열을 채우는 데 O(N \* M)의 시간 복잡도를 사용한다.

### 공간 복잡도

구간 합을 저장하는 2차원 배열을 생성하는데 O(N \* M)의 공간 복잡도를 사용한다.

### 동적 계획법 (구간 합)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      11      |  O(N \* M)  |  O(N \* M)  |

다음과 같은 구간 합을 나타내는 2차원 배열을 생성한다.

```cpp
dp[y][x]; // 0,0부터 y,x까지 모든 값들의 합
```

점화식은 다음과 같다.

```cpp
int fromUp = y < 1 ? 0 : dp[y - 1][x];
int fromLeft = x < 1 ? 0 : dp[y][x - 1];
int duplicated = x > 0 && y > 0 ? dp[y - 1][x - 1] : 0;

dp[y][x] = fromUp + fromLeft - duplicated + mat[y][x];
```

구간의 합을 구할 때, 이전 구간합에서 중복된 부분이 존재할 수 있고 이를 제거해야 한다.

초기값은 모두 0이다.

이를 이용해 구간 합을 구할 때와 마찬가지로 정답 배열을 구할 수 있다.

```cpp
vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
  int rows = mat.size();
  int cols = mat.front().size();

  // dp[y][x]; // 0,0부터 y,x까지 모든 값들의 합
  vector<vector<int>> dp(rows, vector<int>(cols, 0));

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      int fromUp = y < 1 ? 0 : dp[y - 1][x];
      int fromLeft = x < 1 ? 0 : dp[y][x - 1];
      int duplicated = x > 0 && y > 0 ? dp[y - 1][x - 1] : 0;

      dp[y][x] = fromUp + fromLeft - duplicated + mat[y][x];
    }
  }

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      int toY = min(y + k, rows - 1);
      int toX = min(x + k, cols - 1);
      int fromY = y - k - 1;
      int fromX = x - k - 1;

      mat[y][x] = dp[toY][toX];
      if (fromY >= 0) mat[y][x] -= dp[fromY][toX];  // fromUp
      if (fromX >= 0) mat[y][x] -= dp[toY][fromX];  // fromLeft
      if (fromY >= 0 && fromX >= 0) mat[y][x] += dp[fromY][fromX];
    }
  }

  return mat;
}
```

## 고생한 점
