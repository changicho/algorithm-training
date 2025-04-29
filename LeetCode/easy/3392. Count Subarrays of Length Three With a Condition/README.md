# 3392. Count Subarrays of Length Three With a Condition

[링크](https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

한번의 순회를 통해 O(N) 시간 복잡도로 해결할 수 있다.

### 공간 복잡도

순회에 O(1) 공간 복잡도로 해결할 수 있다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

```cpp
int countSubarrays(vector<int>& nums) {
  int size = nums.size();

  int answer = 0;
  for (int i = 0; i < size - 2; i++) {
    int first = nums[i], second = nums[i + 1], third = nums[i + 2];

    if ((first + third) * 2 == second) answer++;
  }
  return answer;
}
```

## 고생한 점
