# 2257. Count Unguarded Cells in the Grid

[링크](https://leetcode.com/problems/count-unguarded-cells-in-the-grid/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C, 경비의 수를 G라 하자.

각 경우마다 시뮬레이션을 돌릴 경우 O(R \* C \* G)의 시간 복잡도가 필요하다.

이 때 감시 범위를 추가할 때 경비를 만나는 경우 더이상 탐색을 진행하지 않아도 되므로 시간 복잡도를 줄일 수 있다.

### 공간 복잡도

시뮬레이션을 수행할 때 O(R \* C)의 공간 복잡도가 필요하다.

### 시뮬레이션

| 내 코드 (ms) |  시간 복잡도   | 공간 복잡도 |
| :----------: | :------------: | :---------: |
|     357      | O(R \* C \* G) |  O(R \* C)  |

2차원 배열을 생성한 뒤 경비와 벽을 표시한다.

이후 각 경비마다 상, 하, 좌, 우 네 방향으로 탐색을 진행하며 감시 범위영역으로 표시한다.

이 때 경비나 벽을 만나는 경우 탐색을 중지한다.

경비를 만나는 경우 이미 해당 방향은 채워져있기 때문이다.

```cpp
vector<int> dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

const int WALL = 1, GUARD = 2, FILLED = 3;

void fill(vector<vector<int>> &board, vector<int> g) {
  int rows = board.size(), cols = board[0].size();

  for (vector<int> &dir : dirs) {
    vector<int> cur = {g[0] + dir[0], g[1] + dir[1]};
    while (true) {
      if (cur[0] >= rows || cur[0] < 0 || cur[1] >= cols || cur[1] < 0) break;
      if (board[cur[0]][cur[1]] == WALL) break;
      if (board[cur[0]][cur[1]] == GUARD) break;

      board[cur[0]][cur[1]] = FILLED;

      cur = {cur[0] + dir[0], cur[1] + dir[1]};
    }
  }
}

int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls) {
  vector<vector<int>> board(m, vector<int>(n, 0));

  for (vector<int> &g : guards) {
    board[g[0]][g[1]] = GUARD;
  }
  for (vector<int> &w : walls) {
    board[w[0]][w[1]] = WALL;
  }

  for (vector<int> &g : guards) {
    fill(board, g);
  }

  int answer = 0;
  for (int y = 0; y < m; y++) {
    for (int x = 0; x < n; x++) {
      if (board[y][x] == 0) answer++;
    }
  }
  return answer;
}
```

## 고생한 점
