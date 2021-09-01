# 994. Rotting Oranges

[링크](https://leetcode.com/problems/rotting-oranges/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

행의 개수를 N, 열의 개수를 M이라 하자.

썩은 오렌지는 시간이 지날수록 4방향에 인접한 오렌지를 썩게만든다.

썩은 오렌지를 찾기 위해 O(N \* M)의 시간 복잡도를 사용한다.

결과적으로 썩은 오렌지에서부터 탐색을 이어나가므로 시간 복잡도는 O(N \* M)이다.

### 공간 복잡도

입력받은 grid에서 썩은 오렌지를 시뮬레이션 하면 되므로 별도의 공간 복잡도가 필요하지 않다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |  O(N \* M)  |    O(1)     |

처음 배열을 순회하며 썩은 오렌지의 위치와 일반 오렌지의 개수를 파악한다.

이후 썩은 오렌지들부터 BFS를 이용해 단계적으로 탐색한다.

일반 오렌지가 썩을 때마다 남은 일반 오렌지의 수를 변경한다.

이후 탐색을 완료한 뒤 일반 오렌지의 수가 0인지 아닌지를 판별한다.

```cpp
int orangesRotting(vector<vector<int>>& grid) {
  int rows = grid.size();
  int cols = grid.front().size();

  queue<Axis> q;
  int remain = 0;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (grid[y][x] == 1)
        remain += 1;
      else if (grid[y][x] == 2)
        q.push({y, x});
    }
  }

  int time = 0;
  while (!q.empty()) {
    int size = q.size();

    while (size--) {
      Axis cur = q.front();
      q.pop();

      for (Axis dir : dirs) {
        Axis next = {cur.y + dir.y, cur.x + dir.x};

        if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
          continue;
        if (grid[next.y][next.x] != 1) continue;

        grid[next.y][next.x] = 2;
        q.push(next);
        remain -= 1;
      }
    }
    time += 1;
  }

  if (remain > 0) return -1;
  return max(time - 1, 0);
}
```

## 고생한 점
