# 351. Android Unlock Patterns

[링크](https://leetcode.com/problems/android-unlock-patterns/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

버튼의 갯수는 9개 이다.

모든 경우를 직접 탐색할 경우 시간 복잡도는 9! 이므로 제한시간 내에 불가능하다.

방문 여부를 비트마스크로 사용하는 동적 계획법을 사용할 경우 방문의 경우의 수는 2^9 이다.

따라서 동적 계획법을 이용할 경우 시간 복잡도는 O(2^9) 이므로 제한시간 내에 충분하다. 이는 O(1)이다.

### 공간 복잡도

동적 계획법에 방문 여부를 저장할 배열을 선언해야 한다.

이에 필요한 공간 복잡도는 O(2^9) 이다. 이는 O(1)이다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      47      |    O(1)     |    O(1)     |

각 좌표마다 특정 좌표로 이동시 중간에 거쳐야 하는 좌표를 미리 계산한다.

이후 동적 계획법을 이용해 각 경우의 수를 탐색한다.

이 때 각 좌표를 방문했을 때 현재까지 방문한 좌표의 상태를 비트마스크로 표현한다.

```cpp
int mids[9][9];

void calcMids() {
  vector<int> nums = {0, 2, 6, 8};

  for (int &from : nums) {
    for (int &to : nums) {
      if (from == to) continue;
      int mid = (from + to) / 2;

      mids[from][to] = mid;
      mids[to][from] = mid;
    }
  }
  mids[1][7] = mids[7][1] = 4;
  mids[3][5] = mids[5][3] = 4;
}

bool checkPath(int from, int to, int bit) {
  int mid = mids[from][to];

  if (mid == 0) {
    return true;
  }

  if (bit & (1 << mid)) return true;
  return false;
}

int numberOfPatterns(int m, int n) {
  calcMids();

  const int BIT_SIZE = 1 << 9;
  // [step][axis][bit]
  int dp[10][9][BIT_SIZE] = {
      0,
  };

  for (int a = 0; a < 9; a++) {
    dp[1][a][1 << a] = 1;
  }

  int answer = 0;
  if (m == 1) answer += 9;

  for (int step = 2; step <= 9; step++) {
    for (int from = 0; from < 9; from++) {
      for (int bit = 0; bit < BIT_SIZE; bit++) {
        for (int to = 0; to < 9; to++) {
          if (bit & (1 << to)) continue;

          if (!checkPath(from, to, bit)) continue;
          int newBit = bit | (1 << to);
          dp[step][to][newBit] += dp[step - 1][from][bit];

          if (m <= step && step <= n) {
            answer += dp[step - 1][from][bit];
          }
        }
      }
    }
  }

  return answer;
}
```

## 고생한 점
