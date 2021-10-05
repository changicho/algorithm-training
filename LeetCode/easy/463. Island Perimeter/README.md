# 463. Island Perimeter

[링크](https://leetcode.com/problems/island-perimeter/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

행의 개수를 N, 열의 개수를 M이라 하자.

모든 요소를 순회하며 각 섬의 면의 개수를 셀 경우 시간 복잡도는 O(N \* M)이 소요된다.

하나의 섬에서 4개의 면에 대해서 세야 하며 이 연산에 O(1)의 시간 복잡도가 소요되므로

최종 시간 복잡도는 O(N \* M)이다.

### 공간 복잡도

각 좌표를 탐색하며 별도로 저장하는 공간이 없으므로 O(1)의 공간 복잡도를 사용한다.

### 4방향 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      80      |  O(N \* M)  |    O(1)     |

각 좌표에서 stripe의 개수를 센다.

- 현재 좌표가 섬이고 각 좌표의 상, 하, 좌, 우에 섬이 없는경우 stripe을 증가시킨다 (각각)

이를 모든 좌표에 대해서 반복해준다.

이 때 좌표의 범위를 벗어나는 경우는 섬이 없다고 판별한다.

```cpp
int islandPerimeter(vector<vector<int>>& grid) {
  int rows = grid.size();
  int cols = grid.front().size();

  vector<Axis> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  int answer = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (grid[y][x] == 0) continue;

      for (Axis dir : dirs) {
        Axis next = {dir.y + y, dir.x + x};

        if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols) {
          answer += 1;
          continue;
        }
        if (grid[next.y][next.x] == 0) {
          answer += 1;
          continue;
        }
      }
    }
  }

  return answer;
}
```

### 중복 제거

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      92      |  O(N \* M)  |    O(1)     |

모든 좌표를 순회하며 다음과 같이 생각할 수 있다.

- 모든 섬은 4개의 stripe를 가진다.
- 만약 섬이 다른 섬과 붙어있는 경우 해당 stripe는 사라진다.

따라서 섬을 순회할 때, 붙어있는 부분 (중복된)을 세고 이후 정답에서 이를 제거한다.

여기서 인접한 A, B좌표에서 중복된 부분을 2번 이상 세지 않도록 한 방향으로만 탐색을 진행한다.

y, x에 대해서 x를 먼저 증가시키고 y를 증가시키므로

현재 좌표에서 위쪽, 왼쪽에 있는 좌표들에 대해서만 중복을 검사한다.

```cpp
int islandPerimeter(vector<vector<int>>& grid) {
  int rows = grid.size();
  int cols = grid.front().size();

  int count = 0, repeat = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (grid[y][x] != 1) continue;

      count++;
      if (y != 0 && grid[y - 1][x] == 1) repeat++;
      if (x != 0 && grid[y][x - 1] == 1) repeat++;
    }
  }
  return 4 * count - repeat * 2;
}
```

## 고생한 점
