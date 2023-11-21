# 1838. Frequency of the Most Frequent Element

[링크](https://leetcode.com/problems/frequency-of-the-most-frequent-element/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

각 수를 차이가 작은 값들끼리 바로 찾을 수 있도록 정렬을 수행한다.

이에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

모든 경우를 직접 판단할 경우 O(N^2)의 시간 복잡도를 사용한다.

슬라이딩 윈도우를 이용해 각 과정에서의 최대값을 구할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 최대 O(N)의 공간 복잡도를 사용한다.

슬라이딩 윈도우를 큐로 구현할 경우 O(N)의 공간 복잡도를 사용한다. 이를 투 포인터로 구현할 경우 O(1)의 공간 복잡도를 사용한다.

### 슬라이딩 윈도우

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     152      | O(N \* log_2(N)) |    O(N)     |

현재 고른 수를 X라고 할 때 (다른 수들을 X에 맞추는 최소 값을 구함) 해당 X보다 작은 큰 수들을 순서대로 고르는 편이 cost를 줄일 수 있다.

따라서 nums를 오름차순으로 정렬 후 현재 index 이전의 값들에서 X보다 작은 값들을 모두 X로 바꾸는 비용을 계산한다.

이후 현재 index까지 순회했을 때 현재 값으로 다른 수들을 변경할 때 최대로 변경할 수 있는 수와 비용을 구한다.

index - 1까지 해당 비용을 구해놨을 경우 현재 index에서의 비용은 X와 X이전값 차이인 diff를 변경한 수 만큼 곱해 이전 비용에 더해 바로 구할 수 있다.

이는 K를 초과할 수 있으며 현재 X에 맞추기 위해 변경한 수들 중 가장 비용이 많이드는 값들(왼쪽에 있는 값들)을 제거하며 K이하의 cost를 만들 수 있다.

이를 위해 슬라이딩 윈도우를 이용해 가장 왼쪽 값들부터 제거하며 정답을 구한다.

```cpp
int maxFrequency(vector<int>& nums, int k) {
  int size = nums.size();
  sort(nums.begin(), nums.end());

  long diffSum = 0;
  int left = 0;

  int answer = 1;
  for (int right = 1; right < size; right++) {
    int diff = nums[right] - nums[right - 1];

    long curCost = diffSum + (long)(right - left) * diff;

    while (curCost > k && left < right) {
      diffSum -= nums[right - 1] - nums[left];
      left++;
      curCost = diffSum + (long)(right - left) * diff;
    }

    diffSum += (right - left) * diff;
    answer = max(answer, (right - left) + 1);
  }

  return answer;
}
```

## 고생한 점
