# 980. Unique Paths III

[링크](https://leetcode.com/problems/unique-paths-iii/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자. (R \* C <= 20)

중복 없이 모든 좌표를 순회하는 경우의 수는 최대 3^(R \* C)이다. (3방향으로 최대 방문할 수 있는 좌표의 수만큼 방문)

입력받은 값이 작으므로 중복없이 모든 경우를 탐색한다.

이 경우 시간 복잡도는 O(3^(R \* C)) 이다.

### 공간 복잡도

DFS를 이용해 탐색할 경우 콜 스택에 O(R \* C)의 공간 복잡도를 사용한다.

### DFS & backtracking

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       | 3^(R \* C)  |  O(R \* C)  |

탐색하는 N이 작으므로 모두 탐색한다.

이 때 재귀호출시 방문해야 하는 빈 공간의 갯수를 넘기고, 남은 갯수가 0개이며 최종점에 도달했을 때 정답을 증가시킨다.

```cpp
Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool visited[21][21] = {
    false,
};
int answer = 0;

void recursive(Axis axis, int leftCount, vector<vector<int>> &grid) {
  if (leftCount == 0 && grid[axis.y][axis.x] == 2) {
    answer++;
    return;
  }

  if (grid[axis.y][axis.x] == 0) leftCount--;
  visited[axis.y][axis.x] = true;

  int rows = grid.size(), cols = grid.front().size();

  for (Axis &dir : dirs) {
    Axis next = {dir.y + axis.y, dir.x + axis.x};

    if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
      continue;
    if (grid[next.y][next.x] == -1) continue;
    if (visited[next.y][next.x]) continue;

    recursive(next, leftCount, grid);
  }

  visited[axis.y][axis.x] = false;
}

int uniquePathsIII(vector<vector<int>> &grid) {
  int leftCount = 0;
  int rows = grid.size(), cols = grid.front().size();

  Axis start = {-1, -1};
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (grid[y][x] == 0) leftCount++;
      if (grid[y][x] == 1) {
        start = {y, x};
      }
    }
  }

  recursive(start, leftCount, grid);

  return answer;
}
```

## 고생한 점
