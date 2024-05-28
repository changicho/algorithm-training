# 1608. Special Array With X Elements Greater Than or Equal X

[링크](https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N, 각 값의 범위를 M이라 하자.

정렬을 이용한 뒤 가능한 갯수에 대해 탐색을 진행할 경우 시간 복잡도는 O(N \* log_2(N) + M)이다.

카운팅 정렬을 수행할 경우 시간 복잡도는 O(N + M)이다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도가 필요하다.

카운팅 정렬을 사용할 경우 O(M)의 공간 복잡도를 사용한다.

### 카운팅 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N + M)   |    O(M)     |

nums를 순회하며 카운팅 정렬을 수행한다.

이후 정렬된 원소에 대해 문제의 조건을 만족하는 target을 0부터 M까지 순회하며 찾는다.

이 때 target이 증가함에 따라 target보다 큰 원소의 수가 줄어들어야 하므로 target이 증가할 때마다 nums에 존재하는 target의 갯수를 뺀다.

```cpp
int specialArray(vector<int>& nums) {
  int counts[1001] = {
      0,
  };

  for (int& num : nums) {
    counts[num]++;
  }

  int left = nums.size();
  for (int target = 0; target <= 1000; target++) {
    if (target == left) return target;

    left -= counts[target];
  }

  return -1;
}
```

## 고생한 점
