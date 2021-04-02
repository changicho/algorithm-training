# 5. Longest Palindromic Substring

[링크](https://leetcode.com/problems/longest-palindromic-substring/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이 s는 최대 1000이다.

모든 경우에 대해 수행할 경우 start index, end index를 설정하는데 O(N^2), 팰린드롬인지 검사하는데 O(N)이 소요된다.

이는 O(N^3) 이므로 제한시간 내에 불가능하다.

따라서 동적 계획법을 이용해 O(N^2) 이내로 줄일 수 있다.

### 공간 복잡도

문자열을 return한다.

동적 계획법을 사용할 경우 1000^2 크기의 boolean 배열이 필요하다.

### 동적계획법

> 120ms

- 시간 복잡도 O(N^2);
- 공간 복잡도 O(N^2);

다음과 같은 dp를 설정한다.

```cpp
bool dp[from][to] // from ~ to 까지의 문자열이 팰린드롬인지 여부
```

i부터 j번째 문자열 까지의 부분 문자열이 팰린드롬일 경우 다음 경우에 팰린드롬이다.

```cpp
if(dp[from][to] == true && s[from - 1] == s[to + 1]) {
  dp[from - 1][to + 1] = true;
}
```

초기값은 다음과 같다.

- 길이가 하나인 펠린드롬
- 길이가 2인 펠린드롬

길이가 2인 펠린드롬을 설정하는 이유는 위 일반식에서 from + 1, to - 1이 역전되는 경우 때문이다.

```cpp
dp[i][i] = true; // i ~ i번째 문자는 모두 펠린드롬
dp[i-1][i] // 두 글자가 연속된 경우 펠린드롬
```

따라서 다음과 같이 풀이할 수 있다.

```cpp
string longestPalindrome(string s) {
  bool dp[1001][1001] = {
      false,
  };

  int answer_from = 0, answer_to = 0;

  dp[0][0] = true;
  for (int i = 1; i < s.length(); i++) {
    dp[i][i] = true;
    if (s[i - 1] == s[i]) {
      dp[i - 1][i] = true;

      answer_from = i - 1;
      answer_to = i;
    }
  }

  for (int length = 3; length <= s.length(); length++) {
    for (int from = 0; from <= s.length() - length; from++) {
      int to = from + length - 1;

      if (dp[from + 1][to - 1] && s[from] == s[to]) {
        dp[from][to] = true;

        if (answer_to - answer_from + 1 < length) {
          answer_from = from;
          answer_to = to;
        }
      }
    }
  }

  return s.substr(answer_from, answer_to - answer_from + 1);
}
```

### Expand Around Center

> 12ms

- 시간 복잡도 : O(N^2)
- 공간 복잡도 : O(1)

index를 변경해가면서, 해당 index가 중심인 펠린드롬을 만들 때 최대 길이가 어느정도인지 검사한다.

이때 펠린드롬의 길이가 홀수인 경우와 짝수인 경우 두가지를 고려한다.

```cpp
string longestPalindrome(string s) {
  int N = s.length();
  int answer_from = 0, answer_to = 0;

  for (int index = 0; index < N; index++) {
    int length = 0;
    int from = index, to = index;
    while (from >= 0 && to < N && s[from] == s[to]) {
      from--;
      to++;
    }
    length = max(to - from - 1, length);

    from = index, to = index + 1;
    while (from >= 0 && to < N && s[from] == s[to]) {
      from--;
      to++;
    }
    length = max(to - from - 1, length);

    if (length > answer_to - answer_from + 1) {
      answer_from = index - (length - 1) / 2;
      answer_to = index + length / 2;
    }
  }

  return s.substr(answer_from, answer_to - answer_from + 1);
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      12      |

## 고생한 점
