# 1351. Count Negative Numbers in a Sorted Matrix

[링크](https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

완전 탐색을 수행할 경우 O(R \* C)의 시간 복잡도를 사용한다.

각 행에 대해 이분 탐색을 수행할 경우 O(R \* log_2(C))의 시간 복잡도를 사용한다.

각 행과 열에 대해 정렬되어 있으므로 이를 이용해 행과 열에 대해서만 순회를 사용할 수 있다.

이 경우 시간 복잡도는 O(R + C)이다.

### 공간 복잡도

정답의 갯수를 저장할 공간이 필요하다. 이는 O(1)의 공간 복잡도를 사용한다.

### 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      11      | O(R \* log_2(C)) |    O(1)     |

주어진 배열은 행과 열에 대해 정렬되어 있으므로 각 행에 이분탐색으로 음수의 시작 위치를 알 수 있다.

이 때 내림차순 정렬되어 있으므로 음수의 갯수를 셀 때 주의한다.

```cpp
int getMinusCount(vector<int> &row) {
  int left = 0, right = row.size();
  int target = right;
  while (left < right) {
    int mid = left + (right - left) / 2;

    if (row[mid] < 0) {
      // pick left
      right = mid;
      target = mid;
    } else {
      // pick right
      left = mid + 1;
    }
  }

  return row.size() - target;
}

int countNegatives(vector<vector<int>> &grid) {
  int count = 0;

  for (vector<int> &row : grid) {
    count += getMinusCount(row);
  }

  return count;
}
```

### 행, 열 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      18      |  O(R + C)   |    O(1)     |

각 행과 열에 대해서 2차원 배열이 정렬되어 있다.

현재 행의 음수의 시작 위치를 x라 했을 때 다음 행의 음수의 시작 위치는 x보다 왼쪽에 있거나 같다.

따라서 각 행에 대해서 음수의 시작 위치를 직전 행의 시작 위치부터 탐색 가능하다.

```cpp
int countNegatives(vector<vector<int>> &grid) {
  int cols = grid.front().size();
  int count = 0;
  int rI = cols - 1;

  for (vector<int> &row : grid) {
    while (rI >= 0 && row[rI] < 0) {
      rI--;
    }
    count += (cols - (rI + 1));
  }
  return count;
}
```

## 고생한 점
