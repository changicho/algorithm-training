# 59. Spiral Matrix II

[링크](https://leetcode.com/problems/spiral-matrix-ii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

전체 공간을 채우기 위해서 모두 순회를 한번씩 해야한다.

이 때 시간 복잡도는 O(N^2)이 소요된다.

### 공간 복잡도

전체 공간을 채우면서 변수 외에 별도의 공간을 사용하지 않는다. 따라서 공간 복잡도는 O(1) 이다.

### 한칸씩 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |   O(N^2)    |    O(1)     |

시작 위치에서 한칸씩 전진하며 모든 공간을 채워나간다.

방향을 바꾸어야 하는 경우는 다음과 같다.

- 다음 위치가 범위를 초과했을 때
- 다음 위치에 이미 숫자가 존재할때

```cpp
vector<vector<int>> generateMatrix(int n) {
  vector<vector<int>> matrix(n, vector<int>(n, 0));

  int dirIdx = 0;
  int limit = n * n;
  Axis cur = {0, 0};
  Axis dir = dirs[dirIdx];

  for (int number = 1; number <= limit; number++) {
    matrix[cur.y][cur.x] = number;

    Axis next = cur;
    next.y += dir.y;
    next.x += dir.x;
    bool needRotate = false;

    if ((next.y < 0 || next.y >= n || next.x < 0 || next.x >= n)) {
      needRotate = true;
    } else if (matrix[next.y][next.x] != 0) {
      needRotate = true;
    }

    if (needRotate) {
      dirIdx = (dirIdx + 1) % 4;
      dir = dirs[dirIdx];

      next = cur;
      next.y += dir.y;
      next.x += dir.x;
    }

    cur = next;
  }

  return matrix;
}
```

### layer 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |   O(N^2)    |    O(1)     |

테두리 layer별로 채우는 방법을 사용할 수도 있다.

테두리 layer의 갯수는 짝수일 경우 n/2개, 홀수일 경우 (n+1)/2개가 생성된다.

테두리를 4분면으로 나눴을 떄 길이는 각각 다음과 같다.

- 위쪽 : n - 2 \* layer
- 오른쪽 : n - 2 \* layer - 1
- 아래쪽 : n - 2 \* layer - 1
- 왼쪽 : n - 2 \* layer - 2

```cpp
vector<vector<int>> generateMatrix(int n) {
  vector<vector<int>> matrix(n, vector<int>(n));

  int number = 1;
  for (int layer = 0; layer < (n + 1) / 2; layer++) {
    // from left to right
    for (int index = layer; index < n - layer; index++) {
      matrix[layer][index] = number;
      number++;
    }
    // from top to bottom
    for (int index = layer + 1; index < n - layer; index++) {
      matrix[index][n - layer - 1] = number;
      number++;
    }
    // from right to left
    for (int index = n - layer - 2; index >= layer; index--) {
      matrix[n - layer - 1][index] = number;
      number++;
    }
    // from bottom to top
    for (int index = n - layer - 2; index > layer; index--) {
      matrix[index][layer] = number;
      number++;
    }
  }

  return matrix;
}
```

## 고생한 점
