# 1095. Find in Mountain Array

[링크](https://leetcode.com/problems/find-in-mountain-array/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

배열의 원소의 갯수를 N이라 하자.

이분 탐색을 이용해 O(log_2(N))의 시간 복잡도를 충족할 수 있다.

주어진 배열은 mountain array 이므로 상승부와 하강부를 구분한 뒤 이분탐색을 각각 수행한다.

이에 필요한 시간 복잡도는 O(log_2(N))이다.

### 공간 복잡도

이분 탐색에 O(1)의 공간 복잡도를 사용한다.

### 이분 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     3         |   O(log_2(N))          |      O(1)       |

주어진 배열은 mountain array 이다.

이는 배열을 상승부와 하강부로 나눌 수 있음을 의미한다.

가장 큰 값을 우선 이분 탐색으로 찾은 뒤 이 값을 기준으로 상승부와 하강부를 탐색한다.

이 때 상승부와 하강부는 각각 오름차순, 내림차순으로 정렬되어있음이 보장된다.

```cpp
int findPeak(MountainArray &mountainArr) {
  int size = mountainArr.length();

  int left = 1, right = size - 1;
  int ret = 0;
  while (left < right) {
    int mid = left + (right - left) / 2;

    int val = mountainArr.get(mid);
    int prev = mountainArr.get(mid - 1);
    int next = mountainArr.get(mid + 1);

    if (prev < val && val > next) {
      ret = mid;
      break;
    }
    if (prev < val) {
      // pick right
      left = mid + 1;
    } else if (val > next) {
      // pick left
      right = mid;
    }
  }
  return ret;
}

int findInMountainArray(int target, MountainArray &mountainArr) {
  int size = mountainArr.length();

  int peak = findPeak(mountainArr);
  int answer = INT_MAX;

  int left, right;
  // leftPart
  left = 0, right = peak + 1;
  while (left < right) {
    int mid = left + (right - left) / 2;

    int val = mountainArr.get(mid);
    if (val < target) {
      // pick right
      left = mid + 1;
    } else if (val > target) {
      // pick left
      right = mid;
    } else {
      answer = min(answer, mid);
      break;
    }
  }

  // right part
  left = peak, right = size;
  while (left < right) {
    int mid = left + (right - left) / 2;

    int val = mountainArr.get(mid);
    if (val > target) {
      // pick right
      left = mid + 1;
    } else if (val < target) {
      // pick left
      right = mid;
    } else {
      answer = min(answer, mid);
      break;
    }
  }
  if (answer == INT_MAX) return -1;
  return answer;
}
```

## 고생한 점
