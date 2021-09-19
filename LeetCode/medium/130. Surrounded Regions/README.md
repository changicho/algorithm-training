# 130. Surrounded Regions

[링크](https://leetcode.com/problems/surrounded-regions/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

행의 갯수를 M, 열의 갯수를 N이라하자.

모든 요소를 한번씩 순회하며 O로 구성된 묶음을 찾아야한다.

따라서 모든 요소를 한번 순회하는데 들어가는 시간복잡도는 O(N \* M) 이다.

각 요소에서 BFS를 순회하며 묶음을 만들때 방문 여부를 체크하는 경우 이후 순회에서 건너뛰므로 최종적으로 묶음을 만드는데 들어가는 시간 복잡도는 O(N \* M)

### 공간 복잡도

방문 여부를 체크해야 하므로 O(N \* M)크기의 배열이 필요하다.

이때 문제에서 주어진 board의 값을 직접 변경하는 경우 별도의 공간이 필요하지 않다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |  O(N \* M)  |  O(N \* M)  |

테두리의 요소를 먼저 탐색하며 테두리에서 시작하는 O묶음의 좌표들을 미리 방문 처리한다.

이후 모든 좌표를 순회하며 O묶음을 만들 수 있는 경우 X로 값을 변경한다.

방문 여부를 저장할 2차원 배열을 생성했으나, 이를 주어진 board값을 직접 변경해 표기할 경우 별도의 공간이 필요하지 않다.

```cpp
struct Axis {
  int y, x;
};
Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void solve(vector<vector<char>>& board) {
  int m = board.size();
  int n = board.front().size();

  vector<vector<bool>> visited(m, vector<bool>(n, false));

  queue<Axis> q;
  for (int y = 0; y < m; y++) {
    if (board[y][0] == 'O') q.push({y, 0});
    if (board[y][n - 1] == 'O') q.push({y, n - 1});
  }
  for (int x = 1; x < n - 1; x++) {
    if (board[0][x] == 'O') q.push({0, x});
    if (board[m - 1][x] == 'O') q.push({m - 1, x});
  }

  while (!q.empty()) {
    Axis cur = q.front();
    q.pop();

    if (visited[cur.y][cur.x]) continue;
    visited[cur.y][cur.x] = true;

    for (Axis dir : dirs) {
      Axis next = cur;
      next.y += dir.y;
      next.x += dir.x;

      if (next.y < 0 || next.y >= m || next.x < 0 || next.x >= n) continue;
      if (board[next.y][next.x] == 'X') continue;

      q.push(next);
    }
  }

  for (int y = 1; y < m - 1; y++) {
    for (int x = 1; x < n - 1; x++) {
      if (board[y][x] == 'X') continue;
      if (visited[y][x]) continue;

      q.push({y, x});

      while (!q.empty()) {
        Axis cur = q.front();
        q.pop();

        if (visited[cur.y][cur.x]) continue;
        visited[cur.y][cur.x] = true;
        board[cur.y][cur.x] = 'X';

        for (Axis dir : dirs) {
          Axis next = cur;
          next.y += dir.y;
          next.x += dir.x;

          if (next.y < 0 || next.y >= m || next.x < 0 || next.x >= n)
            continue;
          if (board[next.y][next.x] == 'X') continue;

          q.push(next);
        }
      }
    }
  }
}
```

### BFS with update fast

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |  O(N \* M)  |  O(N \* M)  |

edge에 붙어있는 'O' 외에 다른 'O'들은 모두 X로 바뀔 것이다.

따라서 edge에 붙은 'O'만 BFS로 탐색하고, 이후 one pass를 통해 업데이트한다.

```cpp
void BFS(vector<vector<char>>& board, Axis axis, char skip, char newValue) {
  if (board[axis.y][axis.x] != skip) return;

  int rows = board.size();
  int cols = board.front().size();

  queue<Axis> q;
  q.push(axis);
  board[axis.y][axis.x] = newValue;

  while (!q.empty()) {
    Axis cur = q.front();
    q.pop();

    for (Axis dir : dirs) {
      Axis next = {cur.y + dir.y, cur.x + dir.x};

      if (next.x < 0 || next.x >= cols || next.y < 0 || next.y >= rows)
        continue;
      if (board[next.y][next.x] != skip) continue;

      board[next.y][next.x] = newValue;
      q.push(next);
    }
  }
}

void solve(vector<vector<char>>& board) {
  int rows = board.size();
  int cols = board.front().size();

  vector<Axis> edges;
  for (int y = 0; y < rows; y++) {
    if (board[y][0] == 'O') edges.push_back({y, 0});
    if (board[y][cols - 1] == 'O') edges.push_back({y, cols - 1});
  }
  for (int x = 0; x < cols; x++) {
    if (board[0][x] == 'O') edges.push_back({0, x});
    if (board[rows - 1][x] == 'O') edges.push_back({rows - 1, x});
  }

  for (Axis edge : edges) {
    BFS(board, edge, 'O', 'E');
  }

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[y][x] == 'O') {
        board[y][x] = 'X';
      } else if (board[y][x] == 'E') {
        board[y][x] = 'O';
      }
    }
  }
}
```

## 고생한 점
