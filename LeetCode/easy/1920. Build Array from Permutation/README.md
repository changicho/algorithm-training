# 1920. Build Array from Permutation

[링크](https://leetcode.com/problems/build-array-from-permutation/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

배열을 순회하며 새 배열을 만들 경우 O(N)의 시간 복잡도를 가진다.

직접 배열을 수정할 경우 O(N)의 시간 복잡도를 가진다.

### 공간 복잡도

새 배열을 생성할 경우 O(N)의 공간 복잡도를 가진다.

직접 배열을 수정할 경우 O(1)의 공간 복잡도를 가진다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

nums의 각 원소는 1 ~ 1000 사이의 N-1 까지의 정수이다.

따라서 nums의 최대값은 999가 된다.

각 index마다 값을 변환할 때 1000을 곱하여 원래 값을 보존할 수 있다.

이후 1000으로 나누어 원래 값을 복원할 수 있다.

```cpp
vector<int> buildArray(vector<int> &nums) {
  int size = nums.size();

  for (int &num : nums) {
    num += 1000 * (nums[num] % 1000);
  }
  for (int &num : nums) {
    num /= 1000;
  }

  return nums;
}
```

## 고생한 점
