# 3487. Maximum Unique Subarray Sum After Deletion

[링크](https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

순회와 hash set을 이용해 중복된 원소를 제거하는데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash set에 O(N)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

nums를 순회하며 hash set에 중복된 원소를 판별하며 정답에 더한다.

이 때 음수는 제외한다.

sub array가 비면 안되므로 모든 수가 음수인 경우 이 중에서 가장 큰 값을 반환한다.

```cpp
int maxSum(vector<int>& nums) {
  unordered_set<int> us;

  int sum = 0;
  int maximum = INT_MIN;
  for (int& num : nums) {
    maximum = max(maximum, num);
    if (us.count(num) == 0 && num > 0) {
      sum += num;
      us.insert(num);
    }
  }

  if (sum == 0) {
    return maximum;
  }

  return sum;
}
```

## 고생한 점
