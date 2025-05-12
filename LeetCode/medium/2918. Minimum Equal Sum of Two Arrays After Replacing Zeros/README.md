# 2918. Minimum Equal Sum of Two Arrays After Replacing Zeros

[링크](https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums1, nums2의 크기를 각각 N, M이라 하자.

두 수를 순회하며 0과 합을 세고 이후 최소 합을 구한다.

이에 O(N + M)의 시간 복잡도를 가진다.

### 공간 복잡도

합과 갯수를 세는 데 O(1)의 공간 복잡도를 가진다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     134      |  O(N + M)   |    O(1)     |

nums1, nums2를 순회하며 0의 갯수와 합을 구한다.

만약 0이 존재하는 경우 해당 값들은 최소 1씩 더해야 한다.

만약 0이 존재하지 않아 합이 고정된 경우 나머지 값으로 합을 생성할 수 있는지 확인한다.

그 외의 경우 두 배열의 각각 합과 0의 갯수를 더한 값을 비교하여 큰 값을 리턴한다.

```cpp
long long minSum(vector<int>& nums1, vector<int>& nums2) {
  int zeroCount1 = 0, zeroCount2 = 0;
  long long sum1 = 0, sum2 = 0;

  for (int& num : nums1) {
    if (num == 0) {
      zeroCount1++;
    }
    sum1 += num;
  }
  for (int& num : nums2) {
    if (num == 0) {
      zeroCount2++;
    }
    sum2 += num;
  }

  if (zeroCount2 == 0 && sum1 + zeroCount1 > sum2 + zeroCount2) {
    return -1;
  }
  if (zeroCount1 == 0 && sum1 + zeroCount1 < sum2 + zeroCount2) {
    return -1;
  }

  return max(sum1 + zeroCount1, sum2 + zeroCount2);
}
```

## 고생한 점
