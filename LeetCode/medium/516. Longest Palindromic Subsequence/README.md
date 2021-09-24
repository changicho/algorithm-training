# 516. Longest Palindromic Subsequence

[링크](https://leetcode.com/problems/longest-palindromic-subsequence/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

모든 경우를 탐색하는 브루트 포스 방법을 사용할 경우 각 index마다 현재 값을 포함하는 경우, 포함하지 않는 경우 2가지로 탐색을 계속하게 된다.

이 경우 시간 복잡도는 O(2^N)이며 제한시간 내에 불가능하다.

브루트 포스 방법에서 메모이 제이션을 사용할 경우 가능한 경우의 수 O(N^2)의 경우에 대해서만 탐색을 진행한다.

따라서 시간 복잡도는 O(N^2)이다.

그 외 동적 계획법을 사용할 경우 또한 시간 복잡도는 O(N^2)이다.

### 공간 복잡도

메모이제이션, 동적 계획법을 일반적으로 사용할 경우 O(N^2)의 공간 복잡도가 필요하다.

만약 최적화된 동적 계획법을 사용할 경우 O(N)의 공간 복잡도만을 사용할 수 있다.

### 브루트 포스 & 메모이제이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      44      |   O(N^2)    |   O(N^2)    |

특정 구간에 대한 재귀식으로 문제를 풀이할 수 있다.

top-down 방식으로 현재 subString의 왼쪽, 오른쪽 중 한칸씩 줄여가며 가장 긴 팰린드롬 subsequence를 찾는다.

```cpp
int recursive(int left, int right, string &s) {
  if (left == right) return 1;
  if (left > right) return 0;

  if (s[left] == s[right]) {
    return 2 + recursive(left + 1, right - 1, s);
  }

  return max(recursive(left + 1, right, s), recursive(left, right - 1, s));
}
```

여기서 left, right에 대해서 중복된 경우가 발생할 수 있고, 이를 메모이제이션을 통해 최적화 할 수 있다.

```cpp
int recursive(int left, int right, string &s, vector<vector<int>> &dp) {
  if (left == right) return 1;
  if (left > right) return 0;
  if (dp[left][right] != 0) return dp[left][right];

  if (s[left] == s[right]) {
    return dp[left][right] = 2 + recursive(left + 1, right - 1, s, dp);
  }

  int rightShift = recursive(left + 1, right, s, dp);
  int leftShift = recursive(left, right - 1, s, dp);

  return dp[left][right] = max(rightShift, leftShift);
}

int longestPalindromeSubseq(string s) {
  int length = s.length();
  vector<vector<int>> dp(length, vector<int>(length, 0));

  return recursive(0, length - 1, s, dp);
}
```

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      44      |   O(N^2)    |   O(N^2)    |

다음과 같이 dp를 설정한다.

```cpp
dp[length][index]; // index에서 시작하는 size크기의 구간 중 palindromic subsequence의 최대값
```

초기값은 다음과 같다.

```cpp
dp[1][index] = 1;
```

dp의 점화식은 다음과 같이 나타낼 수 있다.

```cpp
if (s[start] == s[size + start - 1]) {
  // 시작과 끝의 문자가 같은 경우
  dp[size][start] = dp[size - 2][start + 1] + 2;
} else {
  // 시작과 끝의 문자가 같지 않은 경우, 두 문자중 하나를 삭제한 경우에 대한 최대값 갱신
  dp[size][start] = max(dp[size - 1][start], dp[size - 1][start + 1]);
}
```

이를 이용해 length크기의 첫번째 값에는 가능한 가장 큰 값이 설정된다.

이를 이용해 풀이할 경우 다음과 같다.

```cpp
int longestPalindromeSubseq(string s) {
  int length = s.length();
  // dp[size][index];
  vector<vector<int>> dp(length + 1, vector<int>(length, 0));

  for (int i = 0; i < length; ++i) {
    dp[1][i] = 1;
  }

  for (int size = 2; size <= length; ++size) {
    for (int start = 0; start < length - size + 1; ++start) {  // start index
      if (s[start] == s[size + start - 1]) {
        dp[size][start] = dp[size - 2][start + 1] + 2;
      } else {
        dp[size][start] = max(dp[size - 1][start], dp[size - 1][start + 1]);
      }
    }
  }

  return dp.back().front();
}
```

### 동적 계획법 (space optimized)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      40      |   O(N^2)    |    O(N)     |

위 dp 식에서 직전값, 직직전값에 대해서만 사용하는것을 알 수 있다.

dp식을 다음과 같이 변경한다.

```cpp
dp[index]; // index번째에서 시작하는 palindromic subsequence의 최대값
```

직전 값을 사용하기 위해 같은 크기의 dp배열을 하나 더 생성한다.

일반 식은 다음과 같다.

```cpp
if (s[left] == s[right]) {
  dp[right] = before[right - 1] + 2;
} else {
  dp[right] = max(before[right], dp[right - 1]);
}
```

여기서 size를 증가시키며 탐색해야 하므로 right는 left + 1부터 시작한다.

초기값은 다음과 같다.

```cpp
left[index] = 1; // 한글자 parindrome
```

이를 이용해 구현하면 다음과 같다.

```cpp
int longestPalindromeSubseq(string s) {
  int length = s.length();
  if (length <= 1) return length;

  vector<int> dp(length, 0), before(length, 0);

  for (int left = length - 1; left >= 0; --left) {
    // before과 dp가 서로 swap되므로 left를 현재 탐색할 때 초기값으로 갱신
    dp[left] = 1;

    for (int right = left + 1; right < length; ++right) {
      if (s[left] == s[right]) {
        dp[right] = before[right - 1] + 2;
      } else {
        dp[right] = max(before[right], dp[right - 1]);
      }
    }
    swap(before, dp);
  }

  return before.back();
}
```

## 고생한 점
