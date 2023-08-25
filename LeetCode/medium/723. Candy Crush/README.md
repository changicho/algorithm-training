# 723. Candy Crush

[링크](https://leetcode.com/problems/candy-crush/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

시뮬레이션을 수행하며 더이상 변화가 없을 때 까지 반복해야 한다.

최악의 경우 R \* C 번 연쇄가 발생할 수 있다.

각 경우마다 이동, 삭제, 검색에 O(R \* C)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O((R \* C)^2)이다.

### 공간 복잡도

방문등에 별도의 추가 공간을 사용할 경우 O(R \* C)의 공간을 사용한다.

### 시뮬레이션

| 내 코드 (ms) |  시간 복잡도  | 공간 복잡도 |
| :----------: | :-----------: | :---------: |
|     240      | O((R \* C)^2) |  O(R \* C)  |

각 좌표마다 하나의 방향으로 3개 이상의 연속된 값이 있는 경우 폭파가 가능하다.

이를 모든 좌표에 대해서 탐색한다.

이 때 상&하, 좌&우 탐색은 동일한 결과를 반환할 것이므로 하&우 방향만 탐색을 진행한다.

각 경우마다 탐색을 진행하며 파괴할 좌표들이 존재하는 경우 파괴를 수행한다.

이후 각 열마다 위의 값들을 내려 빈 공간을 채워준다.

이를 더이상 파괴할 값이 없을 때 까지 반복한다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[2] = {{0, 1}, {1, 0}};

vector<vector<int>> board;

queue<Axis> needToCrush;

void move(int x) {
  int rows = board.size(), cols = board[0].size();

  queue<int> vals;
  for (int y = rows - 1; y >= 0; y--) {
    if (board[y][x] != 0) vals.push(board[y][x]);
    board[y][x] = 0;
  }

  for (int y = rows - 1; y >= 0 && !vals.empty(); y--) {
    board[y][x] = vals.front();
    vals.pop();
  }
}
void move() {
  int rows = board.size(), cols = board[0].size();

  for (int x = 0; x < cols; x++) {
    move(x);
  }
}

bool hasCrashedCandy() {
  int rows = board.size(), cols = board[0].size();

  bool checked[51][51][2] = {
      false,
  };

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      int key = board[y][x];
      if (key == 0) continue;

      for (int dirIdx = 0; dirIdx < 2; dirIdx++) {
        Axis &dir = dirs[dirIdx];

        if (checked[y][x][dirIdx]) continue;
        queue<Axis> q;
        vector<Axis> targets;

        q.push({y, x});

        while (!q.empty()) {
          Axis cur = q.front();
          q.pop();

          targets.push_back(cur);

          Axis next = {cur.y + dir.y, cur.x + dir.x};

          if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
            continue;
          if (board[next.y][next.x] != key) continue;

          q.push(next);
        }

        if (targets.size() < 3) continue;
        for (Axis &a : targets) {
          checked[a.y][a.x][dirIdx] = true;
        }
      }
    }
  }
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (checked[y][x][0] || checked[y][x][1]) {
        needToCrush.push({y, x});
      }
    }
  }

  return needToCrush.size() > 0;
}

void crush() {
  while (!needToCrush.empty()) {
    Axis a = needToCrush.front();
    needToCrush.pop();
    board[a.y][a.x] = 0;
  }
}

vector<vector<int>> candyCrush(vector<vector<int>> &board) {
  this->board = board;

  while (hasCrashedCandy()) {
    crush();
    move();
  }

  return this->board;
}
```

## 고생한 점
