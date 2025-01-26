# 2852. Sum of Remoteness of All Cells

[링크](https://leetcode.com/problems/sum-of-remoteness-of-all-cells/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

BFS를 이용해 각 chunk를 구한다. 이를 이용해 각 cell마다 합을 구할 경우 O(R \* C)의 시간 복잡도가 필요하다.

### 공간 복잡도

BFS에 O(R \* C)의 공간 복잡도가 필요하다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      40      |  O(R \* C)  |  O(R \* C)  |

연결된 좌표들을 chunk라 하자.

모든 좌표의 합을 S라 하자. 특정 chunk에 속한 좌표의 합을 C라 하자.

특정 chunk에 속한 좌표의 합은 S - C이다. 이는 정답에 chunk의 크기만큼 더해지는 값이다.

따라서 모든 원소의 합을 구한 뒤 각 chunk의 크기와 합을 구한다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

long long sumRemoteness(vector<vector<int>>& grid) {
  int rows = grid.size(), cols = grid[0].size();

  long long allSum = 0;

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (grid[y][x] != -1) allSum += grid[y][x];
    }
  }
  long long answer = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (grid[y][x] == -1) continue;

      long long curSum = 0;

      queue<Axis> q;
      q.push({y, x});
      curSum += grid[y][x];
      grid[y][x] = -1;
      int size = 1;
      while (!q.empty()) {
        Axis cur = q.front();
        q.pop();

        for (Axis& dir : dirs) {
          Axis next = {cur.y + dir.y, cur.x + dir.x};

          if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
            continue;
          if (grid[next.y][next.x] == -1) continue;
          curSum += grid[next.y][next.x];
          size++;
          grid[next.y][next.x] = -1;
          q.push(next);
        }
      }

      answer += (allSum - curSum) * size;
    }
  }

  return answer;
}
```

## 고생한 점
