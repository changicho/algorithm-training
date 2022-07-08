# 2326. Spiral Matrix IV

[링크](https://leetcode.com/problems/spiral-matrix-iv/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 M, 열의 갯수를 N이라 하자.

현재 좌표에 현재 노드의 값을 순회하며 채워넣으면 된다.

이 경우 시간 복잡도는 O(N \* M)이다.

### 공간 복잡도

반환할 2차원 배열에 O(N \* M)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     460      |  O(N \* M)  |  O(N \* M)  |

좌표를 나타내는 객체와, 방향을 나타내는 객체 배열을 생성한다.

한방향으로 회전하므로 현재 방향 index부터 순차적으로 증가하고 순회하도록 구성한 뒤 회전을 구현한다.

이후 head를 순회하며 현재 좌표에 값을 채우며 좌표를 이동시킨다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

vector<vector<int>> spiralMatrix(int m, int n, ListNode *head) {
  vector<vector<int>> matrix(m, vector<int>(n, -1));

  Axis cur = {0, 0};
  int dir = 0;

  while (head) {
    matrix[cur.y][cur.x] = head->val;
    head = head->next;

    Axis next = {cur.y + dirs[dir].y, cur.x + dirs[dir].x};
    // change dir
    if (next.y < 0 || next.y >= m || next.x < 0 || next.x >= n ||
        matrix[next.y][next.x] != -1) {
      dir = (dir + 1) % 4;
      next = {cur.y + dirs[dir].y, cur.x + dirs[dir].x};
    }
    cur = next;
  }
  return matrix;
}
```

## 고생한 점
