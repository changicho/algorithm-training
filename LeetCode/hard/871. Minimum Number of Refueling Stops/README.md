# 871. Minimum Number of Refueling Stops

[링크](https://leetcode.com/problems/minimum-number-of-refueling-stops/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

stations의 길이를 N이라 하자.

stations들은 우선 위치에 따라 0에 가까운순으로 정렬되어있다.

최소한의 station에 들리는 횟수를 구하기 위해 모든 경우를 탐색할 경우 O(2^N)의 시간 복잡도를 사용하므로 이는 제한시간 내에 불가능하다.

따라서 동적 계획법 혹은 탐욕 알고리즘 (heap)을 이용해 구현한다.

동적 계획법을 이용할 경우 모든 station을 순회하는데 O(N)의 시간 복잡도를, 현재 station에서 dp값을 갱신하는데 O(N)의 시간 복잡도를 사용하므로

시간 복잡도는 O(N^2)가 소요된다.

탐욕 알고리즘을 이용할 경우 heap을 이용하며 heap에 station의 연료 정보를 저장한다.

이 때 O(N \* log_2(N))의 시간 복잡도를 사용한다. (모든 stations에 대해서 저장할 수 있으므로)

### 공간 복잡도

동적 계획법을 이용할 경우 dp배열에 O(N)의 공간 복잡도를 사용한다.

heap을 이용하는 경우 O(N)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      80      |   O(N^2)    |    O(N)     |

fuel은 최대 10^9이며, fuel을 추가할 때 덧셈 연산이 있으므로 int형을 초과할 수 있으므로 주의한다.

```cpp
// dp배열을 다음과 같이 선언한다.
dp[i] // maximum distance when visit i'th station

// 초기값
dp[0] = startFuel;

// 일반식
// 각 station마다 다음을 수행해준다.
for (int cur = 0; cur < stations.size(); cur++) {
  if (dp[cur] >= position) {
    long long newLength = dp[cur] + fuel;

    nextDp[cur + 1] = max(dp[cur + 1], newLength);
  }
}
```

여기서 dp를 갱신할 때 모든 dp를 한번씩 순회하므로 낮은 index부터 갱신할 경우 다음 index를 갱신할 때 오류를 발생시킬 수 있다.

따라서 다음 방법으로 dp를 갱신한다.

- 높은 index부터 0까지 감소시키며 갱신한다.
- 임시 배열을 만들고 값을 모두 갱신한 뒤 이를 반영한다.

dp를 이용해 i개의 station을 들렀을 때의 도달 가능한 최대 거리를 사용할 수 있다.

따라서 이후에 target에 도달 가능한 i의 최소값을 정답으로 이용한다.

```cpp
int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
  int size = stations.size();
  // dp[i] : maximum distance when visit i'th station
  vector<long long> dp(size + 1, 0);
  dp[0] = startFuel;

  for (int i = 0; i < size; i++) {
    vector<int>& station = stations[i];

    // we update from maximum index
    // if we update count + 1, it will effect when update next dp
    // so we use temp vector of current dp
    for (int count = i; count >= 0; count--) {
      // we can visit current station use count'th stop
      if (dp[count] >= station[0]) {
        long long newLength = dp[count] + station[1];

        dp[count + 1] = max(dp[count + 1], newLength);
      }
    }
  }

  // find minimum count to reach target
  int answer = -1;
  for (int i = 0; i < dp.size(); i++) {
    if (dp[i] >= target) {
      answer = i;
      break;
    }
  }
  return answer;
}
```

### heap

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      16      | O(N \* log_2(N)) |    O(N)     |

한 station에서 연료를 충전할 경우 도달 가능한 거리에 연료만큼 더한 값이 다음에 도달 가능한 거리가 된다.

이를 이용해 현재 도달 가능한 거리에서 방문 가능한 station들을 전부 heap에 넣고, 그중 가장 연료를 많이 넣을 수 있는 station에서 주유한다. (다음 도달 거리 갱신)

즉 현재까지 도달 가능한 범위 내에서 가장 연료가 많은 곳에서 주유하면서 전진해나간다.

가장 많은 연료를 매번 한번씩 주입하며 target까지 도달 가능한지 판별한다.

```cpp
int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
  int size = stations.size();
  // push visit possible station's fuel
  priority_queue<int> pq;

  int maximumDistance = startFuel;
  int stopCount = 0;
  int index = 0;

  while (maximumDistance < target) {
    // visit posssible station of current position
    while (index < size && stations[index][0] <= maximumDistance) {
      pq.push(stations[index][1]);
      index++;
    }

    // if there are no station to visit
    if (pq.empty()) return -1;

    maximumDistance += pq.top();
    pq.pop();
    stopCount++;
  }

  return stopCount;
}
```

## 고생한 점
