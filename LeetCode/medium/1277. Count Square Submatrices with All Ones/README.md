# 1277. Count Square Submatrices with All Ones

[링크](https://leetcode.com/problems/count-square-submatrices-with-all-ones/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

행의 개수를 R, 열의 개수를 C라 하자.

만들 수 있는 가장 큰 정사각형의 길이는 min(R, C)가 된다. 이를 L이라 하자.

브루트 포스 방법을 이용해 매번 직접 구할 경우 모든 좌표 순회에 O(R \* C)의 시간 복잡도가 소요된다. 이후 각 좌표마다 만들 수 있는 최대 크기의 정사각형을 구하는 데 O(R \* C)의 시간 복잡도가 소요되므로 O(R^2 \* C^2)의 시간 복잡도를 사용한다.

동적 계획법을 이용해 모든 좌표에서 특정 길이의 정사각형을 만들 수 있는지 판단할 수 있다.

이 경우 시간 복잡도는 O(R \* C \* L)이 된다.

혹은 각 좌표만 순회하며 직전에 만들 수 있는 최대 길이의 정사각형의 갯수를 갱신할 수 있다.

이 경우 각 좌표만 순회하므로 시간 복잡도는 O(R \* C)이다.

### 공간 복잡도

동적 계획법을 이용해 모든 좌표에서 특정 길이의 정사각형을 만들 수 있는지 판단할 경우 O(R \* C \* L)의 공간 복잡도를 사용한다.

각 좌표만 순회하며 각 좌표에서 끝나는 정사각형의 갯수를 입력받은 matrix를 이용해 갱신할 경우 O(1)의 공간 복잡도를 사용한다.

### 동적 계획법 (3차원)

| 내 코드 (ms) |  시간 복잡도   |  공간 복잡도   |
| :----------: | :------------: | :------------: |
|     844      | O(R \* C \* L) | O(R \* C \* L) |

dp를 다음과 같이 정의한다.

```cpp
dp[y][x][length]; // can make length square from (y,x)
```

dp의 일반식은 다음과 같다.

```cpp
int nextY = y + length - 1, nextX = x + length - 1;

bool isBeforeFine = dp[y][x][length - 1];
bool isRightFine = countFromLeft[nextY][nextX] >= length;
bool isDownFine = countFromUp[nextY][nextX] >= length;

dp[y][x][length] = isBeforeFine && isRightFine && isDownFine;
```

즉 끝 지점의 왼쪽, 윗쪽, 대각선 왼쪽위 에서 가능한지 여부를 판단한다.

이 때 끝지점의 왼쪽부분과 위쪽부분에서 현재 정사각형 크기 만큼 이상의 1이 갯수가 연속해서 나오는지를 판단해야한다.

이를 빠르게 하기 위해 미리 다음 배열을 만들어놓는다.

- countFromLeft : y,x좌표에서 왼쪽으로 연속된 1의 개수
- countFromUp : y,x좌표에서 위쪽으로 연속된 1의 개수

이를 이용해 모든 경우에 dp배열을 갱신하고 true인 경우를 센다.

```cpp
int countSquares(vector<vector<int>>& matrix) {
  int rows = matrix.size();
  int cols = matrix.front().size();

  int limit = min(rows, cols);
  vector<vector<int>> countFromUp(rows, vector<int>(cols, 0));
  vector<vector<int>> countFromLeft(rows, vector<int>(cols, 0));

  // fill countFromUp
  for (int x = 0; x < cols; x++) {
    countFromUp[0][x] = matrix[0][x] == 1;

    for (int y = 1; y < rows; y++) {
      if (matrix[y][x] != 1) {
        countFromUp[y][x] = 0;
        continue;
      }
      countFromUp[y][x] = countFromUp[y - 1][x] + 1;
    }
  }

  // fill countFromLeft
  for (int y = 0; y < rows; y++) {
    countFromLeft[y][0] = matrix[y][0] == 1;

    for (int x = 1; x < cols; x++) {
      if (matrix[y][x] != 1) {
        countFromLeft[y][x] = 0;
        continue;
      }
      countFromLeft[y][x] = countFromLeft[y][x - 1] + 1;
    }
  }

  // dp[y][x][length] : can make length square from (y,x)
  vector<vector<vector<bool>>> dp(
      rows, vector<vector<bool>>(cols, vector<bool>(limit + 1, false)));

  int answer = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (matrix[y][x] != 1) continue;

      dp[y][x][1] = true;
      answer += 1;
    }
  }

  for (int length = 2; length <= limit; length++) {
    for (int y = 0; y + length - 1 < rows; y++) {
      for (int x = 0; x + length - 1 < cols; x++) {
        int nextY = y + length - 1, nextX = x + length - 1;

        bool isBeforeFine = dp[y][x][length - 1];
        bool isRightFine = countFromLeft[nextY][nextX] >= length;
        bool isDownFine = countFromUp[nextY][nextX] >= length;

        if (isBeforeFine && isRightFine && isDownFine) {
          dp[y][x][length] = true;
          answer += 1;
        }
      }
    }
  }

  return answer;
}
```

### 동적 계획법 (2차원)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      60      | O(R \* C )  |    O(1)     |

입력받은 matrix를 다음과 같이 갱신한다.

```cpp
matrix[y][x]; // maximum length of square end at (y,x).
              // that means count of square end at (y,x).
```

즉 y, x좌표에서 끝나는 정사각형의 최대 길이가 곧 해당 위치에서 끝나는 정사각형의 최대 개수가 된다.

이를 모든 matrix의 좌표에 대해서 갱신하고, 이후 모든 좌표에 해당하는 값을 정답에 더한다.

```cpp
int countSquares(vector<vector<int>>& matrix) {
  int rows = matrix.size();
  int cols = matrix.front().size();
  int answer = 0;

  // matrix[y][x] : maximum length of square end at (y,x)
  // that means count of square end at (y,x)
  for (int y = 1; y < rows; y++) {
    for (int x = 1; x < cols; x++) {
      if (matrix[y][x] != 1) continue;

      int fromUp = matrix[y - 1][x], fromLeft = matrix[y][x - 1],
          fromLeftUp = matrix[y - 1][x - 1];

      matrix[y][x] = min({fromUp, fromLeft, fromLeftUp}) + 1;
    }
  }

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      answer += matrix[y][x];
    }
  }

  return answer;
}
```

## 고생한 점
