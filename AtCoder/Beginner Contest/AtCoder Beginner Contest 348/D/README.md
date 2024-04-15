# D - Medicines on Grid

[링크](https://atcoder.jp/contests/abc348/tasks/abc348_d)

| 난이도 |
| :----: |
|  425   |

## 설계

### 시간 복잡도

2차원 좌표의 크기를 R \* C 줄여서 RC라 하자. 각 에너지를 얻을 수 있는 좌표들의 갯수를 N이라 하자.

일반 BFS를 수행할 경우 각 상태마다 남은 에너지의 경우마다 탐색해야 한다.

이 경우 O(RC * 2^N)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

우선순위 큐를 사용해 BFS를 수행해 시간 복잡도를 최적화 할 수 있다.

이 다이크스트라 알고리즘을 사용할 경우 O(RC \* log_2(RC))의 시간 복잡도를 사용한다.

### 공간 복잡도

각 좌표 데이터를 저장하는 데 O(RC)의 공간 복잡도가 필요하다.

다이크스트라에 사용하는 우선순위 큐에 O(RC)의 공간 복잡도가 필요하다.

### 다이크스트라

| 내 코드 (ms) |    시간 복잡도     | 공간 복잡도 |
| :----------: | :----------------: | :---------: |
|      4       | O(RC \* log_2(RC)) |    O(RC)    |

각 이동 경로를 순회할 때 현재 방문한 좌표들 중 가장 에너지가 높은 경우만 탐색한다.

이 경우 에너지를 회복할 수 있는 공간에는 가장 에너지가 높은 경우만 처음에 방문할 수 있다.

따라서 해당 방문에서 에너지를 회복해야 하는 경우 회복시키고 사용가능한 에너지 목록에서 이를 제거한다.

따라서 각 경우마다 에너지 사용을 탐욕적으로 탐색 가능하다.

이후 목적지까지 도달 가능한지 판단한다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct Energy {
  int y, x, e;

  const bool operator<(const Energy &energy) const { return e < energy.e; }
};

// .: An empty cell.
// #: An obstacle.
// S: An empty cell and the start point.
// T: An empty cell and the goal point.

Axis getTarget(vector<string> &board, char target) {
  int rows = board.size();
  int cols = board[0].size();
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[y][x] == target) {
        return {y, x};
      }
    }
  }

  return {-1, -1};
}

bool solution(int rows, int cols, vector<string> &board,
              vector<Energy> &energies) {
  vector<vector<int>> dp(rows, vector<int>(cols, -1));
  vector<vector<int>> eBoard(rows, vector<int>(cols, 0));

  for (Energy &energy : energies) {
    eBoard[energy.y - 1][energy.x - 1] = energy.e;
  }

  Axis start = getTarget(board, 'S');
  Axis gaol = getTarget(board, 'T');

  int startEnergy = eBoard[start.y][start.x];

  priority_queue<Energy> pq;

  if (startEnergy > 0) {
    dp[start.y][start.x] = startEnergy;
    pq.push({start.y, start.x, startEnergy});
  }

  while (!pq.empty()) {
    Energy cur = pq.top();
    pq.pop();

    if (cur.y == gaol.y && cur.x == gaol.x) {
      return true;
    }
    if (cur.e <= 0) {
      continue;
    }

    for (Axis dir : dirs) {
      int ny = cur.y + dir.y;
      int nx = cur.x + dir.x;

      if (ny < 0 || ny >= rows || nx < 0 || nx >= cols) {
        continue;
      }
      if (board[ny][nx] == '#') {
        continue;
      }

      int ne = cur.e - 1;
      if (ne < eBoard[ny][nx]) {
        ne = eBoard[ny][nx];
        eBoard[ny][nx] = 0;
      }

      if (ne > dp[ny][nx]) {
        dp[ny][nx] = ne;
        pq.push({ny, nx, ne});
      }
    }
  }

  return false;
}
```

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      59      |   O(RC^2)   |   O(RC^2)   |

위 방법을 BFS를 수행해 탐색한다.

이는 순회마다 에너지의 가능한 최대값이 제한되어 있기 때문이다.

따라서 에너지의 최대값 RC 만큼 에너지를 회복할 수 있고 각 좌표마다 최대값은 RC까지이므로 최악의 경우 O(RC^2)의 시간 복잡도를 사용한다.

```cpp
bool solution(int rows, int cols, vector<string> &board,
              vector<Energy> &energies) {
  vector<vector<int>> dp(rows, vector<int>(cols, -1));
  vector<vector<int>> eBoard(rows, vector<int>(cols, 0));

  for (Energy &energy : energies) {
    eBoard[energy.y - 1][energy.x - 1] = energy.e;
  }

  Axis start = getTarget(board, 'S');
  Axis gaol = getTarget(board, 'T');

  int startEnergy = eBoard[start.y][start.x];

  queue<Energy> q;

  if (startEnergy > 0) {
    dp[start.y][start.x] = startEnergy;
    q.push({start.y, start.x, startEnergy});
  }

  while (!q.empty()) {
    Energy cur = q.front();
    q.pop();

    if (cur.y == gaol.y && cur.x == gaol.x) {
      return true;
    }
    if (cur.e <= 0) {
      continue;
    }

    for (Axis dir : dirs) {
      int ny = cur.y + dir.y;
      int nx = cur.x + dir.x;

      if (ny < 0 || ny >= rows || nx < 0 || nx >= cols) {
        continue;
      }
      if (board[ny][nx] == '#') {
        continue;
      }

      int ne = cur.e - 1;
      if (ne < eBoard[ny][nx]) {
        ne = eBoard[ny][nx];
        eBoard[ny][nx] = 0;
      }

      if (ne > dp[ny][nx]) {
        dp[ny][nx] = ne;
        q.push({ny, nx, ne});
      }
    }
  }

  return false;
}
```

## 고생한 점
