# 알고스팟. 폴리오미노

[링크](https://www.algospot.com/judge/problem/read/POLY)

| 정답률 |
| :----: |
|  68%   |

## 설계

### 시간 복잡도

입력받은 블록의 갯수를 N이라 하자.

각 경우마다 모두 탐색해 정답을 구할 경우 이는 매우 크므로 제한시간 내에 불가능하다.

전체 블록의 갯수 중에 현재 줄에 몇개의 블록을 사용할 지에 대해 동적 계획법을 사용할 수 있다.

이 경우 각 경우들을 탐색하는 데 O(N^2)의 시간 복잡도를 사용한다.

또한 각 과정을 갱신하는 데 O(N)의 시간 복잡도를 사용하므로 O(N^3)의 시간 복잡도를 사용한다.

### 공간 복잡도

N^2가지의 dp값을 생성해야 한다.

이는 O(N^2)의 공간 복잡도를 사용한다.

### 풀이

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     12ms     |   O(N^3)    |   O(N^2)    |

현재 남은 블록의 갯수를 N이라 하자.

해당 N개의 블록으로 만들 수 있는 경우의 수를 계산할 때, 다음 경우를 고려해야 한다.

- 현재 줄에 A개의 블록을 가로로 이어붙였을 때, 다음 가능한 경우의 수는 아래와 같다.
- 1 ~ (N-A)개의 블록을 다음에 이어붙인다 하자 (이를 B라 하자)
- 해당 경우를 이어붙일 수 있는 칸들은 A + B - 1 이다.
- 따라서 (N-A)개의 블록 중에서 B개의 블록을 다음 칸으로 생성한 경우의 수에 (A + B - 1)을 곱한다.
- 이를 가능한 모든 B에 대해 반복한다.

이를 구현하면 아래와 같다.

```cpp
int solution(int totalSize) {
  // [totalSize][curLength]
  int dp[101][101] = {
      0,
  };

  // initialize
  for (int length = 0; length <= totalSize; length++) {
    dp[length][length] = 1;
  }

  // update
  for (int size = 1; size <= totalSize; size++) {
    for (int curLength = 1; curLength <= size; curLength++) {
      for (int nextLength = 1; nextLength <= size - curLength; nextLength++) {
        int curCount = nextLength + curLength - 1;

        curCount *= dp[size - curLength][nextLength];
        curCount %= MOD;

        dp[size][curLength] += curCount;
        dp[size][curLength] %= MOD;
      }
    }
  }

  int answer = 0;
  for (int curLength = 1; curLength <= totalSize; curLength++) {
    answer += dp[totalSize][curLength];
    answer %= MOD;
  }

  return answer;
}
```

## 고생한 점
