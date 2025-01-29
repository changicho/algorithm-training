# 2658. Maximum Number of Fish in a Grid

[링크](https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

BFS를 사용해 탐색하며 최대한 많은 물고기를 먹을 수 있는 경우를 찾아야 한다.

이 경우 O(R \* C)의 시간 복잡도가 소요된다.

### 공간 복잡도

BFS에 O(R \* C)의 공간 복잡도가 필요하다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      20      |  O(R \* C)  |  O(R \* C)  |

BFS를 이용해 탐색하며 붙어있는 물고기 그룹의 합을 구한다.

이후 합의 최대값을 구한다.

```cpp
struct Axis {
  int y, x;

  Axis operator+(const Axis &b) const { return {y + b.y, x + b.x}; }
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int findMaxFish(vector<vector<int>> &grid) {
  int rows = grid.size(), cols = grid[0].size();

  int answer = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (grid[y][x] == 0) continue;

      int count = grid[y][x];
      grid[y][x] = 0;
      queue<Axis> q;
      q.push({y, x});

      while (!q.empty()) {
        Axis cur = q.front();
        q.pop();

        for (Axis &dir : dirs) {
          Axis next = cur + dir;

          if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
            continue;
          if (grid[next.y][next.x] == 0) continue;

          count += grid[next.y][next.x];
          grid[next.y][next.x] = 0;
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
