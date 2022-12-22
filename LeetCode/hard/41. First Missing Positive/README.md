# 41. First Missing Positives

[링크](https://leetcode.com/problems/first-missing-positive/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 배열의 크기를 N이라 하자.

입력받은 수를 순회하며 counting 정렬을 수행할 경우 중간에 빠진 원소를 이후 O(N)의 순회로 탐색 가능하다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

별도의 공간을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

입력받은 nums를 이용할 경우 O(1)의 공간 복잡도를 사용한다.

### index hashing

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     143      |    O(N)     |    O(1)     |

입력받은 수를 순회하며 0이거나 음수거나 절대값이 N보다 큰 경우는 무시하고 넘어간다.

이 경우 순회하는 수들은 N보다 작으며, 이는 입력받은 배열 nums의 index로 처리가 가능하다.

따라서 각 수를 순회하며 해당 수에 매칭하는 index의 값을 음수로 변경할 수 있다.

이 때 이전에 순회하며 해당 값을 음수로 바꿧을 수도 있으므로, 해당 수의 절대값을 이용한다.

이 때 입력받은 수에 N이 있는 경우를 처리해야 하기 때문에 index-1을 변경한다.

```cpp
int firstMissingPositive(vector<int> &nums) {
  int size = nums.size();
  for (auto &num : nums) {
    if (num <= 0 || num > size) {
      num = size + 1;
    }
  }

  for (int &num : nums) {
    if (abs(num) <= size) {
      if (nums[abs(num) - 1] > 0) nums[abs(num) - 1] = -nums[abs(num) - 1];
    }
  }
  for (int i = 0; i < size; i++) {
    if (nums[i] >= 0) return i + 1;
  }
  return size + 1;
}
```

## 고생한 점
