# 1066. Campus Bikes II

[링크](https://leetcode.com/problems/campus-bikes-ii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 workers의 크기를 N, bikes의 크기를 M이라 하자.

각 작업인원별로 bike를 배정하는 모든 경우를 탐색할수있다.

이 경우 시간 복잡도는 O(M!/(M-N)!) 이다.

### 공간 복잡도

각 작업인원별로 bike를 배정하는 모든 경우를 탐색할 때, 재귀호출을 이용한다.

이 경우 O(N + M)의 공간 복잡도를 사용한다.

### DFS & backtracking

| 내 코드 (ms) | 시간 복잡도  | 공간 복잡도 |
| :----------: | :----------: | :---------: |
|     1092     | O(M!/(M-N)!) |  O(N + M)   |

각 작업인원별로 bike를 배정하는 모든 경우를 탐색한다.

이 때 이미 방문한 bike의 경우 다음 탐색에서 무시한다.

각 경우마다 정답을 갱신하며 최소값을 반환한다.

```cpp
vector<vector<int>> workers;
vector<vector<int>> bikes;
bool isVisitBikes[11] = {
    false,
};

int answer = INT_MAX;
int getDistance(vector<int>& a, vector<int>& b) {
  return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}

void recursive(int i, int cost) {
  if (i == workers.size()) {
    answer = min(answer, cost);
    return;
  }

  if (cost >= answer) return;

  for (int j = 0; j < bikes.size(); j++) {
    if (isVisitBikes[j]) continue;
    isVisitBikes[j] = true;

    int nextCost = cost + getDistance(workers[i], bikes[j]);
    recursive(i + 1, nextCost);

    isVisitBikes[j] = false;
  }
}

int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
  this->workers = workers;
  this->bikes = bikes;

  recursive(0, 0);

  return answer;
}
```

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       | O(N \* 2^M) |   O(2^M)    |

각 바이크를 선택하는 경우를 비트마스크를 이용해 표현할 수 있다.

각 바이크를 선택한 경우마다 최소값을 알고있다면, 이를 이용해 각 경우마다의 최소값을 갱신할 수 있다.

이 때 각 경우마다 worker를 순차적으로 bike를 선택하며, 이전에 선택한 bike의 경우 다음 탐색에서 무시한다.

```cpp
int memo[1024];

// Count the number of ones using Brian Kernighan’s Algorithm
int countNumOfOnes(int mask) {
  int count = 0;
  while (mask != 0) {
    mask &= (mask - 1);
    count++;
  }
  return count;
}

// Manhattan distance
int findDistance(vector<int>& worker, vector<int>& bike) {
  return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
}

int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
  for (int i = 0; i < 1024; i++) {
    memo[i] = INT_MAX;
  }
  int bikeSize = bikes.size();
  int workerSize = workers.size();
  int answer = INT_MAX;

  memo[0] = 0;
  for (int mask = 0; mask < (1 << bikeSize); mask++) {
    int workerI = countNumOfOnes(mask);

    if (workerI >= workerSize) {
      answer = min(answer, memo[mask]);
      continue;
    }

    for (int bikeI = 0; bikeI < bikeSize; bikeI++) {
      if ((mask & (1 << bikeI)) != 0) continue;
      int newMask = (1 << bikeI) | mask;

      int nextCost =
          memo[mask] + findDistance(workers[workerI], bikes[bikeI]);
      memo[newMask] = min(memo[newMask], nextCost);
    }
  }

  return answer;
}
```

## 고생한 점
