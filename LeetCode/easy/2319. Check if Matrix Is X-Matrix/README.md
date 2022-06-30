# 2319. Check if Matrix Is X-Matrix

[링크](https://leetcode.com/problems/check-if-matrix-is-x-matrix/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

행, 열의 크기를 N이라 하자.

모든 원소를 순회하며 대각선인 경우와 대각선이 아닌경우 비교해야한다.

모든 원소를 비교하므로 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 좌표가 대각선인지 아닌지 여부는 크기와 좌표 자체로 판단이 가능하다.

따라서 별도로 크기만큼의 공간을 가지고 있지 않아도 된다.

따라서 공간 복잡도는 O(1)이다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      70      |   O(N^2)    |    O(1)     |

각 좌표를 순회하며 대각선인 경우와 아닌 경우 별도로 비교한다.

이 때 대각선 여부는 다음 2가지 경우로 판단한다.

- y == x
- (N - 1) - y == x

이를 구현하면 다음과 같다.

```cpp
bool isX(int y, int x, int size) { return x == y || size - 1 - y == x; }

bool checkXMatrix(vector<vector<int>>& grid) {
  int size = grid.size();

  for (int y = 0; y < size; y++) {
    for (int x = 0; x < size; x++) {
      if (isX(y, x, size)) {
        if (grid[y][x] == 0) return false;
      } else {
        if (grid[y][x] != 0) return false;
      }
    }
  }
  return true;
}
```

## 고생한 점
