# [현대모비스][예선] ADAS 시스템

[링크](https://level.goorm.io/exam/152116/%ED%98%84%EB%8C%80%EB%AA%A8%EB%B9%84%EC%8A%A4-%EC%98%88%EC%84%A0-adas-%EC%8B%9C%EC%8A%A4%ED%85%9C/quiz/1)

## 설계

### 시간 복잡도

입력받은 2차원 배열의 행의 갯수를 W, 열의 갯수를 H라 하자.

시작 위치에서부터 BFS를 수행할 수 있다. 이 때 방문 가능한 좌표들의 목록중에서 최선의 값을 매번 선택해야한다. (이 과정에서 좌표의 목록에 새로 방문가능한 좌표들이 추가된다.)

이를 위해 우선순위 큐를 사용할 수 있다.

따라서 시간 복잡도는 O(W \* H \* log_2(W \* H)) 이다.

### 공간 복잡도

BFS를 수행하는 데 O(W \* H)의 공간 복잡도가 필요하다.

### BFS & 우선순위 큐

|        시간 복잡도         | 공간 복잡도 |
| :------------------------: | :---------: |
| O(W \* H \* log_2(W \* H)) |  O(W \* H)  |

시작점에서부터 붙어있는 4개의 좌표를 우선순위 큐에 집어넣는다.

가장 우선순위의 좌표를 방문하면서 점수를 계산 후, 방문 가능한 좌표에 현재 좌표와 붙어있는 좌표들을 추가한다.

각 과정마다 최선의 좌표를 방문하며 E를 방문할 때 까지 반복한다.

이 때 우선순위를 판단하는데 좌표, 종류 두가지 값을 사용함에 유의한다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct Point {
  Axis axis;
  int rank;  // E:4, P:3, normal:2

  bool operator<(const Point &b) const {
    // compare rank
    if (rank != b.rank) {
      return rank < b.rank;
    }
    if (axis.y != b.axis.y) {
      return axis.y > b.axis.y;
    }
    return axis.x > b.axis.x;
  }
};

int getRank(char c) {
  if (c == 'E') return 4;
  if (c == 'P') return 3;
  return 2;
}

int getDangerScore(vector<string> &board, Axis axis) {
  int rows = board.size(), cols = board[0].size();

  char target = board[axis.y][axis.x];
  if (target == 'S' || target == 'E') return 0;

  int ret = 0;
  for (int y = -1; y <= 1; y++) {
    for (int x = -1; x <= 1; x++) {
      if (y == 0 && x == 0) continue;

      Axis cur = {axis.y + y, axis.x + x};
      if (cur.y < 0 || cur.y >= rows || cur.x < 0 || cur.x >= cols) continue;
      if (board[cur.y][cur.x] == 'P') {
        ret++;
      }
    }
  }
  if (target == 'P') ret -= 3;
  return ret;
}

long long solution(vector<string> &board) {
  int rows = board.size(), cols = board[0].size();
  vector<vector<bool>> visited(rows, vector<bool>(cols, false));

  long long ret = 0;
  Axis start = {-1, -1};
  for (int y = 0; y < rows && start.y == -1; y++) {
    for (int x = 0; x < cols && start.x == -1; x++) {
      if (board[y][x] == 'S') {
        start = {y, x};
        break;
      }
    }
  }

  priority_queue<Point> pq;
  pq.push({start, -1});

  while (!pq.empty()) {
    Point cur = pq.top();
    pq.pop();

    if (visited[cur.axis.y][cur.axis.x]) continue;
    visited[cur.axis.y][cur.axis.x] = true;

    ret += getDangerScore(board, cur.axis);

    if (board[cur.axis.y][cur.axis.x] == 'E') break;

    for (Axis &dir : dirs) {
      Axis next = {cur.axis.y + dir.y, cur.axis.x + dir.x};

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      if (visited[next.y][next.x] == true) continue;

      pq.push({next, getRank(board[next.y][next.x])});
    }
  }

  return max(ret, 0LL);
}
```

## 고생한 점
