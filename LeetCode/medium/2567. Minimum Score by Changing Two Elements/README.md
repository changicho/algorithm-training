# 2567. Minimum Score by Changing Two Elements

[링크](https://leetcode.com/problems/minimum-score-by-changing-two-elements/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

정렬 후 탐욕 알고리즘을 사용할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용한다.

### 정렬 & 그리디

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      17      | O(N \* log_2(N)) |    O(N)     |

같은 원소가 2개이상 있는 경우 low score는 0임이 보장된다.

따라서 가장 점수를 작게 만들기 위해선 high score를 줄이는 방법이 유효하다.

배열을 정렬했을 때 정답의 후보는 다음 3가지 중 하나이다.

- 가장 작은 값 2개를 가장 큰값으로 변경
- 가장 큰 값 2개를 가장 작은값으로 변경
- 가장큰값, 가장작은값을 다음 값으로 변경

```cpp
int minimizeSum(vector<int>& nums) {
  int size = nums.size();
  if (size == 3) return 0;
  sort(nums.begin(), nums.end());

  int answer = INT_MAX;
  for (int i = 0; i < 3; i++) {
    int cur = nums[size - 1 - i] - nums[2 - i];
    answer = min(answer, cur);
  }
  return answer;
}
```

## 고생한 점
