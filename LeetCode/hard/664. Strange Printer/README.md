# 664. Strange Printer

[링크](https://leetcode.com/problems/strange-printer/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(26^100) 이므로 제한시간 내에 불가능하다.

동적 계획법을 이용해 이전에 계산한 값을 이용해 풀이할 수 있다.

이 경우 subString의 시작점과 끝점을 이용해 dp를 구성할 수 있다.

해당 dp값을 채우는 데 O(N^2)의 시간 복잡도를, 내부적으로 갱신하며 계산하는데 O(N)의 시간 복잡도를 사용한다.

따라서 총 O(N^3)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법에 O(N^2)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      28      |   O(N^3)    |   O(N^2)    |

길이가 L인 문자열을 만들기 위해 최악의 경우 L번 타이핑해야한다.

혹은 기존에 타이핑 한 문자열 위에 원하는 문자열을 덮어씌울 수 있다.

따라서 아래와 같은 패턴인 경우 2번의 타이핑으로 문자열을 만들 수 있다.

- aba
- ab

이를 위해 현재 만들고자 하는 문자열에서 왼쪽부터 순회하며 가장 마지막 문자와 같은 경우와 다른 경우에 대해 구분할 수 있다.

따라서 다음과 같은 dp식을 구성한다.

```cpp
int dp[left][right]; // left ~ right 까지의 문자열을 만들기 위한 최소 타이핑 횟수

dp[left][right] = length; // length : right - left + 1, 최악의 경우 타이핑 횟수

int before = -1;
for (int i = left; i < right; i++) {
  if (s[i] != s[right] && before == -1) {
    before = i;
  }
  if (before != -1) {
    dp[left][right] =
        min(dp[left][right], 1 + dp[before][i] + dp[i + 1][right]);
  }
}
if (before == -1) {
  dp[left][right] = 0;
}
```

이를 이용해 풀이하면 다음과 같다.

```cpp
int strangePrinter(string s) {
  int size = s.size();

  int dp[101][101] = {
      0,
  };

  for (int len = 1; len <= size; len++) {
    for (int left = 0; left <= size - len; left++) {
      int right = left + len - 1;

      dp[left][right] = len;

      int before = -1;
      for (int i = left; i < right; i++) {
        if (s[i] != s[right] && before == -1) {
          before = i;
        }
        if (before != -1) {
          dp[left][right] =
              min(dp[left][right], 1 + dp[before][i] + dp[i + 1][right]);
        }
      }

      if (before == -1) {
        dp[left][right] = 0;
      }
    }
  }

  return dp[0][size - 1] + 1;
}
```

## 고생한 점
