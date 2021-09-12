# 1937. Maximum Number of Points with Cost

[링크](https://leetcode.com/problems/maximum-number-of-points-with-cost/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 2차원 배열의 행의 개수를 N, 열의 개수를 M이라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(N \* M^2)가 되며 이는 제한시간 내에 불가능하다.

따라서 매 행마다 값을 갱신하기 위해 동적 계획법을 한번 더 사용해야 한다.

각 행에서 x좌표에 대한 최선의 값을 사용하기 위해 left-right DP를 이용한다.

이 경우 O(M)의 시간 복잡도로 최선의 값을 구할 수 있다.

따라서 시간 복잡도는 O(N \* M)이 된다.

### 공간 복잡도

각 points들에 대해서 dp배열을 만들 경우 필요한 공간 복잡도는 O(N \* M)이다.

그러나 매 경우마다 직전행만 필요하므로 이것만을 이용할 경우 공간 복잡도는 O(M)이다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     272      |  O(N \* M)  |  O(N \* M)  |

모든 points를 순회하며 아래 dp배열을 갱신한다.

```cpp
dp[y][x]; // y,x 좌표의 점을 선택했을 때 가질 수 있는 최대값
```

이 식의 일반식은 다음과 같다.

```cpp
dp[y][x] = max(dp[y][x], points[y][x] + dp[y-1][xx] - abs(x - xx)); // 모든 xx에 대하여
```

여기서 xx값을 모두 탐색할 경우 시간 복잡도는 O(N \* M^2)가 되며 이는 제한시간 내에 불가능하다.

따라서 현재 y,x 좌표의 값을 갱신할 때 left-right dp를 이용해 한번에 구할 수 있도록 한다.

필요한 정보는 다음 두가지 이다.

- x좌표
- 해당 x좌표까지 선택했을 때의 최대값

이 두가지값 중 x좌표는 이후 최대값을 갱신할 때 사용되므로 같이 저장한다.

먼저 left, right dp의 정의는 다음과 같다.

```cpp
left[x]; // 0 ~ x까지 순회했을 때 가질 수 있는 최대의 dp[y - 1][xx] + xx 값
right[x]; // x ~ 0까지 순회했으 떄 가질 수 있는 최대의 dp[y - 1][xx] - xx 값
```

여기서 각 값마다 index값을 더해주는 이유는 다음과 같다.

left, right 두 dp배열을 모두 갱신한 뒤에 각 x좌표마다 최선의 값을 구한다고 하자.

해당 값은 다음과 같이 구할 수 있다.

```cpp
dp[y][x] = points[y][x] + max(left[x] - x, right[x] + x);
```

이는 left배열의 값을 이용해 0 ~ x까지의 값들 중 최선의 값을 찾을 수 있고, right배열을 이용해 x ~ (M - 1)까지의 값들 중 최선의 값을 찾을 수 있기 때문이다.

이 때 각 값들을 갱신할 때 사용한 xx값과 x값의 차이가 abs(x - xx)가 되므로 식으로 나타내면 다음과 같다.

```cpp
left[x] - x = dp[y - 1][xx] + xx - x;
right[x] + x = dp[y - 1][xx] - xx + x;

// xx와 x를 이용해 abs(xx - x)를 구한다.
```

이를 매 rows마다 반복해 정답을 구할 수 있다.

```cpp
long long maxPoints(vector<vector<int>>& points) {
  int rows = points.size();
  int cols = points.front().size();

  vector<vector<long long>> dp(rows, vector<long long>(cols, 0));
  vector<long long> left(cols, 0), right(cols, 0);

  for (int x = 0; x < cols; x++) {
    dp[0][x] = points[0][x];
  }

  for (int y = 1; y < rows; y++) {
    fill(left.begin(), left.end(), 0);
    fill(right.begin(), right.end(), 0);

    left.front() = dp[y - 1].front();
    for (int x = 1; x < cols; x++) {
      left[x] = max(left[x - 1], dp[y - 1][x] + x);
    }

    right.back() = dp[y - 1].back() - (cols - 1);
    for (int x = cols - 2; x >= 0; x--) {
      right[x] = max(right[x + 1], dp[y - 1][x] - x);
    }

    for (int x = 0; x < cols; x++) {
      dp[y][x] = points[y][x] + max(left[x] - x, right[x] + x);
    }
  }

  long long answer = dp.back().front();
  for (long long& val : dp.back()) {
    answer = max(answer, val);
  }
  return answer;
}
```

## 고생한 점
