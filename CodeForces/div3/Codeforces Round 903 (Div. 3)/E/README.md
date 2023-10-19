# E. Block Sequence

[링크](https://codeforces.com/contest/1881/problem/E)

## 설계

### 시간 복잡도

입력받은 배열의 크기를 N이라 하자.

모든 경우를 수행할 경우 O(2^N)의 시간 복잡도를 사용하므로 제한시간 내에 불가능하다.

따라서 동적 계획법을 이용해 O(N)의 시간 복잡도로 풀이한다.

### 공간 복잡도

동적 계획법에 O(N)의 공간 복잡도를 사용한다.

### 동적 계획법

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(N)     |    O(N)     |

길이가 N인 배열을 beautiful 하게 만드는 데 최악의 경우 N번 문자를 지우면 가능하다.

만약 현재 방문한 index가 i라고 하자. i번째 숫자만큼 뒤에 원소들을 남기고 이후 index로 바로 넘어갈 수 있다.

이를 반복하며 특정 index까지 도달하는 최소 횟수를 구할 수 있다.

이를 이용해 다음과 같은 dp식을 설정한다.

```cpp
// definition
int dp[i]; // until i minimum cost to make beautiful

// initialize
dp[i] = i+1;

// update
for (int i = 0; i < size; i++) {
  // came from before value
  if (i - 1 >= 0) {
    // erase current
    dp[i] = min(dp[i], dp[i - 1] + 1);
  }

  // choose current value and skip to next
  int cur = arr[i];
  int beforeCost = i - 1 < 0 ? 0 : dp[i - 1];

  if (i + cur < size) {
    dp[i + cur] = min(dp[i + cur], beforeCost);
  }
}
```

이를 이용해 다음과 같이 구할 수 있다.

```cpp
int solution(vector<int> &arr) {
  int size = arr.size();

  int answer = arr.size();

  // until [i] minimum cost to make beautiful
  vector<int> dp(size);

  for (int i = 0; i < size; i++) {
    dp[i] = i + 1;
  }

  for (int i = 0; i < size; i++) {
    if (i - 1 >= 0) {
      dp[i] = min(dp[i], dp[i - 1] + 1);
    }
    int cur = arr[i];

    int beforeCost = i - 1 < 0 ? 0 : dp[i - 1];

    if (i + cur < size) {
      dp[i + cur] = min(dp[i + cur], beforeCost);
    }
  }

  return dp[size - 1];
}
```

## 고생한 점
