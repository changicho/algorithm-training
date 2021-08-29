# 311. Sparse Matrix Multiplication

[링크](https://leetcode.com/problems/sparse-matrix-multiplication/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2 벡터의 크기의 값을 각각 N, K, M이라 하자.

2차원 벡터의 곱을 구하기 위해 필요한 연산의 횟수는 N \* K \* M 이므로 시간 복잡도는 O(N \* K \* M)이다.

### 공간 복잡도

N \* M 크기의 2차원 배열이 필요하다. 따라서 필요한 공간 복잡도는 O(N \* M) 이다.

### 벡터의 곱 계산

| 내 코드 (ms) |  시간 복잡도   | 공간 복잡도 |
| :----------: | :------------: | :---------: |
|      55      | O(N \* K \* M) |  O(N \* M)  |

벡터의 곱을 다음과 같이 계산할 수 있다.

```cpp
for (int y = 0; y < m; y++) {
  for (int x = 0; x < n; x++) {
    for (int i = 0; i < k; i++) {
      ret[y][x] += mat1[y][i] * mat2[i][x];
    }
  }
}
```

```cpp
vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
  int m = mat1.size();
  int k = mat1.front().size();
  int n = mat2.front().size();

  vector<vector<int>> ret(m, vector<int>(n, 0));

  for (int y = 0; y < m; y++) {
    for (int x = 0; x < n; x++) {
      for (int i = 0; i < k; i++) {
        ret[y][x] += mat1[y][i] * mat2[i][x];
      }
    }
  }

  return ret;
}
```

### 벡터의 곱 backtracking

| 내 코드 (ms) |  시간 복잡도   | 공간 복잡도 |
| :----------: | :------------: | :---------: |
|      4       | O(N \* K \* M) |  O(N \* M)  |

만약 모든 행, 또는 열이 0인 경우에는 벡터의 곱을 계산할 때 어차피 0이 되므로 무시할 수 있다.

따라서 mat1의 경우는 행의 값이 모두 0인 경우, mat2의 경우 열의 값이 모두 0인 경우를 미리 구하고 계산할 때 사용한다.

```cpp
vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
  int rows1 = mat1.size(), cols1 = mat1[0].size();
  int rows1 = mat2.size(), cols2 = mat2[0].size();

  vector<bool> isZeros1(rows1, true), isZeros2(cols2, true);

  for (int y = 0; y < rows1; ++y) {
    bool isZero = true;
    for (int x = 0; x < cols1; ++x) {
      if (mat1[y][x] != 0) {
        isZero = false;
        break;
      }
    }
    isZeros1[y] = isZero;
  }

  for (int x = 0; x < cols2; ++x) {
    bool isZero = true;
    for (int y = 0; y < rows1; ++y) {
      if (mat2[y][x] != 0) {
        isZero = false;
        break;
      }
    }
    isZeros2[x] = isZero;
  }

  vector<vector<int>> res(rows1, vector<int>(cols2, 0));

  for (int y = 0; y < rows1; ++y) {
    if (isZeros1[y]) continue;

    for (int x = 0; x < cols2; ++x) {
      if (isZeros2[x]) continue;

      int sum = 0;
      for (int k = 0; k < cols1; ++k) {
        sum += mat1[y][k] * mat2[k][x];
      }
      res[y][x] = sum;
    }
  }
  return res;
}
```

## 고생한 점
