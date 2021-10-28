# 1091. Shortest Path in Binary Matrix

[링크](https://leetcode.com/problems/shortest-path-in-binary-matrix/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

grid의 크기를 N^2라고 하자.

시작점부터 끝점까지 BFS를 이용해 최단경로를 탐색할 수 있다. 이 경우 방문하는 좌표는 최대 O(N^2)가 된다.

각 경우마다 8방향으로 탐색하며 이전에 방문한 좌표는 건너 뛰므로 시간 복잡도는 O(N^2)이다.

### 공간 복잡도

방문 여부를 체크할 배열이 필요하며 이는 O(N^2)공간을 사용한다.

입력받은 grid배열에 체크할 경우 별도의 공간을 사용하지 않아도 된다.

BFS를 이용할 때 큐의 공간 복잡도는 O(N^2)이다.

따라서 공간 복잡도는 O(N^2)가 된다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      48      |   O(N^2)    |   O(N^2)    |

시작점에서부터 BFS탐색을 이용해 끝점까지 도달 가능한지를 판단한다.

이 때 최단경로의 길이를 구해야 하므로 step별로 BFS를 진행한다.

8방향 탐색임에 유의한다.

만약 도달할 수 없는 경우 -1을 반환하며, 시작점에서 출발할 수 없는 경우 (막혀있는 경우) 또한 -1을 반환한다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[8] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
  int size = grid.size();
  if (grid[0][0] == 1) return -1;

  queue<Axis> q;
  q.push({0, 0});
  grid[0][0] = true;
  bool isConnected = false;
  int length = 1;

  while (!q.empty()) {
    int qSize = q.size();

    while (qSize--) {
      Axis cur = q.front();
      q.pop();

      if (cur.y == size - 1 && cur.x == size - 1) {
        isConnected = true;
        break;
      }

      for (Axis dir : dirs) {
        Axis next = {cur.y + dir.y, cur.x + dir.x};

        if (next.y < 0 || next.y >= size || next.x < 0 || next.x >= size)
          continue;
        if (grid[next.y][next.x] != 0) continue;
        if (grid[next.y][next.x]) continue;

        grid[next.y][next.x] = true;
        q.push(next);
      }
    }

    if (isConnected) break;
    length++;
  }

  return isConnected ? length : -1;
}
```

## 고생한 점
