# 2560. House Robber IV

[링크](https://leetcode.com/problems/house-robber-iv/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 배열의 크기를 N, 수를 K라 하자.

N과 K에 대해 동적 계획법을 사용할 수 있다. 이 경우 O(N \* M)의 시간 복잡도를 사용하며 이는 매우 크므로 제한시간 내에 불가능하다.

이분 탐색을 이용해 정답을 구할 수 있다.

이 경우 탐색에 O(log_2(1e9))의 시간 복잡도를 사용한다.

각 경우마다 정답인지 확인하는 데 O(N)의 시간 복잡도를 사용하므로

총 시간 복잡도는 O(N)이다.

### 공간 복잡도

이분 탐색을 사용하는 데 O(1)의 공간 복잡도를 사용한다.

### 이분 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     168      |    O(N)     |    O(1)     |

선택한 집들의 수가 K개 이상이며 이중 최대값이 최소가 되는 경우를 반환해야한다.

이 문제를 변형해 최대값이 M 이하인 집을 K개 이상 선택 가능한지를 판단하는 문제로 변환하자.

이 경우 현재 집을 K개 이상 선택 가능한 경우는 이중에서 K개만 남길 수 있으므로 정답의 후보가 될 수 있다.

이를 위해 왼쪽에서부터 탐색하며 M이하인 집을 선택하고 선택한 경우 다음 집으로 건너뛴다. (그리디 알고리즘)

현재 앞서있는 가능한 집을 우선 선택하므로 이 방법이 가장 선택할 수 있는 집의 수를 늘리는 방법이다.

이후 M에 대해 이분탐색으로 가능한 최소의 M을 찾는다.

```cpp
int getMaximumChoosableHouse(vector<int>& nums, int cost) {
  int size = nums.size();
  int count = 0;

  for (int i = 0; i < size; i++) {
    if (nums[i] <= cost) {
      count++;
      i++;
    }
  }

  return count;
}

int minCapability(vector<int>& nums, int k) {
  int size = nums.size();

  int answer = INT_MAX;
  int left = 0, right = 1e9 + 1;
  while (left < right) {
    int mid = left + (right - left) / 2;

    if (getMaximumChoosableHouse(nums, mid) >= k) {
      // pick left;
      answer = min(answer, mid);
      right = mid;
    } else {
      // pick right
      left = mid + 1;
    }
  }
  return answer;
}
```

## 고생한 점
