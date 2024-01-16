# 2956. Find Common Elements Between Two Arrays

[링크](https://leetcode.com/problems/find-common-elements-between-two-arrays/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

두 배열의 크기를 각각 N, M이라 하자.

두 배열의 수들을 hash set에 저장 후 각각 순회하며 count할 수 있다.

이 경우 O(N + M)의 시간 복잡도가 소요된다.

### 공간 복잡도

hash set을 이용해 중복된 수 바로 판단할 경우 O(N + M)의 공간 복잡도가 필요하다.

### hash set

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      50      |  O(N + M)   |  O(N + M)   |

nums1, nums2의 수를 각각 hash set에 저장 후 각각 순회하며 현재 배열의 수가 다른 배열에 존재하는 지 판단한다.

존재하는 경우 count를 증가시킨다.

```cpp
vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
  unordered_set<int> us1(nums1.begin(), nums1.end()),
      us2(nums2.begin(), nums2.end());

  int count1 = 0, count2 = 0;

  for (int& num : nums1) {
    if (us2.count(num)) count1++;
  }
  for (int& num : nums2) {
    if (us1.count(num)) count2++;
  }

  return {count1, count2};
}
```

## 고생한 점
