# 3320. Count The Number of Winning Sequences

[링크](https://leetcode.com/problems/count-the-number-of-winning-sequences/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

모든 경우를 탐색할 경우 O(3^N)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

동적 계획법을 이용해 각 index마다 alice와 bob의 점수 차이에 대해 경우의 수를 구할 수 있다.

이 경우 시간 복잡도는 O(N^2)이다.

### 공간 복잡도

동적 계획법을 이용할 경우 O(N^2)의 공간 복잡도가 필요하다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     685      |   O(N^2)    |   O(N^2)    |

다음과 같은 dp 배열을 생성한다.

alice와 bob이 비기는 경우도 존재하므로 각각의 점수가 아닌 점수의 차이를 이용한다.

diff가 양수일 때 bob이 이기는 경우이며 음수일 때 alice가 이기는 경우이다.

```cpp
// index에서 bob이 type인 경우 점수 차이가 diff인 경우의 수
int dp[index][type][diff];

// 초기값
dp[0][type][diff] = isBobWin(s[0], type);

// update
for (int type = 0; type <= 2; type++) {
  for (int beforeType = 0; beforeType <= 2; beforeType++) {
    if (type == beforeType) continue;

    for (int &beforeDiff : beforeDiffs) {
      int beforeCase = memo[i - 1][beforeType][beforeDiff];

      int curDiff = beforeDiff + isBobWin(s[i], type);

      memo[i][type][curDiff] += beforeCase;
    }
  }
}
```

이후 마지막 index에서 각 type별로 diff가 1이상인 경우의 수를 모두 더한다.

```cpp
const int MOD = 1e9 + 7;

vector<char> types = {'F', 'W', 'E'};

int isBobWin(char &a, char &b) {
  if (a == b) return 0;
  if (a == 'W' && b == 'E') return +1;
  if (a == 'E' && b == 'F') return +1;
  if (a == 'F' && b == 'W') return +1;
  return -1;
}

int countWinningSequences(string s) {
  int size = s.size();

  const int MID = 1000;

  // [index][type][diff] = case
  int memo[1001][3][2001] = {
      0,
  };

  int half = (size + 1) / 2;

  int minimum = MID - half, maximum = MID;
  for (int type = 0; type <= 2; type++) {
    int curDiff = MID + isBobWin(s[0], types[type]);

    maximum = max(maximum, curDiff);

    memo[0][type][curDiff] = 1;
  }

  for (int i = 1; i < size; i++) {
    for (int type = 0; type <= 2; type++) {
      for (int before = 0; before <= 2; before++) {
        if (type == before) continue;

        int left = minimum, right = maximum;

        for (int beforeDiff = left; beforeDiff <= right; beforeDiff++) {
          int beforeCase = memo[i - 1][before][beforeDiff];
          if (beforeCase == 0) continue;

          int curDiff = beforeDiff + isBobWin(s[i], types[type]);

          maximum = max(maximum, curDiff);

          memo[i][type][curDiff] += beforeCase;
          memo[i][type][curDiff] %= MOD;
        }
      }
    }
  }
  int answer = 0;
  for (int type = 0; type <= 2; type++) {
    for (int diff = MID + 1; diff <= maximum; diff++) {
      answer += memo[size - 1][type][diff];
      answer %= MOD;
    }
  }

  return answer;
}
```

## 고생한 점
