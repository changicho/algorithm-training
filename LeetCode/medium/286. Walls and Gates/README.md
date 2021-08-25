# 286. Walls and Gates

[링크](https://leetcode.com/problems/walls-and-gates/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

행의 개수를 N, 열의 개수를 M이라 하자.

각 gate별로 다른 위치마다의 거리를 갱신해야 한다. 하나의 gate에서 다른 모든 위치의 거리를 갱신하는데 O(N \* M)의 시간 복잡도가 소요된다.

모든 gate에 대해 한번씩 순회를 할 경우 최종 시간 복잡도는 O(N^2 \* M^2)가 된다.

이는 제한시간내에 불가능하다.

따라서 gate에 대해서 최소 거리들만 갱신하면 되므로 각 gate들을 한번씩 순회하며 BFS를 수행한다.

이 경우 결과적으로 하나의 좌표에서 다음으로 이동할 때 backtracking을 수행하게 되므로 시간 복잡도는 O(N \* M)이 된다.

### 공간 복잡도

입력받은 2차원 배열을 사용하면 되며 BFS를 수행할 때 큐에 최대 N \* M개의 좌표가 들어갈 수 있다.

따라서 공간 복잡도는 O(N \* M)이다.

### BFS with backtracking

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      28      |  O(N \* M)  |  O(N \* M)  |

입력받은 2차원 배열에서 문들의 위치를 찾은 뒤 큐에 삽입한다.

이후 해당 큐에서 순차적으로 BFS를 순회한다.

```cpp
struct Axis {
    int y, x;
  };

const int INF = 2147483647;
Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void wallsAndGates(vector<vector<int>>& rooms) {
  int rows = rooms.size();
  int cols = rooms.front().size();
  queue<Axis> q;

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (rooms[y][x] == 0) {
        q.push({y, x});
      }
    }
  }

  while (!q.empty()) {
    Axis axis = q.front();
    q.pop();

    bool hasNext = false;
    for (Axis dir : dirs) {
      Axis next = {axis.y + dir.y, axis.x + dir.x};

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols) continue;
      if (rooms[next.y][next.x] == -1) continue;
      if (rooms[next.y][next.x] <= rooms[axis.y][axis.x] + 1) continue;

      rooms[next.y][next.x] = rooms[axis.y][axis.x] + 1;
      q.push(next);
    }
  }
}
```

## 고생한 점
