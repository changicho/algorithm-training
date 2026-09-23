# 4050. Minimum Days to Score Exactly N Points

[링크](https://leetcode.com/problems/minimum-days-to-score-exactly-n-points/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

각 step별로 만들 수 있는 최대 크기가 존재한다.

이를 이용해 각 값을 만들 수 있는 최소 횟수를 dp에 저장한다.

현재 step에 대해서 이후 값을 갱신할 때 영향을 받는 부분만 갱신할 경우 총 O(N \* sqrt(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법에 O(N)의 공간 복잡도를 사용한다.

### 동적 계획법 & 탐욕 알고리즘

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|      55      | O(N \* sqrt(N)) |    O(N)     |

earn을 계속해서 값을 만들 경우가 해당 값을 가장 빨리 만드는 경우이다.

해당 케이스들을 탐색하며 각 값에서 skip을 한번 수행했을 때 다른 값들을 만드는 최소 횟수를 구한다.

- skip횟수 1 + 이전 값에서 시작헤 계속 earn을 선택한 횟수

이 때의 탐색 범위는 다음 earn을 수행하기 직전 값까지이다.

이를 이용해 각 값마다의 최소 비용을 갱신한다.

```cpp
int minDays(int n) {
  vector<int> dp(n + 1, INT_MAX);
  dp[0] = 0;
  int cur = 1, earn = 1;

  while (cur <= n) {
    dp[cur] = earn;

    for (int i = cur + 1; i <= min(n, cur + cur); i++) {
      // skip case
      dp[i] = min(dp[i], dp[i - cur] + earn + 1);
    }

    earn++;
    cur += earn;
  }
  return dp[n];
}
```

## 고생한 점
