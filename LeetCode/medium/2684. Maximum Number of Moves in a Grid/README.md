# 2684. Maximum Number of Moves in a Grid

[링크](https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

첫번째 열에 대해서 모두 시작점으로 잡고 BFS를 진행한다.

이 경우 O(R * C)의 시간 복잡도를 사용한다.

### 공간 복잡도

BFS를 진행할 때 뱅문 표시를 위해 O(R * C)의 공간 복잡도를 사용한다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     275      |  O(R * C)   |  O(R * C)   |

첫번째 열의 모든 값을 큐의 시작점으로 삽입하고 BFS를 진행한다.

이 때 가장 오른쪽까지 도달한 경우 정답을 갱신한다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[3] = {{-1, 1}, {0, 1}, {1, 1}};

int maxMoves(vector<vector<int>>& grid) {
  int rows = grid.size(), cols = grid[0].size();

  int answer = 0;

  int step = 0;

  bool visited[1001][1001] = {
      false,
  };

  queue<Axis> q;

  for (int y = 0; y < rows; y++) {
    q.push({y, 0});
  }

  while (!q.empty()) {
    int size = q.size();

    while (size--) {
      Axis cur = q.front();
      q.pop();

      if (cur.x == cols - 1) continue;
      if (visited[cur.y][cur.x]) continue;
      visited[cur.y][cur.x] = true;

      for (Axis dir : dirs) {
        Axis next = {cur.y + dir.y, cur.x + dir.x};

        if (next.y < 0 || next.y >= rows) continue;
        if (grid[next.y][next.x] <= grid[cur.y][cur.x]) continue;

        q.push(next);
      }
    }

    step++;
  }

  return step - 1;
}
```

## 고생한 점
