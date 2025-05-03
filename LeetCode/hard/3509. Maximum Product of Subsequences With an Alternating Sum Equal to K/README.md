# 3509. Maximum Product of Subsequences With an Alternating Sum Equal to K

[링크](https://leetcode.com/problems/maximum-product-of-subsequences-with-an-alternating-sum-equal-to-k/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 배열의 크기를 N, 수를 K, L, 배열의 모든 원소의 합을 M이라 하자.

모든 경우를 탐색할 경우 O(2^N)의 시간 복잡도를 사용하므로 제한시간 내에 불가능하다.

동적 계획법을 사용해 중복 탐색을 최소화한다.

이 때 시간 복잡도는 O(N * M * L) 이다.

### 공간 복잡도

동적 계획법에 O(N * M * L)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도  | 공간 복잡도  |
| :----------: | :----------: | :----------: |
|     1586     | O(N * M * L) | O(N * M * L) |

subsequence에 현재 원소가 포함되는 경우와 포함되지 않는 경우를 나누어 탐색한다.

이 때 현재 subsequence의 합과 갯수 (홀짝여부), 현재까지 곱에 대해 탐색을 진행하며 정답을 갱신한다.

이 때 곱의 절대값이 limit를 초과하는 경우 이후 0이 나올 경우 유효한 정답의 후보가 된다.

따라서 값을 모두 넘기지 않고 limit+1로 치환해 넘겨 overflow를 방지한다.

```cpp
int maxProduct(vector<int>& nums, int k, int limit) {
  int size = nums.size();

  int sum = accumulate(nums.begin(), nums.end(), 0);
  if (abs(k) > abs(sum)) return -1;

  unordered_map<
      int, unordered_map<int, unordered_map<int, unordered_map<int, int>>>>
      dp;

  function<int(int, int, int, int)> recursive =
      [&](int i, int count, int curSum, int curProduct) {
        if (i == size) {
          if (curSum == k && curProduct <= limit && count > 0) {
            return curProduct;
          }
          return -1;
        }

        if (dp[i][curSum][curProduct].count(count % 2)) {
          return dp[i][curSum][curProduct][count % 2];
        }

        int first = recursive(i + 1, count + 1,
                              curSum + (count % 2 == 0 ? 1 : -1) * nums[i],
                              min(curProduct * nums[i], limit + 1));
        int second = recursive(i + 1, count, curSum, curProduct);
        return dp[i][curSum][curProduct][count % 2] = max(first, second);
      };

  return recursive(0, 0, 0, 1);
}
```

## 고생한 점
