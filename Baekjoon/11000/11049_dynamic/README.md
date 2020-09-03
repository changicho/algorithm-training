# 11049. 행렬 곱셈 순서

[링크](https://www.acmicpc.net/problem/11049)

|  난이도  | 정답률(\_%) |
| :------: | :---------: |
| Gold III |   43.598    |

## 설계

### 시간 복잡도

행렬의 개수는 최대 500까지이다.

모든 경우를 탐색해 보는경우 2^500 번 가량의 연산이 필요하므로 제한시간 내에 불가능하다.

따라서 동적 계획법을 이용해 풀이한다.

### 공간 복잡도

연산의 횟수의 크기는 2^31-1 보다 작으므로 int형으로 선언한다.

### 점화식

i는 행렬 시작위치, j는 행렬 끝 위치라 했을 때,

```cpp
dp[i][j] = dp[i][k] + dp[k+1][j] + m[i].r * m[k].c * m[j].c;
```

여기서 dp[i][j]가 구해지지 않은 경우 구해야 하므로, dynamic(i,j)를 호출한다.

### dp를 재귀로 구하는 법

```cpp
int dynamic(int i, int j) {
  if (i == j) return 0;
  if (i + 1 == j) return m[i].r * m[i].c * m[j].c;

  if (dp[i][j] != -1) return dp[i][j];

  int &pointer = dp[i][j];
  for (int k = i; k < j; k++) {
    int temp = dynamic(i, k) + dynamic(k + 1, j) + m[i].r * m[k].c * m[j].c;
    if (pointer == -1 || pointer > temp) {
      pointer = temp;
    }
  }

  return dp[i][j];
}
```

### dp를 반복문으로 구하는 법

```cpp
for (int i = 1; i<N; i++) {
  for (int j = 1; j<N; j++) {
    int f = j;
    int t = j + i;
    if (t>N) break;

    int currentValue = 1 << 30;
    for (int k = f + 1; k <= t; k++) {
      int temp = dp[f][k - 1] + dp[k][t] + m[f].r * m[k].r * m[t].c;
      if (temp < currentValue) currentValue = temp;
    }
    dp[f][t] = currentValue;
  }
}
```

반복문으로 구하는 경우 맨처음 초기화를 할 필요가 없으므로 더 빠르다.

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      40      |       0        |

## 고생한 점
