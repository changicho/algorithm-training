# 410. Split Array Largest Sum

[링크](https://leetcode.com/problems/split-array-largest-sum/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

nums의 숫자들의 갯수를 N, 만들어야 하는 부분을 M이라 하자.

N개의 수를 M개의 부분으로 나누는 모든 경우를 판단하는 데 들어가는 시간 복잡도는 O(N^M)이다.

이는 숫자들을 M개의 연속된 구역으로 나누기 위해서 start1, start2 ... startM 까지 탐색해야 하며 1개의 부분으로 나누는 모든 경우를 판단하는데 O(N^0)의 시간 복잡도가, 2개로 나누는 모든 경우를 판단하는데 O(N^1) ... 총 O(N^(M-1))의 시간 복잡도를 사용하기 때문이다.

이는 제한시간 내에 불가능하다.

따라서 동적 계획법을 이용해 풀이한다.

이 경우 시간 복잡도는 O(N^2 \* M) 이다.

### 공간 복잡도

부분합을 빨리 구하기 위해 O(N)의 공간 복잡도를 사용한다.

동적 계획법을 이용할 경우 O(N \* M)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     1383     | O(N^2 \* M) |  O(N \* M)  |

다음과 같은 dp식을 생성한다.

```cpp
// definition
dp[i][parts]; // dp[i][j]; minimum largest sum of 0 ~ (i - 1), when split j parts

// initial value
dp[0][0] = 0; // there are no sum when array is empty

// update
// in the current case i, part
// loop all left (0 ~ i-1)
for (int left = 0; left < i; left++) {
  // compare leftPart and rightPart
  int currentMaximum = max(dp[left][part - 1], sums(i, left));
  dp[i][part] = min(dp[i][part], currentMaximum);
}
```

이를 이용해 현재 i와 parts의 크기, 그리고 (i, part)에 대해서 가장 적게 parts를 만들기 위해 탐색할 이전 index에 대해서 탐색한다.

여기서 i ~ left 구간의 합을 빠르게 구하기 위해 부분합을 이용한다.

```cpp
vector<int> sums(size + 1, 0); // sums[i]; all sum of 0 ~ i-1
for (int i = 0; i < size; i++) {
  sums[i + 1] = sums[i] + nums[i];
}
```

이를 이용해 구현할 경우 다음과 같다.

```cpp
int splitArray(vector<int>& nums, int m) {
  int size = nums.size();
  vector<int> sums(size + 1, 0);
  for (int i = 0; i < size; i++) {
    sums[i + 1] = sums[i] + nums[i];
  }

  // dp[i][j]; minimum largest sum of 0 ~ i, when split j parts
  vector<vector<int>> dp(size + 1, vector<int>(m + 1, INT_MAX));
  dp[0][0] = 0;

  for (int i = 1; i <= size; i++) {
    for (int part = 1; part <= m; part++) {
      for (int left = 0; left < i; left++) {
        // compare leftPart and rightPart
        int currentMaximum = max(dp[left][part - 1], sums[i] - sums[left]);
        dp[i][part] = min(dp[i][part], currentMaximum);
      }
    }
  }

  return dp[size][m];
}
```

## 고생한 점
