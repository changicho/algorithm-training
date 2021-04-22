# 36. Valid Sudoku

[링크](https://leetcode.com/problems/valid-sudoku/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

모든 칸을 순회하며 3가지 조건에 위배되는지를 검사하면 된다.

이 때 시간 복잡도는 O(9 \* 9) 이므로 O(1)이다.

### 공간 복잡도

각 경우별로 3가지 조건에 위배되는지 검사하기 위해 상황을 체크할 배열이 필요하다.

따라서 공간 복잡도는 O(9 \* 9 \* 3) 이므로 O(1)이다.

### 순회

> 16ms

- 시간 복잡도 : O(1)
- 공간 복잡도 : O(1)

다음 3가지 조건을 판별한다.

- 현재 axis에서 row가 올바른지
- 현재 axis에서 col이 올바른지
- 현재 axis에서 해당 분면이 올바른지

row, col은 board와 같은 크기의 배열을 이용해 판별할 수 있다.

분면의 경우 다음과 같다.

```cpp
0 1 2
3 4 5
6 7 8
```

각 axis별로 해당 분면을 찾는 식은 다음과 같다.

```cpp
int getFieldIndex(int y, int x) {
  return (y / 3) * 3 + x / 3;
}
```

좌표를 순회하며 체크하고, 3가지 조건에 위배되는지를 검사한다.

이 때 공백은 무시한다.

```cpp
bool isValidSudoku(vector<vector<char>>& board) {
  bool row[9][10] = {
      false,
  };
  bool col[9][10] = {
      false,
  };
  bool field[9][10] = {
      false,
  };
  for (int y = 0; y < 9; y++) {
    for (int x = 0; x < 9; x++) {
      if (board[y][x] == '.') continue;

      if (col[x][board[y][x] - '0']) return false;
      if (row[y][board[y][x] - '0']) return false;
      if (field[getFieldIndex(y, x)][board[y][x] - '0']) return false;

      col[x][board[y][x] - '0'] = true;
      row[y][board[y][x] - '0'] = true;
      field[getFieldIndex(y, x)][board[y][x] - '0'] = true;
    }
  }

  return true;
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      16      |

## 고생한 점
