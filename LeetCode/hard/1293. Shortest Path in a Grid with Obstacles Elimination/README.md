# 1293. Shortest Path in a Grid with Obstacles Elimination

[링크](https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

행의 개수를 M, 열의 개수를 N, 벽을 부술 수 있는 횟수를 K라 하자.

벽을 부수지 않고 BFS로 도달 가능한지 탐색하는 데 O(M \* N)의 시간 복잡도를 사용한다.

이 때 벽을 부수는 경우마다 BFS로 탐색할 경우 최대 K번까지 호출이 가능하다.

여기서 중복되는 경우를 제거할 경우 따라서 시간 복잡도는 O(M \* N \* K)이다.

이는 최악의 경우 O(40^4) 이며 O(2,560,000) 이므로 제한시간 내에 가능하다.

### 공간 복잡도

BFS를 사용할 경우 큐에 최대 O(M \* N \* K)의 공간 복잡도를 사용한다.

### BFS with hashing

| 내 코드 (ms) |  시간 복잡도   |  공간 복잡도   |
| :----------: | :------------: | :------------: |
|     1260     | O(M \* N \* K) | O(M \* N \* K) |

시작점에서부터 끝점까지 다음 상태들을 변화시키며 탐색한다.

- 좌표 (y, x)
- 몇번 부쉈는지

이 때 중복된 경우를 제거하기 위해서 각 상태를 저장한다.

hash_set에 상태에 대한 값들을 저장해 중복된 경우를 제거한다.

```cpp
struct Axis {
  int y, x;
};

struct Status {
  Axis axis;
  int crash;

  string convert() {
    return to_string(axis.y) + "," + to_string(axis.x) + "," +
            to_string(crash);
  }
};
```

BFS탐색을 진행할 때 현재 좌표에서 다음 방향에 벽이 있는 경우 벽을 부수고 진행하는 편이 가장 빠르게 도달 가능하다.

따라서 현재 좌표에서 벽을 마주한 경우 벽을 부수고 탐색하고, 벽이 아닌경우는 그냥 탐색한다.

이를 매 step별로 BFS를 반복할 경우 벽을 부수면서 진행할 수 있는 경우에 가장 빨리 도달하는 경우를 탐색할 수 있다.

```cpp
int shortestPath(vector<vector<int>>& grid, int k) {
  int rows = grid.size();
  int cols = grid.front().size();

  queue<Status> q;
  unordered_set<string> visited;
  Status start = {{0, 0}, 0};
  visited.insert(start.convert());
  if (grid[0][0] == 1) start.crash += 1;

  q.push(start);

  int step = 0;
  while (!q.empty()) {
    int size = q.size();

    while (size--) {
      Status cur = q.front();
      q.pop();

      Axis& axis = cur.axis;
      if (axis.y == rows - 1 && axis.x == cols - 1) return step;

      for (Axis& dir : dirs) {
        Axis next = {dir.y + axis.y, dir.x + axis.x};

        if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols) {
          continue;
        }

        Status nextStatus = {next, cur.crash + grid[next.y][next.x]};
        if (nextStatus.crash > k) continue;

        if (visited.find(nextStatus.convert()) != visited.end()) continue;
        visited.insert(nextStatus.convert());
        q.push(nextStatus);
      }
    }
    step++;
  }

  return -1;
}
```

### BFS with visited check

| 내 코드 (ms) |  시간 복잡도   |  공간 복잡도   |
| :----------: | :------------: | :------------: |
|      16      | O(M \* N \* K) | O(M \* N \* K) |

위 방법과 똑같이 탐색을 진행하되, visited배열을 사용한다.

visited 배열은 다음과 같다.

```cpp
visited[y][x]; // minimum crash that approach that axis
```

이를 이용해 현재 좌표에서 다음 좌표로 넘어갈 때 이전에 crash보다 적게 사용한 경우만 탐색을 진행한다.

이는 이전에 탐색을 진행하며 crash를 사용한것보다 더 많이 사용하는 경우는 정답에 도달 불가능 하거나 더 늦게 도달하기 때문이다.

```cpp
int shortestPath(vector<vector<int>>& grid, int k) {
  int rows = grid.size();
  int cols = grid[0].size();

  queue<Status> q;
  vector<vector<int>> visited(rows, vector<int>(cols, INT_MAX));

  q.push({{0, 0}, grid[0][0]});
  visited[0][0] = grid[0][0];

  int steps = 0;

  while (!q.empty()) {
    int size = q.size();

    while (size--) {
      Status cur = q.front();
      q.pop();
      Axis axis = cur.axis;
      int crash = cur.crash;

      if (axis.y == rows - 1 && axis.x == cols - 1) {
        return steps;
      }

      for (Axis& dir : dirs) {
        Axis next = {axis.y + dir.y, axis.x + dir.x};

        if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
          continue;
        int nextCrash = crash + grid[next.y][next.x];

        if (nextCrash > k) continue;
        if (nextCrash < visited[next.y][next.x]) {
          visited[next.y][next.x] = nextCrash;
          q.push({next, nextCrash});
        }
      }
    }
    steps++;
  }
  return -1;
}
```

## 고생한 점
