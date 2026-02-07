# 3634. Minimum Removals to Balance Array

[링크](https://leetcode.com/problems/minimum-removals-to-balance-array/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

정렬을 사용할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이후 투 포인터를 사용할 경우 O(N)의 시간 복잡도를 사용한다.

각 index마다 이분 탐색을 사용할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용한다.

### 정렬 + 투 포인터

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      22      | O(N \* log_2(N)) |    O(N)     |

배열의 원소를 정렬한다.

특정 구간에 대해서 최소값과 최대값이 문제 조건에 맞는지 판단하고, 이 중 최소 제거 개수를 갱신한다.

배열을 정렬한 뒤 구간의 범위를 나타내는 두 index를 관리한다.

left index를 왼쪽부터 이동시켜가며 조건에 맞도록 right index를 이동시킨다.

```cpp
int minRemoval(vector<int>& nums, int k) {
  int size = nums.size();
  sort(nums.begin(), nums.end());

  int answer = size;

  for (int left = 0, right = 0; left < size; left++) {
    while (right < size && nums[right] <= (long long)nums[left] * k) {
      right++;
    }

    int curCount = left + (size - right);

    answer = min(answer, curCount);
  }
  return answer;
}
```

## 고생한 점
