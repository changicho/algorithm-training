# 2860. Happy Students

[링크](https://leetcode.com/problems/happy-students/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

크기를 빠르게 비교하기 위해 정렬을 사용한다. 이에 O(N * log_2(N))의 시간 복잡도를 사용한다.

이후 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 최대  O(1) ~ O(N)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|      88      | O(N * log_2(N)) |    O(1)     |

각 숫자를 직전값, 직후값과 비교해 이전값들과의 대소비교를 빠르게 수행하기 위해 정렬을 사용한다.

현재 index를 i라 하자.

다음 조건을 만족할 때 happy한 학생이다.

- i + 1가 i번째 학생보다 크다.
- i + 1가 i + 1번째 학생보다 작다.

```cpp
int countWays(vector<int>& nums) {
  int size = nums.size();
  sort(nums.begin(), nums.end());
  nums.push_back(INT_MAX);

  int answer = 0;
  for (int i = 0; i < size; i++) {
    if (i + 1 > nums[i] && i + 1 < nums[i + 1]) {
      answer++;
    }
  }
  if (nums[0] != 0) answer++;
  return answer;
}
```

## 고생한 점
