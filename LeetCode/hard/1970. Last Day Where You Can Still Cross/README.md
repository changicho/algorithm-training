# 1970. Last Day Where You Can Still Cross

[링크](https://leetcode.com/problems/last-day-where-you-can-still-cross/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

마지막엔 모든 땅에 물이 찬다. 물이 차는 좌표의 갯수는 R \* C이다.

각 과정마다 DFS, BFS를 이용해 탐색을 진행할 경우 O((R \* C)^2)의 시간 복잡도를 사용하므로 이는 제한시간 내에 불가능하다.

처음에는 맨 위 좌표들과 맨 아래 좌표들이 연결되어있으므로 유니온 파인드를 이용해 물이 찰 때마다 연결되어있는지 확인할 수 있다.

이 경우 O(R \* C)의 시간 복잡도를 사용한다.

### 공간 복잡도

유니온 파인드를 사용할 경우 O(R \* C)의 시간 복잡도를 사용한다.

### 유니온 파인드

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     434      |  O(R \* C)  |  O(R \* C)  |

물이 차는 좌표를 역순으로 순회하며 땅으로 변경한다.

변경한 땅에 인접한 땅들이 있다면 합친다.

이후 맨 위 좌표들과 맨 아래 좌표들이 연결되었는지 매번 확인한다.

이 때 각 좌표마다 같은 그룹에 묶였는지를 유니온 파인드를 사용해 빠르게 확인할 수 있다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

vector<int> parents;

int find(int node) {
  if (parents[node] == node) return node;
  return parents[node] = find(parents[node]);
}

void merge(int a, int b) {
  a = find(a), b = find(b);

  if (a == b) return;
  if (a > b) swap(a, b);
  parents[b] = a;
}

int latestDayToCross(int row, int col, vector<vector<int>> &cells) {
  int rows = row, cols = col;
  // finally all axis will flood
  vector<vector<int>> board(rows, vector<int>(cols, 1));

  parents.resize(rows * cols + 3);
  for (int i = 0; i < rows * cols + 3; i++) {
    parents[i] = i;
  }

  int top = rows * cols + 1, bottom = rows * cols + 2;
  for (int x = 0; x < cols; x++) {
    if (board[0][x] == 0) merge(top, x);
    if (board[rows - 1][x] == 0) merge(bottom, (rows - 1) * cols + x);
  }

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[y][x] == 1) continue;

      for (Axis &dir : dirs) {
        Axis next = {y + dir.y, x + dir.x};

        if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
          continue;
        if (board[next.y][next.x] == 1) continue;

        merge(y * cols + x, next.y * cols + next.x);
      }
    }
  }

  if (find(bottom) == find(top)) return cells.size();

  for (int i = cells.size() - 1; i >= 0; i--) {
    vector<int> c = cells[i];
    int y = c[0] - 1, x = c[1] - 1;
    board[y][x] = 0;

    if (y == 0) merge(y * cols + x, top);
    if (y == rows - 1) merge(y * cols + x, bottom);

    for (Axis &dir : dirs) {
      Axis next = {y + dir.y, x + dir.x};

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      if (board[next.y][next.x] == 1) continue;

      merge(y * cols + x, next.y * cols + next.x);
    }

    if (find(bottom) == find(top)) return i;
  }
  return 0;
}
```

## 고생한 점
