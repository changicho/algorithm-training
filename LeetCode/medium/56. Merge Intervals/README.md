# 56. Merge Intervals

[링크](https://leetcode.com/problems/merge-intervals/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 길이는 최대 10^4 이다. 브루트 포스 방법으로 풀 경우 O(N^2)의 시간 복잡도가 필요하므로 제한시간 내에 불가능하다.

정렬을 이용할 경우 순서대로 범위를 탐색할 수 있다. 이를 이용할 경우 시간 복잡도는 정렬에 O(N \* log_2(N))이 소요되며 이후 순회에 O(N)이 소요된다.

### 공간 복잡도

정렬에 별도 공간이 필요하므로 O(N)의 공간 복잡도가 필요하다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      16      | O(N \* log_2(N)) |    O(N)     |

시작점에 대해 오름차순으로 정렬할 경우 이전에 존재하는 시작점은 현재 시작점보다 빠르다는 것이 보장된다.

따라서 현재 시작점과 직전 끝점이 겹치는 경우 이를 merge할 수 있다.

merge할 때 직전 범위에 현재 범위가 완전히 포함되는지 여부에 따라서 범위를 조절한다.

```cpp
vector<vector<int>> merge(vector<vector<int>>& intervals) {
  sort(intervals.begin(), intervals.end());

  vector<vector<int>> ret;

  for (vector<int> interval : intervals) {
    if (ret.empty()) {
      ret.push_back(interval);
      continue;
    }

    vector<int> top = ret.back();
    if (top.back() >= interval.front()) {
      ret.pop_back();
      ret.push_back({top.front(), max(top.back(), interval.back())});
    } else {
      ret.push_back(interval);
    }
  }

  return ret;
}
```

## 고생한 점
