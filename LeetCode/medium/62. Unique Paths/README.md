# 62. Unique Paths

[링크](https://leetcode.com/problems/unique-paths/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

정답이 2 \* 10^9보다 작은것이 보장된다.

브루트 포스 방법을 수행할 경우 시간 초과가 발생한다.

따라서 동적 계획법을 이용해 이전 결과를 이용해 최적화해 문제를 풀이한다.

이 경우 시간 복잡도는 O(N \* M) 이다.

수학을 이용할 경우 조합(permutation)을 이용해 문제를 풀이할 수 있다.

이 경우 팩토리얼을 계산해야 하므로 시간 복잡도는 약 O(N)이 소요된다. (N이 M보다 큰 경우)

### 공간 복잡도

동적 계획법을 수행하는 경우 이전 계산 결과를 저장해야 하므로 O(N \* M)의 공간 복잡도가 필요하다.

이 때, 이를 최적화 할 수 있으므로 O(N)의 공간으로도 동적 계획법을 사용할 수 있다.

조합을 이용할 경우 별도의 공간이 필요하지 않다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N \* M)  |    O(N)     |

현재 좌표 y,x를 방문하는 경우의 수의 일반식은 다음과 같다.

```cpp
dp[y][x] = dp[y-1][x] + dp[y][x-1];
```

맨 처음 초기값은 다음과 같다.

```cpp
dp[0][i] = 1;
dp[i][0] = 1;
```

이를 이용해 맨 마지막 지점까지 도달하는 경우의 수를 구할 수 있다.

```cpp
int uniquePaths(int m, int n) {
  int dp[100][100] = {
      0,
  };

  for (int i = 0; i < n; i++) {
    dp[0][i] = 1;
  }
  for (int i = 0; i < m; i++) {
    dp[i][0] = 1;
  }

  for (int y = 1; y < m; y++) {
    for (int x = 1; x < n; x++) {
      dp[y][x] += dp[y - 1][x] + dp[y][x - 1];
    }
  }

  return dp[m - 1][n - 1];
}
```

여기서 계산에 필요한 행은 2행 뿐이므로 다음과 같이 공간복잡도를 최적화 할 수 있다.

```cpp
int uniquePaths(int m, int n) {
  int dp[2][100] = {
      0,
  };

  for (int i = 0; i < n; i++) {
    dp[0][i] = 1;
  }
  dp[0][0] = dp[1][0] = 1;

  for (int y = 1; y < m; y++) {
    for (int x = 1; x < n; x++) {
      dp[y % 2][x] = dp[(y - 1) % 2][x] + dp[y % 2][x - 1];
    }
  }

  return dp[(m - 1) % 2][n - 1];
}
```

### 조합

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

> N은 M보다 크다고 가정한다.

n, m크기의 배열이 주어졌을 때 로봇이 이동하는 횟수는 n-1 + m-1 번이다.

여기서 아래로 이동과 오른쪽으로 이동을 섞는 경우의 수를 구하면 된다.

- N` = N - 1
- M` = M - 1

이라고 가정하자.

이 경우 조합의 갯수는

(N`+M`)! / (N`! * M`!) 이다.

팩토리얼을 직접 계산할 경우 overflow가 발생하므로 나눠서 계산한다.

```cpp
int uniquePaths(int m, int n) {
  if (m == 1 || n == 1) {
    return 1;
  }

  m--;
  n--;
  if (m < n) {
    swap(m, n);
  }

  long ret = 1;
  for (int denominator = m + 1, molecule = 1; denominator <= m + n; denominator++, molecule++) {
    ret *= denominator;
    ret /= molecule;
  }

  return (int)ret;
}
```

## 고생한 점
