# 1064. Fixed Point

[링크](https://leetcode.com/problems/fixed-point/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 arr의 크기를 N이라 하자.

이분 탐색을 사용할 경우 O(log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

이분 탐색에 O(1)의 공간 복잡도를 사용한다.

### 이분 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       | O(log_2(N)) |    O(1)     |

정렬된 배열의 index와 값이 같은 경우를 찾아야한다.

특정 i에 대해서 값이 i보다 작거나 크거나 같은 세가지 경우만 존재하며, 

각 비교에 대해서 현재 i가 같지 않으면 더 작거나 더 큰 값들은 비교하지 않아도 된다.

따라서 이를 이용해 이분 탐색을 진행한다.

```cpp
int fixedPoint(vector<int>& arr) {
  int size = arr.size();

  int left = 0, right = size;
  int answer = INT_MAX;
  while (left < right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] == mid) {
      answer = min(answer, mid);
    }
    if (arr[mid] < mid) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  return answer == INT_MAX ? -1 : answer;
}
```

## 고생한 점
