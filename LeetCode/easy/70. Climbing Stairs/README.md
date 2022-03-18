# 70. Climbing Stairs

[링크](https://leetcode.com/problems/climbing-stairs/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

N은 최대 45 이다. 매 경우마다 DFS를 통해 탐색을 진행할 경우 시간 복잡도는 O(2^N)이다.

이는 제한시간 내에 불가능하므로 dp를 이용한다.

dp를 이용할 경우 한번의 순회로 풀이가 가능하다. 따라서 시간 복잡도는 O(N)이다.

### 공간 복잡도

dp를 이용할 경우 이전 연산 결과가 필요하므로 N크기의 배열을 선언한다.

정답은 int형임이 보장되므로 int형 배열을 선언한다.

공간에 최적화된 dp를 사용할 경우 O(1)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

초기값은 다음과 같다.

```cpp
dp[1] = 1;
dp[2] = 2;
```

일반식은 다음과 같다.

```cpp
dp[n] = dp[n-1] + dp[n-2];
```

이는 다음과 같이 증명 가능하다.

N번째에 도달하는 경우의 수는, N-2번째에서 2칸 올라오는 경우 + N-1번째에서 1칸 올라오는 경우 이다.

이를 구현하면 다음과 같다.

```cpp
int climbStairs(int n) {
  vector<int> dp(45);  // dp[n - 1] : count of n steps
  dp[0] = 1;
  dp[1] = 2;

  for (int i = 2; i < n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  return dp[n - 1];
}
```

### 동적 계획법 (space optimized)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

위 식에서 현재값을 구하기위해 사용하는 값은 1개전, 2개전 값 2가지이다.

따라서 두 값만 저장하고 사용해 정답을 구한다.

```cpp
int climbStairs(int n) {
  if (n == 1) {
    return 1;
  } else if (n == 2) {
    return 2;
  }

  int oneAgo = 2, twoAgo = 1;

  for (int i = 2; i < n; i++) {
    int cur = oneAgo + twoAgo;
    twoAgo = oneAgo;
    oneAgo = cur;
  }

  return oneAgo;
}
```

### 브루트 포스

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     TLE      |   O(2^N)    |    O(N)     |

직접 탐색을 수행해 풀이할 수 있다.

이 경우 시간 복잡도는 O(2^N) 이다.

```cpp
int climbStairs(int n) {
  return recursive(0, n);
}
int recursive(int i, int n) {
  if (i > n) {
    return 0;
  }
  if (i == n) {
    return 1;
  }
  return recursive(i + 1, n) + recursive(i + 2, n);
}
```

## 고생한 점
