# 1730. Shortest Path to Get Food

[링크](https://leetcode.com/problems/shortest-path-to-get-food/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

행의 갯수를 R, 열의 갯수를 C, 모든 좌표의 갯수를 N이라 하자. (N = R \* C)

우선 시작 위치를 찾아야하며 이를 탐색하는데 O(N)의 시간 복잡도를 사용한다.

BFS를 이용해 중복방문없이 모든 노드를 방문할 경우 O(N)의 시간 복잡도를 사용한다.

이 과정에서 음식까지의 최단 거리를 탐색할 수 있다.

따라서 총 시간 복잡도는 O(N)이다.

### 공간 복잡도

BFS를 사용할 때 큐에 총 O(N)의 공간 복잡도를 사용한다.

각 좌표의 중복 방문 여부를 체크하는 데 O(N)의 공간 복잡도를 사용한다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      66      |    O(N)     |    O(N)     |

시작위치를 탐색한 뒤, 해당 위치에서부터 BFS를 이용해 음식까지의 최단경로를 탐색한다.

이 때 음식을 찾지 못하는 경우가 있을 수 있으므로 정답을 -1로 초기화한다.

```cpp
int getFood(vector<vector<char>>& grid) {
  int rows = grid.size();
  int cols = grid.front().size();
  vector<vector<bool>> visited(rows, vector<bool>(cols, false));
  queue<Axis> q;

  // find location
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (grid[y][x] != '*') continue;

      q.push({y, x});
      visited[y][x] = true;
    }
  }

  int answer = -1;
  int step = 0;

  while (!q.empty() && answer == -1) {
    int size = q.size();
    while (size--) {
      Axis cur = q.front();
      q.pop();

      if (grid[cur.y][cur.x] == '#') {
        answer = step;
        break;
      }

      for (Axis& d : dirs) {
        Axis n = {cur.y + d.y, cur.x + d.x};

        if (n.y < 0 || n.y >= rows || n.x < 0 || n.x >= cols) continue;
        if (grid[n.y][n.x] == 'X') continue;
        if (visited[n.y][n.x] == true) continue;

        visited[n.y][n.x] = true;
        q.push(n);
      }
    }

    step++;
  }

  return answer;
}
```

## 고생한 점
