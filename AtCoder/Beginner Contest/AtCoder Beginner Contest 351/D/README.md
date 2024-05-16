# D - Grid and Magnet

[링크](https://atcoder.jp/contests/abc351/tasks/abc351_d)

| 난이도 |
| :----: |
|  425   |

## 설계

### 시간 복잡도

2차원 배열의 행, 열의 갯수를 H, W라 하자.

모든 좌표를 시작점으로 탐색할 경우 시간 복잡도는 O((H \* W)^2)이다. 이는 제한시간 내에 불가능하다.

각 좌표에서 탐색 가능한 좌표들을 탐색하며, 더이상 이동할 수 없는 끝점에 대해서 중복방문을 처리할 수 있다.

이 경우 BFS로 모든 좌표를 탐색할 수 있으며 중복 방문해야 하는 좌표는 최대 H \* W개 이므로 시간 복잡도는 O(H \* W)이다.

### 공간 복잡도

BFS에 O(H \* W)의 공간 복잡도가 필요하다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      43      |  O(H \* W)  |  O(H \* W)  |

벽과 붙어있는 좌표는 더이상 이동이 불가능한 좌표이다. 이를 끝점이라 하자.

끝점이 아닌 연결되어 있는 어느좌표에서도 서로 이동 가능하다.

해당 집합이 여러개 존재할 수 있으며 해당 집합에 붙어있는 끝점들은 이동 가능한 경로에 포함이 된다.

따라서 집합들을 구하고, 해당 집합에서 연결된 끝점의 갯수를 구해 정답을 갱신한다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int solution(int rows, int cols, vector<string> &board) {
  function<int(Axis)> convert = [&](Axis a) -> int { return a.y * cols + a.x; };
  vector<vector<int>> visited(rows, vector<int>(cols, -1));

  // find destination point (cannot move)
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[y][x] == '#') continue;

      for (Axis &dir : dirs) {
        int ny = y + dir.y;
        int nx = x + dir.x;

        if (ny < 0 || ny >= rows || nx < 0 || nx >= cols) continue;
        if (board[ny][nx] == '#') {
          board[y][x] = '-';
        }
      }
    }
  }

  function<int(Axis)> go = [&](Axis start) -> int {
    int count = 0;
    queue<Axis> q;

    q.push(start);
    visited[start.y][start.x] = convert(start);

    while (!q.empty()) {
      Axis cur = q.front();
      q.pop();

      count++;
      if (board[cur.y][cur.x] == '-') continue;

      for (Axis &dir : dirs) {
        Axis next = {cur.y + dir.y, cur.x + dir.x};

        if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
          continue;
        if (visited[next.y][next.x] == convert(start)) continue;

        visited[next.y][next.x] = convert(start);
        q.push(next);
      }
    }

    return count;
  };

  int answer = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (visited[y][x] != -1) continue;
      if (board[y][x] == '#') continue;
      int count = go({y, x});

      answer = max(answer, count);
    }
  }
  return answer;
}
```


## 고생한 점
