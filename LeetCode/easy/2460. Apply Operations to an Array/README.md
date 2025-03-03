# 2460. Apply Operations to an Array

[링크](https://leetcode.com/problems/apply-operations-to-an-array/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

각 연산을 실제로 수행하는 데 O(N)의 시간 복잡도가 소요된다.

이후 숫자들과 0을 옮기는데 투 포인터를 사용할 수 있다. 이 경우 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

정답 배열을 만들경우 O(N)의 공간 복잡도가 필요하다.

입력받은 배열에 투 포인터를 이용해 이동할 경우 O(1)의 공간 복잡도를 사용한다.

### 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

문제 조건에 따라 연산을 수행한다.

이후 현재 채워넣을 숫자의 index와 0인 index를 순회하며 0이 아닌 숫자를 앞으로 옮긴다.

```cpp
vector<int> applyOperations(vector<int>& nums) {
  int size = nums.size();

  for (int i = 0; i < size - 1; i++) {
    if (nums[i] == nums[i + 1]) {
      nums[i] *= 2;
      nums[i + 1] = 0;
    }
  }
  int index = 0;
  for (int i = 0, j = 0; i < size; i++) {
    if (nums[i] != 0) {
      swap(nums[i], nums[j]);
      j++;
    }
  }
  return nums;
}
```

## 고생한 점
