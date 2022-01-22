# 766. Toeplitz Matrix

[링크](https://leetcode.com/problems/toeplitz-matrix/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

행의 개수를 N, 열의 개수를 M이라 하자.

모든 원소를 순회하며 group별로 체크할 경우 모든 원소를 순회하므로 O(N \* M)의 시간 복잡도를 사용한다.

대각선 왼쪽 위만을 비교하며 이를 반복할 경우 O(N \* M)의 시간 복잡도를 사용한다.

### 공간 복잡도

비교할 그룹끼리만 비교하는 경우 별도의 공간 복잡도를 사용하지 않는다.

### 모두 비교

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      16      |  O(N \* M)  |    O(1)     |

대각선의 시작점에서 같은 대각선 그룹끼리 모든 원소를 비교한다.

이 때 y == 0, x == 0일 때의 시작 점을 모두 비교한다.

```cpp
bool isToeplitzMatrix(vector<vector<int>>& matrix) {
  int rows = matrix.size();
  int cols = matrix.front().size();

  for (int x = 0; x < cols; x++) {
    // y = 0
    int target = matrix[0][x];
    for (int i = 0; i < rows && x + i < cols; i++) {
      if (matrix[i][x + i] != target) return false;
    }
  }

  for (int y = 0; y < rows; y++) {
    // x = 0
    int target = matrix[y][0];
    for (int i = 0; y + i < rows && i < cols; i++) {
      if (matrix[y + i][i] != target) return false;
    }
  }

  return true;
}
```

### 직전 원소 비교

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      32      |  O(N \* M)  |    O(1)     |

모든 원소에 대해서 같은 그룹에서 대각선 왼쪽 위 원소만 비교한다.

이는 각 그룹에서 하나라도 다른 수가 있는 경우 해당 값이나 다음 값에서 비교시 다른 값을 반환하기 때문이다.

```cpp
bool isToeplitzMatrix(vector<vector<int>>& matrix) {
  int rows = matrix.size();
  int cols = matrix.front().size();

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (y - 1 < 0 || x - 1 < 0) continue;

      if (matrix[y - 1][x - 1] != matrix[y][x]) return false;
    }
  }

  return true;
}
```

## 고생한 점
