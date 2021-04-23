# 37. Sudoku Solver

[링크](https://leetcode.com/problems/sudoku-solver/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

매 빈칸마다 9개의 숫자가 들어갈 수 있다. 각 빈칸의 최대 개수는 9 \* 9 개이다.

따라서 완전 탐색을 진행할 경우 시간 복잡도는 O(9^81) 이므로 제한시간 내에 불가능하다.

따라서 백트래킹을 이용해 가능한 경우만 탐색을 진행한다.

### 공간 복잡도

각 경우별로 3가지 조건에 위배되는지 검사하기 위해 상황을 체크할 배열이 필요하다.

따라서 공간 복잡도는 O(9 \* 9 \* 3) 이므로 O(1)이다.

### 백트래킹

> 4ms

- 시간 복잡도 : O(9^(9^2)) 미만
- 공간 복잡도 : O(1)

스도쿠에서 고려해야 할 경우는 다음 3가지이다.

- 하나의 행(row)에 1~9가 하나씩만 존재하는지
- 하나의 열(col)에 1~9가 하나씩만 존재하는지
- 하나의 분면(field)에 1~9가 하나씩 존재하는지

존재 여부를 판단하기 위해 각 배열들을 다음과 같이 설정한다.

```cpp
bool row[9][10];    // row[y][number]
bool col[9][10];    // col[x][number]
bool field[9][10]; // field[getFieldIndex(y,x)][number]
```

분면은 다음과 같이 설정한다.

```cpp
// 0 1 2
// 3 4 5
// 6 7 8
int getFieldIndex(int y, int x) {
  return (y / 3) * 3 + x / 3;
}
```

각 좌표마다 가능한 숫자를 대입해보며, 가능한 경우 탐색을 이어나간다.

```cpp
bool row[9][10] = {
    false,
};
bool col[9][10] = {
    false,
};
bool field[9][10] = {
    false,
};
bool isOver = false;
vector<Axis> blanks;

void solveSudoku(vector<vector<char>>& board) {
  for (int y = 0; y < 9; y++) {
    for (int x = 0; x < 9; x++) {
      if (board[y][x] > '0') {
        col[x][board[y][x] - '0'] = true;
        row[y][board[y][x] - '0'] = true;
        field[getFieldIndex(y, x)][board[y][x] - '0'] = true;
      } else {
        blanks.push_back({y, x});
      }
    }
  }

  recursive(0, board);
}

void recursive(int depth, vector<vector<char>>& board) {
  if (isOver) return;

  if (depth == blanks.size()) {
    isOver = true;
    return;
  }

  Axis cur = blanks[depth];
  int y = cur.y;
  int x = cur.x;

  if (board[y][x] != '.' && board[y][x] > '0') {
    recursive(depth + 1, board);
    return;
  }

  for (int number = 1; number <= 9; number++) {
    if (!col[x][number] && !row[y][number] && !field[getFieldIndex(y, x)][number]) {
      board[y][x] = number + '0';
      col[x][number] = true;
      row[y][number] = true;
      field[getFieldIndex(y, x)][number] = true;

      recursive(depth + 1, board);
      if (isOver) return;

      board[y][x] = '.';
      col[x][number] = false;
      row[y][number] = false;
      field[getFieldIndex(y, x)][number] = false;
    }
  }
}

int getFieldIndex(int y, int x) {
  return (y / 3) * 3 + x / 3;
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      4       |

## 고생한 점
