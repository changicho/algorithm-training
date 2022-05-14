# 2267. Check if There Is a Valid Parentheses String Path

[링크](https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

행의 갯수를 R, 열의 갯수를 C라 하자.

모든 경우를 재귀호출로 탐색할 경우 R, C가 100일 때 경우의 수는 최대 22750883079422934966181954039568885395604168260154104734000 이며 이는 제한시간 내에 불가능하다.

결국 맨 마지막 좌표에 도착 가능한지 여부만 판단하면 된다.

따라서 백트래킹과 동적 계획법을 이용해 중복되는 경우를 줄인다.

이 경우 나타날 수 있는 최대 경우의 수는 R * C * (R + C)개 이다.

따라서 시간 복잡도는 O(R * C * (R + C)) 이다.

### 공간 복잡도

저장해야 하는 최대 경우의 수는 R * C * (R + C)개 이므로 공간 복잡도는 O(R * C * (R + C)) 이다.

### 동적 계획법 & 백트래킹

| 내 코드 (ms) |    시간 복잡도     |    공간 복잡도     |
| :----------: | :----------------: | :----------------: |
|     211      | O(R * C * (R + C)) | O(R * C * (R + C)) |

시작점에서 끝점까지 도착할 때 path에서 여는 괄호의 갯수 - 닫는 괄호의 갯수 = 0 이며 valid해야 valid path가 존재한다고 판단할 수 있다.

따라서 각 경우마다 openCount를 넘기며 탐색을 계속한다.

현재 좌표에 도달했을 때 다음을 확인한다.

- 이전에 이미 방문한 경우인지 (좌표, 여는 괄호의 갯수)
- 현재 좌표의 괄호에 따라 openCount를 조정했을 때 음수가 되는지 (탐색불가)

이를 이용해 각 좌표마다 여는괄호의 갯수에 따른 방문 여부를 갱신하며 탐색을 이어나간다.

openCount의 최대 값는 R + C까지이다. 따라서 각 좌표마다 openCount의 경우의 수를 곱한 값이 최대 경우의 수가 된다.

이는 R * C * (R + C) 이므로 제한시간 내에 탐색을 완료할 수 있다.

모든 탐색이 끝났을 때 끝점에 valid한 경우가 존재하는지 반환한다.

이를 구현하면 다음과 같다.

```cpp
struct Axis {
  int y, x;
};
Axis dirs[2] = {{0, 1}, {1, 0}};  // only right, down

bool isAppear[101][101][201];

void dfs(Axis axis, vector<vector<char>> &grid, int openCount) {
  int rows = grid.size(), cols = grid.front().size();

  if (grid[axis.y][axis.x] == '(') {
    openCount++;
  } else {
    openCount--;
  }

  if (openCount < 0) return;
  if (isAppear[axis.y][axis.x][openCount]) return;
  isAppear[axis.y][axis.x][openCount] = true;

  for (Axis &d : dirs) {
    Axis next = {axis.y + d.y, axis.x + d.x};
    if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
      continue;

    dfs(next, grid, openCount);
  }
}

bool hasValidPath(vector<vector<char>> &grid) {
  int rows = grid.size(), cols = grid.front().size();

  dfs({0, 0}, grid, 0);

  return isAppear[rows - 1][cols - 1][0];
}
```

### 동적 계획법

| 내 코드 (ms) |    시간 복잡도     |    공간 복잡도     |
| :----------: | :----------------: | :----------------: |
|     237      | O(R * C * (R + C)) | O(R * C * (R + C)) |

위 방법에서 재귀호출이 아닌 반복문을 이용해 풀이할 수 있다.

```cpp
bool hasValidPath(vector<vector<char>> &grid) {
  int rows = grid.size(), cols = grid.front().size();
  // edge case
  if (grid[0][0] == ')') return false;

  // need to initialize for all test case
  // isAppear[y][x][openCount]
  bool isAppear[101][101][201] = {
      false,
  };
  isAppear[0][0][1] = true;

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      int cur = grid[y][x] == '(' ? 1 : -1;

      for (int before = 0; before <= 200; before++) {
        if (before + cur < 0) continue;
        // from up
        if (y - 1 >= 0 && isAppear[y - 1][x][before]) {
          isAppear[y][x][before + cur] = true;
        }
        // from left
        if (x - 1 >= 0 && isAppear[y][x - 1][before]) {
          isAppear[y][x][before + cur] = true;
        }
      }
    }
  }

  return isAppear[rows - 1][cols - 1][0];
}
```

## 고생한 점
