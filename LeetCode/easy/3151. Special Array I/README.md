# 3151. Special Array I

[링크](https://leetcode.com/problems/special-array-i/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

한번의 순회를 이용해 풀이할 경우 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

연이은 값들의 parity만 비교할 경우 별도의 공간이 필요하지 않다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

연속된 값들의 패리티 (홀수, 짝수)가 같은지 비교한다.

```cpp
bool isArraySpecial(vector<int>& nums) {
  int size = nums.size();

  for (int i = 0; i < size - 1; i++) {
    int first = nums[i] % 2;
    int second = nums[i + 1] % 2;

    if (first == second) return false;
  }
  return true;
}
```

## 고생한 점
