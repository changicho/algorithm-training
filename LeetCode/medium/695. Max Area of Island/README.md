# 695. Max Area of Island

[링크](https://leetcode.com/problems/max-area-of-island/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

행의 수를 N, 열의 수를 M이라 하자

모든 좌표에 대해서 한번 탐색해야 하므로 outer 시간 복잡도는 O(N \* M)이 소요된다.

이후 내부적으로 BFS를 이용해 구역의 크기를 구할 수 있다.

내부적으로 BFS를 수행해도 결국 모든 좌표를 방문하는것은 같으므로 시간 복잡도는 O(N \* M)이다.

### 공간 복잡도

방문 배열이 필요하며 큐에 최대 O(N \* M)만큼의 좌표가 쌓일 수 있으므로 공간 복잡도는 O(N \* M)이다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      36      |  O(N \* M)  |  O(N \* M)  |

모든 좌표를 방문하고 섬을 방문할 때마다 섬을 탐색한다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int maxAreaOfIsland(vector<vector<int>>& grid) {
  int row = grid.size();
  int col = grid.front().size();

  vector<vector<bool>> visited(row, vector<bool>(col, false));

  int answer = 0;
  for (int y = 0; y < row; y++) {
    for (int x = 0; x < col; x++) {
      if (visited[y][x] || grid[y][x] == 0) continue;

      int count = 0;
      queue<Axis> q;
      q.push({y, x});
      while (!q.empty()) {
        Axis cur = q.front();
        q.pop();

        if (visited[cur.y][cur.x]) continue;
        visited[cur.y][cur.x] = true;
        count += 1;

        for (Axis dir : dirs) {
          Axis next = cur;
          next.y += dir.y;
          next.x += dir.x;

          if (next.y < 0 || next.y >= row || next.x < 0 || next.x >= col) continue;
          if (grid[next.y][next.x] == 0) continue;
          q.push(next);
        }
      }

      answer = max(answer, count);
    }
  }

  return answer;
}
```

## 고생한 점
