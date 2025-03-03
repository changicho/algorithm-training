# 2570. Merge Two 2D Arrays by Summing Values

[링크](https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums1, nums2의 크기를 각각 N, M이라 하자.

투 포인터를 사용해 두 배열을 순회하며 값을 더할 경우 시간 복잡도는 O(N + M)이다.

### 공간 복잡도

정답에 O(N + M)의 공간이 필요하다.

### 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |  O(N + M)   |  O(N + M)   |

투 포인터를 사용해 두 배열 중 id값이 작은 값을 정답에 추가한다.

만약 두 배열의 id값이 같은 경우 두 배열의 값을 더해준다.

직전에 정답에 추가한 값이 현재 값과 같은 경우 더해주고, 다른 경우 새로 추가한다.

```cpp
vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
  vector<vector<int>> answer;

  int size1 = nums1.size(), size2 = nums2.size();
  int i1 = 0, i2 = 0;

  while (i1 < size1 && i2 < size2) {
    vector<int> cur = {0, 0};
    if (nums1[i1][0] < nums2[i2][0]) {
      cur = nums1[i1];
      i1++;
    } else if (nums1[i1][0] > nums2[i2][0]) {
      cur = nums2[i2];
      i2++;
    } else {
      cur = nums1[i1];
      cur[1] += nums2[i2][1];
      i1++;
      i2++;
    }

    answer.push_back(cur);
  }

  while (i1 < size1) {
    answer.push_back(nums1[i1]);
    i1++;
  }
  while (i2 < size2) {
    answer.push_back(nums2[i2]);
    i2++;
  }
  return answer;
}
```

## 고생한 점
