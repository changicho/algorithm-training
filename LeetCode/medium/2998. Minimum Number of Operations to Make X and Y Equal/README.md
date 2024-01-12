# 2998. Minimum Number of Operations to Make X and Y Equal

[링크](https://leetcode.com/problems/minimum-number-of-operations-to-make-x-and-y-equal/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 두 숫자의 범위중 최대값을 N이라 하자.

X를 다른 숫자로 변화시키는 데 들어가는 최소 연산의 수를 구해야 한다. 이를 동적 계획법으로 구할 경우 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

동적 계획법에 O(N)의 공간 복잡도가 필요하다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      16      |    O(N)     |    O(N)     |

X를 다른 숫자로 변환시키는 최소 횟수를 BFS를 이용해 구한다.

이 때 두 수의 최대값은 10,000 이며 해당 수 이상으로는 변화시키지 않아도 된다.

```cpp
int minimumOperationsToMakeEqual(int x, int y) {
  vector<int> dp(10001, INT_MAX);

  queue<int> q;
  q.push(x);
  dp[x] = 0;

  int step = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    if (cur == y) break;

    if (cur % 11 == 0) {
      int next = cur / 11;
      if (dp[next] == INT_MAX) {
        q.push(next);
        dp[next] = dp[cur] + 1;
      }
    }
    if (cur % 5 == 0) {
      int next = cur / 5;
      if (dp[next] == INT_MAX) {
        q.push(next);
        dp[next] = dp[cur] + 1;
      }
    }
    if (cur > 0) {
      int next = cur - 1;
      if (dp[next] == INT_MAX) {
        q.push(next);
        dp[next] = dp[cur] + 1;
      }
    }
    if (cur < 10000) {
      int next = cur + 1;
      if (dp[next] == INT_MAX) {
        q.push(next);
        dp[next] = dp[cur] + 1;
      }
    }
  }

  return dp[y];
}
```

## 고생한 점
