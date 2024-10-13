# 2406. Divide Intervals Into Minimum Number of Groups

[링크](https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 intervals의 크기를 N, interval의 범위의 최대값을 M이라 하자.

정렬을 이용해 각 interval의 시작점을 기준으로 정렬한다.

이후 interval을 이용하며 multiset을 이용해 그룹에 삽입할 위치를 찾을 수 있다. 이에 O(N \* log_2(N))의 시간 복잡도가 필요하다.

각 시점마다 추가, 삭제되는 카운트의 변화에 대해 정렬을 사용할 수 있다. 이 경우 O(N \* log_2(N))의 시간 복잡도가 필요하다.

카운팅 정렬을 사용할 경우 O(N + M)의 시간 복잡도가 필요하다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도가 필요하다.

카운팅 정렬에 O(M)의 공간 복잡도가 필요하다.

### multiset

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     389      | O(N \* log_2(N)) |    O(N)     |

interval을 시작점을 기준으로 정렬한다.

이후 각 interval을 순회하며 multiset에 끝나는 시간을 삽입한다.

이 때 현재 interval의 시작점보다 이르게 끝나는 시간이 multiset에 존재하는 경우 해당 시간을 제거하고 현재 interval의 끝나는 시간을 삽입한다.

```cpp
int minGroups(vector<vector<int>>& intervals) {
  sort(intervals.begin(), intervals.end());

  multiset<int> ms;
  int answer = 0;
  for (vector<int>& interval : intervals) {
    int left = interval[0], right = interval[1];

    auto it = ms.lower_bound(left);
    if (it == ms.begin()) {
      ms.insert(right);
    } else {
      int target = *prev(it);
      // remove only one
      ms.extract(target);
      ms.insert(right);
    }

    answer = max((int)ms.size(), answer);
  }

  return answer;
}
```

### 정렬 & count

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     248      | O(N \* log_2(N)) |    O(N)     |

interval의 시작점, 끝 점을 분리해 각각을 pair로 묶어 정렬한다.

이 때 시작점은 +1, 끝점은 -1로 표시한다.

이후 각 시간마다 순회하며 시작점이 나오면 count를 증가시키고, 끝점이 나오면 count를 감소시킨다.

해당 count 중 최대값이 동시에 존재하는 그룹의 갯수이다.

```cpp
int minGroups(vector<vector<int>>& intervals) {
  vector<pair<int, int>> inAndOut;
  for (vector<int>& interval : intervals) {
    int left = interval[0], right = interval[1];

    // income +1, outcome -1
    inAndOut.push_back({left, 1});
    inAndOut.push_back({right + 1, -1});
  }

  sort(inAndOut.begin(), inAndOut.end());

  int answer = 0;
  int curSize = 0;
  for (pair<int, int>& p : inAndOut) {
    curSize += p.second;

    answer = max(answer, curSize);
  }

  return answer;
}
```

### 카운팅 정렬 & count

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     216      |  O(N + M)   |    O(M)     |

위 방법에서 정렬을 카운팅 정렬로 변경한다.

```cpp
int minGroups(vector<vector<int>>& intervals) {
  int inAndOut[1000002] = {
      0,
  };

  int from = INT_MAX, to = INT_MIN;
  for (vector<int>& interval : intervals) {
    int left = interval[0], right = interval[1];

    inAndOut[left]++;
    inAndOut[right + 1]--;

    from = min(from, left);
    to = max(to, right + 1);
  }

  int answer = 0;
  int curSize = 0;

  for (int time = from; time <= to; time++) {
    curSize += inAndOut[time];

    answer = max(answer, curSize);
  }

  return answer;
}
```

## 고생한 점
