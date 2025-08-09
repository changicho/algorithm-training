# 1198. Find Smallest Common Element in All Rows

[링크](https://leetcode.com/problems/find-smallest-common-element-in-all-rows/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

각 행마다 중복되는 값이 없으므로, 모든 값들을 순회하며 count하고 이를 셀 수 있다.

이 경우 순회에 O(R \* C)의 시간 복잡도를 사용한다.

각 행은 정렬되어있으므로 이분 탐색을 사용할 수 있다.

이 경우 O(R \* log_2(C))의 시간 복잡도를 사용한다.

### 공간 복잡도

카운팅을 수행할 경우 범위가 최대 10^5 이므로 O(1)의 공간 복잡도를 사용한다.

이분 탐색에 O(1)의 공간 복잡도를 사용한다.

### 카운팅

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     117      |  O(R \* C)  |    O(1)     |

```cpp
int smallestCommonElement(vector<vector<int>> &mat) {
  int rows = mat.size(), cols = mat.front().size();

  int counts[10001] = {
      0,
  };
  int answer = INT_MAX;
  for (vector<int> &row : mat) {
    for (int &num : row) {
      counts[num]++;

      if (counts[num] == rows) {
        answer = min(num, answer);
      }
    }
  }

  if (answer == INT_MAX) return -1;
  return answer;
}
```

### 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      0       | O(R \* log_2(C)) |    O(1)     |

각 행의 원소들은 정렬되어 있으므로 특정 원소를 이분 탐색을 이용해 찾을 수 있다.

```cpp
int smallestCommonElement(vector<vector<int>> &mat) {
  int rows = mat.size(), cols = mat[0].size();

  int answer = -1;
  for (int x = 0; x < cols && answer == -1; x++) {
    bool found = true;
    int target = mat[0][x];

    for (int y = 1; y < rows && found; y++) {
      int i =
          lower_bound(mat[y].begin(), mat[y].end(), target) - mat[y].begin();
      if (i == cols || mat[y][i] != target) {
        found = false;
        break;
      }
    }

    if (found) {
      answer = target;
    }
  }
  return answer;
}
```

## 고생한 점
