# 2664. The Knight’s Tour

[링크](https://leetcode.com/problems/the-knights-tour/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

각 상황마다 8가지 경우로 이동할 수 있다.

모든 경우를 탐색할 경우 시간 복잡도는 O(8^(R \* C)) 이다.

### 공간 복잡도

DFS로 탐색 시 O(R \* C)의 공간 복잡도가 필요하다.

### DFS & backtracking

| 내 코드 (ms) |  시간 복잡도  | 공간 복잡도 |
| :----------: | :-----------: | :---------: |
|     103      | O(8^(R \* C)) |  O(R \* C)  |

DFS를 이용해 각 상황마다 8가지 경우로 이동하며 탐색한다.

정답을 찾은 경우 탐색을 중지한다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[8] = {{-1, -2}, {1, -2}, {-2, -1}, {2, -1}, {-1, 2}, {1, 2}, {-2, 1}, {2, 1}};

bool findAnswer = false;

void recursive(vector<vector<int>> &board, int index, Axis a) {
  int rows = board.size(), cols = board[0].size();

  if (index == rows * cols - 1) {
    findAnswer = true;
    return;
  }

  for (Axis &dir : dirs) {
    Axis next = {a.y + dir.y, a.x + dir.x};
    if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
      continue;
    if (board[next.y][next.x] != -1) continue;

    board[next.y][next.x] = index + 1;
    recursive(board, index + 1, next);
    if (findAnswer) return;

    board[next.y][next.x] = -1;
  }
}

vector<vector<int>> tourOfKnight(int m, int n, int r, int c) {
  vector<vector<int>> board(m, vector<int>(n, -1));

  board[r][c] = 0;

  recursive(board, 0, {r, c});

  return board;
}
```

## 고생한 점
