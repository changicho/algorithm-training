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

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

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
  int left = size - 2, right = size - 1;

  // find first decreasing point from back (nums[i] < nums[i+1])
  while (left >= 0) {
    if (nums[left] < nums[left + 1]) {
      break;
    }
    left--;
  }

  // if there are no decreasing point (already sorted descending order)
  if (left < 0) {
    // rearrange it sorted in ascending order
    reverse(nums.begin(), nums.end());
    return;
  }

  // find first point nums[left] < nums[right]
  while (left < right) {
    if (nums[left] < nums[right]) {
      break;
    }
    right--;
  }

  // swap left and right
  swap(nums[left], nums[right]);
  // reverse the part after left
  reverse(nums.begin() + left + 1, nums.end());
}
```

## 고생한 점
