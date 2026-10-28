# 3619. Count Islands With Total Value Divisible by K

[링크](https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 크기를 RC라 하자.

BFS를 사용할 경우 O(RC)의 시간 복잡도를 사용한다.

### 공간 복잡도

BFS에 O(RC)의 공간 복잡도를 사용한다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     195      |    O(RC)    |    O(RC)    |

BFS를 이용해 섬들을 묶고 크기를 계산한다.

이후 섬의 합이 K로 나누어떨어지는경우만 정답에 더한다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int countIslands(vector<vector<int>>& grid, int k) {
  int rows = grid.size();
  int cols = grid[0].size();

  vector<vector<bool>> visited(rows, vector<bool>(cols, false));

  int answer = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (grid[y][x] == 0) continue;
      if (visited[y][x]) continue;

      queue<Axis> q;
      q.push({y, x});
      visited[y][x] = true;
      long long sum = grid[y][x];
      while (!q.empty()) {
        Axis cur = q.front();
        q.pop();

        for (Axis& d : dirs) {
          Axis next = {cur.y + d.y, cur.x + d.x};

          if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
            continue;
          if (grid[next.y][next.x] == 0) continue;
          if (visited[next.y][next.x]) continue;
          visited[next.y][next.x] = true;
          sum += grid[next.y][next.x];
          q.push(next);
        }
      }

      if (sum % k == 0) answer++;
    }
  }

  return answer;
}
```

## 고생한 점
