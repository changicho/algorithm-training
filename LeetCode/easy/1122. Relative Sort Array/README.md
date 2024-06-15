# 1122. Relative Sort Array

[링크](https://leetcode.com/problems/relative-sort-array/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 arr1, arr2의 크기를 각각 N, M이라 하자.

각 배열의 수의 범위는 0 ~ 1000 이다. 이 최대값을 K라 하자.

카운팅 정렬을 사용할 경우 O(N + M + K)의 시간 복잡도를 사용한다.

### 공간 복잡도

카운팅 정렬을 사용할 경우 O(K)의 공간 복잡도를 사용한다.

정답 배열에 O(N)의 공간 복잡도를 사용한다.

### 카운팅 정렬

| 내 코드 (ms) | 시간 복잡도  | 공간 복잡도 |
| :----------: | :----------: | :---------: |
|      0       | O(N + M + K) |  O(N + K)   |

각 수들을 카운팅 한 후, 우선 arr2를 순회하며 우선순위가 높은 순으로 저장한다.

이후 남은 수들은 크기가 작은 순으로 저장한다.

```cpp
vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
  int counts[1001];

  for (int& num : arr1) {
    counts[num]++;
  }

  vector<int> answer;
  for (int& num : arr2) {
    while (counts[num] > 0) {
      answer.push_back(num);
      counts[num]--;
    }
  }

  for (int num = 0; num <= 1000; num++) {
    while (counts[num] > 0) {
      answer.push_back(num);
      counts[num]--;
    }
  }

  return answer;
}
```

## 고생한 점
