# 1010. 다리 놓기

[링크](https://www.acmicpc.net/problem/1010)

|  난이도  | 정답률(\_%) | 시간 제한(초) |
| :------: | :---------: | :-----------: |
| Silver V |   48.496    |      0.5      |

## 설계

### 시간 복잡도

강의 서쪽과 동쪽에 있는 사이트의 개수 정수 N, M은 최대 30까지이다.

경우의 수를 구하는 문제이며, 모든 경우를 탐색 했을때, 정답의 최대 값은 M : 15, N : 30일 때이며 이는 30! / 15! 이다.

이는 제한시간 내에 불가능하다.

따라서 동적 계획법을 이용해 이전 경우를 이용한다.

### 공간 복잡도

30! / 15!가 정답의 최대 경우이며 이는 2^20 가량이다.

따라서 long long형으로 선언한다.

### 파스칼의 삼각형

N개중 K개를 순서상관없이 고른 경우의 수를 구하는 문제이다.

combination을 구하는 문제이며, nCk= n-1Ck-1 + n-1Ck 공식을 이용한다.

임계값은 k == n 혹은 k == 0 일 때이다.

메모이제이션 배열은 다음과 같다.

```cpp
long long memo[n][k]; // nCk 의 값
```

일반식은 다음과 같다.

```cpp
memo[n][k] = memo[n - 1][k - 1] + memo[n - 1][k];
```

초기값은 다음과 같다.

```cpp
memo[i][i] = 1; // 모든 i에 대해
memo[i][0] = 1; // 모든 i에 대해
```

따라서 다음과 같은 combination을 구하는 함수를 생성한다.

```cpp
long long combination(int n, int k) {
  if (memo[n][k] != 0) {
    return memo[n][k];
  }

  if (k == 0 || n == k) {
    memo[n][k] = 1;
    return 1;
  }

  // case_choose + case_not_choose
  long long sum = combination(n - 1, k - 1) + combination(n - 1, k);
  memo[n][k] = sum;

  return sum;
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
