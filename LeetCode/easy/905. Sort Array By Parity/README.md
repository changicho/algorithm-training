# 905. Sort Array By Parity

[링크](https://leetcode.com/problems/sort-array-by-parity/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 길이를 N이라 하자.

투 포인터를 이용해 짝수부와 홀수부를 이동시킬 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

투 포인터에 O(1)의 공간 복잡도를 사용한다.

### 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(1)     |

홀수부를 앞부분으로 이동시켜야 한다.

현재 채워넣어야 하는 짝수부분 index를 선언하고, 숫자를 왼쪽부터 순회하며 만약 현재 숫자가 홀수인 경우 짝수부 index와 swap한다.

이 때 채울 짝수부 index를 매번 갱신해준다.

```cpp
vector<int> sortArrayByParity(vector<int>& nums) {
  int size = nums.size();
  int index = 0;
  for (int i = 0; i < size; i++) {
    while (index < i && nums[index] % 2 == 0) {
      index++;
    }
    if (nums[index] % 2 == 1 && nums[i] % 2 == 0) {
      swap(nums[index], nums[i]);
      index++;
    }
  }
  return nums;
}
```

## 고생한 점
