# 417. Pacific Atlantic Water Flow

[링크](https://leetcode.com/problems/pacific-atlantic-water-flow/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

BFS를 사용해 각 좌표를 pacific, atlantic에서 시작했을 때 도달할 수 있는지 확인한다.

이 경우 O(R \* C)의 시간 복잡도를 가진다.

### 공간 복잡도

BFS에 O(R \* C)의 공간 복잡도를 사용한다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |  O(R \* C)  |  O(R \* C)  |

pacific, atlantic에서 시작해 BFS로 각 좌표에 도달할 수 있는지 확인한다.

이 때 현재 높이 이상의 높이인 인접한 좌표로만 이동 가능하다.

이후 각 좌표별로 두 바다에서 모두 도달할 수 있는 좌표를 반환한다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct Status {
  Axis a;
  int h;
  bool isPacific;
};

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
  int rows = heights.size(), cols = heights[0].size();

  bool visited[2][201][201] = {
      false,
  };

  queue<Status> q;
  for (int x = 0; x < cols; x++) {
    q.push({{-1, x}, -1, true});
    q.push({{rows, x}, -1, false});
  }
  for (int y = 0; y < rows; y++) {
    q.push({{y, -1}, -1, true});
    q.push({{y, cols}, -1, false});
  }

  while (!q.empty()) {
    Status cur = q.front();
    Axis a = cur.a;
    q.pop();

    for (Axis& dir : dirs) {
      Axis next = {a.y + dir.y, a.x + dir.x};

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      if (visited[cur.isPacific][next.y][next.x]) continue;
      if (heights[next.y][next.x] < cur.h) continue;

      visited[cur.isPacific][next.y][next.x] = true;

      q.push({next, heights[next.y][next.x], cur.isPacific});
    }
  }

  vector<vector<int>> answer;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (visited[0][y][x] && visited[1][y][x]) {
        answer.push_back({y, x});
      }
    }
  }
  return answer;
}
```

## 고생한 점
