# 4010. Maximize Pair Strength Using GCD

[링크](https://leetcode.com/problems/maximize-pair-strength-using-gcd/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N, 최대값을 M이라 하자.

완전 탐색에 O(N^2 \* log_2(M))의 시간 복잡도를 사용한다.

### 공간 복잡도

각 경우마다 gcd를 구하는데 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) |    시간 복잡도     | 공간 복잡도 |
| :----------: | :----------------: | :---------: |
|     715      | O(N^2 \* log_2(M)) |    O(1)     |

모든 쌍에 대해 정답을 갱신한다.

```cpp
long long maxPairStrength(vector<int>& nums) {
  long long answer = 0;

  int size = nums.size();

  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      long long a = 1LL * nums[i] * nums[j];
      long long b = gcd(nums[i], nums[j]);

      long long cur = a / (b * b);

      answer = max(answer, cur);
    }
  }
  return answer;
}
```

## 고생한 점
