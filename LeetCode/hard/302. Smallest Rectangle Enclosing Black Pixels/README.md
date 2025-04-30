# 302. Smallest Rectangle Enclosing Black Pixels

[링크](https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C, 검은색 좌표의 수를 N라고 하자.

모든 경우를 탐색할 경우 O(R * C)의 시간 복잡도를 사용한다.

BFS를 사용할 경우 O(N)으로 줄일 수 있다.

이분 탐색을 사용할 경우 O(R \* log_2(C) + C \* log_2(R))의 시간 복잡도를 사용한다.

### 공간 복잡도

BFS를 사용할 경우 O(N)의 공간 복잡도를 사용한다.

이분 탐색을 사용할 경우 O(1)의 공간 복잡도를 사용한다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      7       |    O(N)     |    O(N)     |

시작 좌표부터 BFS를 사용하여 모든 검은색 좌표를 탐색한다.

이후 검은색 좌표의 가장 큰 y좌표, 가장 작은 y좌표, 가장 큰 x좌표, 가장 작은 x좌표를 구한다.

이후 y좌표의 차이와 x좌표의 차이를 구한 후, 두 값을 곱하여 결과를 반환한다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int minArea(vector<vector<char>>& image, int x, int y) {
  int yMax = INT_MIN, yMin = INT_MAX;
  int xMax = INT_MIN, xMin = INT_MAX;

  int rows = image.size(), cols = image[0].size();

  queue<Axis> q;
  image[x][y] = '0';
  q.push({x, y});
  while (!q.empty()) {
    Axis cur = q.front();
    q.pop();

    yMax = max(cur.y, yMax);
    yMin = min(cur.y, yMin);
    xMax = max(cur.x, xMax);
    xMin = min(cur.x, xMin);

    for (Axis& dir : dirs) {
      Axis next = {cur.y + dir.y, cur.x + dir.x};

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      if (image[next.y][next.x] == '0') continue;
      image[next.y][next.x] = '0';
      q.push(next);
    }
  }

  int yDiff = (yMax - yMin) + 1;
  int xDiff = (xMax - xMin) + 1;

  return yDiff * xDiff;
}
```

## 고생한 점
