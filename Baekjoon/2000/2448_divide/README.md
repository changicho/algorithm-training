# 2448. 별 찍기 - 11

[링크](https://www.acmicpc.net/problem/2448)

| 난이도  | 정답률(\_%) | 제한 시간 |
| :-----: | :---------: | :-------: |
| Gold IV |   37.029    |    1초    |

## 설계

### 시간 복잡도

N은 최대 3\*2^10 까지이다.

### 공간 복잡도

\*이 찍히는경우와 찍히지 않는 경우만 판단하면 된다. 따라서 bool 2차원 배열을 선언한다.

이때 입력받는 N은 세로 행 기준이므로, 가로 행은 이보다 크기가 커야한다.

가로의 크기는 입력받는 N\*2-1 크기이다.

따라서 배열의 크기는 최대 3072 \* (6144 - 1) 가 되어야 한다.

### 분할 정복 (재귀 호출)

전체 크기 N에서 부터 줄여나가며 배열을 갱신한다.

이 때 필요한 점은 다음과 같다.

- 트리의 맨 윗 점
- 트리의 맨 아래 왼쪽 점
- 트리의 맨 아래 오른쪽 점

그리고 다시 재귀 호출을 위해 하나의 트리를 3개의 작은 트리로 나워야 하므로 각 트리마다 3개의 점을 계산해야 한다.

트리의 높이가 3인경우에는 더이상 탐색을 진행하지 않고 배열을 갱신한다.

```cpp
void recursive(Axis top, Axis bottomLeft, Axis bottomRight) {
  Axis midLeft, midRight, midBottom;

  midBottom = {bottomLeft.y, top.x};
  midLeft = {(bottomLeft.y + top.y) / 2, (bottomLeft.x + midBottom.x - 1) / 2 + 1};
  midRight = {(bottomRight.y + top.y) / 2, (bottomRight.x + midBottom.x + 1) / 2 - 1};

  // cout << top.y << "," << top.x << " " << bottomLeft.y << "," << bottomLeft.x << " " << bottomRight.y << "," << bottomRight.x << endl;

  if (bottomLeft.y - top.y == 2) {
    board[top.y][top.x] = board[top.y + 1][top.x - 1] = board[top.y + 1][top.x + 1] = 1;

    for (int x = bottomLeft.x; x <= bottomRight.x; x++) {
      board[bottomLeft.y][x] = 1;
    }
    return;
  }

  recursive(top, midLeft, midRight);
  recursive({midLeft.y + 1, midLeft.x - 1}, bottomLeft, {midBottom.y, midBottom.x - 1});
  recursive({midRight.y + 1, midRight.x + 1}, {midBottom.y, midBottom.x + 1}, bottomRight);
}
```

디버깅을 할 때 작은 N값을 입력하며 각 재귀호출 마다 좌표를 보며 진행한다.

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     176      |       16       |

## 고생한 점
