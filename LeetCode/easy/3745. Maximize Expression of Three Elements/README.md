# 3745. Maximize Expression of Three Elements

[링크](https://leetcode.com/problems/maximize-expression-of-three-elements/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

정렬 후 3개의 값을 고르는 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

순회하며 3개의 값을 고르는 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용한다.

순회에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

가장 큰 2개의 값과 가장 작은 1개의 값을 찾아야 한다.

이 때 3개의 값은 각각 다른 index여야 한다.

미리 처음 3개의 값을 통해 초기값을 설정한 후, 이후 값들을 순회하며 갱신한다.

```cpp
int maximizeExpressionOfThree(vector<int>& nums) {
  int size = nums.size();

  int minimum = min({nums[0], nums[1], nums[2]});
  int maximum1 = max({nums[0], nums[1], nums[2]});
  int maximum2 = nums[0] + nums[1] + nums[2] - minimum - maximum1;

  for (int i = 3; i < size; i++) {
    int& num = nums[i];

    if (minimum > num) {
      minimum = num;
    } else if (maximum1 <= num) {
      maximum2 = maximum1;
      maximum1 = num;
    } else if (maximum2 < num) {
      maximum2 = num;
    }
  }

  return maximum1 + maximum2 - minimum;
}
```

## 고생한 점
