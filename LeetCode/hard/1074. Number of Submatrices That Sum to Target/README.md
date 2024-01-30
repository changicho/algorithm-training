# 1074. Number of Submatrices That Sum to Target

[링크](https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

모든 range를 탐색할 경우 시간 복잡도는 O(R^2 \* C^2)이다.

각 range를 직접 탐색할 경우 O(R \* C)의 시간 복잡도를 사용한다. 이는 총 O(R^3 \* C^3)의 시간 복잡도를 사용하므로 제한시간 내에 불가능하다.

prefix sum을 이용해 각 행마다의 누적합을 미리 구해 사용할 경우 합을 구하는 데 O(1)의 시간 복잡도를 사용한다.

range를 탐색할 때 열의 범위 range를 고정하고 행을 순회하며 풀이할 수 있다.

이 경우 O(R \* C^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

직접 모든 경우를 구할 경우 O(1)의 공간 복잡도를 사용한다.

누적합을 이용할 경우 O(R \* C)의 공간 복잡도를 사용한다.

### 누적합

| 내 코드 (ms) |  시간 복잡도  | 공간 복잡도 |
| :----------: | :-----------: | :---------: |
|     298      | O(R^2 \* C^2) |  O(R \* C)  |

다음과 같은 2차원 prefixSum을 생성한다.

```cpp
int prefixSum[y + 1][x + 1]; // (0,0) ~ (y,x) 까지의 누적합
```

prefixSum을 미리 모두 구한 뒤 모든 범위 range에 대해 탐색을 진행한다.

```cpp
int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
  int rows = matrix.size(), cols = matrix[0].size();

  vector<vector<int>> prefixSum(rows + 1, vector<int>(cols + 1, 0));
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      prefixSum[y + 1][x + 1] += prefixSum[y][x + 1] + prefixSum[y + 1][x] -
                                  prefixSum[y][x] + matrix[y][x];
    }
  }

  int answer = 0;

  for (int y1 = 0; y1 < rows; y1++) {
    for (int y2 = y1; y2 < rows; y2++) {
      for (int x1 = 0; x1 < cols; x1++) {
        for (int x2 = x1; x2 < cols; x2++) {
          int curSum = prefixSum[y2 + 1][x2 + 1] - prefixSum[y1][x2 + 1] -
                        prefixSum[y2 + 1][x1] + prefixSum[y1][x1];
          if (curSum == target) answer++;
        }
      }
    }
  }
  return answer;
}
```

### 누적합 (fix column)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     423      | O(R \* C^2) |  O(R \* C)  |

위 방법에서 prefix sum을 구할 때 이전 행까지 나온 누적합을 알고 있다면 현재 행의 누적합을 구할 때 이를 이용하는것을 알 수 있다.

이 때 이전 행에서 나온 누적합과 현재 행에서 나온 누적 합의 차이가 target인 경우 정답에 추가한다.

이를 이용해 x1 ~ x2까지 범위를 고정한 상태에서 y에 대해 순회하며 각 합들의 차이가 target인 경우를 찾는다.

각 행마다의 누적 합이 필요하므로 이를 미리 구해놓는다.

```cpp
int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
  int rows = matrix.size(), cols = matrix[0].size();
  for (int y = 0; y < rows; y++) {
    for (int x = 1; x < cols; x++) {
      matrix[y][x] += matrix[y][x - 1];
    }
  }

  int answer = 0;

  // fix x1 ~ x2
  for (int x1 = 0; x1 < cols; x1++) {
    for (int x2 = x1; x2 < cols; x2++) {
      // sum, count
      unordered_map<int, int> count;
      count[0] = 1;

      int curSum = 0;
      for (int y = 0; y < rows; y++) {
        curSum += matrix[y][x2] - (x1 > 0 ? matrix[y][x1 - 1] : 0);

        if (count.find(curSum - target) != count.end()) {
          answer += count[curSum - target];
        }
        count[curSum]++;
      }
    }
  }
  return answer;
}
```

## 고생한 점
