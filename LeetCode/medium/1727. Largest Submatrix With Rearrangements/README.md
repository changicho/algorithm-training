# 1727. Largest Submatrix With Rearrangements

[링크](https://leetcode.com/problems/largest-submatrix-with-rearrangements/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

각 좌표를 행마다 순회하며 연속된 최대 높이들을 구한 후 정렬한뒤 현재 최대값을 갱신할 수 있다.

이에 O(C \* log_2(C))의 시간 복잡도를 사용한다.

이를 매 행마다 반복하므로 O(R \* C \* log_2(C))의 시간 복잡도를 사용한다.

### 공간 복잡도

각 행을 정렬시 별도의 공간이 필요하다. 이는 O(C)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |      시간 복잡도      | 공간 복잡도 |
| :----------: | :-------------------: | :---------: |
|     158      | O(R \* C \* log_2(C)) |    O(C)     |

각 열마다의 최대 높이를 매 행마다 갱신한다.

이후 각 행마다 계산한 열들의 최대 높이들을 내림차순으로 정렬할 경우 현재 행까지의 최대 높이는 다음과 같다.

- 현재 열의 높이 \* (왼쪽에 존재하는 높이들의 갯수 + 1)

이는 현재 높이 왼쪽에는 현재값 이상의 값들이 존재하며 이를 이용해 면적을 갱신할 수 있기 때문이다.

이를 반복하며 매 행마다의 높이들을 갱신 후 정답을 구한다.

```cpp
int largestSubmatrix(vector<vector<int>>& matrix) {
  int rows = matrix.size();
  int cols = matrix[0].size();
  int answer = 0;

  for (int y = 0; y < rows; y++) {
    if (y > 0) {
      for (int x = 0; x < cols; x++) {
        if (matrix[y][x] == 0) continue;

        matrix[y][x] += matrix[y - 1][x];
      }
    }

    vector<int> curRow = matrix[y];
    sort(curRow.begin(), curRow.end(), greater());
    for (int x = 0; x < cols; x++) {
      answer = max(answer, curRow[x] * (x + 1));
    }
  }

  return answer;
}
```

## 고생한 점
