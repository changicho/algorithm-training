# 2209. Minimum White Tiles After Covering With Carpets

[링크](https://leetcode.com/problems/minimum-white-tiles-after-covering-with-carpets/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

floor의 길이를 N, numCarpets의 값을 K라고 하자.

모든 경우를 시도해볼 경우 O(2^N \* N)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

동적 계획법을 이용해 이전의 결과를 사용하고 풀이할 수 있다. 이 경우 O(N \* K)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법을 사용할 경우 O(N \* K)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     1080     |  O(N \* K)  |  O(N \* K)  |

문제에서 고려해야할 경우의 수의 대상은 다음 2가지이다.

- floor의 길이
- carpet의 갯수

따라서 다음과 같은 2차원 동적 계획법을 사용할 수 있다.

```cpp
dp[n][k]; // the minimum number of white tiles when cover the first n tiles using k carpet
```

앞에 현재 왼쪽에서 부터 n개의 타일을 보고있고, k개의 carpet을 사용한 경우의 보이는 타일의 갯수이다.

현재 위치에서 dp값은 다음 2가지 중 하나이다.

- 카페트를 사용하지 않은 경우
- 카페트를 사용한 경우

여기서 일반식은 다음과 같이 정의할 수 있다.

```cpp
int jump = dp[i - 1][k] + (floor[i - 1] == '1' ? 1 : 0);
int cover = dp[max(i - carpetLen, 0)][k - 1];

dp[i][k] = min(cover, jump);
```

이전 위치에서 carpet을 사용하지 않은 경우는 현재 위치의 타일의 상황에 따라 dp값이 정의된다.

만약 현재 위치에서 carpet을 사용한 경우, 앞의 carpetLength만큼의 원소는 무조건 가려지므로 이전의 dp값을 사용한다.

초기값은 다음과 같다.

```cpp
// 0개의 타일을 보고있는경우
dp[0][k] = 0;
```

이를 이용해 구현하면 다음과 같다.

```cpp
int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
  int size = floor.size();

  // dp[n][k]
  // the minimum number of white tiles when cover
  // the first n tiles using k carpet
  vector<vector<int>> dp(size + 1, vector<int>(numCarpets + 1, 0));

  for (int i = 1; i <= size; i++) {
    dp[i][0] = dp[i - 1][0] + (floor[i - 1] == '1' ? 1 : 0);

    for (int k = 1; k <= numCarpets; k++) {
      int jump = dp[i - 1][k] + (floor[i - 1] == '1' ? 1 : 0);
      int cover = dp[max(i - carpetLen, 0)][k - 1];

      dp[i][k] = min(cover, jump);
    }
  }
  return dp[size][numCarpets];
}
```

## 고생한 점
