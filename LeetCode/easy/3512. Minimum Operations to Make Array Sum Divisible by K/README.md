# 3512. Minimum Operations to Make Array Sum Divisible by K

[링크](https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

모든 원소의 합을 구한 뒤 K로 나누어 떨어지지 않는 경우 해당 차이를 구한다.

이에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

합에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

연산 한번당 배열 nums의 원소의 값을 1씩 감소시킬 수 있다.

모든 원소의 합을 구한 뒤, K로 나누어 떨어지지 않는 경우 해당 나머지값만큼 빼줄 경우 K로 나누어 떨어지게 된다.

```cpp
int minOperations(vector<int>& nums, int k) {
  int sum = accumulate(nums.begin(), nums.end(), 0);

  return sum % k;
}
```

## 고생한 점
