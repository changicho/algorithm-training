# 1219. Path with Maximum Gold

[링크](https://leetcode.com/problems/path-with-maximum-gold/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C, 금광의 갯수를 G라 하자.

각 점을 시작점으로 가능한 모든 경로를 탐색해야 한다.

이 경우 하나의 좌표에서 가능한 모든 경로를 탐색하는 데 O(4^G)의 시간 복잡도가 소요된다.

이를 모든 좌표에 대해 탐색할 경우 O(R \* C \* 4^G)의 시간 복잡도가 소요된다.

### 공간 복잡도

DFS로 탐색할 때 call stack에 최대 G개의 값이 쌓일 수 있다.

이는 O(G)의 공간 복잡도가 필요하다.

방문 여부를 저장할 visited 배열이 필요하며 이는 O(R \* C)의 공간 복잡도가 필요하다.

### DFS

| 내 코드 (ms) |  시간 복잡도   |  공간 복잡도  |
| :----------: | :------------: | :-----------: |
|     190      | O(R * C * 4^G) | O(R \* C + G) |

각 점을 시작점으로 탐색하며 DFS로 탐색한다.

이 때 동일한 좌표를 다른 경로로 방문할 수 있음에 유의한다.

```cpp
struct Axis {
  int y, x;
};

struct Status {
  Axis a;
  int s;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int search(vector<vector<int>> &grid, Axis start) {
  int rows = grid.size(), cols = grid[0].size();
  bool visited[16][16] = {false};

  int ret = 0;

  function<void(Axis, int)> recursive = [&](Axis cur, int sum) {
    ret = max(ret, sum);

    for (Axis &dir : dirs) {
      Axis next = {dir.y + cur.y, dir.x + cur.x};

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      if (visited[next.y][next.x]) continue;
      if (grid[next.y][next.x] == 0) continue;

      visited[next.y][next.x] = true;

      recursive(next, sum + grid[next.y][next.x]);

      visited[next.y][next.x] = false;
    }
  };

  visited[start.y][start.x] = true;
  recursive(start, grid[start.y][start.x]);

  return ret;
}

int getMaximumGold(vector<vector<int>> &grid) {
  int rows = grid.size(), cols = grid[0].size();

  int answer = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (grid[y][x] == 0) continue;

      int cur = search(grid, {y, x});
      answer = max(answer, cur);
    }
  }
  return answer;
}
```

## 고생한 점
