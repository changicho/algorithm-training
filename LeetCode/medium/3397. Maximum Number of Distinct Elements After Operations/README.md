# 3397. Maximum Number of Distinct Elements After Operations

[링크](https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N, 입력받은 수를 K라 하자.

탐욕 알고리즘을 사용하기 위해 배열의 원소를 정렬하는 데 O(N \* log_2(N))의 시간이 소요된다.

이후 순회에 O(N)의 시간이 소요된다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도가 소요된다.

### 정렬 & 탐욕 알고리즘

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     123      | O(N \* log_2(N)) |    O(N)     |

각 숫자를 오름차순으로 정렬 후, 가장 유리하게 숫자를 변경한다.

첫번째 숫자를 가능한 가장 작은 값으로 바꾼 뒤, 뒤에 숫자들 도 선택할 수 있는 가장 작은 숫자로 변경하거나, 직전 숫자보다 1 이 큰 수로 바꾼다.

각 숫자를 변경하며 최대 K까지 추가할 수 있으며, 직전 숫자와 겹치지 않는 경우 정답을 증가시킨다.

```cpp
int maxDistinctElements(vector<int>& nums, int k) {
  int size = nums.size();
  sort(nums.begin(), nums.end());

  int answer = 1;
  nums[0] -= k;
  for (int i = 1; i < size; i++) {
    nums[i] = min(max(nums[i] - k, nums[i - 1] + 1), nums[i] + k);

    if (nums[i] > nums[i - 1]) {
      answer++;
    }
  }
  return answer;
}
```

## 고생한 점
