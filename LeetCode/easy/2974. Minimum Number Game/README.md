# 2974. Minimum Number Game

[링크](https://leetcode.com/problems/minimum-number-game/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

각 상황마다 가장 작은 값을 찾아야 한다. 이를 위해 정렬을 사용할 경우 O(N \* log_2(N))의 시간 복잡도가 소요된다.

### 공간 복잡도

정렬에 최대 O(N)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      7       | O(N \* log_2(N)) |    O(N)     |

수를 모두 정렬해 매 상황마다 가장 작은값을 고를 수 있도록 한다.

이 때 뽑은 순서와 넣는 순서는 반대이므로 연이은 값들끼리 swap한다.

```cpp
vector<int> numberGame(vector<int>& nums) {
  int size = nums.size();
  sort(nums.begin(), nums.end());

  for (int i = 0; i < size; i += 2) {
    swap(nums[i], nums[i + 1]);
  }
  return nums;
}
```

## 고생한 점
