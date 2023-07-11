# 2765. Longest Alternating Subarray

[링크](https://leetcode.com/problems/longest-alternating-subarray/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

nums의 길이를 N이라 하자.

각 시작점에 대해 최대 길이를 매번 탐색할 경우 O(N^2)의 시간 복잡도를 사용한다.

슬라이딩 윈도우를 이용해 탐색할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

슬라이딩 윈도우를 이용할 경우 O(1)의 공간 복잡도를 사용한다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      39      |    O(N)     |    O(1)     |

윈도우의 시작점을 left, 끝점을 right라 하자.

끝점을 증가시키며 윈도우의 길이를 갱신한다.

각 경우마다 만약 diff가 이전 조건을 만족하는 경우 diff를 갱신하고 정답을 증가시킨다.

조건을 만족하지 않는 경우 윈도우의 시작점을 갱신하거나 (시작 window로 가능한 경우) diff를 초기화한다.

```cpp
int alternatingSubarray(vector<int>& nums) {
  int size = nums.size();

  int left = 1, right = 0;

  int diff = INT_MAX;
  int answer = 0;
  for (int right = 1, left = 0; right < size; right++) {
    int curDiff = nums[right] - nums[right - 1];

    if (curDiff == -diff) {
      diff *= -1;
      answer = max(answer, right - left + 1);
      continue;
    }

    if (curDiff == 1) {
      diff = curDiff;
      left = right - 1;
      answer = max(answer, right - left + 1);
    } else {
      diff = INT_MAX;
    }
  }

  if (answer == 0) return -1;
  return answer;
}
```

## 고생한 점
