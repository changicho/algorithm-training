# Problem A2: Ready, Go (Part 2)

[링크](https://www.facebook.com/codingcompetitions/hacker-cup/2023/round-2/problems/A2)

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

이 때 흰색 돌을 잡을 수 있는 위치를 key로 하는 hash map을 생성 후 value에 현재 흰 돌의 갯수를 더한다.

이를 모든 흰색 돌 그룹에 대해 수행할 경우 흰색 돌을 잡을 수 있는 위치를 key로 하는 hash map을 생성할 수 있다.

이를 이용해 가장 많은 흰색 돌을 잡을 수 있는 좌표를 찾을 수 있다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

long long convert(Axis a) { return a.y * 10000 + a.x; }

int solution(vector<vector<char>> &board) {
  int rows = board.size(), cols = board[0].size();
  int alreadyCaptured = 0;
  int answer = 0;

  unordered_map<long long, int> capturedCount;
  unordered_set<long long> visited;

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[y][x] != 'W') continue;
      if (visited.count(convert({y, x})) > 0) continue;
      queue<Axis> q;

      q.push({y, x});
      visited.insert(convert({y, x}));
      Axis point = {-1, -1};

      unordered_map<char, int> border;
      unordered_set<long long> borderCheck;

      int count = 0;

      while (!q.empty()) {
        Axis cur = q.front();
        q.pop();
        count++;

        for (Axis &dir : dirs) {
          Axis next = {cur.y + dir.y, cur.x + dir.x};

          if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
            continue;
          if (visited.count(convert(next)) > 0) continue;

          if (!borderCheck.count(convert(next))) {
            borderCheck.insert(convert(next));
            border[board[next.y][next.x]]++;
            if (board[next.y][next.x] == '.') point = next;
          }

          if (board[next.y][next.x] != 'W') continue;
          visited.insert(convert(next));

          q.push(next);
        }
      }

      if (border['.'] > 1) {
        count = 0;
        point = {-1, -1};
      }

      if (count == 0) continue;
      if (point.y == -1) {
        alreadyCaptured += count;
      } else {
        capturedCount[convert(point)] += count;
        answer = max(alreadyCaptured + capturedCount[convert(point)], answer);
      }
    }
  }

  return answer;
}
```

## 고생한 점
