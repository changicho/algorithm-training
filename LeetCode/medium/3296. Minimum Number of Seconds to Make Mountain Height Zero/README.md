# 3296. Minimum Number of Seconds to Make Mountain Height Zero

[링크](https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

높이를 H, 배열의 크기를 N, 배열의 최대값을 M이라 하자.

힙을 이용해 풀이할 경우 O((N + H) \* log_2(N))의 시간 복잡도를 가진다.

### 공간 복잡도

힙에 O(N)의 공간 복잡도를 사용한다.

### 힙

| 내 코드 (ms) |      시간 복잡도      | 공간 복잡도 |
| :----------: | :-------------------: | :---------: |
|     248      | O((N + H) * log_2(N)) |    O(N)     |

힙에 각 작업자들마다 특정 높이를 깎는데 걸리는 시간을 저장한다.

힙에 top에는 가장 작은 값이 오도록 하고 매번 작업이 끝날 때마다 해당 작업자의 다음 작업이 끝나는 시간을 계산해 힙에 넣는다.

각 경우마다 mountainHeight를 1씩 줄여가며 작업을 진행하며 각 작업자의 끝나는 시간을 answer에 저장한다.

이후 mountainHeight이 0이 되면 answer를 반환한다.

```cpp
struct Status {
  long long val;
  long long origin;
  int step;

  bool operator<(const Status& b) const { return val > b.val; }
};

long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
  long long answer = 0;

  int size = workerTimes.size();

  priority_queue<Status> pq;
  for (int& worker : workerTimes) {
    pq.push({worker, worker, 1});
  }

  while (mountainHeight > 0) {
    mountainHeight--;

    Status cur = pq.top();
    pq.pop();

    answer = cur.val;

    pq.push(
        {cur.val + cur.origin * (cur.step + 1), cur.origin, cur.step + 1});
  }

  return answer;
}
```

## 고생한 점
