# 1345. Jump Game IV

[링크](https://leetcode.com/problems/jump-game-iv/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

arr의 크기를 N이라 하자. (N <= 5 \* 10^4)

각 index마다 양 옆, 그리고 같은 수로 이동이 가능하다.

이 때 각 수마다 중복되는 값의 index는 최대 N개이다.

BFS를 이용해 step마다 이동을 진행할 수 있다.

이 때 별도의 처리 없이 모든 방문 가능한 경우를 탐색할 경우 O(N^2)의 시간 복잡도를 사용한다.

같은 값에 대해 한번만 방문하고 더이상 방문하지 않을 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

BFS를 이용할 경우 O(N)의 공간 복잡도를 사용한다.

각 값에 대해 최소 방문 시간을 저장하는데 O(N)의 공간 복잡도를 사용한다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     228      |    O(N)     |    O(N)     |

같은 값을 가진 index들끼리 이동이 가능하므로 hash map에 이를 저장한다.

이후 시작점부터 BFS로 탐색을 진행한다.

이 때 같은 값들을 방문시킬 때, 한번 큐에 삽입한 이후로는 더이상 방문할 필요가 없으므로 hash map에서 해당 index들을 제거한다.

이를 구현하면 다음과 같다.

```cpp
int minJumps(vector<int>& arr) {
  int size = arr.size();

  unordered_map<int, vector<int>> indexes;

  for (int i = 0; i < size; i++) {
    indexes[arr[i]].push_back(i);
  }

  vector<int> dp(size, INT_MAX);

  queue<int> q;
  q.push(0);

  int step = 0;
  while (!q.empty()) {
    int curSize = q.size();

    while (curSize--) {
      int cur = q.front();
      q.pop();

      if (dp[cur] <= step) continue;
      dp[cur] = step;

      if (cur - 1 >= 0 && dp[cur - 1] > step + 1) {
        q.push(cur - 1);
      }
      if (cur + 1 < size && dp[cur + 1] > step + 1) {
        q.push(cur + 1);
      }

      for (int next : indexes[arr[cur]]) {
        if (dp[next] <= step + 1) continue;
        q.push(next);
      }

      indexes[arr[cur]].clear();
    }
    step++;
  }

  return dp[size - 1];
}
```

## 고생한 점
