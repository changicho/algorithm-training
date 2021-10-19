# 153. Find Minimum in Rotated Sorted Array

[링크](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 원소의 개수를 N이라 하자.

한번의 순회로 가장 작은 값을 찾을 수 있으므로 O(N)의 시간 복잡도로 풀이가 가능하다.

배열 내의 원소는 정렬 후에 shift되어있으므로, 이분 탐색을 이용하면 O(log_2(N))의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

이분 탐색을 수행할 때 범위의 index값들만 이용하면 되므로 O(1)의 공간 복잡도를 사용한다.

### 이분 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       | O(log_2(N)) |    O(1)     |

주어진 배열은 오름차순으로 정렬된 배열을 shift한 배열이다.

이분탐색을 수행할 때 고려해야할 부분은 현재 구간에 shift된 부분이 있는지를 판단해야한다.

left ~ right 구간으로 탐색한다고 했을 때 현재 구간이 shift되었는지 판별은 다음과 같이 수행할 수 있다.

```cpp
bool isShifted = nums[left] > nums[right];
```

mid를 left ~ right의 중앙이라고 하자.

여기서 중요한 점은 현재 구간에서 제일 오른쪽에 위치한 값을 기준으로 판별이 가능하다는 것이다.

현재 구간이 shift되었을 경우 mid에 위치한 값이 right에 위치한 값보다 클 것이다.

shift 되지 않았을 경우 mid에 위치한 값이 right에 위치한 값보다 작을것이다.

이를 정리하면 다음과 같다.

- mid보다 right가 큰 경우
  - left ~ mid는 right보다 작은값들이 존재함
  - left ~ mid (left part)를 선택함
- mid보다 right가 작은 경우
  - left ~ mid는 right보다 큰 값들이 존재함
  - mid ~ right (right part)를 선택함

여기서 left를 기준으로 판별하지 않는 이유는 다음과 같다.

shift된 구간에서도 오름차순 정렬임이 보장되므로 다음과 같은 경우 left와 mid를 비교했을 때 작은 구간을 판별할 수 없다.

```javascript
[3, 4, 5, 1, 2];
```

이를 이용해 이분 탐색을 구현하면 다음과 같다.

```cpp
int findMin(vector<int>& nums) {
  int size = nums.size();
  int left = 0, right = size - 1;
  int answer = nums.front();

  while (left <= right) {
    int mid = left + (right - left) / 2;

    answer = min(answer, nums[mid]);

    if (nums[mid] <= nums[right]) {
      // pick left part
      right = mid - 1;
    } else {
      // pick right part
      left = mid + 1;
    }
  }

  return answer;
}
```

탐색 구간을 left ~ mid, (mid + 1) ~ right로 설정할 경우 다음과 같이 구현할 수 있다.

(left에 정답을 몰아넣는 방법)

```cpp
int findMin(vector<int>& nums) {
  int size = nums.size();
  int left = 0, right = size - 1;

  while (left < right) {
    int mid = left + (right - left) / 2;

    if (nums[mid] <= nums[right]) {
      // pick left part
      right = mid;
    } else {
      // pick right part
      left = mid + 1;
    }
  }

  return nums[left];
}
```

## 고생한 점
