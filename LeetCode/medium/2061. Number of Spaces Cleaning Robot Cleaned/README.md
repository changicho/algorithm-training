# 2061. Number of Spaces Cleaning Robot Cleaned

[링크](https://leetcode.com/problems/number-of-spaces-cleaning-robot-cleaned/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

시뮬레이션을 이용할 경우 O(R \* C)의 시간 복잡도를 사용한다.

### 공간 복잡도

시뮬레이션에 방문 여부를 체크해야 하므로 O(R \* C)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      40      |  O(R \* C)  |  O(R \* C)  |

시작 위치부터 시뮬레이션을 수행한다.

이 때 같은 좌표를 다른 방향으로 방문할 수 있으므로 방문 여부를 체크할 때 방향 또한 고려한다.

만약 중복 방문인 경우 더이상 탐색을 진행하지 않는다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int numberOfCleanRooms(vector<vector<int>>& room) {
  int rows = room.size(), cols = room[0].size();

  int dir = 0;

  bool visited[300][300][4] = {
      false,
  };
  Axis cur = {0, 0};
  while (visited[cur.y][cur.x][dir] == false) {
    visited[cur.y][cur.x][dir] = true;

    Axis d = dirs[dir];
    Axis next = {cur.y + d.y, cur.x + d.x};

    // change
    if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols ||
        room[next.y][next.x] == 1) {
      dir = (dir + 1) % 4;
      continue;
    }

    cur = next;
  }

  int answer = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      answer += visited[y][x][0] || visited[y][x][1] || visited[y][x][2] ||
                visited[y][x][3];
    }
  }
  return answer;
}
```

## 고생한 점
