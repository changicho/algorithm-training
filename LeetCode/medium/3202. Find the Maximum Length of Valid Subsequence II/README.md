# 3202. Find the Maximum Length of Valid Subsequence II

[링크](https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N, 정수를 K라 하자.

순회하며 매번 정답을 갱신할 경우 O(N^3)의 시간 복잡도를 사용한다.

동적 계획법을 사용할 경우 O(N + K^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법에 O(K^2)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     107      | O(N + K^2)  |   O(K^2)    |

다음과 같은 dp 배열을 선언한다.

```cpp
// 이전 숫자 before에서 현재숫자 cur로 이어지는 유효한 부분 수열의 길이
dp[cur][before];

dp[cur][before] = dp[before][cur] + 1;
```

이를 이용해 각 숫자마다 가능한 before에 대해서 dp 배열을 갱신한다.

이 때 더해서 K로 나눈 나머지가 같으면 되므로 각 숫자들은 K로 나눈 나머지로 변환한다.

```cpp
int maximumLength(vector<int>& nums, int k) {
  vector<vector<int>> dp(k, vector<int>(k, 0));
  int answer = 0;

  for (int& num : nums) {
    num %= k;

    for (int prev = 0; prev < k; ++prev) {
      dp[num][prev] = dp[prev][num] + 1;

      answer = max(answer, dp[num][prev]);
    }
  }

  return answer;
}
```

## 고생한 점
