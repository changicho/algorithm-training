# 3364. Minimum Positive Sum Subarray

[링크](https://leetcode.com/problems/minimum-positive-sum-subarray/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N, 입력받은 범위를 L,R 이라 하자.

완전 탐색을 수행할 경우 O(NR)의 시간 복잡도를 사용한다.

### 공간 복잡도

완전 탐색에 O(1)의 공간 복잡도를 사용한다.

### 완전탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(NR)    |    O(1)     |

```cpp
int minimumSumSubarray(vector<int>& nums, int l, int r) {
  int size = nums.size();
  int answer = INT_MAX;

  for (int i = 0; i < size; i++) {
    int cur = 0;
    for (int j = i; j < size; j++) {
      cur += nums[j];

      int len = j - i + 1;
      if (r < len) break;
      if (l <= len && cur > 0) {
        answer = min(answer, cur);
      }
    }
  }

  if (answer == INT_MAX) return -1;
  return answer;
}
```

## 고생한 점
