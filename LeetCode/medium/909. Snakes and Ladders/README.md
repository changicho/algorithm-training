# 909. Snakes and Ladders

[링크](https://leetcode.com/problems/snakes-and-ladders/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 2차원 배열의 한쪽 길이를 N이라 하자.

2차원 배열의 크기는 N^2이다.

처음 공간부터 시작해 다음 위치로 BFS를 이용해 이동할 수 있다.

이때 BFS를 이용해 적은 count로만 움직일 경우 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

BFS를 이용할 경우 O(N^2)의 공간 복잡도를 사용한다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      20      |   O(N^2)    |   O(N^2)    |

입력받은 board의 각 값을 index로 바로 접근하기 위해 1차원 배열로 변환한다.

이 때 시작점이 (rows-1, 0)임에 유의한다 (index 기준)

이후 시작점에서 부터 BFS를 이용해 다음 칸으로 넘어간다.

현재 위치에서 1 ~ 6칸을 더한 경우로 움직일 수 있으므로 각 좌표마다 해당 경우로 움직인다.

이 때 뱀이나 사다리를 만난 경우는 해당 위치가 아닌 연결된 위치로 이동한다.

각 과정에서 최소 count를 갱신하고, 갱신할 수 없는 경우 이동하지 않는다.

```cpp
int snakesAndLadders(vector<vector<int>>& board) {
  int rows = board.size(), cols = board.front().size();

  vector<int> values;
  for (int y = rows - 1; y >= 0; y--) {
    if ((rows - 1 - y) % 2 == 0) {
      for (int x = 0; x < cols; x++) {
        values.push_back(board[y][x]);
      }
    } else {
      for (int x = cols - 1; x >= 0; x--) {
        values.push_back(board[y][x]);
      }
    }
  }

  vector<int> dp(rows * cols, INT_MAX);

  queue<int> q;
  q.push(0);
  dp[0] = 0;

  int step = 0;
  while (!q.empty()) {
    int i = q.front();
    q.pop();

    for (int j = 1; j <= 6; j++) {
      int next = i + j;
      if (next >= rows * cols) break;

      if (values[next] != -1) {
        int target = values[next] - 1;

        if (dp[target] > dp[i] + 1) {
          q.push(target);
          dp[target] = min(dp[target], dp[i] + 1);
        }
      } else {
        if (dp[next] > dp[i] + 1) {
          q.push(next);
          dp[next] = min(dp[next], dp[i] + 1);
        }
      }
    }
  }

  return dp.back() == INT_MAX ? -1 : dp.back();
}
```

## 고생한 점
