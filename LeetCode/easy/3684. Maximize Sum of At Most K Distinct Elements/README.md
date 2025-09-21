# 3684. Maximize Sum of At Most K Distinct Elements

[링크](https://leetcode.com/problems/maximize-sum-of-at-most-k-distinct-elements/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

정렬을 사용할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      4       | O(N \* log_2(N)) |    O(N)     |

원소를 내림차순으로 정렬 후 중복되지 않은 K개의 원소를 answer에 추가한다.

```cpp
vector<int> maxKDistinct(vector<int>& nums, int k) {
  int size = nums.size();
  sort(nums.begin(), nums.end(), greater<int>());

  vector<int> answer;

  for (int i = 0; i < size; i++) {
    if (answer.empty() || answer.back() != nums[i]) {
      answer.push_back(nums[i]);
    }
    if (answer.size() == k) break;
  }
  return answer;
}
```

## 고생한 점
