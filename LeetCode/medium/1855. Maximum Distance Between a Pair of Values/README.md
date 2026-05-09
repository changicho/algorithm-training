# 1855. Maximum Distance Between a Pair of Values

[링크](https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

두 배열의 크기를 각각 N, M이라 하자.

두 배열은 내림차순으로 정렬되어있다. 따라서 이분 탐색을 사용할 수 있다.

이 경우 O(N \* log_2(M))의 시간 복잡도를 사용한다.

### 공간 복잡도

이분 탐색에 O(1)의 공간 복잡도를 사용한다.

### 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      11      | O(N \* log_2(M)) |    O(1)     |

문제 조건에 따라 `i <= j && nums1[i] <= nums2[j]` 인 j-i의 최대값을 구해야 한다.

nums1의 값을 순회하며 각 값마다 조건을 만족하는 최대 j를 구해야한다.

이를 이분 탐색을 사용해 가장 오른쪽에 있는 `nums1[i]` 이상의 값을 찾아 정답을 갱신한다.

```cpp
int maxDistance(vector<int>& nums1, vector<int>& nums2) {
  int size1 = nums1.size(), size2 = nums2.size();

  int answer = 0;
  for (int i = 0; i < size1; i++) {
    int left = i, right = size2;
    int cur = -1;
    while (left < right) {
      int mid = left + (right - left) / 2;

      if (nums1[i] <= nums2[mid]) {
        // pick right
        cur = mid;
        left = mid + 1;
      } else {
        // pick left
        right = mid;
      }
    }

    if (cur == -1) continue;

    answer = max(answer, cur - i);
  }
  return answer;
}
```

## 고생한 점
