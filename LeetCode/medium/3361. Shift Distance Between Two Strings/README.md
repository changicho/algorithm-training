# 3361. Shift Distance Between Two Strings

[링크](https://leetcode.com/problems/shift-distance-between-two-strings/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

각 문자에서 다른 문자로 변경할 때의 최소 비용을 동적 계획법을 이용해 구할 수 있다.

이 경우 O(26^2)의 시간 복잡도를 사용하며, 이는 상수이므로 O(1)이다.

이후 모든 문자를 순회하며 정답을 구하는 데 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

동적 계획법을 이용해 각 문자에서 다른 문자로 변경할 때의 최소 비용을 구할 때 O(26^2)의 공간 복잡도가 필요하다.

정답이 int를 초과할 수 있으므로 long long형을 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      63      |    O(N)     |    O(1)     |

각 문자에서 다른 문자로 변경할 때의 최소 비용을 동적 계획법을 이용해 구한다.

이후 모든 문자를 순회하며 정답을 구한다.

이 때 정답이 int형을 초과할 수 있으므로 long long형을 이용한다.

```cpp
int calc(int cur, int diff) { return (cur + diff + 26) % 26; }

long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
  vector<vector<long long>> dp(26, vector<long long>(26, LLONG_MAX));
  for (int i = 0; i < 26; i++) {
    dp[i][i] = 0;
  }
  for (int i = 0; i < 26; i++) {
    for (int next = calc(i, +1); next != i; next = calc(next, +1)) {
      int nprev = calc(next, -1);

      dp[i][next] = min(dp[i][next], dp[i][nprev] + nextCost[nprev]);
    }
    for (int prev = calc(i, -1); prev != i; prev = calc(prev, -1)) {
      int pnext = calc(prev, +1);

      dp[i][prev] = min(dp[i][prev], dp[i][pnext] + previousCost[pnext]);
    }
  }

  int size = s.size();
  long long answer = 0;
  for (int i = 0; i < size; i++) {
    int from = s[i] - 'a';
    int to = t[i] - 'a';

    answer += dp[from][to];
  }
  return answer;
}
```

## 고생한 점
