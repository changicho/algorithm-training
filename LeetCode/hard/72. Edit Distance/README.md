# 72. Edit Distance

[링크](https://leetcode.com/problems/edit-distance/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

word1의 길이를 N, word2의 길이를 M이라 하자.

직접 모든 경우를 탐색하는 경우 3^(N + M)의 시간 복잡도가 소요된다. (삽입, 삭제, 교체 3가지 경우로 탐색을 진행하므로)

이는 제한 시간 내에 불가능하다.

따라서 동적 계획법을 이용해 시간복잡도를 최적화한다.

이 경우 시간 복잡도는 O(N \* M)이다.

### 공간 복잡도

word1, word2의 모든 index에 대해서 dp배열을 생성할 경우 공간 복잡도는 O(N \* M)이다.

직전행, 값만을 이용해 공간복잡도를 최적화 할 경우 공간 복잡도는 O(M)이다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      16      |  O(N \* M)  |  O(N \* M)  |

다음과 같은 dp배열을 새성한다.

```cpp
dp[i][j]; // word1의 0 ~ i번째, word2의 0 ~ j번째 까지 변환했을 때 최소값
```

각 글자에 대해서 아무것도 없는 빈 문자열을 생성하는 데 필요한 연산의 횟수는 글자수만큼이 된다.

따라서 초기값은 다음과 같다.

```cpp
dp[i][0] = i;
dp[0][j] = j;
```

만약 word1의 i번째 글자와 word2의 j번째 글자가 같은 경우를 생각해보자

이 경우 직전 dp값에서 연산의 횟수가 추가되지 않는다.

```cpp
dp[i][j] = dp[i - 1][j - 1];
```

만약 두 글자가 다른 경우를 생각해보자.

```cpp
dp[i][j] = dp[i - 1][j - 1] + 1; // word1[i - 1]을 word2[j - 1]로 바꾼다
dp[i][j] = dp[i - 1][j] + 1; // word1[i - 1] 을 삭제한다.
dp[i][j] = dp[i][j - 1] + 1; // word2[j - 1] 를 word1에 추가한다.
```

따라서 일반식은 위와 같다.

```cpp
int minDistance(string word1, string word2) {
  int N = word1.size(), M = word2.size();
  vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));

  for (int idx1 = 1; idx1 <= N; idx1++) {
    dp[idx1][0] = idx1;
  }
  for (int idx2 = 1; idx2 <= M; idx2++) {
    dp[0][idx2] = idx2;
  }

  for (int idx1 = 1; idx1 <= N; idx1++) {
    for (int idx2 = 1; idx2 <= M; idx2++) {
      if (word1[idx1 - 1] == word2[idx2 - 1]) {
        dp[idx1][idx2] = dp[idx1 - 1][idx2 - 1];
        continue;
      }

      int fromFirst = dp[idx1 - 1][idx2];
      int fromSecond = dp[idx1][idx2 - 1];
      int fromBoth = dp[idx1 - 1][idx2 - 1];

      dp[idx1][idx2] = 1 + min(fromBoth, min(fromFirst, fromSecond));
    }
  }
  return dp[N][M];
}
```

### 동적 계획법 - 공간 최적화

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |  O(N \* M)  |    O(M)     |

위 식에서 직전의 행만 이용하므로 다음과 같이 최적화 할 수 있다.

```cpp
int minDistance(string word1, string word2) {
  int N = word1.size(), M = word2.size();
  vector<int> cur(M + 1, 0), pre(M + 1, 0);

  for (int idx2 = 1; idx2 <= M; idx2++) {
    pre[idx2] = idx2;
  }

  for (int idx1 = 1; idx1 <= N; idx1++) {
    cur[0] = idx1;

    for (int idx2 = 1; idx2 <= M; idx2++) {
      if (word1[idx1 - 1] == word2[idx2 - 1]) {
        cur[idx2] = pre[idx2 - 1];
      } else {
        cur[idx2] = min(pre[idx2 - 1], min(cur[idx2 - 1], pre[idx2])) + 1;
      }
    }

    // fill(pre.begin(), pre.end(), 0);
    swap(pre, cur);
  }

  return pre.back();
}
```

## 고생한 점
