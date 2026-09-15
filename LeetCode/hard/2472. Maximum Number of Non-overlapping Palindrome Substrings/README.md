# 2472. Maximum Number of Non-overlapping Palindrome Substrings

[링크](https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

문자열의 길이를 N, 숫자를 K라 하자.

동적 계획법을 사용할 경우 O(N^2)의 시간 복잡도를 사용한다.

탐욕 알고리즘을 사용할 경우 O(NK)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법에 O(N^2)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     302      |   O(N^2)    |   O(N^2)    |

특정 left~right까지 substring이 회문인지 판단하는 2차원 배열을 생성한다.

이후 index를 증가시키며 이전 x에서 0 ~ x, x+1 ~ index 로 나눴을 때 x까지 회문의 수 + 오른쪽부분이 회문인지 여부를 갱신하며 dp배열을 갱신한다.

이를 마지막 index까지 수행하며 최대 갯수를 구한다.

```cpp
int maxPalindromes(string s, int k) {
  int size = s.size();

  vector<vector<bool>> isPalin(size, vector<bool>(size, false));
  for (int i = 0; i < size; i++) {
    isPalin[i][i] = true;
    if (i + 1 < size && s[i] == s[i + 1]) {
      isPalin[i][i + 1] = true;
    }
  }

  for (int l = 3; l <= size; l++) {
    for (int i = 0; i <= size - l; i++) {
      isPalin[i][i + l - 1] =
          isPalin[i + 1][i + l - 2] && (s[i] == s[i + l - 1]);
    }
  }

  vector<int> dp(size, 0);
  for (int i = 0; i < size; i++) {
    for (int before = i - 1; before >= -1; before--) {
      int beforeDp = before >= 0 ? dp[before] : 0;

      bool canAdd = (i - (before + 1) + 1) >= k && isPalin[before + 1][i];
      dp[i] = max(dp[i], beforeDp + canAdd);
    }
  }

  return dp[size - 1];
}
```

### 탐욕 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(NK)    |    O(1)     |

조건을 만족하는 회문의 길이가 짧으면 짧을 수록 유리하다.

만약 S가 회문이라고 한다면, S의 맨 앞과 뒤를 제거한 문자열도 회문이다.

따라서 왼쪽부터 순회하며 해당 index를 right로 하는 길이가 K, K+1인 회문이 존재하는지 판단하고 정답에 추가한다.

이 때 마지막 회문의 끝 위치를 이용해 매번 갱신함에 유의한다.

```cpp
int maxPalindromes(string s, int k) {
  int size = s.size();
  int answer = 0;

  function<bool(int, int)> check = [&](int l, int r) {
    while (l < r) {
      if (s[l++] != s[r--]) {
        return false;
      }
    }
    return true;
  };

  int start = 0;
  for (int r = k - 1; r < size; ++r) {
    int l = r - k + 1;
    if (l >= start && check(l, r)) {
      answer++;
      start = r + 1;
      continue;
    }

    l = r - k;
    if (l >= start && check(l, r)) {
      answer++;
      start = r + 1;
    }
  }

  return answer;
}
```

## 고생한 점
