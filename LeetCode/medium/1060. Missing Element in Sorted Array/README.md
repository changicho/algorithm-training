# 1060. Missing Element in Sorted Array

[링크](https://leetcode.com/problems/missing-element-in-sorted-array/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

직접 순회를 통해 풀이할 경우 시간 복잡도는 O(N)이다.

이분 탐색을 이용할 경우 O(log_2(N))이다.

### 공간 복잡도

순회, 이분탐색에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     205      |    O(N)     |    O(1)     |

missing number를 찾기 위해 nums의 시작점부터 순회한다.

여기서 k번째 missing number를 찾아야 하므로 missing넘버를 찾을 때 마다 k를 감소시키며 찾는 수를 증가시킨다.

만약 현재 찾는 수와 nums의 숫자가 같은 경우 둘 다 (찾는 숫자, index)를 증가시킨다.

```cpp
int missingElement(vector<int>& nums, int k) {
  int target = nums.front();

  int i = 0;
  while (k > 0 && i < nums.size()) {
    if (target != nums[i]) {
      k--;
      target++;
      continue;
    }

    i++;
    target++;
  }

  target--;
  if (k > 0) {
    target += k;
  }

  return target;
}
```

### 이분 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      46      |    O(N)     |    O(1)     |

현재 index에서 missing number의 개수를 다음과 같이 구할 수 있다.

- 현재 숫자와 nums의 첫번째 숫자의 차이
- 위 값에 현재 index를 뺀 값

이는 첫번째 숫자를 제외하고 현재 index는 갖고있는 숫자를 나타내고, 현재 값과 첫번째 값의 차이가 필요한 숫자를 나타내기 때문이다.

따라서 필요한 수와 가진 수의 차이를 이용해 missing number의 갯수를 구할 수 있다.

여기서 missing number의 수가 k 미만인 가장 오른쪽에 있는 index를 구한 다.

해당 index와 첫번째 값, k를 더해 정답을 구한다.

```cpp
int missingElement(vector<int>& nums, int k) {
  int size = nums.size();

  int left = 0, right = size - 1;
  while (left < right) {
    int mid = right - (right - left) / 2;

    int missing = nums[mid] - nums[0] - mid;
    if (missing < k) {
      // pick right
      left = mid;
    } else {
      // pick left
      right = mid - 1;
    }
  }

  return nums[0] + k + left;
}
```

## 고생한 점
