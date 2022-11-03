# 1706. Where Will the Ball Fall

[링크](https://leetcode.com/problems/where-will-the-ball-fall/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

grid의 행의 갯수를 R, 열의 갯수를 C라 하자.

하나의 시작점에 대해 시뮬레이션을 수행할 경우 O(R)의 시간 복잡도를 사용한다.

이를 모든 x좌표에 대해 수행할 경우 O(R \* C)의 시간 복잡도를 사용한다.

### 공간 복잡도

시뮬레이션을 수행하는데 O(1)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      71      |  O(R \* C)  |    O(1)     |

현재 좌표를 (y,x)라 하자.

현재 좌표의 grid의 종류에 따라 다음 3가지 경우가 존재한다.

- 현재 좌표 1, 오른쪽 좌표 1 : 오른쪽 아래로 이동
- 현재 좌표 -1, 왼쪽 좌표 -1 : 왼쪽 아래로 이동
- 그 외의 경우 : 아래로 이동 불가

이를 이용해 각 시작점 x마다 시뮬레이션을 통해 도착점을 찾는다.

```cpp
vector<int> findBall(vector<vector<int>>& grid) {
  int rows = grid.size(), cols = grid.front().size();

  vector<int> answer(cols, -1);
  for (int start = 0; start < cols; start++) {
    int y = 0, x = start;

    while (y < rows) {
      if (grid[y][x] == 1 && x + 1 < cols && grid[y][x + 1] == 1) {
        y++;
        x += 1;
        continue;
      }
      if (grid[y][x] == -1 && x - 1 >= 0 && grid[y][x - 1] == -1) {
        y++;
        x -= 1;
        continue;
      }

      break;
    }

    if (y == rows) answer[start] = x;
  }
  return answer;
}
```

## 고생한 점
