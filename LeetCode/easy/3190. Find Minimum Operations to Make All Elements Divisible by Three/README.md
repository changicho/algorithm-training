# 3190. Find Minimum Operations to Make All Elements Divisible by Three

[링크](https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

각 원소를 순회하며 더하거나 뺏을 때 3의 배수가 되는 가장 작은 횟수를 더한다.

이에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

순회에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

각 원소를 순회하며 더하거나 뺏을 때 3의 배수가 되는 가장 작은 횟수를 더한다.

이 값은 3으로 나눈 나머지 mod값에 대해 mod 또는 3 - mod 중 작은 값이다.

```cpp
int minimumOperations(vector<int>& nums) {
  int answer = 0;
  for (int& num : nums) {
    int mod = num % 3;
    answer += min(mod, 3 - mod);
  }
  return answer;
}
```

## 고생한 점
