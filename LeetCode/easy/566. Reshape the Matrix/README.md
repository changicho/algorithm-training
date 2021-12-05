# 566. Reshape the Matrix

[링크](https://leetcode.com/problems/reshape-the-matrix/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 원소의 개수를 N이라 하자.

만약 배열의 크기를 변환시킬 때 새로운 배열의 크기도 O(N)이며, 이를 채워야 하므로 O(N)의 시간복잡도로 순회를 해야한다.

이 때 기존 배열의 원소에 대해서 index를 이용해 다음 값을 찾을 수도, queue를 이용해 순서대로 값을 방문할 수도 있다.

두 방법 모두 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

새로운 정답 배열을 생성하는 데 O(N)의 공간 복잡도를 사용한다.

### index mod, divide

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      17      |    O(N)     |    O(N)     |

만약 입력받은 r, c크기의 배열을 생성하지 못하는 경우 기존 mat을 반환해야 한다.

새로운 matrix newMatrix를 선언한 뒤 y, x좌표를 순차적으로 순회한다.

이후 해당 좌표에 해당하는 값에 넣을 mat의 값의 순서를 담당할 index 변수를 생성한다.

현재 좌표에 들어갈 값은 index번째 숫자이므로, mat의 (index / c, index % c) 좌표의 값을 옮긴다.

이후 index를 증가시킨다.

```cpp
vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
  int rows = mat.size();
  int cols = mat.front().size();

  if (rows * cols != r * c) return mat;

  vector<vector<int>> newMatrix(r, vector<int>(c));
  int index = 0;

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      newMatrix[index / c][index % c] = mat[y][x];
      index++;
    }
  }

  return newMatrix;
}
```

### queue

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |    O(N)     |    O(N)     |

위에선 index를 이용해서 값을 순차적으로 순회했다면 queue를 이용해 값을 순차적으로 순회할 수 있다.

이 경우 queue에 O(N)의 공간 복잡도를 추가적으로 사용하지만, 전체 공간 복잡도에 큰 영향을 주지 않는다.

```cpp
vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
  int rows = mat.size();
  int cols = mat.front().size();

  if (rows * cols != r * c) return mat;

  vector<vector<int>> newMatrix(r, vector<int>(c));
  queue<int> q;

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      q.push(mat[y][x]);
    }
  }

  for (int y = 0; y < r; y++) {
    for (int x = 0; x < c; x++) {
      newMatrix[y][x] = q.front();
      q.pop();
    }
  }

  return newMatrix;
}
```

## 고생한 점
