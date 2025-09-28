# D - 2x2 Erasing 2

[링크](https://atcoder.jp/contests/abc424/tasks/abc424_d)

| 난이도 |
| :----: |
|  425   |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

모든 경우를 탐색할 경우 제한시간 내에 불가능하다.

직전 행에 대한 상태를 비트마스크로 표현할 경우 2^C 가지의 상태가 존재한다.

이를 동적 계획법을 사용해 각 행에 대해 모든 상태를 탐색할 경우 시간 복잡도는 O(R \* C \* (2^C)^2)가 된다.

### 공간 복잡도

동적 계획법에 O(R \* 2^C) 만큼의 공간이 필요하다.

### 동적 계획법

| 내 코드 (ms) |     시간 복잡도      | 공간 복잡도 |
| :----------: | :------------------: | :---------: |
|      78      | O(R \* C \* (2^C)^2) | O(R \* 2^C) |

현재 행의 상태를 (흰색, 검은색) 비트마스크로 표현할 수 있다.

이 경우 2^C가지 상태가 존재한다.

각 행의 비트 상태에 도달하기 위한 최소 변경 횟수를 동적 계획법으로 구한다.

이 경우 현재 행에 대한 최소값을 다음과 같이 구할 수 있다.

- 직전의 가능한 모든 상태를 탐색한다.
- 현재의 가능한 모든 상태에 대해서 직전 행과 현재 행을 고려했을 때 조건을 만족하는지 판단한다.
- 조건을 만족하는 경우 현재 상태와 입력으로 주어진 상태를 비교해 변경 횟수를 구한다.

이를 마지막 행까지 반복하며, 마지막 행에서의 모든 상태에 대한 최소 변경 횟수 중 최솟값이 답이 된다.

```cpp
auto solution(int rows, int cols, vector<string> &board) {
  vector<int> bit(rows);
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[y][x] == '#') {
        bit[y] |= 1 << x;
      }
    }
  }

  vector<long long> dp(1 << cols, INT_MAX);
  dp[bit[0]] = 0;

  for (int y = 0; y < rows; y++) {
    vector<long long> newDp(1 << cols, INT_MAX);

    for (int before = 0; before < (1 << cols); before++) {
      for (int next = 0; next < (1 << cols); next++) {
        int common = (before & next);

        bool isValid = true;
        for (int x = 0; x < cols - 1; x++) {
          if (((common >> x) & 1) && ((common >> (x + 1) & 1))) {
            isValid = false;
            break;
          }
        }

        if (!isValid && y > 0) continue;
        int changeCount = 0;
        common = next ^ bit[y];

        for (int x = 0; x < cols; x++) {
          if ((common >> x) & 1) {
            changeCount++;
          }
        }
        newDp[next] = min(newDp[next], dp[before] + changeCount);
      }
    }

    swap(dp, newDp);
  }

  return *min_element(dp.begin(), dp.end());
}
```

## 고생한 점
