# 1143. Longest Common Subsequence

[링크](https://leetcode.com/problems/longest-common-subsequence/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 A의 길이를 N, B의 길이를 M이라고 하자.

LCS를 사용할 경우 O(N \* M)의 시간 복잡도로 풀이가 가능하다.

### 공간 복잡도

모든 N, M에 대해서 dp배열을 생성할 경우 O(N \* M)의 공간 복잡도를 사용한다.

이를 최적화 할 경우 O(min(N, M))의 시간 복잡도로 풀이가 가능하다.

### LCS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      20      |  O(N \* M)  |  O(N \* M)  |

문자열 A와 문자열 B의 최장 공통 문자열은 구하는 방법으로 dp를 사용할 수 있다.

문자열 A의 index를 순회하는 i, 문자열 B의 index를 순회하는 j로 순회를 진행한다고 하자.

LCS 배열을 다음과 같이 설정한다.

```cpp
// 첫번째 문자열 i번째 글자, 두번째 문자열 j번째 글자까지 순회했을 때 최장 공통 문자열 길이
// 초기값은 모두 0이다.
LCS[i][j] = 0;
```

1. 문자열 A의 문자열 B의 한글자씩 비교한다.
2. 두 문자가 같다면 `LCS[i - 1][j - 1]` 값에 1을 더한다.
3. 두 문자가 같지 않다면 `LCS[i - 1][j], LCS[i][j - 1]` 중에서 최대값을 정한다.
4. 위 과정을 반복한다.

LCS 배열을 dp로 설정하고 구할 수 있다.

```cpp
int longestCommonSubsequence(string text1, string text2) {
  if (text2.length() > text1.length()) swap(text2, text1);
  int length1 = text1.length(), length2 = text2.length();

  vector<vector<int>> dp(length1 + 1, vector<int>(length2 + 1, 0));

  for (int first = 1; first <= length1; ++first) {
    for (int second = 1; second <= length2; ++second) {
      if (text1[first - 1] == text2[second - 1]) {
        dp[first][second] = dp[first - 1][second - 1] + 1;
      } else {
        dp[first][second] = max(dp[first - 1][second], dp[first][second - 1]);
      }
    }
  }

  return dp[length1][length2];
}
```

## 고생한 점
