# 1547. Minimum Cost to Cut a Stick

[링크](https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 배열 cuts의 크기를 M이라 하자.

모든 경우를 탐색할 경우 O(M!)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

각 경우마다 현재까지 선택한 cuts의 leftIndex, rightIndex에 대해 동적 계획법을 사용할 수 있다.

이 경우 정렬이 필요하므로 O(M * log_2(M))의 시간 복잡도를 사용한다.

탐색의 갯수는 M^2개 이며, 각 경우마다 O(M)의 시간 복잡도를 사용하므로 최종 시간 복잡도는 O(M^3)이다.

### 공간 복잡도

동적 계획법에 O(M^2)의 공간 복잡도를 사용한다.

### 동적 계획법 (bottom-up)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      92      |   O(M^3)    |   O(M^2)    |

cuts가 오름차순으로 정렬되어있다고 가정하자.

특정 구간에서 현재 cut을 선택할 경우 정답에 추가되는 비용은 특정 구간의 길이이다.

이에 따라 특정 구간을 다음과 같이 정의하자.

- left번째 cut부터 right번째 cut까지의 구간

이 경우 left+1이 right인 경우 해당 구간에는 cut이 존재하지 않으므로 비용은 0이다.

left+2이 right인 경우 해당 구간에는 cut이 하나 존재하므로 비용은 right - left이다.

이를 통해 다음과 같은 dp식을 생성할 수 있다.

```cpp
// definition
int dp[left][right]; // left번째 cut부터 right번째 cut까지의 구간에서의 최소 비용

// base condition
dp[left][left + 1] = 0;
dp[left][left + 2] = cuts[left + 2] - cuts[left];

// update
int cur = dp[left][mid] + dp[mid][right] + cuts[right] - cuts[left];
dp[left][right] = min(dp[left][right], cur);
```

여기서 0부터 n까지의 막대에서 정답을 구해야 하므로 cuts에 0, n을 추가시켜준다.

이후 0~n까지의 구간에서의 최소 비용을 구할 수 있다.

```cpp
int minCost(int n, vector<int>& cuts) {
  cuts.push_back(0);
  cuts.push_back(n);

  sort(cuts.begin(), cuts.end());

  int size = cuts.size();
  vector<vector<int>> dp(size, vector<int>(size, INT_MAX));

  for (int i = 0; i < size - 1; i++) {
    dp[i][i + 1] = 0;
  }
  for (int i = 0; i < size - 2; i++) {
    dp[i][i + 2] = cuts[i + 2] - cuts[i];
  }

  for (int len = 4; len <= size; len++) {
    for (int left = 0; left <= size - len; left++) {
      int right = left + len - 1;

      for (int mid = left + 1; mid < right; mid++) {
        int cur = dp[left][mid] + dp[mid][right] + cuts[right] - cuts[left];

        dp[left][right] = min(dp[left][right], cur);
      }
    }
  }

  return dp[0][size - 1];
}
```

### 동적 계획법 (top-down)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      66      |   O(M^3)    |   O(M^2)    |

위 방법을 top-down으로 변경하면 아래와 같다.

```cpp
int dp[102][102] = {};
vector<int> cuts;

int recursive(int left, int right) {
  if (right - left <= 1) return 0;

  if (dp[left][right]) return dp[left][right];
  dp[left][right] = INT_MAX;

  for (int mid = left + 1; mid <= right - 1; mid++) {
    int cur = cuts[right] - cuts[left] + recursive(left, mid) +
              recursive(mid, right);

    dp[left][right] = min(dp[left][right], cur);
  }

  return dp[left][right];
}

int minCost(int n, vector<int>& cuts) {
  cuts.push_back(0);
  cuts.push_back(n);
  sort(begin(cuts), end(cuts));

  this->cuts = cuts;

  int size = cuts.size();
  recursive(0, size - 1);

  return dp[0][size - 1];
}
```

## 고생한 점
