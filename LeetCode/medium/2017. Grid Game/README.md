# 2017. Grid Game

[링크](https://leetcode.com/problems/grid-game/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

grid의 열의 갯수를 N이라 하자. 행의 갯수는 2로 고정이다.

한번 내려갈 경우 다시는 내려갈 수 없다 따라서 첫번째 로봇의 경로의 경우의 수는 N개이다.

첫번째 로봇의 경로가 고정될 경우 두번째 로봇이 얻을 수 있는 점수 또한 고정된다.

첫번째 로봇의 경로마다 합을 빠르게 구하기 위해 prefix sum을 사용할 수 있다. 이에 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

prefix sum을 사용할 경우 O(N)의 공간 복잡도가 필요하다.

이를 순회하며 갱신할 경우 O(1)의 공간 복잡도가 필요하다.

### prefix sum

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

로봇들은 0,0 에서 오른쪽 맨 아래 좌표까지 이동하며 방향은 좌, 하 두가지이다.

두 로봇의 경로는 `하`로 이동 한번에 나머지는 좌로이동으로 구성된다.

첫번째 로봇의 `하`로 이동한 경로를 순차적으로 탐색하며 이 때 두번째 로봇이 얻을 수 있는 최대값을 구한다. 이 중 최소값을 반환한다.

각 로봇의 경로를 빠르게 탐색하기 위해 prefix sum을 사용한다.

```cpp
long long gridGame(vector<vector<int>>& grid) {
  int cols = grid[0].size();

  long long sum1 = accumulate(grid[0].begin(), grid[0].end(), 0LL);
  long long sum2 = accumulate(grid[1].begin(), grid[1].end(), 0LL);

  long long cur1 = 0;
  long long cur2 = 0;

  long long answer = LONG_LONG_MAX;

  for (int x = 0; x < cols; x++) {
    cur1 += grid[0][x];
    long long cur = cur1 + sum2 - cur2;

    long long choose2 = max(sum1 - cur1, cur2);
    answer = min(answer, choose2);

    cur2 += grid[1][x];
  }
  return answer;
}
```

## 고생한 점
