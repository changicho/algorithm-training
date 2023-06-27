# 956. Tallest Billboard

[링크](https://leetcode.com/problems/tallest-billboard/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 rods의 크기를 N, 가능한 합의 최대 크기를 M이라 하자.

모든 경우를 탐색할 경우 O(3^N)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

따라서 동적 계획법을 이용해 풀이한다.

이 경우 각 rod마다 가능한 합들에 대해 순회하며 정답을 갱신할 수 있다.

이 경우 시간 복잡도는 O(N \* M)이다.

### 공간 복잡도

동적 계획법을 이용할 경우 O(N \* M)의 공간 복잡도가 필요하다.

이 때 직전값만을 사용하므로 이를 최적화 하면 O(M)의 공간 복잡도를 사용한다.

### 동적 계획법 (공간 최적화)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     346      |  O(N \* M)  |    O(M)     |

dp를 다음과 같이 정의하자.

```cpp
int dp[diff] = smallestSumOfPair;
```

두 합의 차이를 key로, 값을 두 합중 작은 값으로 설정한다.

이 경우 현재 rod를 첫번째 막대에 더할때, 두번째 막대에 더하는 경우는 아래와 같이 나타낼 수 있다.

```cpp
dp[diff + rod]; // 첫번째 막대에 더하는 경우
dp[diff - rod]; // 두번째 막대에 더하는 경우
```

이를 토대로 다음과 같은 일반식을 나타낼 수 있다.

```cpp
dp[d + x] = max(dp[d + x], y);
dp[abs(x - d)] = max(dp[abs(x - d)], y + min(d, x));
```

이를 이용해 diff가 0인 경우가 존재할 때 까지 탐색을 진행한다.

```cpp
int tallestBillboard(vector<int>& rods) {
  // biggest pair with difference diff
  // dp[diff] = smallest sum of the pair
  unordered_map<int, int> dp;
  dp[0] = 0;
  for (int& rod : rods) {
    unordered_map<int, int> before(dp);
    for (auto it : before) {
      int sum = it.first;

      dp[sum + rod] = max(dp[sum + rod], before[sum]);
      dp[abs(sum - rod)] =
          max(dp[abs(sum - rod)], before[sum] + min(sum, rod));
    }
  }
  return dp[0];
}
```

## 고생한 점
