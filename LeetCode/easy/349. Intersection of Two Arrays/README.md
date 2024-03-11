# 349. Intersection of Two Arrays

[링크](https://leetcode.com/problems/intersection-of-two-arrays/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums1의 크기를 N, nums2의 크기를 M이라 하자.

두 배열을 순회하며 교집합을 구할 경우 시간 복잡도는 O(N \* M)이다.

hash set을 이용해 교집합을 구할 경우 O(N + M)의 시간 복잡도로 구할 수 있다.

### 공간 복잡도

hash set에 O(N)또는 O(M)의 공간 복잡도를 사용한다.

### hash set

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |  O(N + M)   |    O(N)     |

nums1의 원소를 hash set에 저장한다.

이후 nums2를 순회하며 hash set에 존재하는지 확인하고 존재할 경우 answer에 추가한다.

```cpp
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
  unordered_set<int> us(nums1.begin(), nums1.end());

  vector<int> answer;
  for (int& num : nums2) {
    if (us.count(num) > 0) {
      answer.push_back(num);
      us.erase(num);
    }
  }

  return answer;
}
```

## 고생한 점
