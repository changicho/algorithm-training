# 935. Knight Dialer

[링크](https://leetcode.com/problems/knight-dialer/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

각 숫자마다 직전 숫자에서 이동하는 경우에 대해 동적 계획법을 수행할 수 있다.

이 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

직전 값에서만 갱신하므로 동적 계획법의 공간 복잡도를 최적화 할 수 있다. 이는 O(1)이다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     132      |    O(N)     |    O(1)     |

각 숫자에서 다음 숫자로 이동할 수 있는 경우들은 다음과 같다.

- 0 -> 4 6
- 1 -> 6 8
- 2 -> 7 9
- 3 -> 4 8
- 4 -> 3 9 0
- 5 ->
- 6 -> 1 7 0
- 7 -> 2 6
- 8 -> 1 3
- 9 -> 2 4

이를 이용해 현재 숫자에 도달하는 직전 숫자들에 대해 다음과 같은 갱신을 수행할 수 있다.

- 현재 숫자로 도달하는 경우의 수 = 직전 숫자로 도달하는 경우의 수의 합

이를 이용해 정답을 갱신한다.

```cpp
int knightDialer(int n) {
  vector<vector<int>> moves = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}};

  vector<int> before(10, 1);

  for (int i = 2; i <= n; i++) {
    vector<int> dp(10, 0);
    for (int num = 0; num <= 9; num++) {
      for (int &next : moves[num]) {
        dp[next] += before[num];
        dp[next] %= MOD;
      }
    }

    before = dp;
  }

  int answer = 0;
  for (int &num : before) {
    answer += num;
    answer %= MOD;
  }
  return answer;
}
```

## 고생한 점
