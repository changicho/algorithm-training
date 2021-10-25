# 713. Subarray Product Less Than K

[링크](https://leetcode.com/problems/subarray-product-less-than-k/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums 배열의 크기를 N이라 하자.

범위의 left, right를 모두 정해 탐색할 경우 range를 탐색하는데 O(N^2), range의 곱을 구하는 데 O(N)의 연산이 필요하다.

구간 곱을 이용해 range의 곱을 최적화 하더라도 O(N^2)는 최악의 경우 O((3 \* 10^4)^2)이므로 제한시간 내에 불가능하다.

range는 배열의 연속된 부분이므로 슬라이딩 윈도우를 이용할 수 있다.

이 경우 시간 복잡도는 O(N)이 된다.

### 공간 복잡도

현재까지의 곱을 저장할 공간과 index를 저장할 공간이 필요하다.

이에 필요한 공간 복잡도는 O(1)이다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     111      |    O(N)     |    O(1)     |

subArray의 곱이 k이하인 경우를 구해야한다.

모든 경우를 직접 구할 경우 경우의 수는 N^2개 정도가 나오며, 이는 제한시간 내에 불가능하다.

subArray의 성질을 이용해 현재 배열의 range에서 곱이 k가 안되는 경우 right를 증가시키고, k를 초과하는 경우 left에 있는 원소를 하나씩 뺀다. (left는 증가)

이렇게 range를 조절하며 K보다 작은 subArray들을 구할 수 있다.

```cpp
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
  if (k == 0) return 0;

  int size = nums.size();

  int product = 1;
  int answer = 0;
  int left = 0;

  for (int right = 0; right < size; ++right) {
    product *= nums[right];
    while (product >= k) {
      product /= nums[left];
      ++left;
    }
    answer += max(0, right - left + 1);
  }

  return answer;
}
```

## 고생한 점
