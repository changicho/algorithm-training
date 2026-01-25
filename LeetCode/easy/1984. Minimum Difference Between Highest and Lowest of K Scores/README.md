# 1984. Minimum Difference Between Highest and Lowest of K Scores

[링크](https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 원소의 수를 N이라 하자.

배열을 정렬 후 연이은 K개의 원소의 최대값과 최소값의 차이를 구하는 방식으로 문제를 해결할 수 있다.

이 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      0       | O(N \* log_2(N)) |    O(N)     |

배열을 정렬 후 연이은 K개의 원소를 선택한다.

이 선택한 원소들 중 최대값과 최소값의 차이를 구하고 정답을 갱신한다.

```cpp
int minimumDifference(vector<int>& nums, int k) {
  int size = nums.size();

  sort(nums.begin(), nums.end());

  int answer = INT_MAX;

  for (int i = 0; i <= size - k; i++) {
    int left = i, right = i + k - 1;

    int diff = nums[right] - nums[left];

    answer = min(answer, diff);
  }
  return answer;
}
```

## 고생한 점
