# 3788. Maximum Score of a Split

[링크](https://leetcode.com/problems/maximum-score-of-a-split/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

index를 순회하며 왼쪽 부분과 오른쪽 부분의 각각 합과 최솟값을 구해야 한다.

우선순위 큐를 사용할 경우 O(N \* log_2(N))의 시간 복잡도가 소요된다.

index를 순차적으로 이동시키며 양 부분의 값을 갱신하며 최대 점수를 구할 수 있다.

이에 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

우선순위 큐를 사용할 경우 O(N)의 공간 복잡도가 소요된다.

직전 값을 갱신하며 값을 구할 경우 O(1)의 공간 복잡도가 소요된다.

### prefix suffix

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

각 index를 기준으로 suffixMin(i)의 경우 역순으로 순회하며 갱신할 수 있다.

prefixSum(i)의 경우 누적합을 미리 구한 뒤 각 역순회하며 갱신할 수 있다.

이를 이용해 역순회하며 각 경우마다의 점수를 구하고 최대 점수를 갱신한다.

```cpp
long long maximumScore(vector<int>& nums) {
  int size = nums.size();
  long long answer = LLONG_MIN;

  long long sum = accumulate(nums.begin(), nums.end(), 0LL) - nums[size - 1];
  long long beforeMin = nums[size - 1];

  for (int i = size - 2; i >= 0; i--) {
    long long cur = sum - beforeMin;
    beforeMin = min(beforeMin, (long long)nums[i]);
    sum -= nums[i];
    answer = max(cur, answer);
  }
  return answer;
}
```

## 고생한 점
