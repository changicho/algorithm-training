# 1260. Shift 2D Grid

[링크](https://leetcode.com/problems/shift-2d-grid/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 rows, cols를 R, C라고 하자.

입력받은 수를 K, 2차원 배열의 원소의 갯수를 N이라고 하자. (N = R \* C)

각 원소를 K번 이동시키면 된다. 이 때 K번을 이동시킬 때 N번 이상 이동하는경우 한바퀴를 돌게 되므로 불필요한 부분은 무시한다.

각 원소를 순회하며 이동시키면 되며 이 순회에 O(R \* C)의 시간 복잡도를 사용한다.

각 원소를 이동할 때 K만큼 이동시키며 이에 O(1)의 시간 복잡도를 사용한다.

따라서 모든 원소를 순회하며 이동할 경우 O(R \* C)의 시간 복잡도를 사용한다.

reverse를 이용할 경우도 동일하게 O(R \* C)의 시간 복잡도를 사용한다.

### 공간 복잡도

별도의 배열을 만들어 반환할 경우 O(R \* C)의 공간 복잡도를 사용한다.

reverse를 사용할 경우 O(1)의 공간 복잡도를 사용한다.

### mod & move

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      26      |  O(R \* C)  |  O(R \* C)  |

새로운 배열을 만들고 grid의 원소를 각각 이동시켜 채워넣는다.

현재 위치의 index에서 k번 이동한 위치의 index는 (index + k)이다.

이를 mod 연산을 이용해 순회하도록 나타낸다.

또한 K번 모두 이동시킬 필요가 없으므로 K는 size만큼 나눠 압축시킨다.

이를 구현하면 다음과 같다.

```cpp
vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
  int rows = grid.size();
  int cols = grid.front().size();

  int size = rows * cols;
  vector<vector<int>> newGrid(rows, vector<int>(cols));

  k %= size;

  for (int i = 0; i < size; i++) {
    int y = i / cols, x = i % cols;
    int nextIdx = (i + k) % size;
    int ny = nextIdx / cols, nx = nextIdx % cols;

    newGrid[ny][nx] = grid[y][x];
  }

  return newGrid;
}
```

### reverse

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      24      |  O(R \* C)  |    O(1)     |

K번 이동시키기 위해 다음과 같이 순서 뒤바꾸기를 사용한다.

- reverse(grid, 0, size - 1)
- reverse(grid, 0, k - 1)
- reverse(grid, k, size - 1)

우선 모든 원소를 뒤집고, 이후 0 ~ (k-1)까지 뒤집은뒤 나머지를 뒤집는다.

2차원 배열의 원소를 뒤집는 함수는 다음과 같이 구현한다.

```cpp
void reverse(vector<vector<int>>& grid, int from, int to) {
  int rows = grid.size();
  int cols = grid.front().size();

  while (from < to) {
    int y1 = from / cols, x1 = from % cols, y2 = to / cols, x2 = to % cols;

    swap(grid[y1][x1], grid[y2][x2]);

    from++, to--;
  }
}
```

이후 이를 이용해 구현한다.

```cpp
vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
  int rows = grid.size();
  int cols = grid.front().size();

  int size = rows * cols;
  k %= size;

  reverse(grid, 0, size - 1);
  reverse(grid, 0, k - 1);
  reverse(grid, k, size - 1);

  return grid;
}
```

## 고생한 점
