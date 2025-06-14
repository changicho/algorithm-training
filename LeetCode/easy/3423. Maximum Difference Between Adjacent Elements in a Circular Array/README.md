# 3423. Maximum Difference Between Adjacent Elements in a Circular Array

[링크](https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

순회하며 인접한 두 수의 차이의 절대값 중 가장 큰 값을 찾는다.

이에 O(N)의 시간 복잡도를 갖는다.

### 공간 복잡도

최대값을 저장하는데 O(1)의 공간 복잡도를 갖는다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

인접한 두 수의 차이의 절대값을 순회하며 찾는다.

```cpp
int maxAdjacentDistance(vector<int>& nums) {
  int size = nums.size();

  int answer = 0;
  for (int i = 0; i < size; i++) {
    int cur = nums[i];
    int next = nums[(i + 1) % size];

    answer = max(abs(cur - next), answer);
  }
  return answer;
}
```

## 고생한 점
