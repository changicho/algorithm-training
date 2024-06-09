# C - Bingo 2

[링크](https://atcoder.jp/contests/abc355/tasks/abc355_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

주어진 2차원 배열의 한 변의 길이를 N, 시간을 T라 하자.

각 시간을 순회하며 2차원 배열에 방문 여부를 체크한다. 이에 O(T)의 시간 복잡도를 사용한다.

각 과정마다 빙고가 생성되었는지 판단하는데 O(N)의 시간 복잡도가 필요하다.

따라서 최종 시간 복잡도는 O(T \* N)이다.

### 공간 복잡도

빙고 판을 저장하기 위해 O(N^2)의 공간 복잡도를 사용한다.

### 구현

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     203      |  O(T \* N)  |   O(N^2)    |

빙고 판을 생성한 뒤 각 경우마다 빙고가 생성되었는지 판단한다.

```cpp
int solution(int n, int time, vector<int> &a) {
  vector<vector<bool>> board(n, vector<bool>(n, false));

  for (int i = 0; i < time; i++) {
    int target = a[i] - 1;

    int y = target / n;
    int x = target % n;

    board[y][x] = true;

    bool isColMarked = true;
    for (int y = 0; y < n; y++) {
      if (!board[y][x]) {
        isColMarked = false;
        break;
      }
    }
    bool isRowMarked = true;
    for (int x = 0; x < n; x++) {
      if (!board[y][x]) {
        isRowMarked = false;
        break;
      }
    }
    bool isDiagonalMarked = true;
    for (int i = 0; i < n; i++) {
      if (!board[i][i]) {
        isDiagonalMarked = false;
        break;
      }
    }
    bool isReverseDiagonalMarked = true;
    for (int i = 0; i < n; i++) {
      if (!board[i][n - i - 1]) {
        isReverseDiagonalMarked = false;
        break;
      }
    }

    if (isColMarked || isRowMarked || isDiagonalMarked ||
        isReverseDiagonalMarked) {
      return i + 1;
    }
  }
  return -1;
}
```

## 고생한 점
