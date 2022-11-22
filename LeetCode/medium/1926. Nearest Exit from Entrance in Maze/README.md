# 1926. Nearest Exit from Entrance in Maze

[링크](https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

BFS를 이용해 각 좌표를 최대 한번씩만 방문하면 되므로 O(R \* C)의 시간 복잡도를 사용한다.

### 공간 복잡도

BFS를 이용할 경우 O(R \* C)의 공간 복잡도를 사용한다.

### 정리

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     324      |  O(R \* C)  |  O(R \* C)  |

시작점부터 BFS를 이용해 다른 좌표들을 순차적으로 탐색한다.

이 때 edge에 도달했을 때 시작점이 아닌 경우 정답으로 반환한다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool isExit(Axis& axis, int rows, int cols) {
  return axis.x == 0 || axis.y == 0 || axis.y == rows - 1 || axis.x == cols - 1;
}

int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
  int rows = maze.size(), cols = maze.front().size();

  int answer = -1;
  Axis start = {entrance[0], entrance[1]};

  vector<vector<bool>> visited(rows, vector<bool>(cols, false));

  queue<Axis> q;
  q.push(start);
  visited[start.y][start.x] = true;

  int step = 0;
  while (!q.empty() && answer == -1) {
    int size = q.size();

    while (size--) {
      Axis cur = q.front();
      q.pop();

      if (isExit(cur, rows, cols) &&
          !(cur.y == entrance[0] && cur.x == entrance[1])) {
        answer = step;
        break;
      }

      for (Axis& dir : dirs) {
        Axis next = {cur.y + dir.y, cur.x + dir.x};

        if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
          continue;
        if (maze[next.y][next.x] == '+') continue;
        if (visited[next.y][next.x]) continue;
        visited[next.y][next.x] = true;

        q.push(next);
      }
    }
    step++;
  }

  return answer;
}
```

## 고생한 점
