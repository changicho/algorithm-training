# 1914. Cyclically Rotating a Grid

[링크](https://leetcode.com/problems/cyclically-rotating-a-grid/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 크기를 RC 라 하자.

각 layer의 좌표마다 실제 이동을 구현할 경우, 각 좌표별로 한번씩 방문하므로 O(RC)의 시간 복잡도를 사용한다.

### 공간 복잡도

이동 좌표, 값을 저장 후 이동을 구현하는데 O(R + C)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      14      |    O(RC)    |  O(R + C)   |

각 레이어별로 속하는 좌표들을 순서대로 배열에 집어넣고, 해당 값들을 이동한 뒤 새로 좌표에 할당한다.

```cpp
struct Axis {
  int y, x;
};

vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
  int rows = grid.size(), cols = grid[0].size();

  int limit = min(rows, cols) / 2;
  for (int i = 0; i < limit; i++) {
    int length = (rows - i * 2) * 2 + (cols - i * 2) * 2 - 4;

    int moveCount = k % length;

    int ys = i, ye = rows - 1 - i;
    int xs = i, xe = cols - 1 - i;

    vector<Axis> targets;
    vector<int> nums;
    for (int y = ys; y <= ye; y++) {
      targets.push_back({y, xs});
      nums.push_back(grid[y][xs]);
    }
    for (int x = xs + 1; x <= xe; x++) {
      targets.push_back({ye, x});
      nums.push_back(grid[ye][x]);
    }
    for (int y = ye - 1; y >= ys; y--) {
      targets.push_back({y, xe});
      nums.push_back(grid[y][xe]);
    }
    for (int x = xe - 1; x >= xs + 1; x--) {
      targets.push_back({ys, x});
      nums.push_back(grid[ys][x]);
    }

    vector<int> newNums(nums.size());
    for (int i = 0; i < nums.size(); i++) {
      newNums[(i + moveCount) % length] = nums[i];
    }

    for (int i = 0; i < newNums.size(); i++) {
      grid[targets[i].y][targets[i].x] = newNums[i];
    }
  }

  return grid;
}
```

## 고생한 점
