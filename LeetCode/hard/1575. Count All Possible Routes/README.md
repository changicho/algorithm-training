# 1575. Count All Possible Routes

[링크](https://leetcode.com/problems/count-all-possible-routes/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 locations의 크기를 N, fuel의 크기를 F라 하자.

모든 경우를 탐색할 경우 매우 많은 경우가 생길 수 있으므로 제한시간 내에 불가능하다.

따라서 동적 계획법을 이용한다.

남은 연료에 따라서 이동할 수 있는 경우의 수가 제한되므로, 연료와 현재 위치를 이용해 dp배열을 선언한다.

이 경우 각 연료마다 경로의 경우를 탐색하는데 O(N^2)의 시간 복잡도를 사용하므로 최종 시간 복잡도는 O(N^2 \* F) 이다.

### 공간 복잡도

동적 계획법을 사용하는 데 O(N \* F)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     701      | O(N^2 \* F) |  O(N \* F)  |

현재 남은 연료에 따라서 도달할 수 있는 경우는 제한된다.

따라서 현재 남은 연료를 f라 할 때, 두 도시에서 이동 가능한지를 판단하며 dp배열을 갱신한다.

다음과 같은 dp배열을 선언한다.

```cpp
// definition
int dp[city][fuel]; // the number of possible routes starting from the city with fuel

// init
// all finish city can be reached with any fuel
for (int f = 0; f <= fuel; f++) {
  dp[finish][f] = 1;
}

// update
// when reachable
int remainFuel = f - abs(locations[from] - locations[to]);
dp[from][f] = (dp[from][f] + dp[to][remainFuel]) % MOD;
```

이를 이용해 다음과 같이 구현할 수 있다.

```cpp
int MOD = 1e9 + 7;

int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
  int size = locations.size();
  // dp[city][fuel];
  // the number of possible routes starting from the city with fuel
  int dp[101][201] = {
      0,
  };

  for (int f = 0; f <= fuel; f++) {
    dp[finish][f] = 1;
  }

  for (int f = 0; f <= fuel; f++) {
    for (int from = 0; from < size; from++) {
      for (int to = 0; to < size; to++) {
        if (to == from) continue;

        if (abs(locations[from] - locations[to]) <= f) {
          int remainFuel = f - abs(locations[from] - locations[to]);
          dp[from][f] = (dp[from][f] + dp[to][remainFuel]) % MOD;
        }
      }
    }
  }

  return dp[start][fuel];
}
```

## 고생한 점
