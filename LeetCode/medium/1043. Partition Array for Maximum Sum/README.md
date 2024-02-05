# 1043. Partition Array for Maximum Sum

[링크](https://leetcode.com/problems/partition-array-for-maximum-sum/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 길이를 N, 선택할 연속된 수를 K라 하자.

모든 경우를 탐색할 경우 제한시간 내에 불가능하다.

동적 계획법을 이용해 현재 값을 갱신하는데 O(K)의 시간 복잡도를 사용하며 이를 모든 index에 대해 수행할 경우 O(N \* K)의 시간 복잡도가 소요된다.

### 공간 복잡도

동적 계획법을 사용할 경우 O(N)의 공간 복잡도가 필요하다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      7       |  O(N \* K)  |    O(N)     |

dp배열을 다음과 같이 설정한다.

```cpp
int dp[index]; // index번째 까지의 최대값

// j ~ i 까지 같은 수로 변경할 경우
dp[i] = max(dp[i], dp[j-1] + (i - j + 1) * maximum);
```

각 index까지의 최대값을 알 수 있는 경우, 현재 index에서 왼쪽으로 K개 이하의 수를 선택할 때의 최대값을 구할 수 있다.

```cpp
int maxSumAfterPartitioning(vector<int>& arr, int k) {
  int size = arr.size();
  vector<int> dp(size);

  for (int i = 0; i < size; i++) {
    int maximum = 0, best = 0;

    for (int chosen = 1; chosen <= k; chosen++) {
      int curI = i - (chosen - 1);
      int beforeI = curI - 1;

      if (curI < 0) break;
      maximum = max(maximum, arr[curI]);

      int curBest = maximum * (chosen) + (beforeI < 0 ? 0 : dp[beforeI]);

      best = max(best, curBest);
    }
    dp[i] = best;
  }

  return dp[size - 1];
}
```

## 고생한 점
