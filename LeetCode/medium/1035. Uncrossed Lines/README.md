# 1035. Uncrossed Lines

[링크](https://leetcode.com/problems/uncrossed-lines/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums1의 크기를 N, nums2의 크기를 M이라 하자.

서로 교차하지 않는 순서를 보장하는 가장 긴 공통 subSequence를 찾아야 한다.

LCS알고리즘을 이용해 O(N \* M)의 시간 복잡도를 사용해 풀이할 수 있다.

### 공간 복잡도

LCS 알고리즘을 사용할 경우 O(N \* M)의 공간 복잡도를 사용한다.

이를 최적화 할 경우 O(min(N, M))의 공간 복잡도를 사용한다.

### LCS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      7       |  O(N \* M)  |  O(N \* M)  |

교차하는 선이 없어야 하므로, 왼쪽부터 순회하며 각 경우마다 해당 값을 선택했을 때 가능한 가장 왼쪽에 있는 선을 선택해야 한다.

이는 두 배열에서 선택한 숫자의 순서가 서로 보장됨을 의미한다.

이는 결국 선택한 숫자들의 순서가 nums1, nums2의 subSequence가 되는것이 보장된다.

따라서 LCS를 dp를 이용해 구한다.

```cpp
int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
  if (nums2.size() > nums1.size()) swap(nums2, nums1);
  int size1 = nums1.size(), size2 = nums2.size();

  int dp[501][501] = {
      0,
  };

  for (int first = 1; first <= size1; ++first) {
    for (int second = 1; second <= size2; ++second) {
      if (nums1[first - 1] == nums2[second - 1]) {
        dp[first][second] = dp[first - 1][second - 1] + 1;
      } else {
        dp[first][second] = max(dp[first - 1][second], dp[first][second - 1]);
      }
    }
  }

  return dp[size1][size2];
}
```

## 고생한 점
