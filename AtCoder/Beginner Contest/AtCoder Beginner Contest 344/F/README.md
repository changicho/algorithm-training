# F - Earn to Advance

[링크](https://atcoder.jp/contests/abc344/tasks/abc344_f)

| 난이도 |
| :----: |
|  550   |

## 설계

### 시간 복잡도

입력받은 2차원 배열의 크기를 N^2라 하자.

동적 계획법을 사용해 이전 좌표에서 현재 좌표로 올 때의 최적값을 구할 수 있다.

이 경우 O(N^4)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법을 사용할 경우 O(N^2)의 공간 복잡도가 필요하다.

계산 식에서 int형을 초과할 수 있으므로 long long형을 선언한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      62      |   O(N^4)    |   O(N^2)    |

시작점에서 현재 좌표까지 경로를 path라 하자.

만약 현재 좌표에서 다음 좌표로 넘어갈 때 필요한 비용이 현재 가진 돈보다 많은 경우 path의 이전 좌표에서 대기하며 돈을 벌어야 한다.

이 때 가장 많은 돈을 벌 수 있는 좌표에서 대기하는 편이 유리하다.

path를 순회하며 가장 많은 돈을 벌 수 있는 값을 maximum이라 하자.

따라서 비용이 돈보다 더 많은 경우 maximum에서 대기하며 돈을 벌며 동작 횟수를 증가시킨다.

각 path마다 path의 maximum이 다를 수 있으므로 좌표와 maximum에 대해서 동적 계획법을 수행한다.

이 때 maximum의 경우의 수는 이전까지 지나온 좌표의 갯수이므로 다음과 같은 dp를 사용할 수 있다.

```cpp
pair<long long, long long> dp[fromY][fromX][toY][toX]; // (fromY, fromX)가 maximum일때 (toY, toX)로 가는 최소 동작 횟수, 남은 돈
```

이 때 최소 동작 횟수와 남은 돈에 대한 dp식을 생성하며 다음과 같은 순으로 판단한다.

- 동작 횟수가 적은 순
- 남은 돈이 많은 순

이를 이용해 동적 계획법을 수행한다.

```cpp
struct Status {
  long long step, money;
};

long long solution(vector<vector<int>> &powers, vector<vector<int>> &rights,
                   vector<vector<int>> &downs) {
  int size = powers.size();

  vector<vector<Status>> dp(size, vector<Status>(size, {LLONG_MAX, 0}));

  dp[0][0] = {0, 0};

  for (int curY = 0; curY < size; ++curY) {
    for (int curX = 0; curX < size; ++curX) {
      vector<vector<long long>> costs(curY + 1,
                                      vector<long long>(curX + 1, LLONG_MAX));

      costs[curY][curX] = 0;

      for (int y = curY; y >= 0; y--) {
        for (int x = curX; x >= 0; x--) {
          if (y < curY) {
            costs[y][x] = min(costs[y][x], downs[y][x] + costs[y + 1][x]);
          }
          if (x < curX) {
            costs[y][x] = min(costs[y][x], rights[y][x] + costs[y][x + 1]);
          }

          long long stay =
              max(0LL, (long long)ceil((double)(costs[y][x] - dp[y][x].money) /
                                       powers[y][x]));

          int distance = curY - y + curX - x;
          long long step = dp[y][x].step + stay + distance;
          long long money = dp[y][x].money + stay * powers[y][x] - costs[y][x];

          if (step < dp[curY][curX].step ||
              (step == dp[curY][curX].step && money > dp[curY][curX].money)) {
            dp[curY][curX] = {step, money};
          }
        }
      }
    }
  }

  long long answer = dp[size - 1][size - 1].step;

  return answer;
}
```

## 고생한 점
