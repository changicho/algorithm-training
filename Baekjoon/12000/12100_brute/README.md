# 12100. 2048 (Easy)

[링크](https://www.acmicpc.net/problem/12100)

| 난이도  | 정답률(\_%) | 시간 제한(초) |
| :-----: | :---------: | :-----------: |
| Gold II |   24.207    |       1       |

## 설계

### 시간 복잡도

보드의 크기 N은 최대 20^2 이다. 모든 경우의 수를 돌려봐야 하므로 이 때 시간 복잡도는 4^5 이다.

이는 2^10 = 1024 번 이므로 모든 경우를 제한시간 내에 탐색할 수 있다.

각 경우마다 블록을 이동시킬 때 들어가는 시간 복잡도는 N^3 정도이다.

따라서 최악의 경우 시간 복잡도는 O(N^3 \* 2^10) = 8,192,000 이므로 제한시간 내에 충분하다.

### 공간 복잡도

입력받는블록의 최대값은 1024까지이다.

최악의 경우도 정답은 1024 \* 32 이하임이 보장되므로 int형으로 선언한다.

### 블록의 이동

블록의 이동에서 고려해야 할 부분은 다음과 같다.

- 다음 위치에 블록이 없는지
- 다음 위치에 블록이 있는경우 그 블록이 이미 합쳐졌는지
- 다음 위치에 블록이 있는 경우 현재 블록과 숫자가 같은지

다음 위치에 블록이 없는 경우는 이동할 수 있다.

그러나 그 외의 경우는 블록은 합쳐지거나 이동을 멈춘다.

이동하는 방향의 모서리에서 가장 가까운 블록부터 이동시켜야 이미 합쳐진 블록에대한 분기 처리를 할 수 있다.

```cpp
vector<vector<int>> move_up(vector<vector<int>> board) {
  vector<vector<bool>> visited(N, vector<bool>(N, false));

  for (int x = 0; x < N; x += 1) {
    for (int y = 1; y < N; y += 1) {
      if (board[y][x] == 0) continue;

      for (int cur = y; cur > 0; cur -= 1) {
        int next = cur - 1;
        if (next < 0) break;

        if (board[next][x] == 0) {
          board[next][x] = board[cur][x];
          board[cur][x] = 0;
        } else if (board[next][x] == board[cur][x] && !visited[next][x]) {
          board[next][x] += board[cur][x];
          board[cur][x] = 0;
          visited[next][x] = true;
          break;
        } else {
          break;
        }
      }
    }
  }
  return board;
}
```

### 완전 탐색

이동은 5번까지만 수행하면 된다.

이 때 5번 이동한 경우에만 블록의 최대값을 찾는다. 5번 이동하기 전에 최대값이 5번 이동한 후에도 남아있기 때문이다.

```cpp
queue<Status> q;
q.push({board, 0});

while (!q.empty()) {
  Status cur = q.front();
  q.pop();

  if (cur.step == 5) {
    answer = max(answer, findMax(cur.board));
    continue;
  }

  q.push({move_up(cur.board), cur.step + 1});
  q.push({move_down(cur.board), cur.step + 1});
  q.push({move_left(cur.board), cur.step + 1});
  q.push({move_right(cur.board), cur.step + 1});
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      12      |       0        |

## 고생한 점
