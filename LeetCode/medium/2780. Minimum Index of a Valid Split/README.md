# 2780. Minimum Index of a Valid Split

[링크](https://leetcode.com/problems/minimum-index-of-a-valid-split/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

가장 많은 빈도의 수를 찾는데 O(N)의 시간 복잡도가 소요된다.

이후 각 경우에 대해서 두 배열로 나누는 경우를 탐색해야한다.

이에 대한 시간 복잡도는 O(N)이다.

### 공간 복잡도

각 수별로 빈도를 찾기 위해 hash map을 사용할 경우 O(N)의 공간 복잡도가 필요하다.

보이어 무어의 알고리즘을 이용할 경우 O(1)의 공간 복잡도가 필요하다.

### 보이어 무어 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      7       |    O(N)     |    O(1)     |

가장 빈도가 높은 수가 절반 이상을 차지하는 상황에서 보이어 무어 알고리즘을 사용해 가장 빈도가 높은 수를 구할 수 있다.

이후 해당 수의 빈도를 찾고, 해당 수를 기준으로 두 배열로 나누는 경우를 탐색한다.

```cpp
int minimumIndex(vector<int> &nums) {
  int size = nums.size();

  int target = nums[0], count = 0;
  for (int &num : nums) {
    if (num == target) {
      count++;
    } else {
      count--;
    }
    if (count == 0) {
      target = num;
      count = 1;
    }
  }
  count = 0;
  for (int &num : nums) {
    if (num == target) count++;
  }

  int left = 0, right = count;
  for (int i = 0; i < size - 1; i++) {
    if (nums[i] == target) {
      left++;
      right--;
    }
    int leftSize = i + 1, rightSize = size - (i + 1);

    if (left >= (leftSize / 2) + 1 && right >= (rightSize / 2) + 1) {
      return i;
    }
  }
  return -1;
}
```

## 고생한 점
