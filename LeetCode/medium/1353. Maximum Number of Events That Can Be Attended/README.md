# 1353. Maximum Number of Events That Can Be Attended

[링크](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

events 배열의 크기를 N, 가장 늦게 끝나는 날을 M이라 하자.

정렬을 이용해 이벤트를 시작하는 순으로 정렬한다.

힙을 이용해 각 경우마다 가장 먼저 끝나는 이벤트를 찾는 데 O(log_2(N))의 시간이 걸린다.

이를 모든 이벤트에 대해 반복하므로 전체 시간 복잡도는 O((M + N) \* log_2(N))이 된다.

### 공간 복잡도

정렬에 O(N) 공간이 필요하고, 힙을 사용하므로 O(N) 공간이 추가로 필요하다.

### 힙

| 내 코드 (ms) |      시간 복잡도       | 공간 복잡도 |
| :----------: | :--------------------: | :---------: |
|      61      | O((M + N) \* log_2(N)) |    O(N)     |

events 배열을 시작하는 날을 기준으로 정렬한다.

이후 가장 먼저 끝나는 이벤트를 관리하기 위해 힙을 사용한다.

이후 각 날을 순회하며 가장 먼저 끝나는 이벤트를 우선적으로 참여한다.

이 때 현재 날 이전에 끝난 이벤트들은 힙에서 제거한다.

```cpp
int maxEvents(vector<vector<int>>& events) {
  int size = events.size();
  int maxDay = 0;
  for (vector<int>& e : events) {
    maxDay = max(maxDay, e[1]);
  }

  priority_queue<int, vector<int>, greater<>> pq;
  sort(events.begin(), events.end());
  int answer = 0;

  for (int day = 0, i = 0; day <= maxDay; day++) {
    while (i < size && events[i][0] <= day) {
      pq.push(events[i][1]);
      i++;
    }

    while (!pq.empty() && pq.top() < day) {
      pq.pop();
    }
    if (!pq.empty()) {
      pq.pop();
      answer++;
    }
  }

  return answer;
}
```

## 고생한 점
