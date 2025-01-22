# 2661. First Completely Painted Row or Column

[링크](https://leetcode.com/problems/first-completely-painted-row-or-column/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

좌표 배열의 크기를 N, 2차원 배열의 크기를 R \* C라고 하자.

각 좌표의 값들을 미리 저장해 놓은 뒤 좌표 배열을 순회하며 표시할 수 있다.

이 때 매번 행, 열이 완성되는지 판단할 경우 O(R \* C)의 시간 복잡도가 소요된다.

각 행, 열에 방문 횟수를 count할 경우 O(1)의 시간 복잡도로 해결이 가능하다.

따라서 총 시간 복잡도는 O(R \* C)이다. 여기에 좌표를 순회하는 데 O(N)의 시간 복잡도가 추가된다.

### 공간 복잡도

각 좌표마다 값을 저장하는데 O(R \* C)의 공간 복잡도가 필요하다.

각 행, 열마다 방문된 좌표의 수를 저장하는 데 O(R + C)의 공간 복잡도가 필요하다.

### 행, 열 방문횟수 카운트

| 내 코드 (ms) |  시간 복잡도  | 공간 복잡도 |
| :----------: | :-----------: | :---------: |
|      4       | O(R \* C + N) |  O(R \* C)  |

2차원 배열 mat의 원소마다의 좌표를 저장한다.

이후 arr을 순회하며 방문한 값의 좌표를 빠르게 탐색한다.

이 때 각 좌표의 행, 열에 해당하는 방문 횟수를 증가시키며, 만약 행, 열이 완성되었을 때의 index를 반환한다.

```cpp
struct Axis {
  int y, x;
};

int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
  int rows = mat.size(), cols = mat[0].size();

  vector<Axis> um(rows * cols + 1);
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      um[mat[y][x]] = {y, x};
    }
  }

  vector<int> rowCounts(rows, 0);
  vector<int> colCounts(cols, 0);

  int size = arr.size();
  for (int i = 0; i < size; i++) {
    Axis cur = um[arr[i]];

    rowCounts[cur.y]++;
    colCounts[cur.x]++;

    if (rowCounts[cur.y] == cols) return i;
    if (colCounts[cur.x] == rows) return i;
  }
  return -1;
}
```

## 고생한 점
