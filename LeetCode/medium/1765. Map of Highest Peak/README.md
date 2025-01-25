# 1765. Map of Highest Peak

[링크](https://leetcode.com/problems/map-of-highest-peak/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

BFS를 이용해 각 지점마다 최소 높이를 구한다. 이 경우 O(R \* C)의 시간 복잡도가 필요하다.

### 공간 복잡도

BFS에 O(R \* C)의 공간 복잡도가 필요하다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      50      |  O(R \* C)  |  O(R \* C)  |

물이 존재하는 위치부터 BFS로 탐색을 진행한다.

이 때 높이별로 BFS순회를 진행하며 높이를 갱신한다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

vector<vector<int>> highestPeak(vector<vector<int>> &isWater) {
  int rows = isWater.size(), cols = isWater[0].size();

  queue<Axis> q;

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (isWater[y][x] == 1) {
        isWater[y][x] = 0;
        q.push({y, x});
      } else {
        isWater[y][x] = -1;
      }
    }
  }

  int level = 1;
  while (!q.empty()) {
    int size = q.size();

    while (size--) {
      Axis cur = q.front();
      q.pop();

      for (Axis &dir : dirs) {
        Axis next = {cur.y + dir.y, cur.x + dir.x};
        if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
          continue;

        if (isWater[next.y][next.x] != -1) continue;
        isWater[next.y][next.x] = level;

        q.push(next);
      }
    }

    level++;
  }

  return isWater;
}
```

## 고생한 점
