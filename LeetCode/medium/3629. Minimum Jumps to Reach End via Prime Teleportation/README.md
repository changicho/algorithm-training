# 3629. Minimum Jumps to Reach End via Prime Teleportation

[링크](https://leetcode.com/problems/minimum-jumps-to-reach-end-via-prime-teleportation/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N, 최대값을 M이라 하자.

에라토스테네스의 채를 이용해 각 숫자마다의 소인수들을 구한다. 이를 모두 구하는데  O(10^6 \* log_2(10^6))의 시간 복잡도를 사용한다.

이후 index를 마지막부터 순회하며 0으로 도달 가능한지 판단한다. 이때 각 수마다 소인수를 가지는 경우 해당 소인수들의 index로 이동할 수 있다.

이를 BFS로 탐색하는데 O(N \* log_2(M))의 시간 복잡도를 사용한다.

### 공간 복잡도

소인수, 방문여부들을 저장하는데 O(N + M)의 공간 복잡도를 사용한다.

### 에라토스 테네스의 채 & BFS

| 내 코드 (ms) |           시간 복잡도            | 공간 복잡도 |
| :----------: | :------------------------------: | :---------: |
|     260      | O(M \* log_2(M) + N \* log_2(M)) |  O(N + M)   |

에라토스 테네스의 채를 이용해 각 수들의 소인수들을 모두 구한다.

이후 마지막 index부터 역으로 순회하며, 현재 index로 도달 가능한 이전 index들을 연결한다.

이를 위해 현재 값이 소인수를 가지는 경우 해당 소인수들의 index들을 현재 값에 모두 연결해준다.

이후 탐색을 step별 BFS 진행하며 0번 index에 도달 가능한지 판단한다.

```cpp
vector<int> factors[1000001];

bool init = [] {
  for (int i = 2; i <= 1000000; i++) {
    if (factors[i].size() > 0) continue;

    for (int j = i; j <= 1000000; j += i) {
      factors[j].push_back(i);
    }
  }
  return true;
}();

int minJumps(vector<int>& nums) {
  int size = nums.size();
  unordered_map<int, vector<int>> primeIndexes;
  for (int i = 0; i < size; i++) {
    int cur = nums[i];

    // prime
    if (factors[cur].size() == 1) {
      primeIndexes[cur].push_back(i);
    }
  }

  vector<bool> visited(size, false);

  queue<int> q;
  visited[size - 1] = true;
  int step = 0;
  q.push(size - 1);

  while (!q.empty()) {
    int qSize = q.size();

    while (qSize--) {
      int i = q.front();
      q.pop();
      int cur = nums[i];

      if (i == 0) return step;

      if (i + 1 < size && !visited[i + 1]) {
        visited[i + 1] = true;
        q.push(i + 1);
      }
      if (i - 1 >= 0 && !visited[i - 1]) {
        visited[i - 1] = true;
        q.push(i - 1);
      }

      for (int& p : factors[cur]) {
        if (primeIndexes.count(p)) {
          for (int& n : primeIndexes[p]) {
            if (!visited[n]) {
              visited[n] = true;
              q.push(n);
            }
          }
          primeIndexes[p].clear();
        }
      }
    }

    step++;
  }

  return size - 1;
}
```

## 고생한 점

에라토스 테네스의 채를 사용해 소수들을 구하는 작업을 각 테스트 케이스마다 한번만 수행해야한다.

이를 class 외부로 빼고 수행해줘야한다.
