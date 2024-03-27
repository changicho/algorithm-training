# D - Tiling

[링크](https://atcoder.jp/contests/abc345/tasks/abc345_d)

| 난이도 |
| :----: |
|  450   |

## 설계

### 시간 복잡도

입력받은 2차원 좌표의 크기를 H \* W 라 하자.

입력받은 직사각형의 갯수는 N이라 하자.

각 좌표를 순회하며 직사각형들을 순회하며 놓을 수 있는 경우 직사각형을 놓고 탐색을 이어나간다.

이를 모두 탐색할 경우 O(N! \* 2^N \* H \* W) 이다.

### 공간 복잡도

call stack에 O(H \* W) 만큼의 공간 복잡도를 사용한다. 각 직사각형 사용 여부에 O(N)의 공간 복잡도를 사용한다.

### 완전 탐색 DFS

| 내 코드 (ms) |      시간 복잡도       |  공간 복잡도  |
| :----------: | :--------------------: | :-----------: |
|      27      | O(N! \* 2^N \* H \* W) | O(H \* W + N) |

시작점부터 좌표별로 탐색을 이어나가며 각 경우마다 직사각형을 놓을 수 있는 경우 놓고 다음 좌표로 넘어간다.

각 상태별로 2차원 배열에 놓을 수 있는 공간과 아닌 경우를 2차원 배열을 갱신하며 넘어간다.

```cpp
struct Rectangle {
  int h, w;
};

bool answer = false;

bool board[10][10] = {
    false,
};

bool isUsed[10] = {
    false,
};

int width, height;

bool isAllFilled() {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      if (!board[y][x]) return false;
    }
  }
  return true;
};

bool checkCanPlace(Rectangle &rec, int y, int x) {
  for (int i = 0; i < rec.h; i++) {
    for (int j = 0; j < rec.w; j++) {
      if (board[y + i][x + j]) {
        return false;
      }
    }
  }
  return true;
}

void recursive(vector<Rectangle> &recs, int y, int x) {
  if (answer) return;

  if (y == height) {
    if (isAllFilled()) {
      answer = true;
    }
    return;
  }

  int nx = x == width - 1 ? 0 : x + 1;
  int ny = nx == 0 ? y + 1 : y;

  if (board[y][x]) {
    recursive(recs, ny, nx);
  }

  for (int index = 0; index < recs.size(); index++) {
    if (isUsed[index]) continue;

    vector<Rectangle> curs = {recs[index], {recs[index].w, recs[index].h}};

    for (Rectangle &rec : curs) {
      if (y + rec.h > height || x + rec.w > width) continue;

      bool canPlace = checkCanPlace(rec, y, x);

      if (!canPlace) continue;
      for (int i = 0; i < rec.h; i++) {
        for (int j = 0; j < rec.w; j++) {
          board[y + i][x + j] = true;
        }
      }

      isUsed[index] = true;
      recursive(recs, y, x);
      isUsed[index] = false;

      for (int i = 0; i < rec.h; i++) {
        for (int j = 0; j < rec.w; j++) {
          board[y + i][x + j] = false;
        }
      }
    }
  }
}

bool solution(int h, int w, vector<Rectangle> &rectangles) {
  width = w;
  height = h;

  recursive(rectangles, 0, 0);

  return answer;
}
```

## 고생한 점

좌표별 순회가 아닌 직사각형에 대해 순회하며 탐색할 경우 제한시간 내에 불가능하다.