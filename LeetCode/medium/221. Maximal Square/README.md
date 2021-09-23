# 221. Maximal Square

[링크](https://leetcode.com/problems/maximal-square/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

행의 개수를 N, 열의 개수를 M이라고 하자.

브루트 포스로 모든 좌표에 대해서 가장 큰 정사각형을 구할 경우 시간 복잡도는 O(N^2 \* M^2)이다.

혹은 동적 계획법을 이용할 수 있다.

미리 각 방향별 연속된 1의 개수 (변이 될 수 있는 길이)들을 모두 구한 뒤 이를 이용할 경우 하나의 좌표에서 가장 큰 정사각형을 구하는 데 O(min(N, M))이 된다.

따라서 시간 복잡도는 O(N \* M \* min(N, M)) 이 된다.

혹은 하나의 dp배열에 직전까지의 가장 큰 정사각형의 길이를 저장할 경우 한번의 순회를 통해 구할 수 있다.

이 경우는 O(N \* M)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법을 이용할 경우 각 좌표마다의 dp값이 필요하다.

이 경우 공간 복잡도는 O(N \* M)이 된다.

### 동적 계획법 (4방향 탐색)

| 내 코드 (ms) |      시간 복잡도       | 공간 복잡도 |
| :----------: | :--------------------: | :---------: |
|      36      | O(N \* M \* min(N, M)) |  O(N \* M)  |

다음과 같은 4개의 dp배열을 구한다.

- 4방향으로 진행했을 때 1이 연속적으로 나오는 갯수

이를 이용해 한 변의 길이가 될 수 있는 후보를 구할 수 있다.

시작점 (왼쪽 위)와 끝점 (오른쪽 아래)에 대한 좌표와 다음 4개의 dp값으로 현재 크기의 정사각형을 만들 수 있는지 구할 수 있다.

따라서 모든 좌표에 대해서 가능한 정사각형의 최대 길이를 탐색한다.

```cpp
int maximalSquare(vector<vector<char>>& matrix) {
  int rows = matrix.size();
  int cols = matrix.front().size();

  vector<vector<int>> dpLeft(rows, vector<int>(cols, 0));
  vector<vector<int>> dpRight(rows, vector<int>(cols, 0));
  vector<vector<int>> dpUp(rows, vector<int>(cols, 0));
  vector<vector<int>> dpDown(rows, vector<int>(cols, 0));

  for (int y = 0; y < rows; ++y) {
    for (int x = 0; x < cols; ++x) {
      int reverseY = rows - 1 - y;

      if (y == 0) {
        dpDown[y][x] = matrix[y][x] == '1' ? 1 : 0;
        dpUp[reverseY][x] = matrix[reverseY][x] == '1' ? 1 : 0;
        continue;
      }

      dpDown[y][x] = matrix[y][x] == '1' ? dpDown[y - 1][x] + 1 : 0;
      dpUp[reverseY][x] =
          matrix[reverseY][x] == '1' ? dpUp[reverseY + 1][x] + 1 : 0;
    }
  }

  for (int x = 0; x < cols; ++x) {
    for (int y = 0; y < rows; ++y) {
      int reverseX = cols - 1 - x;

      if (x == 0) {
        dpRight[y][x] = matrix[y][x] == '1' ? 1 : 0;
        dpLeft[y][reverseX] = matrix[y][reverseX] == '1' ? 1 : 0;
        continue;
      }

      dpRight[y][x] = matrix[y][x] == '1' ? dpRight[y][x - 1] + 1 : 0;
      dpLeft[y][reverseX] =
          matrix[y][reverseX] == '1' ? dpLeft[y][reverseX + 1] + 1 : 0;
    }
  }

  int limitSize = min(rows, cols);
  int answer = 0;
  for (int y = 0; y < rows; ++y) {
    for (int x = 0; x < cols; ++x) {
      for (int size = 1; size <= limitSize; ++size) {
        int endY = y + size - 1;
        int endX = x + size - 1;
        if (endY >= rows || endX >= cols) break;

        int squareLength = min(min(dpRight[endY][endX], dpDown[endY][endX]),
                                min(dpUp[y][x], dpLeft[y][x]));

        if (squareLength >= size) {
          answer = max(answer, (size) * (size));
        } else {
          break;
        }
      }
    }
  }

  return answer;
}
```

### 동적 계획법 (one pass)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      24      |  O(N \* M)  |  O(N \* M)  |

위 방법에서 4방향에 대한 dp배열을 모두 구했다.

dp배열을 다음과 같이 설정할 경우 하나의 dp배열을 이용할 수 있다.

```cpp
dp[y][x]; // y,x좌표 까지 가능한 정사각형의 최대 길이
```

점화식은 다음과 같다.

```cpp
dp[y][x] = min(min(dp[y][x - 1], dp[y - 1][x]), dp[y - 1][x - 1]) + 1;
```

이는 dp값 자체가 가능한 정사각형의 최대 길이를 나타내기 때문이다.

현재 좌표 (y, x)를 갱신하기 위해서는 (y, x-1), (y-1,x), (y-1,x-1)의 좌표의 값을 이용할 수 있다.

- 왼쪽에서 오른쪽 방향으로의 길이
- 위에서 아래 방향으로의 길이
- 대각선에서 오는 중간에 비지 않은 값

초기값은 다음과 같다.

```cpp
dp[y][x] = 0; // 모든 좌표에 대해
```

이를 이용해 구할 경우 다음과 같다.

여기서 y, x가 각각 0일 경우에 대해서 별도로 처리하지 않도록 1을 시작점으로 설정한다.

```cpp
int maximalSquare(vector<vector<char>>& matrix) {
  int rows = matrix.size();
  int cols = matrix.front().size();

  vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));
  int length = 0;

  for (int y = 1; y <= rows; y++) {
    for (int x = 1; x <= cols; x++) {
      if (matrix[y - 1][x - 1] != '1') continue;

      dp[y][x] = min(min(dp[y][x - 1], dp[y - 1][x]), dp[y - 1][x - 1]) + 1;
      length = max(length, dp[y][x]);
    }
  }

  return length * length;
}
```

### 동적 계획법 (space optimized)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      24      |  O(N \* M)  |    O(N)     |

이전 방법에서 y,x 좌표의 값을 갱신하려 할 때 다음 3가지 값만을 이용한다.

- (y, x-1)
- (y-1,x)
- (y-1,x-1)

따라서 위 방법에서 2차원 배열의 dp를 하나의 행에 대해서만 사용할 수 있다.

여기서 직전의 dp값 (x에 대한 직전 값)의 경우 갱신되므로 별도의 변수에 저장한다.

```cpp
int maximalSquare(vector<vector<char>>& matrix) {
  int rows = matrix.size();
  int cols = matrix.front().size();

  vector<int> dp(cols + 1, 0);
  int length = 0;
  int prev = 0;

  for (int y = 1; y <= rows; y++) {
    for (int x = 1; x <= cols; x++) {
      int temp = dp[x];

      if (matrix[y - 1][x - 1] == '1') {
        dp[x] = min(prev, min(dp[x - 1], dp[x])) + 1;
      } else {
        dp[x] = 0;
      }
      length = max(length, dp[x]);
      prev = temp;
    }
  }
  return length * length;
}
```

## 고생한 점
