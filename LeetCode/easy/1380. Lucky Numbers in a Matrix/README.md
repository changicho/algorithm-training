# 1380. Lucky Numbers in a Matrix

[링크](https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

모든 좌표에 대해 직접 탐색할 경우 O(R^2 \* C^2)의 시간 복잡도가 필요하다.

각 행, 열마다의 최소값과 최대값을 구하고 이를 이용해 풀이할 경우 O(R \* C)의 시간 복잡도가 필요하다.

### 공간 복잡도

각 행, 열마다 최소값과 최대값을 구할 경우 O(R + C)의 공간 복잡도를 사용한다.

정답에 O(R \* C)의 공간 복잡도를 사용한다.

### two pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |  O(R \* C)  |  O(R \* C)  |

각 행, 열마다의 최소값과 최대값을 구한다.

이후 각 좌표를 순회하며 해당 좌표의 값이 정답에 해당하는지 판단한다.

```cpp
vector<int> luckyNumbers(vector<vector<int>>& matrix) {
  int rows = matrix.size(), cols = matrix[0].size();

  vector<int> rowMins(rows, INT_MAX);
  vector<int> colMaxs(cols, INT_MIN);

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      rowMins[y] = min(rowMins[y], matrix[y][x]);
      colMaxs[x] = max(colMaxs[x], matrix[y][x]);
    }
  }

  vector<int> answer;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      int cur = matrix[y][x];

      if (rowMins[y] == cur && colMaxs[x] == cur) {
        answer.push_back(cur);
      }
    }
  }
  return answer;
}
```

## 고생한 점
