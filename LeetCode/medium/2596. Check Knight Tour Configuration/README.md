# 2596. Check Knight Tour Configuration

[링크](https://leetcode.com/problems/check-knight-tour-configuration/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

좌표의 갯수를 N이라 하자.

각 좌표별로 이동 순서가 겹치지 않게 설정되어있다.

따라서 이동 순서를 비교하며 이동 가능한지 여부를 판별한다.

이에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

이동 순서대로 미리 정렬해 놓는경우 O(N)의 공간 복잡도를 사용한다.

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      22      |    O(N)     |    O(N)     |

각 좌표별로 이동 순서가 유일하게 정해져 있다.

해당 이동 순서대로 이동하는 위치를 별도의 배열로 설정해놓는다.

이후 각 좌표별로 이동 가능한지 판별한다.

이 때 이동 가능한지 여부는 아래 두 가지중 하나이다.

- y좌표의 차이가 2이고 x좌표의 차이가 1인 경우
- y좌표의 차이가 1이고 x좌표의 차이가 2인 경우

이 때 시작 위치가 0,0 인지 판별해야한다.

```cpp
struct Axis {
  int y, x;
};

bool canMove(Axis &from, Axis &to) {
  int yDiff = abs(from.y - to.y), xDiff = abs(from.x - to.x);
  if (yDiff == 2 && xDiff == 1) return true;
  if (yDiff == 1 && xDiff == 2) return true;
  return false;
}

bool checkValidGrid(vector<vector<int>> &grid) {
  int rows = grid.size(), cols = grid.front().size();
  vector<Axis> moves(rows * cols);

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      int idx = grid[y][x];

      moves[idx] = {y, x};
    }
  }

  // check start point is correct
  if (moves[0].y != 0 || moves[0].x != 0) return false;

  for (int i = 0; i < moves.size() - 1; i++) {
    if (!canMove(moves[i], moves[i + 1])) return false;
  }
  return true;
}
```

## 고생한 점
