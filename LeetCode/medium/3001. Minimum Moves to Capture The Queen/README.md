# 3001. Minimum Moves to Capture The Queen

[링크](https://leetcode.com/problems/minimum-moves-to-capture-the-queen/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

세 좌표가 주어진다. 보드의 크기는 8^2이다.

각 좌표별로 같은 행, 열, 대각선에 위치하는지 판단하는 데 O(1)의 시간 복잡도를 사용한다.

퀸에 대해서 모든 좌표에 자신을 죽일 수 있는 말이 있는지 판단하는데 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 좌표들로 판단하는 데 O(1)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

퀸을 기준으로 같은 행, 열, 대각선에 위치한 말들을 찾는다.

해당 말이 자신을 죽일 수 있는 말인지 판단한다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
Axis diagonalDirs[4] = {{-1, -1}, {1, -1}, {1, 1}, {-1, 1}};

int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
  Axis rook = {a, b}, bishop = {c, d}, queen = {e, f};

  // find rook
  for (Axis &dir : dirs) {
    Axis cur = queen;
    for (int i = 0; i < 8; i++) {
      cur.y += dir.y;
      cur.x += dir.x;

      if (cur.y == bishop.y && cur.x == bishop.x) break;
      if (cur.y == rook.y && cur.x == rook.x) return 1;
    }
  }

  // find bishop
  for (Axis &dir : diagonalDirs) {
    Axis cur = queen;
    for (int i = 0; i < 8; i++) {
      cur.y += dir.y;
      cur.x += dir.x;

      if (cur.y == bishop.y && cur.x == bishop.x) return 1;
      if (cur.y == rook.y && cur.x == rook.x) break;
    }
  }

  return 2;
}
```

### 좌표 계산

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

퀸과 룩, 비숍의 좌표를 판단해 같은 직선상에 놓여있는지 판단한다.

이 때 자신을 죽일 수 없는 말이 중간에 끼어 있는지 판단한다.

```cpp
int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
  Axis rook = {a, b}, bishop = {c, d}, queen = {e, f};

  if (rook.y == queen.y) {
    if (bishop.y != rook.y) return 1;

    vector<int> arr = {rook.x, bishop.x, queen.x};
    sort(arr.begin(), arr.end());

    if (bishop.x != arr[1]) return 1;
  }
  if (rook.x == queen.x) {
    if (bishop.x != rook.x) return 1;

    vector<int> arr = {rook.y, bishop.y, queen.y};
    sort(arr.begin(), arr.end());

    if (bishop.y != arr[1]) return 1;
  }

  if ((bishop.y - bishop.x) == (queen.y - queen.x)) {
    if ((bishop.y - bishop.x) != (rook.y - rook.x)) return 1;

    // check x
    vector<int> arr = {bishop.x, rook.x, queen.x};
    sort(arr.begin(), arr.end());

    if (rook.x != arr[1]) return 1;
  }

  if ((bishop.y + bishop.x) == (queen.y + queen.x)) {
    if ((bishop.y + bishop.x) != (rook.y + rook.x)) return 1;

    // check y
    vector<int> arr = {bishop.y, rook.y, queen.y};
    sort(arr.begin(), arr.end());

    if (rook.y != arr[1]) return 1;
  }
  return 2;
}
```

## 고생한 점
