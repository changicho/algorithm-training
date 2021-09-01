# 542. 01 Matrix

[링크](https://leetcode.com/problems/01-matrix/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

행의 개수를 N, 열의 개수를 M이라 하자.

하나의 0을 찾고 그 위치들과 1에 대해서 갱신할 경우에 시간 복잡도는 O(N \* M)이다.

이를 모든 0에 대해서 반복할 경우 시간 복잡도는 O(N^2 \* M^2)가 된다.

이는 제한시간 내에 불가능하다.

따라서 시간 복잡도를 줄이기 위해 한번의 탐색에 모든 값을 갱신한다.

BFS를 이용해 0인 것들부터 거리를 모두 갱신할 경우 O(N \* M)의 시간 복잡도가 소요된다.

동적 계획법을 이용해 인접한 직전값을 이용해 갱신할 경우 O(N \* M)의 시간 복잡도가 소요된다.

### 공간 복잡도

입력받은 2차원 벡터에 직접 값을 갱신하는 경우 별도의 공간 복잡도가 필요하지 않으므로 공간 복잡도는 O(1)이다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      64      |  O(N \* M)  |    O(1)     |

먼저 순회를 통해 0인 좌표들을 모두 저장한다.

이후 BFS를 통해 단계별로 거리들을 갱신해 나간다.

이때 직전에 방문한 값들은 현재 값보다 이전 단계이므로 거리가 더 짧고 이를 이용해 방문한 좌표를 다시 방문하지 않을 수 있다.

이 때 방문하지 않은 좌표의 초기값은 가능한 최대값으로 설정하며 거리의 최대값은 N + M 이므로 이 값으로 설정한다.

```cpp
struct Axis {
  int y, x;
};
Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
  int rows = mat.size();
  int cols = mat.front().size();
  int limit = rows + cols;  // The distance of cells is up to (M + N)

  queue<Axis> q;

  Axis start = {-1, -1};
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (mat[y][x] == 0) {
        q.push({y, x});
      } else {
        mat[y][x] = limit;
      }
    }
  }

  while (!q.empty()) {
    int size = q.size();

    while (size--) {
      Axis cur = q.front();
      q.pop();

      for (Axis dir : dirs) {
        Axis next = {cur.y + dir.y, cur.x + dir.x};

        if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
          continue;
        if (mat[next.y][next.x] <= mat[cur.y][cur.x] + 1) continue;

        mat[next.y][next.x] = mat[cur.y][cur.x] + 1;
        q.push(next);
      }
    }
  }

  return mat;
}
```

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      68      |  O(N \* M)  |    O(1)     |

모든 좌표는 인접한 좌표에 대해 거리가 -1, 0, +1 이다.

따라서 두번 순회를 통해 (순회 방향은 반대로) 모든 좌표에 대해 값을 갱신할 수 있다.

이 때 방문하지 않은 좌표의 초기값은 가능한 최대값으로 설정하며 거리의 최대값은 N + M 이므로 이 값으로 설정한다.

```cpp
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
  int rows = mat.size();
  int cols = mat.front().size();
  int limit = rows + cols;  // The distance of cells is up to (M + N)

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (mat[y][x] == 0) continue;

      int top = limit, left = limit;
      if (y - 1 >= 0) top = mat[y - 1][x];
      if (x - 1 >= 0) left = mat[y][x - 1];

      mat[y][x] = min(top, left) + 1;
    }
  }
  for (int y = rows - 1; y >= 0; y--) {
    for (int x = cols - 1; x >= 0; x--) {
      if (mat[y][x] == 0) continue;
      int bottom = limit, right = limit;

      if (y + 1 < rows) bottom = mat[y + 1][x];
      if (x + 1 < cols) right = mat[y][x + 1];
      mat[y][x] = min(mat[y][x], min(bottom, right) + 1);
    }
  }
  return mat;
}
```

## 고생한 점
