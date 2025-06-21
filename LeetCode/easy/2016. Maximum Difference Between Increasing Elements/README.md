# 2016. Maximum Difference Between Increasing Elements

[링크](https://leetcode.com/problems/maximum-difference-between-increasing-elements/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

순회를 이용해 이전까지의 최소값과 현재 값의 차이를 계산한다.

이에 O(N)의 시간 복잡도를 갖는다.

### 공간 복잡도

직전 최소값과 정답에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

값을 왼쪽부터 순회하며 이전까지 최소값을 저장한다.

이후 현재 값과 이전까지의 최소값의 차이를 구한 뒤 정답을 갱신한다.

```cpp
int maximumDifference(vector<int>& nums) {
  int size = nums.size();
  int answer = -1;

  int minimum = INT_MAX;
  for (int& num : nums) {
    if (minimum < num) {
      answer = max(answer, num - minimum);
    }
    minimum = min(minimum, num);
  }
  return answer;
}
```

## 고생한 점
