# 1428. Leftmost Column with at Least a One

[링크](https://leetcode.com/problems/leftmost-column-with-at-least-a-one/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

행의 개수를 N, 열의 개수를 M이라 하자.

브루트 포스 방법을 수행할 경우 시간 복잡도는 O(N \* M)이며 이는 get을 1000번 이상 호출할 수 있으므로 적합하지 않다.

이분 탐색을 이용할 경우 모든 행을 순회하며 열에 대해 이분탐색을 수행하므로 시간 복잡도는 O(N \* log_2(M))이다.

그리디 알고리즘을 사용할 경우 시간 복잡도는 O(N + M)이다.

### 공간 복잡도

이분탐색, 그리디 알고리즘의 경우 별도의 2차원 배열 값 또는 배열의 값을 저장할 필요가 없으므로 공간 복잡도는 O(1)이다.

### 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      13      | O(N \* log_2(M)) |    O(1)     |

각 row들은 0과 1이 정렬되어있다.

각 row에서 최초로 나타나는 1의 위치 중 가장 왼쪽의 위치를 찾아야한다.

이는 각 row마다 이분탐색을 통해 찾을 수 있다.

```cpp
int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
  vector<int> dimensions = binaryMatrix.dimensions();
  int rows = dimensions.front();
  int cols = dimensions.back();

  int answer = cols;
  for (int row = 0; row < rows; row++) {
    int left = 0, right = cols - 1;
    int target = -1;

    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (binaryMatrix.get(row, mid) == 1) {
        right = mid - 1;
        answer = min(mid, answer);
      } else {
        left = mid + 1;
      }
    }
  }

  if (answer == cols) return -1;
  return answer;
}
```

### 그리디 알고리즘

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      13      | O(N \* log_2(M)) |    O(1)     |

move only left and down

맨 처음 가장 오른쪽 위 좌표에서 시작한다.

현재 값이 0인 경우는 다음 줄로 넘어가고 1인 경우는 가장 왼쪽 위치를 찾기 위해 왼쪽으로 이동한다.

이는 이전에 1을 찾은 경우, 다음 rows들에서 오른쪽 값들은 무시하기 위함이며 1을 찾을 때 마다 range를 좁히는 방식이다.

```cpp
int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
  vector<int> dimensions = binaryMatrix.dimensions();
  int rows = dimensions.front();
  int cols = dimensions.back();

  int currentRow = 0;
  int currentCol = cols - 1;

  while (currentRow < rows && currentCol >= 0) {
    if (binaryMatrix.get(currentRow, currentCol) == 0) {
      currentRow++;
    } else {
      currentCol--;
    }
  }

  if (currentCol == cols - 1) return -1;
  return currentCol + 1;
}
```

## 고생한 점
