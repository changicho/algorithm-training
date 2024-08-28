# 885. Spiral Matrix III

[링크](https://leetcode.com/problems/spiral-matrix-iii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

시뮬레이션을 수행할 경우 최악의 경우 순회하는 path의 한 변의 최대 길이는 2 \* max(R, C)이다.

따라서 시간 복잡도는 O(max(R, C)^2)이다.

### 공간 복잡도

path를 저장할 때 필요한 공간은 최대 R \* C 이다.

따라서 공간 복잡도는 O(R \* C)이다.

### 시뮬레이션

| 내 코드 (ms) |  시간 복잡도   | 공간 복잡도 |
| :----------: | :------------: | :---------: |
|      7       | O(max(R, C)^2) |  O(R \* C)  |

시작 위치부터 시작하여 시계방향으로 순회하며 path를 갱신한다.

이 때 범위를 벗어나는 경우 path에 추가하지 않는다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
  int limit = rows * cols;

  vector<vector<int>> path;
  int dir = 0;
  int temp = 0;
  int dirLimit = 1;
  int turnCount = 0;

  int val = 1;
  Axis cur = {rStart, cStart};

  while (val <= limit) {
    if (cur.y < 0 || cur.y >= rows || cur.x < 0 || cur.x >= cols) {
    } else {
      path.push_back({cur.y, cur.x});
      val++;
    }

    cur.y += dirs[dir].y;
    cur.x += dirs[dir].x;

    temp++;
    if (temp == dirLimit) {
      dir = (dir + 1) % 4;
      temp = 0;
      turnCount++;

      if (turnCount % 2 == 0) {
        dirLimit++;
      }
    }
  }

  return path;
}
```

## 고생한 점
