# 632. Smallest Range Covering Elements from K Lists

[링크](https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

2차원 배열 nums의 행의 갯수를 K, 총 원소의 갯수 N이라 하자.

각 원소를 시작점으로 설정하고 이를 이용해 각 행마다 이분 탐색을 수행해 가장 작은 범위를 찾을 수 있다.

set과 이분 탐색을 사용할 경우 O(N \* log_2(N))의 시간 복잡도가 소요된다.

힙을 이용해 각 경우마다 여러 행 중에서 가장 작은 값을 찾을 경우 O(N \* log_2(K))의 시간 복잡도가 소요된다.

### 공간 복잡도

set을 이용할 경우 O(N)의 공간 복잡도가 필요하다.

힙을 이용할 경우 O(K)의 공간 복잡도가 필요하다.

### set & 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     268      | O(N \* log_2(N)) |    O(N)     |

set을 이용해 모든 원소를 정렬하고, 이를 시작점으로 설정한다.

각 시작점 마다 lower_bound를 이용해 해당 원소보다 큰 값 중 가장 작은 값을 찾는다.

해당 값들 중 가장 큰 값과 현재 원소의 차이를 구해 가장 작은 범위를 찾는다.

```cpp
vector<int> smallestRange(vector<vector<int>> &nums) {
  set<int> s;
  for (vector<int> &arr : nums) {
    for (int &num : arr) {
      s.insert(num);
    }
  }

  vector<int> answer = {0, INT_MAX};

  for (int left : s) {
    int right = left;

    for (vector<int> &arr : nums) {
      int index = lower_bound(arr.begin(), arr.end(), left) - arr.begin();

      if (index == arr.size()) {
        right = INT_MAX;
        continue;
      }

      int target = arr[index];
      right = max(right, target);
    }

    int range = right - left;

    if (range < (answer[1] - answer[0])) {
      answer = {left, right};
    }
  }
  return answer;
}
```

### heap

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      44      | O(N \* log_2(K)) |    O(K)     |

각 행마다 최소값을 빠르게 찾기 위해 최소 heap을 이용한다.

이 때 현재 힙의 max값과 현재 힙의 top에 있는 값의 차이가 가장 작은 범위를 찾는다.

이후 가장 작은 값을 pop하고 해당 행의 다음 값을 push 한다.

이 때 더이상 다음 값을 push할 수 없는 경우에는 탐색을 중지한다.

```cpp
struct Data {
  int val, row, col;

  const bool operator<(const Data &d) const { return val > d.val; }
};

vector<int> smallestRange(vector<vector<int>> &nums) {
  int size = nums.size();

  priority_queue<Data> pq;
  int curMax = INT_MIN;
  vector<int> answer = {0, INT_MAX};

  for (int row = 0; row < size; row++) {
    pq.push({nums[row][0], row, 0});
    curMax = max(curMax, nums[row][0]);
  }

  while (pq.size() == size) {
    auto [val, row, col] = pq.top();
    pq.pop();

    if (curMax - val < (answer[1] - answer[0])) {
      answer = {val, curMax};
    }

    if (col + 1 < nums[row].size()) {
      int next = nums[row][col + 1];

      pq.push({next, row, col + 1});
      curMax = max(curMax, next);
    }
  }

  return answer;
}
```

## 고생한 점
