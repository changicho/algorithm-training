# 74. Search a 2D Matrix

[링크](https://leetcode.com/problems/search-a-2d-matrix/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

N은 행의 갯수, M은 열의 갯수이다. 이는 각각 최대 100까지이다.

모든 요소를 탐색하는 경우 시간 복잡도는 O(N \* M)가 소요된다.

모든 요소가 정렬되어 있으므로 이분 탐색을 이용해 값이 존재하는지 찾을 수 있다. 이 경우 O(log_2(N + M))의 시간 복잡도가 소요된다.

또한 모든 요소가 정렬되어있음을 이용해 좌표이동으로 찾을 수 있다. 이 경우 시간 복잡도는 O(N + M)이다.

### 공간 복잡도

세 방법 모두 상수만큼의 공간이 필요하므로 공간 복잡도는 O(1)이다.

### y축 탐색 후 이분 탐색

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|      0       | O(N + log_2(M)) |    O(1)     |

해당 값이 있을만한 y축을 찾은 뒤에, 찾은 행에서 이분탐색으로 값을 찾는다.

값이 존재하는 지 여부는 upper_bound와 lower_bound를 이용해 찾을 수 있다.

```cpp
bool searchMatrix(vector<vector<int>>& matrix, int target) {
  int rows = matrix.size();
  int cols = matrix.front().size();

  int target_row = -1;
  for (int y = 0; y < rows; y++) {
    if (matrix[y].front() <= target && target <= matrix[y].back()) {
      target_row = y;
      break;
    }
  }

  if (target_row == -1) return false;

  if (upper_bound(matrix[target_row].begin(), matrix[target_row].end(), target) - lower_bound(matrix[target_row].begin(), matrix[target_row].end(), target) >= 1) return true;

  return false;
}
```

### 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      4       | O(log_2(N \* M)) |    O(1)     |

해당 좌표들을 index로 나타낼 경우 index를 다음과 같이 나타낼 수 있다.

```cpp
index = cols * y + x;

y = index / cols;
x = index % cols;
```

이를 이용해 이차원 배열을 일차원 배열을 이분 탐색하는것 처럼 문제를 풀이할 수 있다.

```cpp
bool searchMatrix(vector<vector<int>>& matrix, int target) {
  int rows = matrix.size();
  int cols = matrix.front().size();

  int left = 0;
  int right = cols * rows - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    int y = mid / cols;
    int x = mid % cols;

    if (matrix[y][x] == target) {
      return true;
    } else if (matrix[y][x] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return false;
}
```

### 좌표 이동

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |  O(N + M)   |    O(1)     |

배열의 요소들은 정렬되어 있으므로 y좌표, x좌표를 이동하며 target을 찾을 수 있다.

이 때 두 좌표 모두 0에서 시작할 경우 값을 증가할 때 y, x중 어떤 값을 증가시킬지 판단하기 어려우므로

x는 맨 마지막 좌표에서 감소하며 값을 찾는다.

```cpp
bool searchMatrix(vector<vector<int>>& matrix, int target) {
  if (matrix.empty()) return false;

  int rows = matrix.size();
  int cols = matrix.front().size();
  int y = 0, x = cols - 1;

  while (y < rows && x >= 0) {
    if (matrix[y][x] == target) {
      return true;
    } else if (matrix[y][x] > target) {
      x--;
    } else if (matrix[y][x] < target) {
      y++;
    }
  }

  return false;
}
```

## 고생한 점

이 문제에서 이분탐색에서 target을 찾은 경우에는 탈출하도록 구성해야 한다.
