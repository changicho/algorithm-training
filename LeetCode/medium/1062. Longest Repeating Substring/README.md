# 1062. Longest Repeating Substring

[링크](https://leetcode.com/problems/longest-repeating-substring/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

hash map을 이용해 모든 경우를 탐색할 경우 시간 복잡도는 O(N^3)이다. 이는 제한시간 내에 불가능하다.

동적 계획법을 이용해 풀이할 경우 시간 복잡도는 O(N^2)이다.

### 공간 복잡도

동적 계획법에 O(N^2)의 공간 복잡도가 필요하다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      10      |   O(N^2)    |   O(N^2)    |

다음과 같은 dp식을 생성한다.

```cpp
int dp[i][j]; // i, j번째 문자열로 끝나는 겹치는 substring의 최대 길이

dp[i][i] = 1;

if (s[i] == s[j]) {
  dp[i][j] = dp[i-1][j-1] + 1;
}
```

즉 두 문자에 대해서 같은 경우 두 문자의 직전 값을 비교해 연속된 문자열의 길이를 갱신한다.

```cpp
int longestRepeatingSubstring(string s) {
  int size = s.size();
  vector<vector<int>> dp(size, vector<int>(size, 0));

  int answer = 0;
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (s[i] != s[j]) continue;

      dp[i][j] = (i > 0 ? dp[i - 1][j - 1] : 0) + 1;
      answer = max(answer, dp[i][j]);
    }
  }

  return answer;
}
```

## 고생한 점
