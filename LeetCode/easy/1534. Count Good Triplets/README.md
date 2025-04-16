# 1534. Count Good Triplets

[링크](https://leetcode.com/problems/count-good-triplets/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 arr의 크기를 N, 원소의 최대 크기를 M이라 하자.

완전 탐색을 사용할 경우 O(N^3)의 시간복잡도를 사용한다.

두 수에 대해서 순회하며 나머지 수를 확인하는 경우 O(N \* (N + M))의 시간복잡도를 사용한다.

### 공간 복잡도

완전 탐색에 O(1)의 공간복잡도를 사용한다.

두 수에 대해서 순회하며 나머지 수의 갯수를 확인하는 경우 O(M)의 공간복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      7       |   O(N^3)    |    O(1)     |

```cpp
int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
  int size = arr.size();
  int answer = 0;
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (abs(arr[i] - arr[j]) > a) continue;

      for (int k = j + 1; k < size; k++) {
        if (abs(arr[j] - arr[k]) > b) continue;
        if (abs(arr[k] - arr[i]) > c) continue;

        answer++;
      }
    }
  }
  return answer;
}
```

## 고생한 점
