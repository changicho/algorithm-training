# 1848. Minimum Distance to the Target Element

[링크](https://leetcode.com/problems/minimum-distance-to-the-target-element/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

배열을 순회하며 값과 start와 차이를 구하는데 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

순회에 O(1)의 공간 복잡도가 소요된다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

배열을 순회하며 현재 값이 target과 같은 경우 start와의 차이를 구해 최소값을 갱신한다.

```cpp
int getMinDistance(vector<int>& nums, int target, int start) {
  int size = nums.size();

  int answer = INT_MAX;
  for (int i = 0; i < size; i++) {
    if (nums[i] == target) {
      answer = min(answer, abs(start - i));
    }
  }
  return answer;
}
```

## 고생한 점
