# 11062. 카드 게임

[링크](https://www.acmicpc.net/problem/11062)

|  난이도  | 정답률(\_%) | 시간 제한(초) |
| :------: | :---------: | :-----------: |
| Gold III |   44.728    |       1       |

## 설계

### 시간 복잡도

카드의 개수 N은 최대 1,000 이다.

모든 경우를 탐색할 경우 시간 복잡도는 O(2^1,000) 이며 이는 제한시간 내에 불가능하다.

따라서 동적 계획법을 이용해 문제를 풀이한다.

### 공간 복잡도

카드에 적혀있는 수는 10,000 이하이다.

점수의 최대치는 1,000 \* 10,000 이므로 10^7 이다. 이는 int형으로 충분하다.

### 동적계획법

다음과 같은 dp 배열을 선언한다.

```cpp
int dp[start][end] // 남은 카드뭉치가 start ~ end 범위일때 가질 수 있는 합계의 최대값
```

초기값은 다음과 같다.

```cpp
dp[i][i] = cards[i];
```

점화식은 다음과 같다.

```cpp
// 현재 상황에서 앞의 카드를 상대방이 가져갈지, 뒤에 카드를 상대방이 가져갈지
dp[start][end] = max(sum - dp[start + 1][end], sum - dp[start][end - 1];
```

여기서 sum은 남은 카드뭉치들의 합이다.

이 sum을 구하기 위해 메모이제이션을 사용한다.

```cpp
int sum[index]; // index번째 까지의 카드의 합

for (int i = 1; i <= N; i++) {
  cin >> cards[i];
  sums[i] = sums[i - 1] + cards[i];
}
```

### bottom-up 방식

start ~ end 번째 까지의 dp를 구하면 된다.

size(end - start)의 크기를 키워가며 dp배열을 갱신한다.

```cpp
for (int index = 1; index <= N; index++) {
  dp[index][index] = cards[index];
}

for (int size = 1; size <= N; size++) {
  for (int index = 1; index <= N - size; index++) {
    int start = index, end = index + size;
    int sum = sums[end] - sums[start - 1];
    dp[start][end] = max(sum - dp[start + 1][end], sum - dp[start][end - 1]);
  }
}
```

### top-down 방식

start ~ end 번째 까지의 dp를 구하면 된다.

현재 dp를 구할 때 왼쪽 카드를 없애는 경우, 오른쪽 카드를 없애는 경우 두 가지 경우를 탐색한다.

이는 start == end 일 때까지 반복한다.

```cpp
int recursive(int start, int end) {
  if (dp[start][end] != 0) {
    return dp[start][end];
  }
  if (start == end) {
    return dp[start][end] = cards[start];
  }

  int sum = sums[end] - sums[start - 1];

  dp[start][end] = max(sum - recursive(start + 1, end), sum - recursive(start, end - 1));
  return dp[start][end];
}

recursive(1, N);
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      32      |       0        |

## 고생한 점
