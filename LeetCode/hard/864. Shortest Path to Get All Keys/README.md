# 864. Shortest Path to Get All Keys

[링크](https://leetcode.com/problems/shortest-path-to-get-all-keys/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

grid의 행의 갯수를 R, 열의 갯수를 C, 키의 갯수를 K라 하자.

각 좌표마다 키들을 가진 경우의 수만큼 경우의 수가 존재한다.

따라서 BFS로 탐색을 진행하며, 가진 키의 종류들에 따라 방문 여부를 판단해야 한다.

이동시마다 비용이 증가하며 이를 이용해 중복방문을 체크할 수 있다.

이 경우 키를 가진 경우의 수는 2^K개 이며 각 좌표만큼 해당 경우의 수가 존재하므로 시간 복잡도는 O(R \* C \* 2^K) 이다.

### 공간 복잡도

중복 탐색을 방지하기 위해 방문 여부를 체크해야 한다.

이에 O(R \* C \* 2^K)의 공간 복잡도를 사용한다.

### BFS

| 내 코드 (ms) |   시간 복잡도    |   공간 복잡도    |
| :----------: | :--------------: | :--------------: |
|      62      | O(R \* C \* 2^K) | O(R \* C \* 2^K) |

시작점부터 BFS를 진행하며 키를 습득한 경우 가지고 있는 키의 목록을 갱신한다.

이후 다음 좌표에 문이 존재할 때 해당 키를 가지고 있는지 판단후 방문 가능한지 판단한다.

이 때 각 경우마다 키의 상태에 따른 상태를 저장해야 한다.

따라서 중복 방문 여부를 체크할 때도 키의 상태를 고려해야 한다.

이를 구현하면 다음과 같다.

```cpp
struct Axis {
  int y, x;
};

struct Data {
  int y, x, cost;
  int bitMask = 0;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

Axis getStart(vector<string>& grid) {
  int rows = grid.size(), cols = grid[0].size();

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (grid[y][x] == '@') return {y, x};
    }
  }
  return {-1, -1};
}

int getKeyCount(vector<string>& grid) {
  int rows = grid.size(), cols = grid[0].size();
  int count = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (islower(grid[y][x])) count++;
    }
  }
  return count;
}

int shortestPathAllKeys(vector<string>& grid) {
  int rows = grid.size(), cols = grid[0].size();

  Axis start = getStart(grid);
  int keys = getKeyCount(grid);

  vector<vector<vector<int>>> visited(
      1 << 6, vector<vector<int>>(rows, vector<int>(cols, INT_MAX)));

  queue<Data> q;
  q.push({start.y, start.x, 0, 0});

  int answer = INT_MAX;
  while (!q.empty()) {
    Data cur = q.front();
    q.pop();

    // get key
    if (islower(grid[cur.y][cur.x])) {
      cur.bitMask |= 1 << (grid[cur.y][cur.x] - 'a');
    }

    if (visited[cur.bitMask][cur.y][cur.x] <= cur.cost) continue;
    visited[cur.bitMask][cur.y][cur.x] = cur.cost;

    // has all key
    if (((1 << keys) - 1) == cur.bitMask) {
      answer = cur.cost;
      break;
    }

    for (Axis& dir : dirs) {
      Axis next = {cur.y + dir.y, cur.x + dir.x};

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      if (grid[next.y][next.x] == '#') continue;
      if (isupper(grid[next.y][next.x])) {
        int target = grid[next.y][next.x] - 'A';

        if ((cur.bitMask & (1 << target)) == 0) continue;
      }

      q.push({next.y, next.x, cur.cost + 1, cur.bitMask});
    }
  }

  if (answer == INT_MAX) return -1;
  return answer;
}
```

## 고생한 점

&연산에 오타가 있어 &&연산으로 판단해 틀렸었다.

&&연산은 논리곱연산으로 두 값이 모두 true인 경우만 true이다.
