# 2580. 스도쿠

[링크](https://www.acmicpc.net/problem/2580)

| 난이도  | 정답률(\_%) | 시간 제한(초) |
| :-----: | :---------: | :-----------: |
| Gold IV |   29.239    |       1       |

## 설계

### 시간 복잡도

입력되는 판의 크기는 9^2이다.

모든 경우를 탐색하는 경우 최악의 경우 시간 복잡도는 9!^9 이므로 제한시간 내에 불가능하다.

따라서 불가능한 결과는 과감하게 제외하는 백트래킹 방법을 사용해야한다.

### 공간 복잡도

입력되는 판의 크기는 9^2 이며 0~9까지 수를 표현해야한다.

가능한 경우 한가지만 진행하면 되므로 int형 2차원 배열을 선언한다.

### 가능한 경우의 수 나누기

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

### 탐색 & 백트래킹

각 좌표마다 가능한 숫자를 대입해보며, 가능한 경우 탐색을 이어나간다.

```cpp
void recursive(int count) {
  if (isOver) return;
  if (count == 81) {
    isOver = true;
    return;
  }

  int y = count / 9;
  int x = count % 9;

  if (board[y][x] > 0) {
    recursive(count + 1);
    return;
  }

  for (int number = 1; number <= 9; number++) {
    if (!col[x][number] && !row[y][number] && !field[getFieldIndex(y, x)][number]) {
      board[y][x] = number;
      col[x][number] = true;
      row[y][number] = true;
      field[getFieldIndex(y, x)][number] = true;

      recursive(count + 1);
      if (isOver) return;

      board[y][x] = 0;
      col[x][number] = false;
      row[y][number] = false;
      field[getFieldIndex(y, x)][number] = false;
    }
  }
}
```

### 다른 방법으로 풀이

check를 배열이 아닌 각 탐색마다 수행하는 방법으로도 풀이할 수 있다.

이 방법의 경우 200ms 정도 소요된다.

```cpp
bool check_row(axis current, int number) {
  bool check[10] = { 0, };
  for (int x = 0; x < 9; x++) {
    if (map[current.y][x] == number) return false;
  }
  return true;
}

bool check_col(axis current, int number) {
  bool check[10] = { 0, };
  for (int y = 0; y < 9; y++) {
    if (map[y][current.x] == number) return false;
  }
  return true;
}

bool check_square(axis current, int number) {
  int x_start = (current.x / 3) * 3, y_start = (current.y / 3) * 3;

  for (int y = y_start; y < y_start + 3; y++) {
    for (int x = x_start; x < x_start + 3; x++) {
      if (map[y][x] == number) return false;
    }
  }
  return true;
}
```

### 빈칸만 탐색

숫자를 채워야 하는 빈 칸들만 탐색할 수 있다.

실행 시간의 감소는 크지 않음.

```cpp
struct axis {
  int y, x;
};

vector<axis> blanks;  // 입력시 빈칸인 경우 blanks에 저장.

void recursive(int depth) {
  if (isOver) return;
  if (depth == blanks.size()) {
    isOver = true;
    return;
  }

  Axis cur = blanks[depth];
  int y = cur.y;
  int x = cur.x;
  // ...
}
```

## 정리

| 내 코드 | 빠른 코드 |
| :-----: | :-------: |
|  92 ms  |     0     |

## 고생한 점
