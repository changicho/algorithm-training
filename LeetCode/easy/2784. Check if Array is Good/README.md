# 2784. Check if Array is Good

[링크](https://leetcode.com/problems/check-if-array-is-good/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

정렬 후 값의 위치가 valid한지 판단할 수 있다. 이 경우 정렬에 O(N \* log_2(N))의 시간 복잡도가 소요된다.

순회하며 count 후 비교할 수 있다. 이 경우 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도가 필요하다.

count에 O(N)의 공간 복잡도가 필요하다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      0       | O(N \* log_2(N)) |    O(N)     |

배열을 정렬 후 순회하며 각 index마다의 값이 index + 1인지 비교한다.

이 때 맨 마지막 값은 N-1 이여야 한다.

```cpp
bool isGood(vector<int>& nums) {
  int size = nums.size();

  sort(begin(nums), end(nums));

  for (int i = 0; i < size - 1; i++) {
    if (nums[i] != (i + 1)) return false;
  }
  if (nums.back() != size - 1) return false;
  return true;
}
```

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |    O(N)     |    O(N)     |

각 수를 count하며 N보다 큰 수가 나오면 false를 반환한다.

N-1은 2번, 나머지 수는 1번씩만 나와야 한다.

```cpp
bool isGood(vector<int>& nums) {
  int size = nums.size();

  int counts[101] = {
      0,
  };
  for (int i = 0; i < size; i++) {
    if (nums[i] >= size) return false;
    counts[nums[i]]++;

    if (nums[i] < (size - 1) && counts[nums[i]] > 1) return false;
  }
  if (counts[size - 1] > 2) return false;
  return true;
}
```

## 고생한 점
