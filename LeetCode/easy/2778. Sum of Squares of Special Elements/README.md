# 2778. Sum of Squares of Special Elements

[링크](https://leetcode.com/problems/sum-of-squares-of-special-elements/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

순회하며 조건에 맞는 경우 정답에 더할 때 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

합에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(1)     |

각 index를 순회하며 조건에 맞는 경우 각 값의 제곱을 정답에 더한다.

```cpp
int sumOfSquares(vector<int>& nums) {
  int size = nums.size();
  int answer = 0;

  for (int i = 0; i < size; i++) {
    if (size % (i + 1) == 0) {
      answer += nums[i] * nums[i];
    }
  }
  return answer;
}
```

## 고생한 점
