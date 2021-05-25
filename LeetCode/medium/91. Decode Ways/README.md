# 91. Decode Ways

[링크](https://leetcode.com/problems/decode-ways/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

모든 경우를 직접 탐색할 경우 제한 시간 내에 불가능하다. (정답은 int형 이므로 10^8을 초과한다)

따라서 동적 계획법을 이용해 O(N)의 시간 복잡도로 문제를 풀이한다.

### 공간 복잡도

이전 연산의 결과를 기억 하기 위해 O(N)의 공간 복잡도가 필요하다.

1 ~ 26까지 알파벳에 대응할 숫자를 기억해야 한다. set을 이용할 경우 O(26)만큼의 공간 복잡도가 필요하다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

dp 배열을 다음과 같이 설정한다.

```cpp
dp[length]; // 길이 length 까지인 문자열에서 가능한 경우의 수
```

(좀더 직관적으로 이해하기 위해 글자를 뒤집은 후 생각한다.)

맨 처음에서 글자를 순회하며 현재 글자의 index에서 가능한 경우의 수는 다음과 같다.

- 현재 index 한 글자를 영어로 치환
- index, index - 1번째 글자를 영어로 치환

따라서 현재 경우의 수는 다음과 같다.

```cpp
dp[length] = dp[length - 1] + dp[length -2];
```

여기서 두번째 경우는 항상 만족하지 않으므로 조건을 따져야 한다.

먼저 index, index -1 두 글자를 합친 2자리 숫자가 0으로 시작하거나 알파벳 표현 범위를 벗어난 경우에는 두 글자를 영어로 바꿀 수 없다.

초기값은 다음과 같다.

```cpp
if (s[0] != '0') {
  dp[1] = 1;
  dp[2] = 1;
}

if (s[1] != '0') {
  int key = (s[1] - '0') * 10 + (s[0] - '0');
  if (0 < key && key <= 26) dp[2] += 1;
}
```

이후 length 까지 반복하며 정답을 갱신한다.

```cpp
int numDecodings(string s) {
  int answer = 0;
  if (s.front() == '0') return answer;

  int length = s.length();
  int dp[101] = {1};
  reverse(s.begin(), s.end());

  if (s.front() != '0') {
    dp[1] = 1;
    dp[2] = 1;
  }

  if (length >= 2 && s[1] != '0') {
    int key = (s[1] - '0') * 10 + (s[0] - '0');
    if (0 < key && key <= 26) {
      dp[2] += dp[0];
    }
  }

  for (int i = 3; i <= length; i++) {
    if (s[i - 2] != '0') {
      dp[i] += dp[i - 1];
    }

    if (s[i - 1] == '0') continue;
    int key = (s[i - 1] - '0') * 10 + (s[i - 2] - '0');

    if (0 < key && key <= 26 && s[i - 3] != '0') {
      dp[i] += dp[i - 2];
    }
  }

  return dp[length];
}
```

## 고생한 점
