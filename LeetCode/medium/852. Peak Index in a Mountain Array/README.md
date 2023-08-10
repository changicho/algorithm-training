# 852. Peak Index in a Mountain Array

[링크](https://leetcode.com/problems/peak-index-in-a-mountain-array/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 원소의 수를 N이라 하자.

O(log_2(N))의 시간 복잡도로 풀이하기 위해 이분 탐색을 이용한다.

### 공간 복잡도

이분 탐색에 O(1)의 공간 복잡도를 사용한다.

### 이분 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     112      | O(log_2(N)) |    O(1)     |

주어진 배열에서 양 끝이 아닌 index에 가장 큰 값이 있음이 보장된다.

따라서 이분탐색마다 현재 mid값을 기준으로 mid의 양쪽 값과 비교하고 큰쪽으로 이동한다.

```cpp
int peakIndexInMountainArray(vector<int>& arr) {
  int size = arr.size();

  int left = 0, right = size;
  int answerIdx = 0;
  while (left < right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] > arr[mid - 1]) {
      answerIdx = mid;
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  return answerIdx;
}
```

## 고생한 점
