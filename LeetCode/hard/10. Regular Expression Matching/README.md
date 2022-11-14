# 10. Regular Expression Matching

[링크](https://leetcode.com/problems/regular-expression-matching/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 문자열의 길이를 N, 패턴의 길이를 M이라 하자.

재귀 호출을 이용해 직접 판단할 경우 O((N + M) \* 2^(N + M))의 시간 복잡도를 사용한다.

동적 계획법을 이용해 탐색할 경우 O(N \* M)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법을 사용할 경우 O(N \* M)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      7       |  O(N \* M)  |  O(N \* M)  |

dp식을 다음과 같이 정의한다.

```cpp
// definition
dp[sI][pI]; // to be true if s[0..sI) matches p[0..pI)

// initialize
dp[0][0] = true;

// update
if (p[pI - 1] == '*') {  // wildcard case
  if (dp[sI][pI - 2]) {
    dp[sI][pI] = true;
  } else {
    if (!dp[sI - 1][pI]) continue;
    dp[sI][pI] = (s[sI - 1] == p[pI - 2] || p[pI - 2] == '.');
  }
} else if (p[pI - 1] == '.') {  // skip case
  if (!dp[sI - 1][pI - 1]) continue;
  dp[sI][pI] = true;
} else {  // normal case
  if (!dp[sI - 1][pI - 1]) continue;
  dp[sI][pI] = (s[sI - 1] == p[pI - 1]);
}
```

현재 패턴의 문자가 '\*'인 경우와 '.'인 경우, 그리고 일반 문자인 경우로 나눠서 판단할 수 있다.

현재 문자가 일반 문자인 경우 직전 매칭이 true이고 현재 비교할 문자가 같을때 true로 갱신 가능하다.

'.'인 경우 직전 매칭이 true인 경우 현재 경우를 넘어갈 수 있다.

'\*'인 경우는 이전 매칭까지 통과했거나, 직전 패턴까지 통과한경우, 직전 패턴이 '.'인 경우 true이다.

```cpp
bool isMatch(string s, string p) {
  int length = s.size(), patternLength = p.size();
  vector<vector<bool>> dp(length + 1, vector<bool>(patternLength + 1, false));
  dp[0][0] = true;

  for (int pI = 2; pI <= patternLength; pI++) {
    if (p[pI - 1] == '*' && dp[0][pI - 2]) {
      dp[0][pI] = true;
    }
  }

  for (int sI = 1; sI <= length; sI++) {
    for (int pI = 1; pI <= patternLength; pI++) {
      if (p[pI - 1] == '*') {  // wildcard case
        if (dp[sI][pI - 2]) {
          dp[sI][pI] = true;
        } else {
          if (!dp[sI - 1][pI]) continue;
          dp[sI][pI] = (s[sI - 1] == p[pI - 2] || p[pI - 2] == '.');
        }
      } else if (p[pI - 1] == '.') {  // skip case
        if (!dp[sI - 1][pI - 1]) continue;
        dp[sI][pI] = true;
      } else {  // normal case
        if (!dp[sI - 1][pI - 1]) continue;
        dp[sI][pI] = (s[sI - 1] == p[pI - 1]);
      }
    }
  }

  return dp[length][patternLength];
}
```

## 고생한 점
