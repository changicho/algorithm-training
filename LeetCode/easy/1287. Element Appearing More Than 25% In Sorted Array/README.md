# 1287. Element Appearing More Than 25% In Sorted Array

[링크](https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 arr의 원소의 갯수를 N이라 하자.

모든 원소를 순회하며 갯수를 세는 경우 시간 복잡도는 O(N)이다. 이 때 투 포인터를 사용해 공간 복잡도를 줄일 수 있다.

이분 탐색을 이용해 특정 원소의 갯수를 찾는 경우 시간 복잡도는 O(log_2(N))이다.

### 공간 복잡도

투 포인터를 사용할 경우 O(1)의 공간 복잡도를 사용한다.

이분 탐색을 사용할 경우 O(1)의 공간 복잡도를 사용한다.

### 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      13      |    O(N)     |    O(1)     |

배열은 정렬되어 있으므로 투 포인터를 사용해 원소의 갯수를 셀 수 있다.

left, right 포인터를 설정하고 right를 증가시키며 left와 값이 같을 때 까지 left를 증가시킨다.

이를 이용해 25% 이상 차지하는 원소를 찾는다.

```cpp
int findSpecialInteger(vector<int>& arr) {
  int size = arr.size();

  for (int right = 0, left = 0; right < size; right++) {
    while (left < right && arr[left] != arr[right]) {
      left++;
    }

    int count = right - left + 1;
    if (count > size / 4) return arr[right];
  }
  return -1;
}
```

### 이분 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      13      | O(log_2(N)) |    O(1)     |

문제에서 정답은 존재하므로 25% 이상 차지하는 원소는 항상 존재한다.

이는 원소의 index 중에서 다음 3 지점중 하나에는 무조건 존재해야 한다.

- size / 4 \* 1
- size / 4 \* 2
- size / 4 \* 3

해당 위치의 값의 갯수를 이분 탐색을 이용해 찾고 해당 값이 25% 이상 차지하는지 검사한다.

```cpp
int findSpecialInteger(vector<int>& arr) {
  int size = arr.size();
  vector<int> candidates = {arr[size / 4], arr[size / 2], arr[3 * size / 4]};

  for (int& candidate : candidates) {
    int count = upper_bound(arr.begin(), arr.end(), candidate) -
                lower_bound(arr.begin(), arr.end(), candidate);

    if (count > size / 4) {
      return candidate;
    }
  }

  return -1;
}
```

## 고생한 점
