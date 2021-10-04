# 279. Perfect Squares

[링크](https://leetcode.com/problems/perfect-squares/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

N까지 모든 경우에 대해서 탐색 할 경우 인자로 가능한 개수는 sqrt(N)개 이다.

이 수에 대해서 모두 반복할 경우 최악의 경우 시간 복잡도는 O(sqrt(N)^N)개 이므로 이는 제한시간 내에 불가능하다.

따라서 동적 계획법을 이용해 풀이한다.

동적 계획법을 이용할 경우 현재 N에 대해서 이전에 구한 N값들 모두를 탐색할 경우 시간 복잡도는 O(N^2)이다. 이는 제한 시간 내에 불가능하다 (10^8 이므로)

문제에서는 제곱수의 합의 최소를 구하므로 현재 dp를 구할 때 제곱 수에 대해서만 탐색한다.

이 경우 시간 복잡도는 O(N \* sqrt(N))이므로 제한시간 내에 풀이할 수 있다.

### 공간 복잡도

N까지의 값들에 대한 dp배열을 생성해야 하므로 O(N)의 공간 복잡도가 필요하다.

### 동적 계획법

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|     216      | O(N \* sqrt(N)) |    O(N)     |

현재 수 X에 대한 perfect squares 값을 다음과 같이 나타낸다고 하자.

```cpp
dp[x]; // x의 perfect squares
```

현재 x에 대한 값을 구할 때 이전의 dp값들을 이용할 수 있다.

```cpp
for(int part = 1; part <= x / 2; part++){
  dp[x] = min(dp[x], dp[x - part] + dp[part]);
}
```

그러나 이 경우는 시간 복잡도가 O(N^2)가 되므로 제한시간 내에 불가능하다.

따라서 모든 part에 대해서 탐색하지 않고, part의 제곱들에 대해서만 탐색을 진행한다.

(1^2 = 1이므로 x-1일때의 dp값에 1을 더한 값을 가질 수 있다.)

따라서 일반 식은 다음과 같다.

```cpp
for (int part = 1; part * part <= cur; ++part) {
  dp[cur] = min(dp[cur], dp[cur - part * part] + 1);
}
```

초기값은 다음과 같다.

```cpp
dp[0] = 0;
dp[1] = 1;
```

이를 이용해 풀이할 경우 다음과 같다.

```cpp
int numSquares(int n) {
  vector<int> dp(n + 1, 0);

  for (int cur = 1; cur <= n; ++cur) {
    dp[cur] = cur;

    for (int part = 1; part * part <= cur; ++part) {
      dp[cur] = min(dp[cur], dp[cur - part * part] + 1);
    }
  }

  return dp[n];
}
```

### static vector

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|      3       | O(N \* sqrt(N)) |    O(N)     |

위 풀이법에서 static vector를 사용할 경우 매우 빠르게 풀이 가능하다.

```cpp
int numSquares(int n) {
  static vector<int> dp(1, 0);

  while (dp.size() <= n) {
    int cur = dp.size();
    int value = cur;

    for (int part = 1; part * part <= cur; ++part) {
      value = min(value, dp[cur - part * part] + 1);
    }

    dp.emplace_back(value);
  }

  return dp[n];
}
```

### BFS

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|      18      | O(N \* sqrt(N)) |    O(N)     |

현재 수에서 다음 수로 넘어갈 때 가장 정답에 근접하게 탐색하기 위해서는 제곱수들을 더한 값들을 다음 수로 설정해야한다.

따라서 이에 대해서 BFS로 탐색해 최선의 값을 구할 수 있다.

```cpp
int numSquares(int n) {
  vector<int> squares;
  vector<int> dp(n + 1, 0);

  // init
  for (int cur = 1; cur * cur <= n; cur++) {
    squares.push_back(cur * cur);
    dp[cur * cur] = 1;
  }

  if (squares.back() == n) {
    return 1;
  }

  queue<int> q;
  for (int& i : squares) {
    q.push(i);
  }

  int step = 1;
  int answer = -1;
  while (!q.empty() && answer == -1) {
    step++;

    int size = q.size();

    while (answer == -1 && size--) {
      int cur = q.front();

      for (int& part : squares) {
        if (cur + part == n) {
          answer = step;
          break;
        }

        if (cur + part > n) {
          break;
        }

        if (dp[cur + part] == 0) {
          dp[cur + part] = step;

          q.push(cur + part);
        }
      }

      q.pop();
    }
  }

  return answer;
}
```

## 고생한 점
