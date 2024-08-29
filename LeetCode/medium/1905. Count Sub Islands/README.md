# 1905. Count Sub Islands

[링크](https://leetcode.com/problems/count-sub-islands/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

BFS를 이용해 탐색하며 섬의 갯수를 구할 수 있다. 이 경우 시간 복잡도는 O(R \* C)이다.

### 공간 복잡도

BFS에 O(R \* C)만큼의 공간 복잡도가 필요하다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     252      |  O(R \* C)  |  O(R \* C)  |

grid2에 대해 섬을 구하며, 이 때 grid1과 겹치는 부분만 탐색을 진행한다.

이 때 grid1에는 없지만 grid2에 있는 경우는 sub island가 아니므로 이를 무시한다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
  int rows = grid1.size(), cols = grid1[0].size();

  int answer = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (grid2[y][x] == 0 || grid1[y][x] == 0) continue;

      bool isCovered = true;
      queue<Axis> q;
      q.push({y, x});
      grid2[y][x] = 0;

      while (!q.empty()) {
        Axis cur = q.front();
        q.pop();

        for (Axis& dir : dirs) {
          Axis next = {cur.y + dir.y, cur.x + dir.x};

          if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
            continue;
          if (grid2[next.y][next.x] == 0) continue;
          if (grid1[next.y][next.x] == 0) {
            isCovered = false;
            continue;
          }
          grid2[next.y][next.x] = 0;
          q.push(next);
        }
      }

      answer += isCovered;
    }
  }

  return answer;
}
```

## 고생한 점
