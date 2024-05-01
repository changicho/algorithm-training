# 2370. Longest Ideal Subsequence

[링크](https://leetcode.com/problems/longest-ideal-subsequence/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

동적 계획법을 이용해 각 문자별 가장 긴 길이를 저장후 이후 탐색에 사용할 수 있다.

이 경우 O(N)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

동적 계획법에 O(1)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      43      |    O(N)     |    O(1)     |

각 문자로 끝나는 조건을 만족하는 가장 긴 문자열의 길이를 알고있다고 하자.

현자 문자 c를 이용해 만들 수 있는 가장 긴 문자열의 길이는 다음과 같다.

- 이전 문자 x로 끝나는 가장 긴 문자열의 길이를 M이라 하자.
- c와 x의 차이가 k보다 작은 경우 M + 1
- M의 후보군들 중에서 가장 큰 값을 선택한다.

이를 이용해 각 index별 최장 길이를 갱신한다.

```cpp
int longestIdealString(string s, int k) {
  int size = s.size();
  int dp[26] = {
      0,
  };

  for (int i = 0; i < size; i++) {
    int cur = s[i] - 'a';

    int len = 0;
    for (int before = 0; before < 26; before++) {
      if (abs(before - cur) > k) continue;

      len = max(len, dp[before] + 1);
    }

    dp[cur] = max(dp[cur], len);
  }

  int answer = 0;
  for (int i = 0; i < 26; i++) {
    answer = max(answer, dp[i]);
  }

  return answer;
}
```

## 고생한 점
