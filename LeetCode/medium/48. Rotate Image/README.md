# 48. Rotate Image

[링크](https://leetcode.com/problems/rotate-image/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

모든 수를 시계방향으로 90도 회전시키기 위해선 N^2만큼의 시간 복잡도가 필요하다. (가로 세로 길이 모두 N 이므로)

따라서 시간 복잡도는 O(N^2)이다.

### 공간 복잡도

별도의 공간을 이용해 뒤집을 경우 O(N^2)만큼의 공간 복잡도가 필요하다.

중앙을 기준으로 4 점씩 옮길 경우 별도의 공간이 필요하지 않다.

2차원 행렬의 전치, 대칭을 이용할 경우 별도의 공간이 필요하지 않다.

### 회전 배열 만들기

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |   O(N^2)    |   O(N^2)    |

현재 좌표 y,x를 회전시킬 경우 도달하는 위치는 다음과 같다.

```javascript
const rotate = (y, x, size) => [x, size - y];
```

이 방법을 이용해 모든 위치의 값을 새로운 배열에 옮긴 뒤 새로운 배열로 덮어씌운다.

```cpp
void rotate(vector<vector<int>>& matrix) {
  int size = matrix.size();

  vector<vector<int>> rotatedMatrix(size, vector<int>(size));

  for (int y = 0; y < size; y++) {
    for (int x = 0; x < size; x++) {
      rotatedMatrix[x][size - 1 - y] = matrix[y][x];
    }
  }

  matrix = rotatedMatrix;
}
```

### 4점씩 이동

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |   O(N^2)    |    O(1)     |

중심점을 기준으로 회전할 4 구역별로 원소를 이동시킨다.

y,x좌표에서 중심점을 기준으로 거리가 같은(같은 거리로 떨어진) 좌표는 다음 4가지이다.

- y, x
- size - 1 - x, y
- size - 1 - y, size - 1 - x
- x, size - 1 - y

위 점들을 고르고 한꺼번에 이동시킨다.

4 분면에서 한 분면의 좌표만 탐색하면 된다.

```cpp
// size + 1인 경우는 홀수일 때 중앙을 같이 탐색하기 위함
for (int y = 0; y < (size + 1) / 2; y++)
  for (int x = 0; x < size / 2; x++)
```

```cpp
void rotate(vector<vector<int>>& matrix) {
  int size = matrix.size();
  for (int y = 0; y < (size + 1) / 2; y++) {
    for (int x = 0; x < size / 2; x++) {
      int temp = matrix[size - 1 - x][y];
      matrix[size - 1 - x][y] = matrix[size - 1 - y][size - 1 - x];
      matrix[size - 1 - y][size - 1 - x] = matrix[x][size - 1 - y];
      matrix[x][size - 1 - y] = matrix[y][x];
      matrix[y][x] = temp;
    }
  }
}
```

### 전치후 대칭

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |   O(N^2)    |    O(1)     |

행렬에서 전치 후 대칭을 할 경우 시계 방향으로 90도 회전한 것과 동일하다.

여기서 전치의 경우 y=x 선을 기준으로 좌표를 바꾸는 것이다.

대칭의 경우 y는 동일하고 x를 기준으로 대칭한다.

```cpp
void rotate(vector<vector<int>>& matrix) {
  transpose(matrix);
  reflect(matrix);
}
void transpose(vector<vector<int>>& matrix) {
  int size = matrix.size();

  for (int y = 0; y < size; y++) {
    for (int x = y; x < size; x++) {
      swap(matrix[x][y], matrix[y][x]);
    }
  }
}
void reflect(vector<vector<int>>& matrix) {
  int size = matrix.size();

  for (int y = 0; y < size; y++) {
    for (int x = 0; x < size / 2; x++) {
      swap(matrix[y][x], matrix[y][size - x - 1]);
    }
  }
}
```

## 고생한 점
