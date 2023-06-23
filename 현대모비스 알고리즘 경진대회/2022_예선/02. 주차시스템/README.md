# [현대모비스][예선] 주차시스템

[링크](https://level.goorm.io/exam/152115/%ED%98%84%EB%8C%80%EB%AA%A8%EB%B9%84%EC%8A%A4-%EC%98%88%EC%84%A0-%EC%A3%BC%EC%B0%A8%EC%8B%9C%EC%8A%A4%ED%85%9C/quiz/1)

## 설계

### 시간 복잡도

입력받은 2차원 좌표의 행의 갯수를 N, 열의 갯수를 M이라 하자.

각 좌표에서 차량이 없는 구역에 대해 BFS로 순회할 수 있다.

이 경우 시간 복잡도는 O(N \* M) 이다.

### 공간 복잡도

BFS를 수행하는데 공간 복잡도는 O(N \* M)이다.

### 풀이

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|  O(N \* M)  |  O(N \* M)  |

각 좌표를 순회하며 방문하지 않은 좌표의 경우 BFS를 순회해 가능한 경우를 모두 방문한다.

방문과 동시에 점수를 계산후 정답을 갱신한다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int getScore(vector<vector<int>> &board, Axis start) {
  int rows = board.size(), cols = board[0].size();

  queue<Axis> q;
  q.push(start);

  int score = 0;
  while (!q.empty()) {
    Axis cur = q.front();
    q.pop();

    if (board[cur.y][cur.x] == 1) continue;
    score += board[cur.y][cur.x] == 0 ? 1 : -2;
    board[cur.y][cur.x] = 1;

    for (Axis &dir : dirs) {
      Axis next = {cur.y + dir.y, cur.x + dir.x};

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      if (board[next.y][next.x] == 1) continue;

      q.push(next);
    }
  }

  return score;
}

int solution(vector<vector<int>> &board) {
  int rows = board.size(), cols = board[0].size();

  int answer = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[y][x] == 1) continue;

      int curScore = getScore(board, {y, x});
      answer = max(curScore, answer);
    }
  }

  return answer;
}
```

## 고생한 점
