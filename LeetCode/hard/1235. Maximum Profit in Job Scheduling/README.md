# 1235. Maximum Profit in Job Scheduling

[링크](https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 작업의 수를 N이라 하자. (N은 최대 5 \* 10^4)

모든 경우를 탐색할 경우 O(2^N)의 시간 복잡도를 사용하며, 이는 제한 시간 내에 불가능하다.

각 작업을 우선 정렬 후, 현재 작업이 이전 작업들 보다 늦게 끝난다는것이 확실 할 때 동적 계획법을 사용할 수 있다.

이 경우 정렬에 O(N \* log_2(N))의 시간 복잡도를, 각 순회하며 현재 값을 갱신하는 데 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     212      | O(N \* log_2(N)) |    O(N)     |

각 작업을 끝나는 시간을 기준으로 정렬한다.

이는 이전까지 방문한 작업들이 현재 작업 이전에 끝나는 것이 확실한 경우, 이전 작업들을 다시 방문할 필요가 없기 때문이다.

dp값을 다음과 같이 정의한다.

```cpp
dp[time]; // until time, maximum profit
```

현재 작업에 대해서 dp값을 갱신할 때 다음 2가지 경우가 존재한다.

- 선택 가능한 이전까지 최대 profit과 현재 profit의 합
- 직전 최대 profit 값

여기서 선택 가능한 이전까지 최대 profit 값은 현재 startTime보다 이하의 key를 갖는 dp값중 최대값이다.

key는 정렬되어있으며 이를 빠르게 구하기 위해 이분 탐색을 사용한다.

이를 이용해 구현하면 다음과 같다.

```cpp
struct Job {
  int start, end, profit;

  const bool operator<(const Job& b) const { return end < b.end; }
};

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
  int size = startTime.size();
  // key : time, val : maximum
  // maximum val until time
  unordered_map<int, int> dp;

  vector<Job> jobs;
  for (int i = 0; i < size; i++) {
    jobs.push_back({startTime[i], endTime[i], profit[i]});
  }
  sort(jobs.begin(), jobs.end());

  vector<int> keys;
  int before = -1;
  for (int i = 0; i < size; i++) {
    Job cur = jobs[i];

    int leftCost = 0;
    int leftIdx =
        (upper_bound(keys.begin(), keys.end(), cur.start) - keys.begin()) - 1;
    if (leftIdx >= 0) {
      leftCost = dp[keys[leftIdx]];
    }

    dp[cur.end] = max(leftCost + cur.profit, before);
    before = dp[cur.end];
    keys.push_back(cur.end);
  }

  return dp[keys.back()];
}
```

## 고생한 점
