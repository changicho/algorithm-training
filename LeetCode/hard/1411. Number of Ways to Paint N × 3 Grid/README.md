# 1411. Number of Ways to Paint N × 3 Grid

[링크](https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

각 row별 가능한 경우의 수는 12가지 이다. 또한 각 row별 가능한 다음 row의 경우의 수는 최대 4,5가지 이다.

따라서 한 row에서 다음 row로 넘어가는 경우의 수를 미리 구해놓으면, 각 row마다 최대 5가지의 경우의 수를 탐색하게 된다.

동적 계획법을 사용할 경우 시간 복잡도는 O(N)이 된다.

### 공간 복잡도

직전 행만 사용하므로 동적 계획법에 O(1)의 공간 복잡도를 사용한다.

### 동적계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

각 행마다 패턴을 두가지로 표현할 수 있다.

- ABA : 첫번째와 세번째 색이 같고 두번째 색이 다른 패턴
- ABC : 세가지 색이 모두 다른 패턴

N이 1일 때 각 패턴의 갯수는 각각 6개이다.

이후 각 패턴에서 다음 패턴으로 넘어가는 경우의 수는 다음과 같다.

- ABA -> ABA : 2가지
- ABA -> ABC : 2가지
- ABC -> ABA : 2가지
- ABC -> ABC : 3가지

이를 이용해 패턴의 가짓수를 동적 계획법으로 구할 수 있다.

```cpp
int numOfWays(int n) {
  const int MOD = 1e9 + 7;

  long aba = 6;
  long abc = 6;

  for (int i = 1; i < n; i++) {
    long abaNew = (2 * aba + 2 * abc) % MOD;
    long abcNew = (2 * aba + 3 * abc) % MOD;

    aba = abaNew;
    abc = abcNew;
  }

  long answer = (aba + abc) % MOD;
  return answer;
}
```

### 동적계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      34      |    O(N)     |    O(1)     |

각 행의 경우의 수는 3^3 = 27가지 이다.

이 상태를 int형 3진법으로 표현한다.

또한 가능한 상태만을 미리 구해놓으며 해당 상태에서 다음 상태로 넘어가는 경우의 수를 미리 구해놓는다.

이후 동적 계획법을 이용해 각 행마다 가능한 경우의 수를 누적해나간다.

```cpp
vector<int> convert(int state) {
  int c = state % 3;
  int b = ((state - c) % 9) / 3;
  int a = state / 9;

  return {a, b, c};
}

bool isRowFine(int cur) {
  vector<int> curS = convert(cur);
  for (int i = 0; i < 2; i++) {
    if (curS[i] == curS[i + 1]) return false;
  }
  return true;
}

bool isFine(int before, int cur) {
  vector<int> beforeS = convert(before);
  vector<int> curS = convert(cur);

  if (!isRowFine(before)) return false;
  if (!isRowFine(cur)) return false;
  for (int i = 0; i < 3; i++) {
    if (beforeS[i] == curS[i]) return false;
  }
  return true;
}

int numOfWays(int n) {
  const int MOD = 1e9 + 7;
  vector<long> dp(27, 0);

  vector<int> validStates;
  vector<vector<int>> nexts(27);

  for (int s = 0; s < 27; s++) {
    if (isRowFine(s)) {
      validStates.push_back(s);
      dp[s] = 1;
    }
  }

  for (int& before : validStates) {
    for (int& next : validStates) {
      if (isFine(before, next)) {
        nexts[before].push_back(next);
      }
    }
  }

  for (int i = 1; i < n; i++) {
    vector<long> newDp(27, 0);

    for (int& before : validStates) {
      for (int& cur : nexts[before]) {
        newDp[cur] += dp[before];
        newDp[cur] %= MOD;
      }
    }

    swap(dp, newDp);
  }

  long answer = 0;
  for (int& c : validStates) {
    answer += dp[c];
    answer %= MOD;
  }

  return answer;
}
```

## 고생한 점
