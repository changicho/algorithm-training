# 529. Minesweeper

[링크](https://leetcode.com/problems/minesweeper/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

board의 행의 갯수를 R, 열의 갯수를 C라고 하자.

시뮬레이션을 이용해 현재 좌표에서부터 이후 다른 좌표들을 탐색할 수 있다.

이 경우 탐색에 BFS를 사용할 경우 O(R \* C)의 시간 복잡도를 사용한다.

현재 좌표에서 근처에 폭탄이 있는지 탐색하는 데 O(1)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(R \* C)이다.

### 공간 복잡도

BFS를 사용할 경우 O(R \* C)의 공간 복잡도를 사용한다.

### 시뮬레이션 & BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      34      |  O(R \* C)  |  O(R \* C)  |

총 8 방향으로 탐색을 이어가야한다.

만약 클릭한 좌표에 폭탄이 있는 경우 폭탄을 발견하고 더이상 탐색하지 않는다.

만약 빈칸을 선택한 경우 해당 좌표를 시작점으로 주변 좌표들을 BFS로 탐색해나간다.

만약 현재 좌표 근처에 폭탄이 있는 경우 해당 좌표는 숫자를 남기고 더이상 탐색을 진행하지 않는다.

이를 구현하면 다음과 같다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[8] = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                {1, 0},  {1, -1}, {0, -1}, {-1, -1}};

int countNearBomb(Axis &cur, vector<vector<char>> &board) {
  int rows = board.size();
  int cols = board.front().size();

  int count = 0;
  for (Axis &dir : dirs) {
    Axis next = {cur.y + dir.y, cur.x + dir.x};

    if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
      continue;
    if (board[next.y][next.x] == 'M') {
      count++;
    }
  }
  return count;
}

vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click) {
  int rows = board.size();
  int cols = board.front().size();

  vector<vector<bool>> visited(rows, vector<bool>(cols, false));

  if (board[click.front()][click.back()] == 'M') {
    board[click.front()][click.back()] = 'X';
    return board;
  }
  if (board[click.front()][click.back()] != 'E') {
    return board;
  }

  queue<Axis> q;
  q.push({click.front(), click.back()});
  visited[click.front()][click.back()] = true;

  while (!q.empty()) {
    Axis cur = q.front();
    q.pop();

    int bombCount = countNearBomb(cur, board);

    if (bombCount > 0) {
      board[cur.y][cur.x] = ('0' + bombCount);
      continue;
    }
    board[cur.y][cur.x] = 'B';

    for (Axis &dir : dirs) {
      Axis next = {cur.y + dir.y, cur.x + dir.x};

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      if (board[next.y][next.x] != 'E') continue;
      if (visited[next.y][next.x]) continue;

      visited[next.y][next.x] = true;
      q.push(next);
    }
  }

  return board;
}
```

## 고생한 점
