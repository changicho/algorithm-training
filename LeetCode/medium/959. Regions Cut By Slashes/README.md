# 959. Regions Cut By Slashes

[링크](https://leetcode.com/problems/regions-cut-by-slashes/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 2차원 배열 grid의 각 변의 크기를 R, C라 하자.

각 slash 문자에 대해서 3\*3 크기의 정사각형으로 모양을 표시한다.

이 경우 R\*3, C\*3 크기의 2차원 배열을 새로 만들어 BFS를 이용해 탐색할 수 있다.

이 경우 O(R \* C)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

BFS에 O(R \* C)의 공간 복잡도가 필요하다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      23      |  O(R \* C)  |  O(R \* C)  |

입력받은 grid를 순회하며 공백, slash 문자열을 3\*3 크기의 정사각형으로 변환한다.

이후 변환한 2차원 배열을 순회하며 BFS를 이용해 탐색을 진행한다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int regionsBySlashes(vector<string>& grid) {
  int rows = grid.size(), cols = grid[0].size();

  vector<vector<bool>> board(rows * 3, vector<bool>(cols * 3, false));

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      int ny = y * 3, nx = x * 3;

      if (grid[y][x] == '\\') {
        board[ny][nx] = board[ny + 1][nx + 1] = board[ny + 2][nx + 2] = true;
      } else if (grid[y][x] == '/') {
        board[ny][nx + 2] = board[ny + 1][nx + 1] = board[ny + 2][nx] = true;
      }
    }
  }

  function<void(Axis)> check = [&](Axis a) {
    queue<Axis> q;
    q.push(a);
    board[a.y][a.x] = true;
    while (!q.empty()) {
      Axis cur = q.front();
      q.pop();

      for (Axis& dir : dirs) {
        Axis next = {cur.y + dir.y, cur.x + dir.x};

        if (next.y < 0 || next.y >= rows * 3 || next.x < 0 ||
            next.x >= cols * 3)
          continue;
        if (board[next.y][next.x]) continue;
        board[next.y][next.x] = true;
        q.push(next);
      }
    }
  };

  int answer = 0;

  for (int y = 0; y < rows * 3; y++) {
    for (int x = 0; x < cols * 3; x++) {
      if (board[y][x]) continue;

      answer++;
      check({y, x});
    }
  }
  return answer;
}
```

## 고생한 점
