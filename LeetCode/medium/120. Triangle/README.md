# 120. Triangle

[링크](https://leetcode.com/problems/triangle/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

삼각형의 높이를 N이라고 하자.

모든 경우를 탐색할 때 시간 복잡도는 2^N 정도이므로 이는 제한시간 내에 불가능하다.

따라서 동적 계획법을 이용해 시간 복잡도를 최적화한다.

이 경우 모든 요소를 한번 순회만 하면 되므로 시간 복잡도는 O(N^2)이다.

### 공간 복잡도

모든 요소에 대해 메모이제이션을 수행할 수 있다. 이 경우 O(N^2)의 공간 복잡도가 필요하다.

혹은 현재 갱신할 line에 대해서만 메모이 제이션을 수행한다.

이 경우 공간 복잡도는 O(N)이다.

### 동적 계획법 O(N^2)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |   O(N^2)    |   O(N^2)    |

dp 배열을 다음과 같이 생성한다.

```cpp
dp[y][x]; // 끝나는 점이 y, x일 때 경로를 지나는 값들의 합의 최소
```

이 경우 초기값은 다음과 같다.

```cpp
dp[0][0] = triangle[0][0];
```

일반식은 다음과 같다.

현재 좌표에서의 dp값은 대각선 왼쪽 위 혹은 바로 위에서 내려오는 값 중 하나를 선택한 경우이다.

```cpp
// 양 끝의 경우
// x = 0
dp[y][0] = triangle[y][0] + dp[y-1][0];
// x = y
dp[y][x] = triangle[y][x] + dp[y-1][x-1];

// 그 외의 경우
dp[y][x] = triangle[y][x] + min(dp[y-1][x-1], dp[y-1][x]);
```

```cpp
int minimumTotal(vector<vector<int>>& triangle) {
  int size = triangle.size();
  vector<vector<int>> dp(size, vector<int>(size, 0));

  dp[0][0] = triangle[0][0];

  for (int y = 1; y < size; y++) {
    dp[y][0] = triangle[y][0] + dp[y - 1][0];
    for (int x = 1; x < y; x++) {
      dp[y][x] = triangle[y][x] + min(dp[y - 1][x - 1], dp[y - 1][x]);
    }
    dp[y][y] = triangle[y][y] + dp[y - 1][y - 1];
  }

  int answer = dp[size - 1][0];
  for (int val : dp[size - 1]) answer = min(answer, val);
  return answer;
}
```

### 동적 계획법 O(N)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |   O(N^2)    |    O(N)     |

위 방법에서 모든 경우에 대한 dp값을 구하지 않고 이전 값만을 이용해 현재값을 만들 수 있다.

따라서 현재 값을 생성하기 위해 직전 값만을 저장하며, 이를 같은 공간에 저장해 공간복잡도를 향상할 수 있다.

이 때 일반항은 다음과 같다.

```cpp
// 양 끝의 경우
// x = 0
dp[0] = triangle[y][0] + dp[0];
// x = y
dp[x] = triangle[y][x] + dp[x-1];

// 그 외의 경우
dp[x] = triangle[y][x] + min(dp[x-1], dp[x]);
```

일반항에서 현재 값을 구할 때 x-1, x의 값을 이용하므로 x를 증가하며 갱신하는것이 아닌 감소하며 갱신해야 한다.

이는 증가하는 순으로 값을 갱신했을 때 다음 값이 현재 값을 참조해 갱신하려 하기 떄문이다.

```cpp
int minimumTotal(vector<vector<int>>& triangle) {
  int size = triangle.size();
  vector<int> dp(size, 0);

  dp[0] = triangle[0][0];

  for (int y = 1; y < size; y++) {
    dp[y] = triangle[y][y] + dp[y - 1];
    for (int x = y - 1; x > 0; x--) {
      dp[x] = triangle[y][x] + min(dp[x - 1], dp[x]);
    }
    dp[0] = triangle[y][0] + dp[0];
  }

  int answer = dp[0];
  for (int val : dp) answer = min(answer, val);
  return answer;
}
```

## 고생한 점
