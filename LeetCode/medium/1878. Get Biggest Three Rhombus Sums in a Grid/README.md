# 1878. Get Biggest Three Rhombus Sums in a Grid

[링크](https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

prefix sum을 이용해 특정 좌표에서의 마름모의 길이를 빠르게 구할 수 있다.

이 경우 prefix sum을 생성하는데 O(RC \* min(R, C))의 시간이 소요된다.

이후 각 좌표를 순회하며 정답을 구하는데 O(RC \* min(R, C))의 시간이 소요된다.

### 공간 복잡도

대각선 방향의 prefix sum을 사용할 경우 O(RC)의 공간 복잡도를 사용한다.

각 좌표마다 마름모 상단, 하단에 대한 길이에 대해 prefix sum을 저장할 경우 O(RC \* min(R, C))의 공간 복잡도를 사용한다.

### prefix sum & heap

| 내 코드 (ms) |    시간 복잡도     |    공간 복잡도     |
| :----------: | :----------------: | :----------------: |
|     255      | O(RC \* min(R, C)) | O(RC \* min(R, C)) |

2개의 prefix sum을 생성한다.

- `topDp[y][x][l]` : (y, x)를 시작으로 하는 마름모의 상단 부분의 길이가 l인 경우의 합
- `downDp[y][x][l]` : (y, x)를 시작으로 하는 마름모의 하단 부분의 길이가 l인 경우의 합

이를 미리 구한 뒤 각 좌표마다 마름모의 길이를 늘려가며 정답을 구한다.

이 때 정답의 값이 유니크하며 가장 큰 3개를 구해야 하므로 힙과 unordered_set을 이용한다.

```cpp
vector<int> getBiggestThree(vector<vector<int>>& grid) {
  int rows = grid.size(), cols = grid[0].size();

  vector<vector<vector<int>>> topDp(
      rows, vector<vector<int>>(cols, vector<int>(51, INT_MIN)));
  vector<vector<vector<int>>> downDp(
      rows, vector<vector<int>>(cols, vector<int>(51, INT_MIN)));

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      topDp[y][x][0] = 0;
      topDp[y][x][1] = grid[y][x];
      for (int l = 2; l <= 50; l++) {
        int diff = l - 1;

        if (x - diff < 0 || x + diff >= cols) break;
        if (y + diff >= rows) break;
        topDp[y][x][l] = topDp[y][x][l - 1] + grid[y + diff][x + diff] +
                          grid[y + diff][x - diff];
      }

      downDp[y][x][0] = 0;
      downDp[y][x][1] = grid[y][x];
      for (int l = 2; l <= 50; l++) {
        int diff = l - 1;

        if (x - diff < 0 || x + diff >= cols) break;
        if (y - diff < 0) break;
        downDp[y][x][l] = downDp[y][x][l - 1] + grid[y - diff][x + diff] +
                          grid[y - diff][x - diff];
      }
    }
  }

  priority_queue<int, vector<int>, greater<int>> pq;
  unordered_set<int> visited;
  function<void(int)> add = [&](int sum) {
    if (visited.count(sum) == 0) {
      visited.insert(sum);
      pq.push(sum);
      if (pq.size() > 3) {
        pq.pop();
      }
    }
  };
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      for (int l = 1; l <= 50; l++) {
        int diff = l - 1;
        if (y + 2 * diff >= rows) break;
        if (topDp[y][x][l] == INT_MIN ||
            downDp[y + 2 * diff][x][l - 1] == INT_MIN)
          break;
        int cur = topDp[y][x][l] + downDp[y + 2 * diff][x][l - 1];

        add(cur);
      }
    }
  }

  vector<int> answer;
  while (!pq.empty()) {
    answer.push_back(pq.top());
    pq.pop();
  }
  reverse(answer.begin(), answer.end());
  return answer;
}
```

## 고생한 점
