# 583. Delete Operation for Two Strings

[링크](https://leetcode.com/problems/delete-operation-for-two-strings/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

단어1의 길이를 N, 단어2의 길이를 M이라 하자.

현재 단어에서 다른 단어를 만들기 위한 최소 연산을 구하기 위해 LCS를 이용할 수 있다.

이 경우 시간 복잡도는 O(N \* M)이 소요된다.

### 공간 복잡도

LCS를 만들 때 기존 값을 이용하기 위해 메모이제이션을 사용할 수 있다.

이 경우 O(N \* M)의 공간 복잡도를 사용한다.

### LCS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      39      |  O(N \* M)  |  O(N \* M)  |

현재 단어에서 다른 단어를 만들기 위해 다음 두가지 연산을 수행할 수 있다.

- 문자를 하나 삭제
- 문자를 하나 추가

따라서 두 단어에서 공통된 부분만 남기고 남은 부분은 삭제하거나 새로 추가할 경우가 가장 비용이 적게 드는 경우이다.

두 단어의 최대 공통 부분은 LCS알고리즘을 이용해 구할 수 있다.

이를 구하고 word1에서 불필요한 문자를 삭제하는데 들어가는 비용, word2에 필요한 문자를 추가하는데 들어가는 비용을 계산한다.

이 두 비용을 더해 값을 구한다.

```cpp
int longestCommonSubsequence(string &word1, string &word2) {
  int length1 = word1.length(), length2 = word2.length();
  vector<vector<int>> dp(length1 + 1, vector<int>(length2 + 1, 0));

  for (int idx1 = 1; idx1 <= length1; ++idx1) {
    for (int idx2 = 1; idx2 <= length2; ++idx2) {
      if (word1[idx1 - 1] == word2[idx2 - 1]) {
        dp[idx1][idx2] = dp[idx1 - 1][idx2 - 1] + 1;
      } else {
        dp[idx1][idx2] = max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);
      }
    }
  }

  return dp[length1][length2];
}

int minDistance(string word1, string word2) {
  int length1 = word1.length();
  int length2 = word2.length();

  int lcsLength = longestCommonSubsequence(word1, word2);

  return length1 + length2 - 2 * lcsLength;
}
```

## 고생한 점
