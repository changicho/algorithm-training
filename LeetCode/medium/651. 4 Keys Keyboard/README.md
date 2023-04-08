# 651. 4 Keys Keyboard

[링크](https://leetcode.com/problems/4-keys-keyboard/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

각 경우마다 모두 탐색할 경우, 현재 상태에서 가능한 경우의 수는 4가지이다.

따라서 4^N의 경우를 탐색해야하며 이는 제한시간 내에 불가능하다.

동적 계획법을 이용해 이전에 만들어 놓은 최대 값들을 이용해 풀이할 수 있다.

이 경우 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |   O(N^2)    |    O(N)     |

각 상태마다 다음의 경우의 수가 존재한다.

- A를 누른다.
- Ctrl + A
- Ctrl + C
- Ctrl + V

여기서 A만 누르는 경우는 각 경우마다 누른 횟수만큼 A가 존재한다.

이후 각 경우마다 정답이 갱신될 수 있는 경우는 복사 후 붙여넣기 하는 경우이다.

따라서 현재 경우에서 복사 한 후 붙여넣기를 반복했을 때의 경우를 탐색한다.

이를 n까지 반복한다.

```cpp
int maxA(int n) {
  // dp[i] : max A's when i presses
  int dp[51] = {
      0,
  };
  // iota(dp.begin(), dp.end(), 0);
  for (int i = 0; i <= n; i++) {
    dp[i] = i;
  }

  for (int i = 0; i <= n; i++) {
    // select, copy, paste
    for (int pastedCount = 1; i + 2 + pastedCount <= n; pastedCount++) {
      int next = i + 2 + pastedCount;
      dp[next] = max(dp[next], dp[i] + pastedCount * dp[i]);
    }
  }
  return dp[n];
}
```

## 고생한 점
