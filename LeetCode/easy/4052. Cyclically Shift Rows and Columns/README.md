# 4052. Cyclically Shift Rows and Columns

[링크](https://leetcode.com/problems/cyclically-shift-rows-and-columns/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

2차원 정방형 격자의 크기를 N^2라 하자.

직접 변경할 경우 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

원본 값에 대한 추가 공간을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

값의 범위가 한정되어있으므로 이 추가공간을 사용해 유효한 값만 남길 경우 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색 (추가공간)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |   O(N^2)    |    O(N)     |

각 과정마다 직접 shift연산을 수행한다.

```cpp
vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
  for (int y = 0; y < n; y++) {
    if (rowShift[y] == 0) continue;
    int shift = rowShift[y];

    vector<int> nums;
    for (int x = 0; x < n; x++) {
      nums.push_back(grid[y][x]);
    }

    for (int x = 0; x < n; x++) {
      grid[y][x] = nums[(x + shift) % n];
    }
  }
  for (int x = 0; x < n; x++) {
    if (colShift[x] == 0) continue;
    int shift = colShift[x];

    vector<int> nums;
    for (int y = 0; y < n; y++) {
      nums.push_back(grid[y][x]);
    }

    for (int y = 0; y < n; y++) {
      grid[y][x] = nums[(y + shift) % n];
    }
  }
  return grid;
}
```

## 고생한 점
