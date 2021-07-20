# 1254. Number of Closed Islands

[링크](https://leetcode.com/problems/number-of-closed-islands/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

좌표의 행의 개수를 N, 열의 개수를 M이라 하자.

우선 모든 좌표를 한번 순회해야 하므로 outer 시간 복잡도는 O(N \* M) 이다.

이 때 내부적으로 섬인 경우에 대해서 BFS, DFS로 방문 처리를 진행한다.

이 경우에 결국에는 모든 좌표를 한번씩 방문하는 것과 동일하다.

따라서 시간 복잡도는 O(N \* M)이다.

### 공간 복잡도

방문 여부를 체크할 배열이 필요하다. 이 크기는 O(N \* M)이다.

### flood fill

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |  O(N \* M)  |  O(N \* M)  |

유사한 문제 : [1020. Number of Enclaves](https://leetcode.com/problems/number-of-enclaves/)

섬이 모서리에 위치한 경우는 제외해야한다.

따라서 처음 모서리에 있는 섬들은 미리 방문체크를 진행한다.

이후 모든 좌표를 순회하며 섬을 발견한 경우 방문 체크를 진행하며 순회를 마친다.

이 때 공간복잡도를 줄이기 위해 주어진 grid 배열에 숫자를 바꾸는 방법으로 풀이할 수 있다.

BFS로 풀이한 방법은 다음과 같다.

```cpp
struct Axis {
  int y, x;
  Axis operator+(Axis& b) const { return {y + b.y, x + b.x}; }
};
Axis dirs[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void explorer(Axis start, vector<vector<int>>& grid,
              vector<vector<bool>>& visited) {
  int row = grid.size();
  int col = grid.front().size();

  queue<Axis> q;
  q.push(start);

  while (!q.empty()) {
    Axis cur = q.front();
    q.pop();

    if (visited[cur.y][cur.x]) continue;
    visited[cur.y][cur.x] = true;

    for (Axis dir : dirs) {
      Axis next = cur + dir;

      if (next.y < 0 || next.y >= row || next.x < 0 || next.x >= col)
        continue;
      if (visited[next.y][next.x]) continue;

      if (grid[next.y][next.x] == 1) continue;

      q.push(next);
    }
  }
}

int closedIsland(vector<vector<int>>& grid) {
  int row = grid.size();
  int col = grid.front().size();

  vector<vector<bool>> visited(row, vector<bool>(col, false));

  for (int y = 0; y < row; y++) {
    if (grid[y][0] == 0) explorer({y, 0}, grid, visited);
    if (grid[y][col - 1] == 0) explorer({y, col - 1}, grid, visited);
  }

  for (int x = 0; x < col; x++) {
    if (grid[0][x] == 0) explorer({0, x}, grid, visited);
    if (grid[row - 1][x] == 0) explorer({row - 1, x}, grid, visited);
  }

  int answer = 0;
  for (int y = 1; y < row - 1; y++) {
    for (int x = 1; x < col - 1; x++) {
      if (grid[y][x] == 1) continue;
      if (visited[y][x]) continue;

      answer += 1;

      explorer({y, x}, grid, visited);
    }
  }

  return answer;
}
```

DFS로 풀이한 방법은 다음과 같다.

```cpp
int fill(vector<vector<int>>& grid, int y, int x) {
  if (y < 0 || x < 0 || y >= grid.size() || x >= grid[y].size()) return 0;
  if (grid[y][x] > 0) return 0;

  grid[y][x] = 1;
  return grid[y][x] + fill(grid, y + 1, x) + fill(grid, y, x + 1) +
          fill(grid, y - 1, x) + fill(grid, y, x - 1);
}

int closedIsland(vector<vector<int>>& grid) {
  int answer = 0;

  for (int y = 0; y < grid.size(); ++y) {
    for (int x = 0; x < grid[y].size(); ++x) {
      if (y * x == 0 || y == grid.size() - 1 || x == grid[y].size() - 1)
        fill(grid, y, x);
    }
  }

  for (int y = 0; y < grid.size(); ++y) {
    for (int x = 0; x < grid[y].size(); ++x) {
      answer += fill(grid, y, x) > 0;
    }
  }
  return answer;
}
```

## 고생한 점
