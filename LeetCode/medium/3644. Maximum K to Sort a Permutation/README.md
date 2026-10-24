# 3644. Maximum K to Sort a Permutation

[링크](https://leetcode.com/problems/maximum-k-to-sort-a-permutation/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

순서를 바꿔야 하는 숫자들들만 찾을 수 있다.

해당 목록을 찾는 데 O(N)의 시간 복잡도를 사용한다.

이후 해당 숫자들의 AND 연산 값이 가능한 K의 최대값이 된다.

이에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

AND 연산 값을 저장하는데 O(1)의 공간 복잡도를 사용한다.

### AND연산

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

정렬을 위해 순서를 바꿔야 하는 숫자들이 존재한다.

해당 숫자들을 모두 제자리에 옮기기 위해서는 해당 모든 숫자에 대해 같은 AND연산 한 값을 만족하는 K를 찾아야한다.

이를 위해 모든 숫자들을 AND연산한 결과를 반환한다.

```cpp
int sortPermutation(vector<int>& nums) {
  int size = nums.size();

  int answer = INT_MAX;
  for (int i = 0; i < size; i++) {
    if (nums[i] == i) continue;

    answer &= nums[i];
  }
  return answer == INT_MAX ? 0 : answer;
}
```

## 고생한 점
