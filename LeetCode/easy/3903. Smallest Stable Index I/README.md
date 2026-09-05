# 3903. Smallest Stable Index I

[링크](https://leetcode.com/problems/smallest-stable-index-i/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

매번 모든 경우를 계산할 경우 O(N^2)의 시간 복잡도를 사용한다.

suffix에 해당하는 minimum을 미리 구해놓고 각 index별로 최대값을 갱신하며 정답을 구할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

suffix를 저장하는데 O(N)의 공간 복잡도를 사용한다.

### suffix & 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

각 index에 해당하는 i ~ (N-1) 까지의 minimum값을 미리 역순회로 구해놓는다.

이후 정방향으로 index를 순회하며 maximum을 갱신 후 정답을 갱신한다.

```cpp
int firstStableIndex(vector<int>& nums, int k) {
  int size = nums.size();

  vector<int> minimum(size);
  minimum[size - 1] = nums[size - 1];

  for (int i = size - 2; i >= 0; i--) {
    minimum[i] = min(minimum[i + 1], nums[i]);
  }

  int maximum = nums[0];

  for (int i = 0; i < size; i++) {
    maximum = max(maximum, nums[i]);

    if (maximum - minimum[i] <= k) {
      return i;
    }
  }
  return -1;
}
```

## 고생한 점
