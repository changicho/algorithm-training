# D - Intersecting Intervals

[링크](https://atcoder.jp/contests/abc355/tasks/abc355_d)

| 난이도 |
| :----: |
|  400   |

## 설계

### 시간 복잡도

주어진 구간의 길이를 N이라 하자.

각 구간을 끝점에 대해 정렬한 뒤 순회할 수 있다. 이에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이후 현재까지 방문한 구간을 저장하며 현재 구간과 이전 구간들이 겹치는 갯수를 이분 탐색으로 구한다.

이분 탐색을 수행하는데 O(log_2(N))의 시간 복잡도가 소요되므로 최종 시간 복잡도는 O(N \* log_2(N))이다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용한다.

방문한 구간의 값을 저장하는 데 O(N)의 공간 복잡도가 필요하다.

### 정렬 & 이분탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     140      | O(N \* log_2(N)) |    O(N)     |

구간들을 끝점에 대해 오름차순으로 정렬한다.

이 경우 현재까지 구간을 방문했을 때, 이전에 방문한 모든 구간들은 현재 구간 이전에 끝나는 것을 알 수 있다.

이후 이전까지 방문한 구간들의 끝나는 시간과 현재 구간의 시작 시간을 비교하며 겹치는 구간의 갯수를 구한다.

```cpp
long long solution(int size, vector<pair<int, int>> intervals) {
  // find cross pairs of intervals

  long long answer = 0;
  // sort by end time
  sort(
      intervals.begin(), intervals.end(),
      [](pair<int, int> &a, pair<int, int> &b) { return a.second < b.second; });

  vector<int> rights;
  for (int i = 0; i < size; i++) {
    int left = intervals[i].first;

    // find right count left <= right
    int overCount =
        rights.end() - lower_bound(rights.begin(), rights.end(), left);

    answer += overCount;
    rights.push_back(intervals[i].second);
  }

  return answer;
}
```

## 고생한 점
