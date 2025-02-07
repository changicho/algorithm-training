# C - Paint to make a rectangle

[링크](https://atcoder.jp/contests/abc390/tasks/abc390_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

입력받은 2차원 배열의 행의 갯수를 H, 열의 갯수를 W라고 하자.

각 black 좌표들을 모두 포함하는 최대 범위값을 찾고 이를 이용해 정답을 구할 수 있다.

이 때 시간 복잡도는 O(H \* W) 이다.

### 공간 복잡도

black 좌표의 범위를 저장하는 데 O(1)의 공간 복잡도가 필요하다.

### 좌표 범위

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      6       |  O(H \* W)  |    O(1)     |

2차원 배열의 black 좌표들을 모두 포함하는 범위를 구한다.

이후 해당 범위의 값들을 모두 black으로 칠할 수 있는지 판별한다.

```cpp
struct Axis {
  int y, x;
};

bool solution(int rows, int cols, vector<string> &board) {
  Axis topLeft = {INT_MAX, INT_MAX};
  Axis bottomRight = {INT_MIN, INT_MIN};

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[y][x] != '#') continue;

      topLeft.y = min(topLeft.y, y);
      topLeft.x = min(topLeft.x, x);

      bottomRight.y = max(bottomRight.y, y);
      bottomRight.x = max(bottomRight.x, x);
    }
  }

  for (int y = topLeft.y; y <= bottomRight.y; y++) {
    for (int x = topLeft.x; x <= bottomRight.x; x++) {
      if (board[y][x] == '.') return false;
    }
  }

  return true;
}
```

## 고생한 점
