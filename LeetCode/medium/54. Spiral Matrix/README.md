# 54. Spiral Matrix

[링크](https://leetcode.com/problems/spiral-matrix/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

결국 모든 요소를 순회하므로 시간 복잡도는 O(N \* M) 이다. (N은 세로길이, M은 가로길이)

### 공간 복잡도

방문 배열을 이용할 경우 별도의 공간이 O(N \* M) 만큼 필요하다.

방문 배열을 이용하지 않을 경우 별도의 공간이 필요하지 않다.

### 방문 배열을 이용

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N \* M)  |  O(N \* M)  |

matrix의 크기와 같은 크기의 방문 배열을 만들고 범위를 초과하거나, 이전에 방문한 좌표를 방문할 때마다 방향을 바꾼다.

이 순회는 row \* col 번 만큼만 일어난다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

vector<int> spiralOrder(vector<vector<int>>& matrix) {
  int row = matrix.size();
  int col = matrix[0].size();
  int dirIdx = 0;
  Axis dir = dirs[dirIdx];
  Axis cur = {0, 0};

  vector<int> answer;
  vector<vector<bool>> visited(row, vector<bool>(col));

  int limit = row * col;
  for (int i = 0; i < limit; i++) {
    answer.push_back(matrix[cur.y][cur.x]);
    visited[cur.y][cur.x] = true;

    Axis next = cur;
    next.y += dir.y;
    next.x += dir.x;

    if (0 > next.y || row <= next.y || 0 > next.x || col <= next.x || visited[next.y][next.x]) {
      dirIdx = (dirIdx + 1) % 4;
      dir = dirs[dirIdx];

      next = cur;
      next.y += dir.y;
      next.x += dir.x;
    }

    cur = next;
  }

  return answer;
}
```

### 테두리 이동

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N \* M)  |  O(N \* M)  |

테두리들을 순회하며 수를 채워나간다.

이 때 테두리영역별로 채우다가 중간에 모든 점을 방문할 수 있으므로 매번 체크해준다.

```cpp
vector<int> spiralOrder(vector<vector<int>>& matrix) {
  int row = matrix.size();
  int col = matrix[0].size();
  Axis cur = {0, -1};

  vector<int> answer;

  int limit = row * col;
  while (answer.size() < limit) {
    for (int i = 0; i < col; i++) {
      cur.x += 1;
      answer.push_back(matrix[cur.y][cur.x]);
    }
    if (answer.size() == limit) break;

    for (int i = 0; i < row - 1; i++) {
      cur.y += 1;
      answer.push_back(matrix[cur.y][cur.x]);
    }
    if (answer.size() == limit) break;

    for (int i = 0; i < col - 1; i++) {
      cur.x -= 1;
      answer.push_back(matrix[cur.y][cur.x]);
    }
    if (answer.size() == limit) break;

    for (int i = 0; i < row - 2; i++) {
      cur.y -= 1;
      answer.push_back(matrix[cur.y][cur.x]);
    }
    if (answer.size() == limit) break;

    col -= 2;
    row -= 2;
  }

  return answer;
}
```

## 고생한 점
