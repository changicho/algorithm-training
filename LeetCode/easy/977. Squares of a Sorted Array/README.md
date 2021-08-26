# 977. Squares of a Sorted Array

[링크](https://leetcode.com/problems/squares-of-a-sorted-array/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 원소의 개수를 N이라 하자

정렬을 이용할 경우 O(N \* log_2(N))의 시간 복잡도로 해결이 가능하다.

투 포인터를 이용할 경우 O(N)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

정답으로 반환할 새로운 배열을 생성하므로 O(N)의 공간 복잡도가 사용된다.

deque를 이용할 경우 dq에 O(N)의 공간 복잡도가 필요하다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      40      | O(N \* log_2(N)) |    O(N)     |

새로운 배열에 숫자를 제곱한 값을 삽입 후에 정렬한다.

```cpp
vector<int> sortedSquares(vector<int>& nums) {
  vector<int> array;
  for (int& num : nums) {
    array.emplace_back(num * num);
  }

  sort(array.begin(), array.end());
  return array;
}
```

### 투 포인터 & deque

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      36      |    O(N)     |    O(N)     |

0을 기준으로 음수와 양수에서 음수인 수의 제곱이 양수의 수의 제곱보다 더 커질 수 있다.

따라서 양 끝부터 절대값이 큰 값부터 deque에 push_front를 통해 오름차순으로 정렬이 가능하다. (앞에 삽입)

```cpp
vector<int> sortedSquares(vector<int>& nums) {
  deque<int> dq;

  int left = 0, right = nums.size() - 1;

  while (left < right) {
    if (abs(nums[left]) > abs(nums[right])) {
      dq.push_front(nums[left] * nums[left]);
      left += 1;
    } else {
      dq.push_front(nums[right] * nums[right]);
      right -= 1;
    }
  }

  dq.push_front(nums[left] * nums[left]);

  vector<int> array;
  for (int num : dq) {
    array.emplace_back(num);
  }
  return array;
}
```

## 고생한 점
