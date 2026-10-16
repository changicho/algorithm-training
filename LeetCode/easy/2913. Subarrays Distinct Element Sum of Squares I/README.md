# 2913. Subarrays Distinct Element Sum of Squares I

[링크](https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

완전 탐색 및 hash set을 사용할 경우 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash set에 O(N)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      42      |   O(N^2)    |    O(N)     |

각 경우마다 hash set에 원소를 저장해 유니크한 원소의 수를 관리한다.

```cpp
int sumCounts(vector<int>& nums) {
  int size = nums.size();

  int answer = 0;

  for (int i = 0; i < size; i++) {
    unordered_set<int> us;
    for (int j = i; j < size; j++) {
      us.insert(nums[j]);

      answer += us.size() * us.size();
    }
  }
  return answer;
}
```

## 고생한 점
