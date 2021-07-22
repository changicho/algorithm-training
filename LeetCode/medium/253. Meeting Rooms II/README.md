# 253. Meeting Rooms II

[링크](https://leetcode.com/problems/meeting-rooms-ii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

모든 interval의 개수를 N이라 하자.

한번 순회를 통해서 이전에 겹치는 부분과 현재 interval이 겹치는지 확인해야 한다.

이 때 순서대로 순회를 하기 위해 입력받은 intervals를 한번 정렬한다.

이에 O(N \* log_2(N))의 시간 복잡도가 필요하다.

이후 순회하는데 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

모든 interval들을 저장하는데 O(N)의 공간 복잡도가 필요하다.

### heap

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      16      | O(N \* log_2(N)) |    O(N)     |

우선 intervals들을 특정 기준에 따라 순회하기 위해 정렬을 수행한다.

정렬의 경우 from순으로 오름차순으로 정렬하며, from이 같은 경우 to의 오름차순으로 정렬한다.

이후 직전 interval이 끝난 to를 저장할 heap을 생성한다.

interval들을 순회하며 현재 range의 시작점이 heap의 최상단에 저장되어 있는 값보다 큰경우는 겹치지 않는것이 보장되므로 heap의 최상단 값을 pop한다.

이후 현재 range의 끝나는 값을 heap에 삽입한다.

이 때 한번만 pop하는 이유는 이전의 heap의 크기를 보존하기 위함이다.

```cpp
int minMeetingRooms(vector<vector<int>>& intervals) {
  priority_queue<int, vector<int>, greater<int>> pq;
  sort(intervals.begin(), intervals.end());

  for (vector<int>& interval : intervals) {
    int from = interval[0], to = interval[1];
    if (pq.empty()) {
      pq.push(to);
      continue;
    }

    if (from >= pq.top()) pq.pop();
    pq.push(to);
  }

  return pq.size();
}
```

### map

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      16      | O(N \* log_2(N)) |    O(N)     |

다음과 같은 구조의 map을 생성한다.

- key : time
- value : count (start : +1, end : -1)

range가 시작할 때 값을 1씩 증가시키고, 끝날 때 값을 1씩 감소한다.

이를 통해 모든 time에 대해서 순회하며 value값을 이용해 겹친 구간의 count를 수행할 수 있다.

```cpp
int minMeetingRooms(vector<vector<int>>& intervals) {
  map<int, int> m;  // key: time, val: +1 if start, -1 if end

  for (vector<int>& interval : intervals) {
    int from = interval[0], to = interval[1];
    m[from]++;
    m[to]--;
  }

  int count = 0, answer = 0;
  for (auto &cur : m) {
    count += cur.second;
    answer = max(count, answer);
  }

  return answer;
}
```

## 고생한 점
