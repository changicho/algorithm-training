# 5876. Horseshoes

[링크](https://www.acmicpc.net/problem/5872)

| 난이도 | 정답률(\_%) | 시간 제한(초) |
| :----: | :---------: | :-----------: |
| 실버 1 |   52.128    |       1       |

## 설계

### 시간 복잡도

입력받은 2차원 정방 배열의 한 변의 길이를 N이라 하자.

시작좌표에서 끝 좌표까지 DFS로 순회해 모든 경우를 탐색할 경우 시간 복잡도는 O(N^2)이다.

### 공간 복잡도

DFS에 방문 여부를 저장할 2차원 배열이 필요하다. 이는 O(N^2)의 공간 복잡도를 사용한다.

또한 call stack에 최대 O(N^2)의 공간 복잡도를 사용한다.

## DFS

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|   O(N^2)    |   O(N^2)    |

시작 좌표부터 DFS를 수행하며 최대 길이를 갱신해 나간다.

이 때 현재까지 지나온 여는 괄호의 수와 닫는 괄호의 수를 저장한다.

만약 현재 좌표까지 여는 괄호만 존재하는 경우 다음좌표에 닫는 괄호를 선택할 수 있다.

여는 괄호으 수와 닫는 괄호의 수가 같은 경우 이는 정답이 도리 수 있다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int answer = 0;

bool visited[5][5] = {false};
vector<string> board;

void recursive(Axis axis, int open, int closed) {
  int size = board.size();

  visited[axis.y][axis.x] = true;

  if (open == closed) {
    answer = max(answer, open + closed);
    visited[axis.y][axis.x] = false;
    return;
  }

  char cur = board[axis.y][axis.x];

  // check open
  if (closed == 0 && cur == '(') {
    for (Axis &dir : dirs) {
      Axis next = {axis.y + dir.y, axis.x + dir.x};
      if (next.y < 0 || next.y >= size || next.x < 0 || next.x >= size)
        continue;
      if (visited[next.y][next.x]) continue;
      if (board[next.y][next.x] == ')') continue;

      recursive(next, open + 1, closed);
    }
  }

  // check closed
  for (Axis &dir : dirs) {
    Axis next = {axis.y + dir.y, axis.x + dir.x};
    if (next.y < 0 || next.y >= size || next.x < 0 || next.x >= size) continue;
    if (visited[next.y][next.x]) continue;
    if (board[next.y][next.x] == '(') continue;

    recursive(next, open, closed + 1);
  }

  visited[axis.y][axis.x] = false;
}

int solution() {
  int size = board.size();
  if (board[0][0] == ')') return 0;
  recursive({0, 0}, 1, 0);

  return answer;
}
```

## 고생한 점
