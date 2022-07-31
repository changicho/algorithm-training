# 474. Ones and Zeroes

[링크](https://leetcode.com/problems/ones-and-zeroes/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

strs의 크기를 K, 모든 문자열의 길이의 합을 L, 입력받은 수를 M, N이라 하자.

각 str들을 순회하며 포함하고있는 0, 1의 수를 세는데 O(L)의 시간 복잡도를 사용한다.

모든 경우를 탐색할 경우 O(2^K)의 경우의 수가 나오며 이는 제한시간 내에 불가능하다.

이후 동적 계획법(knapsack)을 이용해 풀이할 경우 O(K \* M \* N)의 시간복잡도를 사용한다.

### 공간 복잡도

동적 계획법을 사용할 경우 O(K \* M \* N)의 공간 복잡도를 사용한다.

### 동적 계획법(knapsack)

| 내 코드 (ms) |    시간 복잡도     |  공간 복잡도   |
| :----------: | :----------------: | :------------: |
|     744      | O(K \* M \* N + L) | O(K \* M \* N) |

knapsack 문제이므로 다음 방법으로 풀이할 수 있다.

이 때 사용할 변수(무게)가 하나가 아니라 1의 갯수, 0의 갯수 2가지 임에 유의한다.

다음과 같은 dp식을 선언한다.

```cpp
// definition
int dp[i][m][n]; // maximum count until visit i'th str, left m, n weight

// init
dp[i][0][0] = 0;

// update
for (int zero = 0; zero <= m; zero++) {
  for (int one = 0; one <= n; one++) {
    // first str case
    if (zero - curZero < 0 || one - curOne < 0) {
      dp[i][zero][one] = dp[i - 1][zero][one];
      continue;
    }

    dp[i][zero][one] = max(dp[i - 1][zero][one], dp[i - 1][zero - curZero][one - curOne] + 1);
  }
}
```

여기서 아무것도 방문하지 않은 경우에 대해 0으로 처리를 쉽게 하기 위해 i를 1씩 증가시키고 0일때는 아무것도 방문하지 않은 상태로 유지한다.

이를 구현하면 다음과 같다.

```cpp
int findMaxForm(vector<string>& strs, int m, int n) {
  int size = strs.size();

  // dp[i][m][n] : maximum count until visit i'th str, left m, n weight
  vector<vector<vector<int>>> dp(
      size + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

  for (int i = 1; i <= size; i++) {
    int curOne = 0, curZero = 0;
    for (char& c : strs[i - 1]) {
      if (c == '0')
        curZero++;
      else if (c == '1')
        curOne++;
    }

    for (int zero = 0; zero <= m; zero++) {
      for (int one = 0; one <= n; one++) {
        if (zero - curZero < 0 || one - curOne < 0) {
          dp[i][zero][one] = dp[i - 1][zero][one];
          continue;
        }

        dp[i][zero][one] = max(dp[i - 1][zero][one],
                                dp[i - 1][zero - curZero][one - curOne] + 1);
      }
    }
  }

  return dp[size][m][n];
}
```

## 고생한 점
