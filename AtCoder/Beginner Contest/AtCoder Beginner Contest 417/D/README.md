# D - Takahashi's Expectation

[링크](https://atcoder.jp/contests/abc417/tasks/abc417_d)

| 난이도 |
| :----: |
|  425   |

## 설계

### 시간 복잡도

배열 present의 크기를 N, 쿼리의 크기를 Q, 점수의 범위를 M이라 하자.

동적 계획법을 이용해 특정 index부터 마지막 present까지 선택했을 때 시작점수와 끝 점수를 계산할 수 있다. 이에 O(N \* M)의 시간 복잡도를 사용한다.

각 present까지 점수 범위의 최대값들을 prefixSum을 이용해 배열로 만들 수 있다.

이후 각 쿼리마다 점수에 대해 이분 탐색으로 순회하며 정답을 구할 수 있다.

이에 O(N \* M + Q \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법에 O(N \* M)의 공간 복잡도를 사용한다. 또한 prefixSum 배열에 O(N)의 공간 복잡도를 사용한다.

### 동적 계획법 & prefix sum & 이분탐색

| 내 코드 (ms) |        시간 복잡도        | 공간 복잡도 |
| :----------: | :-----------------------: | :---------: |
|     425      | O(N \* M + Q \* log_2(N)) |  O(N \* M)  |

present의 점수 범위는 1 ~ 500 까지이다.

이 때 현재 기분점수가 500을 초과할 수 있다.

따라서 현재 present부터 마지막 present까지 선택했을 때 다음과 같은 dp 배열을 생성한다.

```cpp
dp[i][score]; // i번째 present부터 시작했을 때 현재 점수가 score일 때의 최종 점수

dp[N - 1][score] = score + present.a; // 현재 점수가 present.p 이하일 때
dp[N - 1][score] = max(score - present.b, 0); // 현재 점수가 present.p 초과일 때

dp[i][score] = dp[i + 1][score + present.a]; // i번째 present부터 시작했을 때 다음 present를 선택했을 때의 점수
dp[i][score] = dp[i + 1][max(score - present.b, 0)]; // i번째 present부터 시작했을 때 다음 present를 선택했을 때의 점수
```

이를 이용해 특정 index에서 시작 점수와 끝 점수를 계산할 수 있다.

이 때 각 점수의 범위는 500을 초과할 수 있으므로, 현재 present를 선택했을 때 값이 변하는 최대 범위인 1000까지의 점수에 대해서만 계산한다.

이후 각 present의 b값을 prefixSum 배열로 만들어, 현재 present까지의 b값의 합을 구할 수 있다.

만약 현재 쿼리가 모든 present의 b값의 합보다 크다면, 해당 쿼리에서 점수 감소연산만 수행되므로 현재 present의 b값의 합을 빼면 된다.

현재 쿼리가 1000 이하인 경우 dp[0] 배열을 사용해 해당 쿼리의 점수에 대한 최종 점수를 구할 수 있다.

만약 현재 쿼리가 특정 present까지의 b값의 합보다 크다면, 해당 present까지의 b값의 합을 빼고, dp 배열에서 현재 present 이후부터 시작했을 때의 점수를 구할 수 있다.

```cpp
struct Present {
  int p, a, b;
};

vector<long long> solution(int size, vector<Present> &presents, int qSize, vector<int> &queries) {
  vector<vector<long long>> dp(size, vector<long long>(1000 + 1));

  for (int i = size - 1; i >= 0; i--) {
    Present &present = presents[i];

    for (int score = 0; score <= 1000; score++) {
      if (score <= present.p) {
        int next = score + present.a;

        dp[i][score] = i == size - 1 ? next : dp[i + 1][next];
      } else {
        int next = max(score - present.b, 0);

        dp[i][score] = i == size - 1 ? next : dp[i + 1][next];
      }
    }
  }

  vector<long long> prefixSums(size);
  prefixSums[0] = presents[0].b;
  for (int i = 1; i < size; i++) {
    prefixSums[i] = prefixSums[i - 1] + presents[i].b;
  }

  vector<long long> answer;
  for (int query : queries) {
    if (query > 1000) {
      int idx = lower_bound(prefixSums.begin(), prefixSums.end(), query - 500) - prefixSums.begin();

      if (idx >= size - 1) {
        answer.push_back(query - prefixSums[size - 1]);
        continue;
      }

      query -= prefixSums[idx];
      answer.push_back(dp[idx + 1][query]);
    } else {
      answer.push_back(dp[0][query]);
    }
  }

  return answer;
}
```

## 고생한 점
