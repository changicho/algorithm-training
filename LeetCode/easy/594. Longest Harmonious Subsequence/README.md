# 594. Longest Harmonious Subsequence

[링크](https://leetcode.com/problems/longest-harmonious-subsequence/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

각 값을 정렬 후 투 포인터를 사용할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

hash map을 사용하여 각 값의 개수를 세는 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash map에 O(N)의 공간 복잡도를 사용한다.

### hash map (one pass)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      43      |    O(N)     |    O(N)     |

nums의 원소를 count하며 현재 원소 +1, -1 값의 갯수를 확인한다.

이후 정답을 갱신한다.

```cpp
int findLHS(vector<int>& nums) {
  int size = nums.size();

  int answer = 0;

  unordered_map<int, int> um;
  for (int& num : nums) {
    um[num]++;

    if (um.count(num + 1)) {
      int next = um[num] + um[num + 1];
      answer = max(answer, next);
    }
    if (um.count(num - 1)) {
      int prev = um[num] + um[num - 1];
      answer = max(answer, prev);
    }
  }

  return answer;
}
```

## 고생한 점
