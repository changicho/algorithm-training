# 650. 2 Keys Keyboard

[링크](https://leetcode.com/problems/2-keys-keyboard/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

이전까지 해당 글자 수의 최소 횟수를 구해 놓을 경우, 현재 글자 수의 최소 횟수를 구할 때 이전의 최소 횟수를 이용해 구할 수 있다.

이에 O(N)의 시간 복잡도를 사용한다.

이를 모든 수에 대해 반복할 경우 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

이전 최소 횟수들을 저장해야 하므로 O(N)의 공간 복잡도가 필요하다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      13      |   O(N^2)    |    O(N)     |

만들고자 하는 문자열의 길이를 A, 시작 문자열의 길이를 B라 하자.

(A % B == 0 이라 가정한다.)

B를 복사하는데 들어가는 연산의 수는 1이다.

이후 B를 붙여넣어야 하는 횟수는 (A / B) - 1 이다.

따라서 A를 만드는데 필요한 최소 횟수는 (A / B) + B를 만드는 최소 횟수 이다.

이를 이용해 각 길이에 대해 이전 시작 문자열의 길이를 모두 순회하며 최소 횟수를 구할 수 있다.

```cpp
int minSteps(int n) {
  int dp[1001];

  dp[1] = 0;
  for (int i = 2; i <= n; i++) {
    int cur = INT_MAX;

    for (int before = 1; before <= i / 2; before++) {
      if (i % before != 0) continue;

      int operations = i / before;
      cur = min(cur, dp[before] + operations);
    }

    dp[i] = cur;
  }

  return dp[n];
}
```

## 고생한 점
