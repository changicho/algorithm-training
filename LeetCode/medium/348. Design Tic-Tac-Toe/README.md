# 348. Design Tic-Tac-Toe

[링크](https://leetcode.com/problems/design-tic-tac-toe/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 보드의 한 변의 크기를 N이라 하자.

각 경우마다 보드에 표시하는데 O(1)의 시간 복잡도를 사용한다.

이후 매번 보드를 탐색하며 승리 여부를 판단하는데 O(N^2)의 시간 복잡도가 소요된다.

표시가 된 부분만 탐색하며 승리 여부를 판단할 경우 O(N)의 시간 복잡도가 소요된다.

행, 열, 그리고 대각선에 대해서 승리 여부를 각 인원이 놓은 말의 수로 판단할 수 있다.

이 경우 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

보드를 시뮬레이션 해야 하므로 O(1)의 시간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      37      |    O(N)     |   O(N^2)    |

각 보드에 인원별로 표시한 내용을 기록한다.

이 때 현재 표시된 기록의 좌표에 따라서 승리 여부를 판단할 수 있다.

- 연관되는 행
- 연관되는 열
- (연관될 경우) 대각선

이 떄 판단해야 하는 길이는 각각 N이므로 O(N)의 시간 복잡도로 승리 여부를 판단할 수 있다.

```cpp
class TicTacToe {
 private:
  vector<vector<int>> board;
  bool hasWinner = false;

  bool checkDiagonal(int player) {
    int size = board.size();
    bool lToR = true, rToL = true;
    for (int i = 0; i < size; i++) {
      int rX = size - 1 - i;
      if (board[i][i] != player) {
        lToR = false;
      }
      if (board[i][rX] != player) {
        rToL = false;
      }
    }
    return lToR || rToL;
  }

  bool checkHorizontal(int player, int y) {
    int size = board.size();
    for (int x = 0; x < size; x++) {
      if (board[y][x] != player) return false;
    }
    return true;
  }
  bool checkHorizontal(int player) {
    int size = board.size();
    for (int y = 0; y < size; y++) {
      if (checkHorizontal(player, y)) return true;
    }
    return false;
  }

  bool checkVertical(int player, int x) {
    int size = board.size();
    for (int y = 0; y < size; y++) {
      if (board[y][x] != player) return false;
    }
    return true;
  }
  bool checkVertical(int player) {
    int size = board.size();
    for (int x = 0; x < size; x++) {
      if (checkVertical(player, x)) return true;
    }
    return false;
  }

  int checkWinner(int row, int col, int player) {
    int size = board.size();

    if (checkDiagonal(player) || checkHorizontal(player, row) ||
        checkVertical(player, col)) {
      return player;
    }
    return 0;
  }

 public:
  TicTacToe(int n) { board.resize(n, vector<int>(n, 0)); }

  int move(int row, int col, int player) {
    if (!hasWinner) {
      board[row][col] = player;
    }

    int ret = checkWinner(row, col, player);
    if (ret != 0) {
      hasWinner = true;
    }
    return ret;
  }
};
```

### 완전 탐색 (optimized)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      35      |    O(1)     |   O(N^2)    |

한 줄에 대해서 승리 여부를 다음과 같이 판단할 수 있다.

- 해당 줄에 한 인원이 표시한 말의 수가 N개인 경우

따라서 각 행, 열, 그리고 대각선에 대해서 표시가 될 때마다 count를 변화시킨다.

이후 해당 count중에 N이 되는 경우가 존재하는지 판단할 수 있다.

```cpp
class TicTacToe {
 private:
  int size;
  int rowCounts[101] = {
      0,
  };
  int colCounts[101] = {
      0,
  };
  int diagonalCount = 0;
  int reverseDiagonalCount = 0;

 public:
  TicTacToe(int n) { size = n; }

  int move(int row, int col, int player) {
    int currentPlayer = (player == 1) ? 1 : -1;

    // update row and col
    rowCounts[row] += currentPlayer;
    colCounts[col] += currentPlayer;

    // update diagonal
    if (row == col) {
      diagonalCount += currentPlayer;
    }
    if (col == (size - row - 1)) {
      reverseDiagonalCount += currentPlayer;
    }

    if (abs(rowCounts[row]) == size || abs(colCounts[col]) == size ||
        abs(diagonalCount) == size || abs(reverseDiagonalCount) == size) {
      return player;
    }

    return 0;
  }
};
```

## 고생한 점
