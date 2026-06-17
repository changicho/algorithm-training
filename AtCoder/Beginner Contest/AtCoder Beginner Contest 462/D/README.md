# D - Accomplice

[링크](https://atcoder.jp/contests/abc462/tasks/abc462_d)

| 난이도 |
| :----: |
|  400   |

## 설계

### 시간 복잡도

용의자 배열의 크기를 N, 전체 시간을 T라 하자.

각 시간마다 용의자가 머무르는 시간이 존재한다.

이를 정렬후 시간별로 순회하는데 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이후 전체 시간을 순차적으로 순회하며 현재 방문중인 용의자의 나가는 시간을 힙에 관리한다.

이 경우 총 O(T + N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

힙과 정렬에 O(N)의 공간 복잡도를 사용한다.

### 힙 & 정렬

| 내 코드 (ms) |     시간 복잡도      | 공간 복잡도 |
| :----------: | :------------------: | :---------: |
|      43      | O(T + N \* log_2(N)) |    O(N)     |

특정 시간 T ~ (T + D)까지 몇명의 용의자가 머무르고 있는지를 매번 찾아야한다.

시간을 순회하며 용의자가 머무르기 시작하는 경우 용의자가 떠나는 시간을 힙에 저장한다. (top으로 갈수록 작아지는 힙)

이후 현재 시간 T일때 (T + D)보다 작은 값이 힙에 있는 경우 이를 모두 제거한다.

이를 수행하고 나면 현재 힙의 크기가 T ~ (T + D)까지 머무르는 용의자의 숫자이다.

여기서 2명을 뽑는 경우의 수를 정답에 더한다.

```cpp
ll solution(int size, int d, vector<pair<int, int>>& times) {
  const int LIMIT = 1e6 + 1;
  ll answer = 0;

  sort(times.begin(), times.end());
  int i = 0;

  priority_queue<int, vector<int>, greater<int>> pq;
  for (int t = 0; t + d <= LIMIT; t++) {
    while (i < size && times[i].first == t) {
      pq.push(times[i].second);
      i++;
    }

    while (!pq.empty() && pq.top() < t + d) {
      pq.pop();
    }

    int c = pq.size();
    answer += ll(c) * (c - 1) / 2;

    if (i == size && pq.empty()) break;
  }

  return answer;
}
```

## 고생한 점
