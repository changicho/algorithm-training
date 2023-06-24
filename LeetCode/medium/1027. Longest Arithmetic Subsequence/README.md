# 1027. Longest Arithmetic Subsequence

[링크](https://leetcode.com/problems/longest-arithmetic-subsequence/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 배열의 길이를 N, 값의 범위를 M이라 하자.

직접 모든 경우를 탐색할 경우 O(N^3)의 시간 복잡도를 사용한다.

동적 계획법을 이용해 이전 단계에서의 값을 받아와 갱신할 경우 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법을 사용할 경우 각 index에서 diff가 될 수 있는 후보들을 저장해야 한다. 이에 O(N \* M)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     134      |   O(N^2)    |  O(N \* M)  |

현재 값을 A, 비교하고자 하는 값을 B라고 하자.

A-B를 diff라고 할 때, B에서 끝나는 subsequence 중에서 diff가 같은 subsequence의 길이를 알 수 있다면, A에서 끝나는 subsequence의 길이를 알 수 있다.

따라서 각 index마다 diff값들을 저장하고 갱신한다.

이후 왼쪽부터 순회하며 매 index로 끝나는 subsequence의 값들과 정답을 갱신한다.

```cpp
int longestArithSeqLength(vector<int>& nums) {
  int size = nums.size();
  int dp[1001][1001] = {
      0,
  };

  int answer = 0;
  for (int i = 0; i < size; i++) {
    for (int before = 0; before < i; before++) {
      int curDiff = nums[i] - nums[before] + 500;

      int curMax = dp[before][curDiff] + 1;
      dp[i][curDiff] = max(dp[i][curDiff], curMax);

      answer = max(answer, dp[i][curDiff]);
    }
  }

  return answer + 1;
}
```

## 고생한 점

hash map으로 구현할 경우 시간초과가 발생한다.
