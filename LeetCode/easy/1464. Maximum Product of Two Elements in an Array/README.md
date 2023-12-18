# 1464. Maximum Product of Two Elements in an Array

[링크](https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(N^2)이다.

정렬 후 가장 큰 2개의 값을 선택할 경우 시간 복잡도는 O(N \* log_2(N))이다.

한번의 순회로 가장 큰 값과 두번째로 큰 값을 선택할 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

가장 큰 값과 두번째로 큰 값을 선택하는 데 O(1)의 공간 복잡도가 필요하다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      5       |    O(N)     |    O(1)     |

문제에서 주어진 연산의 결과를 크게 하기 위해선 큰 값을 선택하는 편이 유리하다.

이는 배열 nums의 원소가 모두 양수이기 때문이다.

순회를 진행하며 가장 큰 값과 두번째로 큰 값을 찾는다.

```cpp
int maxProduct(vector<int>& nums) {
  int size = nums.size();

  int first = 0, second = 0;

  for (int& num : nums) {
    if (num >= first) {
      second = first;
      first = num;
    } else if (num > second) {
      second = num;
    }
  }
  return (first - 1) * (second - 1);
}
```

## 고생한 점
