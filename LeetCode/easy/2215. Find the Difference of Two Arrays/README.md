# 2215. Find the Difference of Two Arrays

[링크](https://leetcode.com/problems/find-the-difference-of-two-arrays/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

두 배열의 크기의 합을 N이라 하자.

각 요소들을 hash set에 저장 후 이후 순회를 통해 중복되지 않은 값을 구할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

모든 수를 hash set에 저장할 경우 O(N)의 공간 복잡도를 사용한다.

### hash set

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      54      |    O(N)     |    O(N)     |

두 hash set에 nums1, nums2의 원소들을 삽입한다.

이후 각 배열에 대해 다른 배열에 없는 원소들을 찾아 정답에 삽입한다.

```cpp
vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
  vector<vector<int>> ans(2);
  unordered_set<int> us1(nums1.begin(), nums1.end()),
      us2(nums2.begin(), nums2.end());

  for (int n : us1) {
    if (us2.count(n) == 0) {
      ans[0].push_back(n);
    }
  }

  for (int n : us2) {
    if (us1.count(n) == 0) {
      ans[1].push_back(n);
    }
  }
  return ans;
}
```

## 고생한 점
