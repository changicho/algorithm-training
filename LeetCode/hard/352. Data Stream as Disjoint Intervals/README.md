# 352. Data Stream as Disjoint Intervals

[링크](https://leetcode.com/problems/data-stream-as-disjoint-intervals/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

저장되는 총 원소의 갯수를 N이라 하자.

BST기반의 set을 사용할 수 있다.

이 경우 저장에 O(log_2(N))의 시간 복잡도를 사용한다.

정렬된 원소들을 순회하며 interval을 구할 때 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 원소들을 저장하는데 O(N)의 공간 복잡도를 사용한다.

### 정렬된 set

| 내 코드 (ms) |    시간 복잡도    | 공간 복잡도 |
| :----------: | :---------------: | :---------: |
|     164      | O(log_2(N)), O(N) |    O(N)     |

정렬된 원소들에서 interval을 구할 때 단순히 순회를 이용할 수 있으므로 O(N)의 시간 복잡도를 사용한다.

따라서 각 원소들을 삽입할 때마다 정렬된 상태로 유지한다.

set을 사용할 경우 O(log_2(N))의 시간 복잡도로 삽입과 동시에 정렬이 가능하다.

이를 구현하면 다음과 같다.

```cpp
class SummaryRanges {
 private:
  set<int> nums;

 public:
  SummaryRanges() {}

  void addNum(int value) { nums.insert(value); }

  vector<vector<int>> getIntervals() {
    if (nums.empty()) {
      return {};
    }
    vector<vector<int>> ret;
    int left = -1, right = -1;
    for (int num : nums) {
      if (left == -1) {
        left = right = num;
      } else if (num == right + 1) {
        right = num;
      } else {
        ret.push_back({left, right});
        left = right = num;
      }
    }
    ret.push_back({left, right});
    return ret;
  }
};
```

## 고생한 점
