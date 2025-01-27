# 2948. Make Lexicographically Smallest Array by Swapping Elements

[링크](https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

각 숫자를 swap할 수 있는 그룹별로 묶은 뒤 해당 그룹들만 정렬한다.

이 경우 O(N \* log_2(N))의 시간 복잡도가 소요된다.

### 공간 복잡도

숫자별로 그룹을 생성하는 데 O(N)의 공간 복잡도가 필요하다.

### 그룹 & 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     471      | O(N \* log_2(N)) |    O(N)     |

두 인덱스 i, j에 대해서 swap이 가능한 경우는 두 수의 차가 limit 이하인 경우이다.

chaining이 가능한 경우는 숫자들을 정렬했을 때 연이은 두 숫자 차이가 limit 이하인 경우이다.

이 경우 해당 숫자들은 모두 순서를 바꿀 수 있다.

따라서 nums의 숫자들을 chaining이 가능한 그룹으로 묶은 뒤, 해당 그룹들을 정렬한다.

```cpp
vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit) {
  int size = nums.size();

  // make group by limit
  vector<int> copied = nums;
  sort(copied.begin(), copied.end());

  vector<deque<int>> groups;
  groups.push_back({});
  for (int &num : copied) {
    if (!groups.back().empty() && num - groups.back().back() > limit) {
      groups.push_back({});
    }

    groups.back().push_back(num);
  }

  unordered_map<int, int> um;
  for (int g = 0; g < groups.size(); g++) {
    for (int &num : groups[g]) {
      um[num] = g;
    }
  }

  // change group num to sorted
  for (int i = 0; i < size; i++) {
    int g = um[nums[i]];

    nums[i] = groups[g].front();
    groups[g].pop_front();
  }

  return nums;
}
```

## 고생한 점
