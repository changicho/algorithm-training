# 1020. Number of Enclaves

[링크](https://leetcode.com/problems/number-of-enclaves/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 크기를 N이라 하자.

테두리와 연결된 땅을 빼고 나머지 땅의 개수를 구해야 한다.

BFS 순회를 이용할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

BFS를 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      89      |    O(N)     |    O(N)     |

양 끝에 붙어있는 땅들을 BFS로 탐색하여 0으로 만든다.

이후 남은 1의 갯수를 센다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void visitBFS(vector<vector<int>>& grid, Axis start) {
  int rows = grid.size(), cols = grid[0].size();

  queue<Axis> q;
  q.push(start);

  while (!q.empty()) {
    Axis cur = q.front();
    q.pop();

    if (grid[cur.y][cur.x] == 0) continue;
    grid[cur.y][cur.x] = 0;

    for (Axis& dir : dirs) {
      Axis next = {cur.y + dir.y, cur.x + dir.x};

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      if (grid[next.y][next.x] == 0) continue;
      q.push(next);
    }
  }
}

int numEnclaves(vector<vector<int>>& grid) {
  int rows = grid.size(), cols = grid[0].size();

  for (int y = 0; y < rows; y++) {
    if (grid[y][0] == 1) {
      visitBFS(grid, {y, 0});
    }
    if (grid[y][cols - 1] == 1) {
      visitBFS(grid, {y, cols - 1});
    }
  }
  for (int x = 0; x < cols; x++) {
    if (grid[0][x] == 1) {
      visitBFS(grid, {0, x});
    }
    if (grid[rows - 1][x] == 1) {
      visitBFS(grid, {rows - 1, x});
    }
  }
  int answer = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (grid[y][x] == 1) answer++;
    }
  }
  return answer;
}
```

## 고생한 점
