# 3105. Longest Strictly Increasing or Strictly Decreasing Subarray

[링크](https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

모든 경우를 탐색할 경우 O(N^2)의 시간 복잡도를 사용한다.

한번의 순회로 풀이할 경우 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

각 경우마다 직전값만 비교하므로 별도의 공간 복잡도가 필요하지 않다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

왼쪽부터 순회하며 현재값이 이전 값과 비교해 정렬되어 있는 경우 count를 증가시킨다.

이 때 증가하는 count와 감소하는 count 두 개를 관리하며 각각 경우에 따라 업데이트한다.

```cpp
int longestMonotonicSubarray(vector<int>& nums) {
  int size = nums.size();

  int answer = 1;
  int incCount = 0, descCount = 0;
  for (int i = 0; i < size; i++) {
    if (incCount > 0 && nums[i] > nums[i - 1]) {
      incCount++;
    } else {
      incCount = 1;
    }
    if (descCount > 0 && nums[i] < nums[i - 1]) {
      descCount++;
    } else {
      descCount = 1;
    }

    answer = max({answer, incCount, descCount});
  }
  return answer;
}
```

## 고생한 점
