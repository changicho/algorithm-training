# A - 12435

[링크](https://atcoder.jp/contests/abc390/tasks/abc390_a)

| 난이도 |
| :----: |
|  150   |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자. (N = 5)

배열이 정렬되어있는지 판단하는데 O(N)의 시간 복잡도가 필요하다.

연이은 두 수를 swap해보고 정렬하는지 모두 판단하는 데 O(N^2)의 시간 복잡도가 필요하다.

### 공간 복잡도

완전 탐색에 별도의 공간이 필요하지 않으므로 O(1)의 공간 복잡도가 필요하다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |   O(N^2)    |    O(1)     |

```cpp
bool checkSorted(vector<int> &nums) {
  int size = nums.size();
  for (int i = 0; i < size - 1; i++) {
    if (nums[i] > nums[i + 1]) {
      return false;
    }
  }
  return true;
}

bool solution(vector<int> &nums) {
  int size = nums.size();
  for (int i = 0; i < size - 1; i++) {
    swap(nums[i], nums[i + 1]);

    bool isSorted = checkSorted(nums);

    if (isSorted) {
      return true;
    }

    swap(nums[i], nums[i + 1]);
  }

  return false;
}
```

## 고생한 점
