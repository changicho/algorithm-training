# 47. Permutations II

[링크](https://leetcode.com/problems/permutations-ii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

가능한 모든 조합의 개수는 8!이다. 따라서 중복을 제거하는 경우 시간 복잡도는 O(N!)이다.

여기서 수가 중복될 수도 있으므로 중복된 경우의 탐색을 피해야 한다.

### 공간 복잡도

정답은 최악의 경우 O(N!)개 이다. 따라서 해당 공간 만큼의 공간 복잡도가 필요하다.

### next_permutation

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N!)    |    O(N!)    |

next_permutation의 연산은 다음과 같다.

- 끝 점에서부터 순회하며 숫자가 증가하다가 감소하는 지점을 찾는다. (감소한 숫자 index)
- 해당 index에서부터 다시 끝까지 순회하며 해당 index의 숫자보다 작아지는 숫자의 직전 index를 기억한다.
- 두 index에 있는 숫자의 위치를 바꾼다.
- 1번에서 찾은 index의 다음부터 끝까지 뒤집는다.

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

이를 직접 구현해 조합을 만들 경우 다음과 같다.

```cpp
vector<vector<int>> permuteUnique(vector<int>& nums) {
  vector<vector<int>> answer;

  sort(nums.begin(), nums.end());

  do {
    answer.push_back(nums);
  } while (nextPermutation(nums));

  return answer;
}

bool nextPermutation(vector<int>& nums) {
  int size = nums.size();
  int decreasingIdx = size - 1;

  while (decreasingIdx > 0 && nums[decreasingIdx - 1] >= nums[decreasingIdx]) {
    decreasingIdx--;
  }
  decreasingIdx--;

  if (decreasingIdx < 0) {
    return false;
  }

  int largerIdx = size - 1;
  while (largerIdx >= 0 && nums[largerIdx] <= nums[decreasingIdx]) {
    largerIdx--;
  }
  swap(nums[decreasingIdx], nums[largerIdx]);

  reverse(nums.begin() + decreasingIdx + 1, nums.end());
  return true;
}
```

## 고생한 점
