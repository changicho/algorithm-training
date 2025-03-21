# 2025 프로그래머스 코드챌린지 1차 예선 - 지게차와 크레인

[링크](https://school.programmers.co.kr/learn/courses/30/lessons/388353)

| 난이도 |
| :----: |
|  lv2   |

## 설계

### 시간 복잡도

창고의 크기를 R * C라 하자. 쿼리 요청의 갯수를 Q라 하자.

각 경우마다 쿼리를 수행 후 BFS를 수행해 바로 꺼낼 수 있는 좌표들을 검색한다.

에애 O(Q \* R \* C)의 시간 복잡도를 사용한다.

### 공간 복잡도

BFS에 O(R \* C)의 공간 복잡도를 사용한다.

별도의 공간을 만들어 사용할 경우 O(R \* C)의 공간 복잡도가 필요하다.

### hash map & BFS

|  시간 복잡도   | 공간 복잡도 |
| :------------: | :---------: |
| O(Q \* R \* C) |  O(R \* C)  |

각 경우마다 2가지 값을 저장한다.

- 각 알파벳 별 모든 좌표들
- 각 알파벳 별 현재 바로 꺼낼 수 있는 좌표들

이후 각 쿼리를 수행하며 BFS를 수행해 바로 꺼낼 수 있는 좌표들을 갱신한다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int convertAxis(Axis &a) { return a.y * 100 + a.x; }

vector<vector<char>> getBoard(vector<string> &storage) {
  int rows = storage.size(), cols = storage[0].size();

  vector<vector<char>> board(rows + 2, vector<char>(cols + 2, '0'));
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      board[y + 1][x + 1] = storage[y][x];
    }
  }
  return board;
}

unordered_map<char, unordered_set<int>> getEdges(vector<vector<char>> &board) {
  int rows = board.size(), cols = board[0].size();

  unordered_map<char, unordered_set<int>> um;

  queue<Axis> q;
  bool visited[55][55] = {
      false,
  };
  visited[0][0] = true;
  q.push({0, 0});

  while (!q.empty()) {
    Axis cur = q.front();
    q.pop();

    for (Axis &d : dirs) {
      Axis next = {cur.y + d.y, cur.x + d.x};

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      if (visited[next.y][next.x]) continue;
      visited[next.y][next.x] = true;

      if (board[cur.y][cur.x] == '0' && board[next.y][next.x] != '0') {
        int converted = next.y * 100 + next.x;

        um[board[next.y][next.x]].insert(converted);
      }

      if (board[next.y][next.x] == '0') q.push(next);
    }
  }

  return um;
}

int solution(vector<string> storage, vector<string> requests) {
  vector<vector<char>> board = getBoard(storage);
  int rows = board.size(), cols = board[0].size();

  unordered_map<char, unordered_set<int>> alls;
  unordered_map<char, unordered_set<int>> edges = getEdges(board);

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[y][x] == '0') continue;

      char key = board[y][x];

      alls[key].insert(y * 100 + x);
    }
  }

  for (string &r : requests) {
    char key = r[0];

    if (r.size() == 1) {
      for (int e : edges[key]) {
        int y = e / 100, x = e % 100;

        board[y][x] = '0';
      }
    } else {
      for (int e : alls[key]) {
        int y = e / 100, x = e % 100;

        board[y][x] = '0';
      }
      alls[key].clear();
    }

    edges = getEdges(board);
  }

  int answer = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[y][x] == '0') continue;
      answer++;
    }
  }

  return answer;
}
```

## 고생한 점
