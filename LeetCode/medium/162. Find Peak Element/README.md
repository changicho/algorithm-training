# 162. Find Peak Element

[링크](https://leetcode.com/problems/find-peak-element/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 원소의 개수를 N이라 하자.

브루트 포스로 풀이할 경우 O(N)의 시간 복잡도를 소요한다.

이분 탐색으로 풀이할 경우 O(log_2(N))의 시간 복잡도로 풀 수 있다.

### 공간 복잡도

별도로 저장할 값이 없으므로 O(1)의 공간 복잡도를 사용한다.

### 이분 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      7       | O(log_2(N)) |    O(1)     |

peak를 찾기 위해서는 다음과 같은 방법을 사용할 수 있다.

i가 peak일 때 i-1, i+1 번째 원소보다 i번째 원소가 크다.

따라서 한 방향으로 탐색하며 오름차순을 깨뜨리는 순서의 직전 값이 peak가 된다.

(여러 개의 peak 중 하나만 찾으면 되므로)

이를 이용해 이분 탐색으로 정답을 찾는다.

left ~ right 범위에서 mid번째 숫자를 비교한다고 했을 때,

- `mid > mid + 1` : 왼쪽 범위를 선택한다
- `mid <= mid + 1` : 오른쪽 범위를 선택한다.

위 조건으로 이분탐색을 수행한다.

정답을 left에 수렴시키는 경우 임계값을 고민하지 않아도 되므로 다음과 같이 구현할 수 있다.

(mid + 1 < size 조건을 만족하는 경우만 탐색)

```cpp
int findPeakElement(vector<int>& nums) {
  int size = nums.size();
  int left = 0, right = size - 1;

  while (left < right) {
    int mid = left + (right - left) / 2;

    if (nums[mid] > nums[mid + 1]) {
      // pick left part
      right = mid;
    } else {
      // pick right part
      left = mid + 1;
    }
  }

  return left;
}
```

만약 mid가 임계값이 되는 경우는 다음과 같이 구현한다.

- 임계값을 넘지 않으면서 `mid - 1 > mid` : pick left
- 임계값을 넘지 않으면서 `mid < mid + 1` : pick right
- 그 외의 경우는 mid가 정답인 경우

```cpp
int findPeakElement(vector<int>& nums) {
  int size = nums.size();
  int left = 0, right = size - 1;

  int answer = 0;
  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (mid > 0 && nums[mid - 1] > nums[mid]) {
      // pick left part
      right = mid - 1;
    } else if (mid < size - 1 && nums[mid] < nums[mid + 1]) {
      // pick right part
      left = mid + 1;
    } else {
      // find answer case
      answer = mid;
      break;
    }
  }
  return answer;
}
```

## 고생한 점

left part, right part를 고르는 부분에 조건이 들어가므로, 해당 조건을 만족하지 못할 때 정답인 탈출 케이스를 생성해야 한다.
