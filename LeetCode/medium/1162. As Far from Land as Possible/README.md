# 1162. As Far from Land as Possible

[링크](https://leetcode.com/problems/as-far-from-land-as-possible/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 2차원 배열의 크기를 O(N^2)라 하자. (N <= 100)

완전 탐색을 이용할 경우 O(N^4)의 시간 복잡도를 사용한다.

이는 제한시간 내에 불가능하다.

BFS를 이용해 각 좌표마다 거리를 갱신할 수 있다. 이 경우 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

BFS를 이용할 경우 O(N^2)의 공간 복잡도를 사용한다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      83      |   O(N^2)    |   O(N^2)    |

물에서 가장 가까운 섬들을 찾아야하므로, 모든 섬에서부터 같은 단계로 BFS를 돌리며 거리를 갱신한다.

이 때 더이상 방문할 필요가 없는 경우는 제외 처리한다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int maxDistance(vector<vector<int>>& grid) {
  int rows = grid.size(), cols = grid.front().size();

  vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX));

  queue<Axis> q;

  int answer = -1;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (grid[y][x] == 1) q.push({y, x});
    }
  }

  int step = 0;
  while (!q.empty()) {
    int size = q.size();
    while (size--) {
      Axis cur = q.front();
      q.pop();

      if (dp[cur.y][cur.x] <= step) continue;
      dp[cur.y][cur.x] = step;

      for (Axis& dir : dirs) {
        Axis next = {cur.y + dir.y, cur.x + dir.x};

        if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
          continue;
        if (grid[next.y][next.x] == 1) continue;

        q.push(next);
      }
    }
    step++;
  }

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (dp[y][x] == INT_MAX) continue;
      if (grid[y][x] == 1) continue;

      answer = max(dp[y][x], answer);
    }
  }

  return answer;
}
```

## 고생한 점

100^4의 시간 복잡도는 제한시간 내에 불가능하다.
