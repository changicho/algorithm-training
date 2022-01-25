# 827. Making A Large Island

[링크](https://leetcode.com/problems/making-a-large-island/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

grid의 행, 열의 크기를 N이라 하자.

한 좌표에서 flood fill을 수행하는 데 O(N^2)의 시간 복잡도를 사용한다.

빈 모든 공간에 대해서 1을 채우고 flood fill을 수행해 최대 크기를 구할 경우 시간 복잡도는 O(N^4)이다.

flood fill을 수행하며 color로 영역과 count를 구분한다.

이후 빈 영역에 대해서 4방향에 연결되어있는 color에 대해 필요한 덧셈만 수행할 경우 O(N^2)의 시간 복잡도로 풀이가 가능하다.

### 공간 복잡도

color, count를 채우는 데 O(N^2)의 공간 복잡도를 사용한다.

### BFS with color

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     1011     |   O(N^2)    |   O(N^2)    |

4방향 탐색을 사용하므로 다음과 같은 자료 구조를 사용한다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
```

각 섬마다 color와 해당 섬의 크기를 count한다.

이후 빈 공간을 순회하며 4방향으로 섬을 연결하고 연결된 섬의 color와 갯수를 더해 정답을 구한다.

```cpp
int largestIsland(vector<vector<int>> &grid) {
  int rows = grid.size();
  int cols = grid.front().size();
  int size = rows * cols;

  vector<vector<bool>> visited(rows, vector<bool>(cols, false));
  unordered_map<int, int> counts;
  vector<vector<int>> colors(rows, vector<int>(cols, -1));
  int color = 1;

  vector<Axis> zeros;
  int answer = 0;

  // flood fill
  // fill color and count color
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (grid[y][x] == 0) {
        zeros.push_back({y, x});
        continue;
      }
      if (visited[y][x]) continue;

      vector<Axis> paths;
      queue<Axis> q;
      q.push({y, x});
      visited[y][x] = true;
      int count = 1;

      while (!q.empty()) {
        Axis cur = q.front();
        q.pop();

        paths.push_back(cur);

        for (Axis &dir : dirs) {
          Axis next = {cur.y + dir.y, cur.x + dir.x};

          if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
            continue;
          if (grid[next.y][next.x] == 0) continue;
          if (visited[next.y][next.x]) continue;

          visited[next.y][next.x] = true;
          count++;
          q.push(next);
        }
      }

      for (Axis &a : paths) {
        colors[a.y][a.x] = color;
      }
      counts[color] = count;

      color++;
      answer = max(answer, count);
    }
  }

  // iterate zero and count new sum
  for (Axis &axis : zeros) {
    unordered_set<int> linkedColors;
    int count = 1;

    for (Axis &dir : dirs) {
      Axis next = {axis.y + dir.y, axis.x + dir.x};

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      if (grid[next.y][next.x] == 0) continue;
      if (linkedColors.count(colors[next.y][next.x]) > 0) continue;

      linkedColors.insert(colors[next.y][next.x]);
      count += counts[colors[next.y][next.x]];
    }

    answer = max(answer, count);
  }

  return answer;
}
```

## 고생한 점
