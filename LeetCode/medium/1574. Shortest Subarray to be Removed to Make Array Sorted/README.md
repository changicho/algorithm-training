# 1574. Shortest Subarray to be Removed to Make Array Sorted

[링크](https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 arr의 크기를 N이라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(N^2)이므로 제한시간 내에 불가능하다.

투 포인터를 사용할 경우 O(N)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

투 포인터에 O(1)의 공간 복잡도가 필요하다.

### 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

배열은 다음과 같이 구성될 수 있다.

- 왼쪽 부분
- 중앙 부분 (삭제되는 부분)
- 오른쪽 부분

중앙 부분을 제거했을 때, 왼쪽 부분과 오른쪽 부분이 정렬된 배열이 되어야 한다.

왼쪽 부분을 구성하는 index를 left, 오른쪽 부분을 구성하는 index를 right로 설정한다.

맨 처음 오른쪽 부분만 정렬되어 있고 나머지 부분을 제거하는 경우의 갯수를 구한다.

이후 왼쪽 부분의 index left를 증가시키며, 유효한 right로 포인터를 이동시킨 뒤 삭제되는 중앙 부분의 갯수를 갱신한다.

```cpp
int findLengthOfShortestSubarray(vector<int>& arr) {
  int size = arr.size();
  int left = 0, right = size - 1;
  while (right > 0 && arr[right] >= arr[right - 1]) {
    right--;
  }

  int answer = right;
  while (left < right && (left == 0 || arr[left - 1] <= arr[left])) {
    while (right < size && arr[left] > arr[right]) {
      right++;
    }

    answer = min(answer, right - left - 1);
    left++;
  }

  return answer;
}
```

## 고생한 점
