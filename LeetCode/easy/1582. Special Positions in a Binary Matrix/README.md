# 1582. Special Positions in a Binary Matrix

[링크](https://leetcode.com/problems/special-positions-in-a-binary-matrix/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

각 행, 열 별로 1의 갯수를 구해 각 좌표마다 비교할 수 있다. 이 시간 복잡도는 O(R \* C)이다.

### 공간 복잡도

각 행과 열에 대한 갯수를 저장할 배열이 필요하다. 이 배열의 크기는 O(R + C)이다.

### 카운팅

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      18      |  O(R \* C)  |  O(R + C)   |

각 행, 열마다 1의 갯수를 구한다.

이후 각 좌표마다 각 행과 열에 1의 갯수가 1인 좌표를 구한다.

```cpp
int numSpecial(vector<vector<int>>& mat) {
  int rows = mat.size(), cols = mat[0].size();

  vector<int> rowCounts(rows, 0), colCounts(cols, 0);

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      rowCounts[y] += mat[y][x];
      colCounts[x] += mat[y][x];
    }
  }

  int answer = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (mat[y][x] == 1 && rowCounts[y] == 1 && colCounts[x] == 1) {
        answer++;
      }
    }
  }
  return answer;
}
```

## 고생한 점
