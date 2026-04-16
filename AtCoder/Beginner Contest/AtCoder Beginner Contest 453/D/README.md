# D - Go Straight

[링크](https://atcoder.jp/contests/abc453/tasks/abc453_d)

| 난이도 |
| :----: |
|  425   |

## 설계

### 시간 복잡도

2차원 배열의 크기를 R \* C라 하자.

각 방향에 대해 중복을 제외한 완전 탐색을 진행할 경우 O(R \* C \* 4)의 시간 복잡도를 사용한다.

이는 O(R \* C)이다.

### 공간 복잡도

DFS로 완전 탐색을 수행할 경우 O(R \* C \* 4)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     483      |  O(R \* C)  |  O(R \* C)  |

각 좌표와 방향에 대해서 완전 탐색을 수행한다.

각 과정마다 path를 저장후 목표 지점에 도달할 경우 path를 answer에 저장한다.

이전에 이미 방문한 좌표, 방향의 경우 중복 방문하지 않는다.

```cpp
struct Axis {
  int y, x;
};

// U R D L
Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

unordered_map<int, char> dirToChar = {
    {0, 'U'},
    {1, 'R'},
    {2, 'D'},
    {3, 'L'},
};

string answer = "";
bool dp[1000][1000][4] = {
    false,
};  // y, x, dir

void recursive(vector<string>& board, Axis cur, string& path, int dir) {
  int rows = board.size(), cols = board[0].size();

  if (answer.size() > 0) {
    return;
  }

  if (dp[cur.y][cur.x][dir]) {
    return;
  }
  dp[cur.y][cur.x][dir] = true;

  if (board[cur.y][cur.x] == 'G') {
    answer = path;
    return;
  }

  for (int d = 0; d < 4; d++) {
    if (board[cur.y][cur.x] == 'o' && d != dir) {
      continue;
    } else if (board[cur.y][cur.x] == 'x' && d == dir) {
      continue;
    }
    Axis dd = dirs[d];
    Axis next = {cur.y + dd.y, cur.x + dd.x};

    if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols) {
      continue;
    }
    if (board[next.y][next.x] == '#') {
      continue;
    }
    path.push_back(dirToChar[d]);
    recursive(board, next, path, d);
    path.pop_back();
  }
}

// # : wall
// . : free
// o : ice must go same direction
// x : need to change direction
// S : start
// G : goal
string solution(int rows, int cols, vector<string>& board) {
  Axis start, goal;

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[y][x] == 'S') {
        start = {y, x};
      } else if (board[y][x] == 'G') {
        goal = {y, x};
      }
    }
  }

  for (int d = 0; d < 4; d++) {
    string path = "";
    recursive(board, start, path, d);
  }

  return answer;
}
```

## 고생한 점
