# 1391. Check if There is a Valid Path in a Grid

[링크](https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 크기를 RC라 하자.

DFS를 이용해 탐색할 경우 O(RC)의 시간 복잡도를 사용한다.

### 공간 복잡도

DFS에 O(RC)의 공간 복잡도를 사용한다.

방문 여부 배열에 O(RC)의 공간 복잡도를 사용한다.

### DFS & 구현

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      39      |    O(RC)    |    O(RC)    |

0,0부터 DFS를 이용해 탐색하며 목적지까지 도달 가능한지 판단한다.

이때 두 좌표의 도로가 실제로 연결되어있는지 판단하는 함수를 별도로 생성해 관리한다.

```cpp
struct Axis {
  int y, x;
};

// U R D L
Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

string streets[7] = {"", "LR", "UD", "LD", "RD", "LU", "RU"};

bool isConnected(vector<vector<int>>& grid, int ay, int ax, int by, int bx) {
  string streetA = streets[grid[ay][ax]], streetB = streets[grid[by][bx]];

  // U
  if ((by + 1) == ay) {
    if (streetA.contains('U') && streetB.contains('D')) return true;
  }
  // R
  else if ((bx - 1) == ax) {
    if (streetA.contains('R') && streetB.contains('L')) return true;
  }
  // D
  else if ((by - 1) == ay) {
    if (streetA.contains('D') && streetB.contains('U')) return true;
  }
  // L
  else if ((bx + 1) == ax) {
    if (streetA.contains('L') && streetB.contains('R')) return true;
  }
  return false;
}

bool answer = false;
bool visited[301][301] = {
    false,
};

void dfs(vector<vector<int>>& grid, Axis cur) {
  if (answer) return;
  int rows = grid.size(), cols = grid[0].size();

  if (cur.y == rows - 1 && cur.x == cols - 1) {
    answer = true;
    return;
  }

  for (Axis& dir : dirs) {
    Axis next = {cur.y + dir.y, cur.x + dir.x};

    if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
      continue;
    if (visited[next.y][next.x]) continue;
    if (!isConnected(grid, cur.y, cur.x, next.y, next.x)) continue;

    visited[next.y][next.x] = true;

    dfs(grid, next);
  }
}

bool hasValidPath(vector<vector<int>>& grid) {
  int rows = grid.size(), cols = grid[0].size();

  visited[0][0] = true;
  dfs(grid, {0, 0});
  return answer;
}
```

## 고생한 점
