# 2859. Sum of Values at Indices With K Set Bits

[링크](https://leetcode.com/problems/sum-of-values-at-indices-with-k-set-bits/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

nums의 길이를 N이라 하자. N은 최대 1000 이다.

각 수를 순회하며 index에 대해 비트가 K개인지를 판단한다.

각 index를 판단하는데 O(log_2(N))의 시간 복잡도를 사용하며 이를 모든 수에 대해 수행할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

순회와 count에 O(1)의 공간 복잡도를 사용한다.

### 정리

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|      13      | O(N * log_2(N)) |    O(1)     |

각 index에 대해 비트를 세는 함수를 실행한다.

만약 비트가 K개인 경우 index번째 숫자를 정답에 더한다.

```cpp
int count(int num) {
  int count = 0;
  while (num > 0) {
    count += num % 2;
    num /= 2;
  }
  return count;
}

int sumIndicesWithKSetBits(vector<int>& nums, int k) {
  int size = nums.size();

  int answer = 0;
  for (int i = 0; i < size; i++) {
    if (count(i) == k) {
      answer += nums[i];
    }
  }
  return answer;
}
```

## 고생한 점
