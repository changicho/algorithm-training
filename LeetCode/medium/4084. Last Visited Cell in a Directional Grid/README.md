# 4084. Last Visited Cell in a Directional Grid

[링크](https://leetcode.com/problems/last-visited-cell-in-a-directional-grid/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 크기를 RC라 하자.

시뮬레이션을 수행할 경우 O(RC)의 시간 복잡도를 사용한다.

### 공간 복잡도

방문 여부 판단에 O(RC)의 공간 복잡도를 사용한다.

입력받은 배열을 수정할 경우 O(1)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      65      |    O(RC)    |    O(RC)    |

시작 위치부터 이동하며 이미 방문한 위치, 범위를 벗어나는 경우까지 탐색을 진행한다.

이후 멈춘 위치를 반환한다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
unordered_map<char, Axis> dirMap = {{'U', {-1, 0}}, {'R', {0, 1}}, {'D', {1, 0}}, {'L', {0, -1}}};

vector<int> lastVisitedCell(vector<vector<char>>& grid) {
  int rows = grid.size();
  int cols = grid[0].size();

  vector<vector<bool>> visited(rows, vector<bool>(cols, false));

  Axis cur = {0, 0};
  visited[0][0] = true;
  while (true) {
    Axis dir = dirMap[grid[cur.y][cur.x]];

    Axis next = {cur.y + dir.y, cur.x + dir.x};

    if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols) break;
    if (visited[next.y][next.x]) break;
    visited[next.y][next.x] = true;
    cur = next;
  }
  return {cur.y, cur.x};
}
```

## 고생한 점
