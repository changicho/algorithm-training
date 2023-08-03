# 712. Minimum ASCII Delete Sum for Two Strings

[링크](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

s1의 길이를 N, s2의 길이를 M이라 하자.

직접 모든 경우를 탐색할 경우 제한시간 내에 불가능하다.

LCS를 응용해 동적 계획법을 적용할 수 있다. 이 경우 O(N \* M)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법에 O(N \* M)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      15      |  O(N \* M)  |  O(N \* M)  |

두 문자열의 길이에 대해서 dp식을 구성한다.

두 문자열의 왼쪽부터의 길이에 대해서 각각의 최소값을 구한다.

dp식을 다음과 같이 구성한다.

```cpp
// definition
int dp[len1][len2]; // dp[i][j]일때 s1.substr(0,i)와 s2.substr(0,j)때의 최소값

// update
if (s1[i - 1] == s2[j - 1]) {
  dp[i][j] = dp[i - 1][j - 1];
} else {
  int fromS1 = s1[i - 1] + dp[i - 1][j];
  int fromS2 = s2[j - 1] + dp[i][j - 1];
  dp[i][j] = min(fromS1, fromS2);
}

// init
for (int i = 1; i <= size1; i++) {
  costs[i][0] = costs[i - 1][0] + s1[i - 1];
}
for (int j = 1; j <= size2; j++) {
  costs[0][j] = costs[0][j - 1] + s2[j - 1];
}
```

즉 현재 각 문자열의 길이를 len1, len2라 할 때 현재 값은 다음과 같다.

- 두 문자열의 마지막 문자가 같을 때 : 이전 값과 같음
- 다른 경우 : s1의 마지막 문자를 제거한 경우, s2의 마지막 문자를 제거한 경우 중 최소값

이를 구현하면 다음과 같다.

```cpp
int minimumDeleteSum(string s1, string s2) {
  int size1 = s1.length(), size2 = s2.length();
  // costs[len1][len2] : cost of s1.substr(0,len1) and s2.substr(0,len2)
  int costs[1001][1001] = {
      0,
  };

  for (int i = 1; i <= size1; i++) {
    costs[i][0] = costs[i - 1][0] + s1[i - 1];
  }
  for (int j = 1; j <= size2; j++) {
    costs[0][j] = costs[0][j - 1] + s2[j - 1];
  }

  for (int i = 1; i <= size1; i++) {
    for (int j = 1; j <= size2; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        costs[i][j] = costs[i - 1][j - 1];
      } else {
        int fromS1 = s1[i - 1] + costs[i - 1][j];
        int fromS2 = s2[j - 1] + costs[i][j - 1];
        costs[i][j] = min(fromS1, fromS2);
      }
    }
  }

  return costs[size1][size2];
}
```

## 고생한 점
