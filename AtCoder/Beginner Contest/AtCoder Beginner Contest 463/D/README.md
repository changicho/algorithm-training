# D - Maximize the Gap

[링크](https://atcoder.jp/contests/abc463/tasks/abc463_d)

| 난이도 |
| :----: |
|  400   |

## 설계

### 시간 복잡도

구간의 갯수를 N, 구간의 범위를 M이라 하자.

각 구간을 끝나는 시간대로 정렬하는데 O(N \* log_2(N))의 시간 복잡도를 사용한다.

구간이 떨어질 수 있는 최소거리 범위에 대해 이분탐색을 수행하는데 O(log_2(M))의 시간 복잡도를 사용한다.

각 최소거리마다 유효한지 판단하는데 O(N)의 시간복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N \* (log_2(NM))) 이다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용한다.

### 정렬 & 이분 탐색

| 내 코드 (ms) |     시간 복잡도     | 공간 복잡도 |
| :----------: | :-----------------: | :---------: |
|      47      | O(N \* (log_2(NM))) |    O(N)     |

각 구간을 끝나는 시간순으로 정렬한다.

만약 각 구간별로 최소 떨어진 거리가 D일때 구간에서 K개를 뽑아 해당 조건을 만족하는지 판단해야한다.

이를 위해 구간을 순차적으로 순회하며, 현재 구간이 이전 구간과 D이상 떨어진 경우 해당 구간을 뽑는다.

뽑은 구간의 수가 K개 미만인 경우 조건을 만족못한다.

위 조건판단은 D가 작을수록 만족하며 D가 클수록 만족하기 어려워진다. 이를 이분 탐색으로 가장 큰 D를 찾는다.

이때 모든 구간이 연속되어있는경우 답이 0이 될 수 없으므로 최소 구간의 값은 1 이상이여야한다.

```cpp
using pii = pair<int, int>;

bool check(int d, int k, vector<pii>& arr) {
  int size = arr.size();

  vector<pii> chosen;
  for (int i = 0; i < size; i++) {
    pii& cur = arr[i];

    if (chosen.empty()) {
      chosen.push_back(cur);
      continue;
    }

    if (!chosen.empty() && (cur.first - chosen.back().second) >= d) {
      chosen.push_back(cur);
    } else {
      continue;
    }
  }

  return chosen.size() >= k;
}

int solution(int size, int k, vector<pii>& arr) {
  int answer = -1;
  int left = 1, right = INT_MAX;

  sort(arr.begin(), arr.end(),
       [](auto& a, auto& b) { return a.second < b.second; });

  while (left < right) {
    int mid = left + (right - left) / 2;

    if (check(mid, k, arr)) {
      // pick right
      answer = mid;
      left = mid + 1;
    } else {
      // pick left
      right = mid;
    }
  }

  return answer;
}
```

## 고생한 점
