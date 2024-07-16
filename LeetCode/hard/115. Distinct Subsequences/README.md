# 115. Distinct Subsequences

[링크](https://leetcode.com/problems/distinct-subsequences/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

문자열 s의 길이를 N, t의 길이를 M이라 하자.

동적 계획법을 사용할 경우 s, t의 index에 대한 2차원 dp를 사용한다.

이 경우 갱신에 O(N \* M)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법을 사용할 경우 2차원 dp배열을 사용한다.

이에 O(N \* M)의 공간 복잡도를 사용한다.

이 때 직전값만을 사용하므로 O(M)의 공간 복잡도를 사용해 풀이할 수 있다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      20      |  O(N * M)   |  O(N * M)   |

다음과 같은 dp배열을 생성한다.

```cpp
// definition
dp[sI][tI]; // sI까지 순회했을 때 0~tI까지 t의 부분문자열을 만들 수 있는 경우의 수

// base condition
dp[sI][0] = s[sI] == t[0];

// update
dp[i][j] = dp[i-1][j];

if (s[i] == t[j]){
  dp[i][j] += dp[i-1][j-1]
}
```

즉 이전 sI까지의 t의 부분문자열을 만들 수 있는 갯수를 저장한 뒤 이를 이용한다.

이를 구현하면 다음과 같다.

```cpp
int numDistinct(string s, string t) {
  long dp[1001][1001] = {
      0,
  };

  for (int i = 0; i < s.size(); i++) {
    dp[i][0] = i > 0 ? dp[i - 1][0] : 0;
    if (s[i] == t[0]) {
      dp[i][0] += 1;
      dp[i][0] = min(dp[i][0], (long)INT_MAX);
    }
    for (int j = 1; j < t.size(); j++) {
      dp[i][j] = i > 0 ? dp[i - 1][j] : 0;

      if (i > 0 && t[j] == s[i]) {
        dp[i][j] += dp[i - 1][j - 1];
        dp[i][j] = min(dp[i][j], (long)INT_MAX);
      }
    }
  }
  int answer = dp[s.size() - 1][t.size() - 1];
  return answer;
}
```

## 고생한 점
