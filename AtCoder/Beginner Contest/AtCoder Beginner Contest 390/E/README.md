# E - Vitamin Balance

[링크](https://atcoder.jp/contests/abc390/tasks/abc390_e)

| 난이도 |
| :----: |
|  450   |

## 설계

### 시간 복잡도

음식 배열의 수를 N, 칼로리 값을 C라 하자.

각 음식을 비타민별로 칼로리를 채웠을 때 최대 비타민 의 최대값을 동적 계획법으로 구할 수 있다.

이 경우 O(N \* C)의 시간 복잡도를 사용한다.

이후 해당 값을 이용해 비타민마다의 칼로리의 경우의 수를 탐색해 최대값을 구할 수 있다.

이 경우 O(C^2)의 시간 복잡도가 소요된다.

따라서 총 시간 복잡도는 O(C \* (N + C))이다.

### 공간 복잡도

동적 계획법에 O(N \* C)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|      20      | O(C \* (N + C)) |  O(N \* C)  |

각 비타민별로 칼로리마다의 비타민값의 최대값을 동적 계획법을 이용해 구할 수 있다.

이 때 현재 음식에 대한 현재 칼로리의 최대값을 구할 때 칼로리가 높은 순으로 탐색하며 현재 음식에 대해 구한 이전 칼로리 값이 포함되지 않도록 유의한다.

각 비타민 타입별 칼로리에 대한 최대값을 구한 뒤 각 비타민 칼로리에 대해 탐색한다.

3가지 비타민 타입별 칼로리의 경우의 수를 구하며 세 합이 결국 C가 되어야 하므로 2가지 값에 대해 탐색하면 나머지 하나의 값은 고정된다.

이후 각 칼로리 경우의 최솟값을 구하며 이 중 최대값을 정답으로 반환한다.

```cpp
struct Food {
  int v, a, c;
};

int solution(int size, int limit, vector<Food> &foods) {
  vector<vector<int>> dp(4, vector<int>(limit + 1, 0));

  for (int i = 0; i < size; i++) {
    Food cur = foods[i];

    for (int next = limit; next >= cur.c; next--) {
      int prev = next - cur.c;

      dp[cur.v][next] = max(dp[cur.v][next], dp[cur.v][prev] + cur.a);
    }
  }

  int answer = 0;
  for (int first = 0; first < limit; first++) {
    for (int second = 0; first + second < limit; second++) {
      int third = limit - first - second;

      answer = max(answer, min({dp[1][first], dp[2][second], dp[3][third]}));
    }
  }

  return answer;
}
```

## 고생한 점
