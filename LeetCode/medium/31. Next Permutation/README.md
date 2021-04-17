# 31. Next Permutation

[링크](https://leetcode.com/problems/next-permutation/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

next_permutation의 연산은 다음과 같다.

- 끝 점에서부터 순회하며 숫자가 증가하다가 감소하는 지점을 찾는다. (감소한 숫자 index)
- 해당 index에서부터 다시 끝까지 순회하며 해당 index의 숫자보다 작아지는 숫자의 직전 index를 기억한다.
- 두 index에 있는 숫자의 위치를 바꾼다.
- 1번에서 찾은 index의 다음부터 끝까지 뒤집는다.

해당 연산들은 각각 시간복잡도가 O(N)이 소요되므로 next_permutation의 시간 복잡도는 O(N)이다.

### 공간 복잡도

연산을 수행하는 데 별도의 공간을 사용하지 않는다.

### next_permutation

STL의 next_permutation은 다음과 같다.

```cpp
template <class BidirIt>
bool next_permutation(BidirIt first, BidirIt last) {
  if (first == last) return false;
  BidirIt i = last;
  if (first == --i) return false;

  while (true) {
    BidirIt i1, i2;

    i1 = i;
    if (*--i < *i1) {
      i2 = last;
      while (!(*i < *--i2))

      std::iter_swap(i, i2);
      std::reverse(i1, last);
      return true;
    }
    if (i == first) {
      std::reverse(first, last);
      return false;
    }
  }
}
```

이를 직접 구현하면 다음과 같다.

```cpp
void nextPermutation(vector<int>& nums) {
  int size = nums.size();
  int decreasingIdx = size - 2;

  while (decreasingIdx >= 0 && nums[decreasingIdx] >= nums[decreasingIdx + 1]) {
    decreasingIdx--;
  }

  if (decreasingIdx >= 0) {
    int largerIdx = size - 1;
    while (largerIdx >= 0 && nums[largerIdx] <= nums[decreasingIdx]) {
      largerIdx--;
    }
    swap(nums[decreasingIdx], nums[largerIdx]);
  }
  reverse(nums.begin() + decreasingIdx + 1, nums.end());
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      0       |

## 고생한 점
