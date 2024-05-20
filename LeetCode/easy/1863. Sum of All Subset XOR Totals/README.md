# 1863. Sum of All Subset XOR Totals

[링크](https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

모든 subset을 구하는데 시간 복잡도는 O(2^N)이다.

### 공간 복잡도

DFS를 이용해 모든 subset을 구할 경우 재귀 호출의 깊이는 최대 N이다.

따라서 공간 복잡도는 O(N)이다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |   O(2^N)    |    O(N)     |

nums에 대해 subset에 포함되는 경우와 포함되지 않는 경우를 나눠 모든 경우를 탐색한다.

이후 각 과정마다 XOR연산을 수행한 값을 정답에 더한다.

```cpp
int sum = 0;

void recursive(vector<int>& nums, int size, int index, int bit) {
  if (index == size) {
    sum += bit;
    return;
  }

  recursive(nums, size, index + 1, bit);
  recursive(nums, size, index + 1, bit ^ nums[index]);
}

int subsetXORSum(vector<int>& nums) {
  int size = nums.size();

  recursive(nums, size, 0, 0);

  return sum;
}
```

## 고생한 점
