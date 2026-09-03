# 3568. Minimum Moves to Clean the Classroom

[링크](https://leetcode.com/problems/minimum-moves-to-clean-the-classroom/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 크기를 RC, 남은 L의 수를 L이라 하자.

각 좌표마다 남은 L의 경우의 수에 따라 메모이제이션을 사용할 수 있다.

이에 O(RC \* 2^L)의 시간 복잡도를 사용한다.

### 공간 복잡도

메모이제이션에 O(RC \* 2^L)의 공간 복잡도를 사용한다.

### 메모이제이션 & BFS

| 내 코드 (ms) | 시간 복잡도  | 공간 복잡도  |
| :----------: | :----------: | :----------: |
|     219      | O(RC \* 2^L) | O(RC \* 2^L) |

각 좌표마다 다음과 같은 상태가 존재한다.

- 좌표
- 남은 L의 종류
- 남은 에너지

step별로 BFS를 수행할 때 각 좌표를 방문하는 경우 가장 에너지가 높은 경우만 남기는 것이 유리하다.

이 때 각 상태별로 가장 높은 에너지값만 남기고 해당 상태에서 에너지가 더 낮은 경우는 탐색을 진행하지 않는다.

이를 반복하며 정답을 구한다.

```cpp
struct Axis {
  int y, x;
};

struct Status {
  Axis a;
  int e;
  int remain = 0;
  int bit = 0;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int minMoves(vector<string>& classroom, int energy) {
  int rows = classroom.size(), cols = classroom[0].size();
  int dp[21][21][1024] = {
      0,
  };
  memset(dp, -1, sizeof(dp));

  Axis start = {-1, -1};
  int indexes[21][21] = {
      0,
  };

  int targetIndex = 0;
  int target = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (classroom[y][x] == 'S') {
        start = {y, x};
      } else if (classroom[y][x] == 'L') {
        target++;

        indexes[y][x] = targetIndex;
        targetIndex++;
      }
    }
  }

  if (start.y == -1) return -1;

  int answer = INT_MAX;
  queue<Status> q;
  q.push({start, energy, target, 0});
  dp[start.y][start.x][0] = energy;
  int step = 0;

  while (!q.empty()) {
    int size = q.size();

    while (size--) {
      Status cur = q.front();
      q.pop();

      Axis a = cur.a;
      int e = cur.e;
      int remain = cur.remain;
      int bit = cur.bit;

      if (cur.remain == 0) {
        return step;
      }

      if (e == 0) continue;

      for (Axis& d : dirs) {
        Axis next = {a.y + d.y, a.x + d.x};
        int nextE = e - 1;
        int nextRemain = remain;
        int nextBit = bit;

        if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
          continue;

        if (classroom[next.y][next.x] == 'X') {
          continue;
        } else if (classroom[next.y][next.x] == 'L') {
          if ((nextBit & (1 << (indexes[next.y][next.x]))) == 0) {
            nextRemain--;
            nextBit |= 1 << (indexes[next.y][next.x]);
          }
        } else if (classroom[next.y][next.x] == 'R') {
          nextE = energy;
        }

        if (nextE < 0) continue;
        if (dp[next.y][next.x][nextBit] >= nextE) continue;
        dp[next.y][next.x][nextBit] = nextE;

        q.push({next, nextE, nextRemain, nextBit});
      }
    }

    step++;
  }

  return -1;
}
```

## 고생한 점
