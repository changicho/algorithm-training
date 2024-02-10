# 647. Palindromic Substrings

[링크](https://leetcode.com/problems/palindromic-substrings/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

팰린드롬을 판별하기 위해 동적 계획법을 이용해 풀이할 경우 시간 복잡도는 O(N^2)이다.

### 공간 복잡도

동적 계획법을 이용할 경우 O(N^2)의 공간 복잡도가 필요하다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      11      |   O(N^2)    |   O(N^2)    |

다음과 같은 팰린드롬을 판단하는 dp배열을 선언한다.

```cpp
// definition
bool dp[left][right]; // left ~ right 까지의 문자열이 팰린드롬인지 여부

// init
dp[i][i] = true;
dp[i][i+1] = s[i] == s[i+1];

// update
dp[left][right] = dp[left+1][right-1] && s[left] == s[right];
```

이를 이용해 dp배열을 갱신하면서 팰린드롬인 경우 answer를 증가시킨다.

```cpp
int countSubstrings(string s) {
  int size = s.size();
  bool dp[1001][1001] = {
      false,
  };

  int answer = 0;
  for (int i = 0; i < size; i++) {
    dp[i][i] = true;
    answer++;

    if (i + 1 < size && s[i] == s[i + 1]) {
      dp[i][i + 1] = true;
      answer++;
    }
  }
  for (int len = 2; len <= size; len++) {
    for (int from = 0; from < size - len + 1; from++) {
      int to = from + len - 1;
      if (dp[from + 1][to - 1] == false) continue;
      if (s[from] == s[to]) {
        dp[from][to] = true;
        answer++;
      }
    }
  }
  return answer;
}
```

## 고생한 점
