# 36. Valid Sudoku

[링크](https://leetcode.com/problems/valid-sudoku/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

행의 개수를 N이라 하자. (열의 개수도 같음)

모든 칸을 순회하며 3가지 조건에 위배되는지를 검사하면 된다.

한 칸에 대해서 검사해야 하는 항목은 다음 3가지이다.

- 행에 대해서
- 열에 대해서
- 구역에 대해서

모든 칸을 순회하는데 O(N^2)의 시간 복잡도가 소요된다.

만약 행, 열, 구역에 대해서 매번 검사할 경우 O(N)의 시간 복잡도를 사용하므로,

매번 검사시에 O(N^3)의 시간 복잡도를 사용한다.

혹은 각 경우에 대해서 미리 숫자 유무 배열을 만들어 검사할 수 있다.

이 경우 한 칸에 대해서 검사시에 O(1)의 시간 복잡도로 검색 가능하다.

이 경우 시간 복잡도는 O(N^2)이다.

### 공간 복잡도

각 경우별로 3가지 조건에 위배되는지 검사하기 위해 상황을 체크할 배열이 필요하다.

각 경우마다 O(N^2)크기의 배열을 사용한다. (각 행, 열, 구역에 대해서 숫자 1 ~ 9 까지 나타났는지 여부)

### 숫자 중복 체크

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |   O(N^2)    |   O(N^2)    |

각 좌표마다 숫자가 행, 열, 구역에 대해서 이미 존재하는 숫자인지 판별한다.

```cpp
bool isValidSudoku(vector<vector<char>>& board) {
  // we check colFine[index][number], rowFine[index][number],
  // sectionFine[y][y][number]
  bool colFine[10][10] =
      {
          false,
      },
        rowFine[10][10] =
            {
                false,
            },
        sectionFine[3][3][10] = {
            false,
        };

  // fill fine check array's
  for (int y = 0; y < 9; y++) {
    for (int x = 0; x < 9; x++) {
      if (board[y][x] == '.') continue;
      int num = board[y][x] - '0';

      if (colFine[x][num] || rowFine[y][num] ||
          sectionFine[y / 3][x / 3][num]) {
        return false;
      }

      colFine[x][num] = true;
      rowFine[y][num] = true;
      sectionFine[y / 3][x / 3][num] = true;
    }
  }

  return true;
}
```

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      16      |   O(N^2)    |   O(N^2)    |

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

## 고생한 점

배열 check시에 index에 y, x를 잘못 표기하는 문제가 있었다.

코드 작성 이후 index 관련 실수를 꼼꼼하게 확인하자.
