# 436. Find Right Interval

[링크](https://leetcode.com/problems/find-right-interval/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

intervals의 크기를 N이라 하자.

시작점에 대해 정렬 후 이분 탐색을 이용할 경우 O(N * log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬을 위해 별도의 벡터를 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### 정렬 & 이분 탐색

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|      75      | O(N * log_2(N)) |    O(N)     |

각 interval들을 시작점에 대해 정렬 한다. 이 때 원래 index를 알아야 하므로 같이 저장한다.

이후 각 interval마다 끝나는 점 이후 시작하는 interval을 이분 탐색으로 찾고 정답을 갱신한다.

```cpp
struct Interval {
  int start, end, index;

  bool operator<(const Interval &b) const { return start < b.start; }
};

int getIndex(vector<Interval> &arr, int target) {
  int left = 0, right = arr.size();

  int ret = -1;
  while (left < right) {
    int mid = left + (right - left) / 2;

    if (target <= arr[mid].start) {
      // pick left;
      right = mid;
      ret = mid;
    } else {
      // pick right;
      left = mid + 1;
    }
  }

  if (ret == -1) return -1;
  return arr[ret].index;
}

vector<int> findRightInterval(vector<vector<int>> &intervals) {
  int size = intervals.size();

  vector<int> ret(size, -1);
  vector<Interval> arr;
  for (int i = 0; i < size; i++) {
    vector<int> &interval = intervals[i];
    arr.push_back({interval[0], interval[1], i});
  }

  sort(arr.begin(), arr.end());

  for (int i = 0; i < size; i++) {
    Interval &cur = arr[i];

    ret[cur.index] = getIndex(arr, cur.end);
  }

  return ret;
}
```

## 고생한 점
