# 4056. Number of Intersecting Interval Pairs I

[링크](https://leetcode.com/problems/number-of-intersecting-interval-pairs-i/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

완전 탐색을 수행할 경우 O(N^2)의 시간 복잡도를 사용한다.

정렬과 우선순위 큐를 사용할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

완전 탐색에 O(1)의 공간 복잡도를 사용한다.

정렬과 우선순위 큐에 O(N)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      3       | O(N \* log_2(N)) |    O(N)     |

intervals을 시작 시간 순으로 정렬을 수행한다. (시작 시간, 끝 시간 순으로 정렬)

이후 우선순위 큐를 사용해 현재까지 끝나지 않은 interval의 수를 저장한다. (끝나는 시간을 저장한다.)

각 interval을 시작시간 순으로 순회하며 현재 시작시간보다 빨리 끝나는 interval을 우선순위 큐에서 제거한다.

이후 현재 interval과 겹치는 구간의 수는 우선순위 큐에 존재하는 갯수와 동일하다.

이후 우선순위 큐에 현재 interval의 끝나는 시간을 저장한다.

```cpp
int countIntersectingIntervals(vector<vector<int>>& intervals) {
  int size = intervals.size();

  sort(intervals.begin(), intervals.end());

  priority_queue<int, vector<int>, greater<int>> pq;

  int answer = 0;
  for (vector<int>& i : intervals) {
    while (!pq.empty() && pq.top() < i[0]) {
      pq.pop();
    }

    answer += pq.size();

    pq.push(i[1]);
  }
  return answer;
}
```

## 고생한 점
