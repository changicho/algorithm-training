# 1886. Determine Whether Matrix Can Be Obtained By Rotation

[링크](https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

2차원 배열의 크기를 N^2라 하자.

회전을 4번 수행하며 직접 회전시킬 경우 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

새 공간을 만들어 회전할 경우 O(N^2)의 공간 복잡도를 사용한다.

기존 공간을 사용할 경우 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |   O(N^2)    |    O(1)     |

```cpp
pair<int, int> moveNext(pair<int, int> pos, int rows, int cols) {
  int y = pos.first, x = pos.second;
  return {x, rows - y - 1};
}

void rotate(vector<vector<int>>& mat) {
  int rows = mat.size(), cols = mat[0].size();

  for (int y = 0; y < rows; y++) {
    for (int x = y; x < cols - y - 1; x++) {
      int temp = mat[y][x];
      pair<int, int> pos = {y, x};

      for (int d = 0; d < 4; d++) {
        pair<int, int> next = moveNext(pos, rows, cols);
        int before = temp;
        temp = mat[next.first][next.second];
        mat[next.first][next.second] = before;
        pos = next;
      }
    }
  }
}

bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
  for (int d = 0; d < 4; d++) {
    if (mat == target) {
      return true;
    }
    rotate(mat);
  }
  return false;
}
```

## 고생한 점
