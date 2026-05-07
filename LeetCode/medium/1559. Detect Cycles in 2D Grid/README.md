# 1559. Detect Cycles in 2D Grid

[링크](https://leetcode.com/problems/detect-cycles-in-2d-grid/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 크기를 RC라 하자.

DFS를 이용해 길이가 4 이상의 사이클을 판별할 수 있다. 이 경우 중복방문을 제거할 때 O(RC)의 시간 복잡도를 사용한다.

### 공간 복잡도

DFS에 O(RC)의 공간 복잡도를 사용한다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      26      |    O(RC)    |    O(RC)    |

2차원 격좌 자표에서 상하좌우 4가지 방향으로 이동할 때 최소 사이클의 길이는 4이다.

이는 DFS로 탐색할 때 부모를 제외하고 같은 문자만 탐색하며, 자신과 같은 문자를 이후 방문할 경우 사이클이 있다고 판단 가능하다.

따라서 DFS를 사용해 탐색을 진행하며 방문 여부를 판단한다.

```cpp
bool answer = false;

pair<int, int> dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool visited[501][501] = {
    0,
};

void dfs(int y, int x, int py, int px, vector<vector<char>>& grid) {
  if (answer) return;
  int rows = grid.size(), cols = grid[0].size();
  visited[y][x] = true;

  for (int d = 0; d < 4; d++) {
    int yd = dirs[d].first;
    int xd = dirs[d].second;

    int ny = y + yd;
    int nx = x + xd;

    if (ny == py && nx == px) continue;
    if (nx < 0 || nx >= cols || ny < 0 || ny >= rows) continue;
    if (grid[ny][nx] != grid[y][x]) continue;
    if (visited[ny][nx]) {
      answer = true;
      return;
    }

    dfs(ny, nx, y, x, grid);
  }
};

bool containsCycle(vector<vector<char>>& grid) {
  int rows = grid.size(), cols = grid[0].size();

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (visited[y][x]) continue;

      dfs(y, x, y, x, grid);
    }
  }

  return answer;
}
```

## 고생한 점
