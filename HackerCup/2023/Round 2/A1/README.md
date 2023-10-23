# Problem A1: Ready, Go (Part 1)

[링크](https://www.facebook.com/codingcompetitions/hacker-cup/2023/round-2/problems/A1)

## 설계

### 시간 복잡도

입력받은 2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

모든 좌표의 갯수를 N이라 할 때 (R \* C = N) 검은 돌을 놓을 수 있는 경우의 수는 O(N)이다.

이후 내부적으로 BFS를 이용해 탐색할 경우 총 O(N^2)의 시간 복잡도를 사용한다.

혹은 백색 돌들을 BFS로 순회 후 테두리의 빈 공간을 세는 방법도 가능하다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

BFS에 O(N)의 공간 복잡도를 사용한다.

### BFS

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(N)     |    O(N)     |

붙어있는 흰색 돌들을 그룹으로 묶는다 하자.

해당 그룹의 테두리에 검은 돌들이 존재하며, 빈 공간이 하나만 존재할 때 해당 위치에 검은 돌을 두면 흰색 돌을 잡을 수 있다.

따라서 테두리의 공간의 종류를 세고 빈 공간이 하나인 경우가 존재하면 정답은 true이다.

그 외에 경우는 false 이다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool hasCaptured(vector<vector<char>> &board, int y, int x) {
  int rows = board.size(), cols = board[0].size();

  queue<Axis> q;

  q.push({y, x});

  unordered_map<char, int> border;

  bool visited[21][21] = {false};
  bool borderCheck[21][21] = {false};
  visited[y][x] = true;

  while (!q.empty()) {
    Axis cur = q.front();
    q.pop();

    for (Axis &dir : dirs) {
      Axis next = {cur.y + dir.y, cur.x + dir.x};

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      if (visited[next.y][next.x]) continue;

      if (!borderCheck[next.y][next.x]) {
        borderCheck[next.y][next.x] = true;
        border[board[next.y][next.x]]++;
      }

      if (board[next.y][next.x] != 'W') continue;
      visited[next.y][next.x] = true;

      q.push(next);
    }
  }

  return border['.'] <= 1;
}

bool solution(vector<vector<char>> &board) {
  int rows = board.size(), cols = board[0].size();

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[y][x] != 'W') continue;

      bool isPossible = hasCaptured(board, y, x);
      if (isPossible) return true;
    }
  }

  return false;
}
```

## 고생한 점
