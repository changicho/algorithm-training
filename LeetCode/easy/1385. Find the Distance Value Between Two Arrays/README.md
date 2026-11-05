# 1385. Find the Distance Value Between Two Arrays

[링크](https://leetcode.com/problems/find-the-distance-value-between-two-arrays/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

두 배열의 크기를 각각 N, M이라 하자.

arr2를 정렬 후 이분탐색으로 현재 값과 차이가 D 이하인 숫자가 존재하는지 알 수 있다.

이 경우 정렬 후 이분탐색에 O((N + M) \* log_2(M))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(M)의 공간 복잡도를 사용한다.

### 정렬 & 이분 탐색

| 내 코드 (ms) |      시간 복잡도       | 공간 복잡도 |
| :----------: | :--------------------: | :---------: |
|      0       | O((N + M) \* log_2(M)) |    O(M)     |

num1의 숫자와 절대값 차이가 D 이하인 값이 있는지 매번 찾아야한다.

이는 X-D ~ X+D 구간의 값이 있는지 찾으면 된다.

따라서 arr2를 정렬 후 각 경우마다 이분탐색을 수행한다.

```cpp
int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
  int answer = 0;

  sort(arr2.begin(), arr2.end());

  for (int& num1 : arr1) {
    int left = num1 - d;
    int right = num1 + d;

    int count = upper_bound(arr2.begin(), arr2.end(), right) -
                lower_bound(arr2.begin(), arr2.end(), left);

    if (count == 0) answer++;
  }
  return answer;
}
```

## 고생한 점
