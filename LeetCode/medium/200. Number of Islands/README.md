# 200. Number of Islands

[링크](https://leetcode.com/problems/number-of-islands/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

좌표의 행의 개수를 N, 열의 개수를 M이라 하자.

우선 모든 좌표를 한번씩 방문해야 하므로 outer 시간 복잡도는 O(N \* M)이다.

이 때 내부적으로 섬의 경우 해당 섬의 모든 좌표를 탐색해야 한다.

이 과정에서 최악의 경우 O(N \* M)의 시간 복잡도가 소요되지만, 이는 outer 시간 복잡도로 방문하는 것과 동일하다.

따라서 시간 복잡도는 O(N \* M)이다.

### 공간 복잡도

방문 여부를 판별알 O(N \* M)크기의 2차원 배열이 필요하다.

입력받은 좌표 배열을 사용해 공간 복잡도를 줄일 수 있다.

### 정리

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |  O(N \* M)  |    O(1)     |

좌표를 순차적으로 탐색하며 섬을 만난 경우 해당 섬의 모든 좌표를 방문 처리한다.

이 때 해당 섬의 탐색은 DFS, BFS로 할 수 있다.

```cpp

struct Axis {
  int y, x;
  Axis operator+(const Axis& b) const {
    return {y + b.y, x + b.x};
  }
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
```

```cpp
// BFS
int numIslands(vector<vector<char>>& grid) {
  int rows = grid.size();
  int cols = grid.front().size();
  int answer = 0;

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (grid[y][x] != '1') continue;
      answer += 1;

      queue<Axis> q;
      q.push({y, x});

      while (!q.empty()) {
        Axis cur = q.front();
        q.pop();

        if (grid[cur.y][cur.x] != '1') continue;
        grid[cur.y][cur.x] = '2';

        for (Axis dir : dirs) {
          Axis next = cur + dir;

          if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols) continue;
          if (grid[next.y][next.x] != '1') continue;

          q.push(next);
        }
      }
    }
  }

  return answer;
}
```

```cpp
// DFS
void recursive(Axis cur, vector<vector<char>>& grid) {
  int rows = grid.size();
  int cols = grid.front().size();

  if (grid[cur.y][cur.x] != '1') return;
  grid[cur.y][cur.x] = '2';

  for (Axis dir : dirs) {
    Axis next = cur + dir;

    if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols) continue;
    if (grid[next.y][next.x] != '1') continue;

    recursive(next, grid);
  }
}

public:
int numIslands(vector<vector<char>>& grid) {
  int rows = grid.size();
  int cols = grid.front().size();
  int answer = 0;

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (grid[y][x] != '1') continue;
      answer += 1;

      recursive({y, x}, grid);
    }
  }

  return answer;
}
```

## 고생한 점
