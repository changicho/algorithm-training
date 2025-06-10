# 361. Bomb Enemy

[링크](https://leetcode.com/problems/bomb-enemy/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

각 행과 열을 순회하며 매번 최적의 값을 찾는 데 O(R \* C \* (R + C))의 시간이 소요된다.

동적 계획법을 이용해 현재 행의 enemy의 수와 현재 열의 enemy의 수를 저장한다면, 각 행과 열을 순회하는 데 O(R \* C)의 시간이 소요된다.

### 공간 복잡도

매번 직접 탐색할 경우 별도의 공간 복잡도를 사용하지 않는다.

각 열마다의 현재까지 순회한 enemy의 수를 저장하기 위해 O(C)의 공간이 필요하다.

### 완전 탐색

| 내 코드 (ms) |     시간 복잡도      | 공간 복잡도 |
| :----------: | :------------------: | :---------: |
|     1034     | O(R \* C \* (R + C)) |    O(1)     |

각 좌표를 순회하며 해당 행, 열에 존재하는 enemy의 수를 계산한다.

이 때 벽에 막히는 경우 무시한다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int maxKilledEnemies(vector<vector<char>> &grid) {
  int rows = grid.size(), cols = grid[0].size();

  auto check = [rows, cols, grid](Axis &a) {
    if (a.y < 0 || a.y >= rows || a.x < 0 || a.x >= cols) return false;
    if (grid[a.y][a.x] == 'W') return false;
    return true;
  };

  int answer = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (grid[y][x] != '0') continue;

      int count = 0;

      for (Axis &dir : dirs) {
        Axis next = {y + dir.y, x + dir.x};

        while (check(next)) {
          if (grid[next.y][next.x] == 'E') count++;

          next.y += dir.y;
          next.x += dir.x;
        }
      }

      answer = max(answer, count);
    }
  }

  return answer;
}
```

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      6       |  O(R \* C)  |    O(C)     |

각 행을 위에서부터 순차적으로 순회하며 해당 행에서 왼쪽부터 순회한다.

따라서 이전에 현재 좌표에 해당하는 행의 enemy 수와 현재 열의 enemy 수를 저장해두고, 이를 이용해 현재 좌표에서의 enemy 수를 계산한다.

```cpp
int maxKilledEnemies(vector<vector<char>> &grid) {
  int rows = grid.size(), cols = grid[0].size();

  int answer = 0;

  vector<int> colHits(cols, 0);
  for (int y = 0; y < rows; y++) {
    int rowHits = 0;

    for (int x = 0; x < cols; x++) {
      if (x == 0 || grid[y][x - 1] == 'W') {
        rowHits = 0;

        for (int nx = x; nx < cols && grid[y][nx] != 'W'; nx++) {
          rowHits += grid[y][nx] == 'E';
        }
      }

      if (y == 0 || grid[y - 1][x] == 'W') {
        colHits[x] = 0;

        for (int ny = y; ny < rows && grid[ny][x] != 'W'; ny++) {
          colHits[x] += grid[ny][x] == 'E';
        }
      }

      if (grid[y][x] == '0') {
        answer = max(answer, rowHits + colHits[x]);
      }
    }
  }

  return answer;
}
```

## 고생한 점
