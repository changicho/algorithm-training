# 491. Non-decreasing Subsequences

[링크](https://leetcode.com/problems/non-decreasing-subsequences/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 원소의 수를 N이라 하자. (N <= 15)

모든 경우를 탐색해야 하므로 DFS로 탐색을 수행한다.

이 때 각 경우마다 가능한 경우만 다음으로 진행한다. (backtracking)

이후 정답에서 중복을 제거한다.

이를 위해 set, hash set을 사용할 수 있으며 set을 사용할 경우 최대 O(N^2)의 시간 복잡도를 사용한다.

시간 복잡도는 O(2^N \* N^2)이다.

### 공간 복잡도

정답의 경우의 수에 O(2^N)의 공간 복잡도를 사용한다.

각 경우마다 O(N)의 공간 복잡도를 사용하므로 O(2^N \* N)의 공간 복잡도를 사용한다.

### backtracking

| 내 코드 (ms) |  시간 복잡도  | 공간 복잡도 |
| :----------: | :-----------: | :---------: |
|      74      | O(2^N \* N^2) | O(2^N \* N) |

DFS를 이용해 모든 경우를 탐색하며, 가능한 경우만 진행한다.

이후 정답에서 중복을 제거한다.

```cpp
set<vector<int>> answer;

void recursive(int index, vector<int> &nums, vector<int> &cur) {
  int size = nums.size();

  if (size == index) {
    if (cur.size() >= 2) {
      answer.insert(cur);
    }
    return;
  }

  if (cur.empty() || cur.back() <= nums[index]) {
    cur.push_back(nums[index]);
    recursive(index + 1, nums, cur);
    cur.pop_back();
  }

  recursive(index + 1, nums, cur);
}

vector<vector<int>> findSubsequences(vector<int> &nums) {
  vector<int> cur;
  recursive(0, nums, cur);

  vector<vector<int>> ret;
  for (auto &ans : answer) {
    ret.push_back(ans);
  }
  return ret;
}
```

## 고생한 점
