# 329. Longest Increasing Path in a Matrix

[링크](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

모든 좌표(노드)의 개수를 N이라 하자. (행의 개수를 R, 열의 개수를 C라고 하면 R \* C)

각 좌표에서 간선의 수는 4 \* N이다. (4방향 이므로)

각 좌표에서 DFS로 탐색할 경우 가능한 경우의 수는 O(2^(R + C))이 되며 이는 제한시간 내에 불가능하다. (각 좌표 방향에 따라서 다음 두가지 경우만 가능하므로)

- Case 1: left or right
- Case 2: Up or Down.

우선순위 큐를 이용해 매번 최적의 경우에서부터 BFS로 탐색을 진행할 수 있다.

이 경우 우선순위 큐에 모든 노드를 삽입하고 시작하므로 O(N \* log_2(N))의 시간 복잡도를 사용한다.

각 경우마다 4가지 경우로 탐색이 가능하며, 이전에 방문한 노드는 다시 방문하지 않으므로 최종 시간 복잡도는 O(N \* log_2(N)) 이다.

DFS와 메모이제이션을 이용해 각 노드를 한번만 방문할 수도 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

이전에 방문한 노드를 skip하기 위해 O(N)크기의 배열을 사용한다.

DFS를 이용할 경우 최악의 경우 call stack에 N번 쌓일 수 있다.

또한 우선순위 큐에는 O(N)의 공간 복잡도를 사용한다.

따라서 공간 복잡도는 O(N)이다.

### DFS with memoization

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      48      |    O(N)     |    O(N)     |

각 좌표에 대해서 다음과 같은 dp배열을 생성한다.

```cpp
dp[y][x]; // maximum length start from {y, x}
```

이를 이용해 현재 좌표에서부터 DFS로 탐색할 때 다음과 같이 갱신이 가능하다.

- 다음 좌표가 이미 방문되지 않은 경우
  - 방문할 수 있다면 방문을 진행함
- 다음 좌표가 이미 방문된 경우, 해당 좌표의 dp값은 이미 갱신되어 있음
  - 더이상 탐색하지 않고 현재 좌표의 최대 값의 후보로 dp[next] + 1을 가짐
- 이후 현재 좌표의 dp값을 갱신함

즉 이전에 탐색했던 값을 dp배열에 저장해 사용하고 재방문을 줄인다.

이는 각 dp값이 각 노드에서 가능한 최대 length를 사용하므로 가능하다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<vector<int>> dp;

int recursive(vector<vector<int>>& matrix, Axis& axis) {
  int rows = matrix.size();
  int cols = matrix.front().size();

  int maxLength = 0;
  for (Axis& dir : dirs) {
    Axis next = {dir.y + axis.y, dir.x + axis.x};

    if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
      continue;
    if (matrix[next.y][next.x] <= matrix[axis.y][axis.x]) continue;
    if (dp[next.y][next.x] != 1) {
      maxLength = max(maxLength, dp[next.y][next.x]);
      continue;
    }

    int curLength = recursive(matrix, next);
    maxLength = max(maxLength, curLength);
  }

  return dp[axis.y][axis.x] = maxLength + 1;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
  int rows = matrix.size();
  int cols = matrix.front().size();

  dp.resize(rows, vector<int>(cols, 1));

  int answer = 1;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      Axis start = {y, x};
      int curAnswer = recursive(matrix, start);
      answer = max(answer, curAnswer);
    }
  }

  return answer;
}
```

### heap

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     620      | O(N \* log_2(N)) |    O(N)     |

heap을 이용해 숫자가 낮은순서로 탐색을 진행하며 dp배열을 갱신해나간다.

이 때 최악의 경우 dp는 총 4번 갱신되므로 같은 노드를 4번 방문하는 경우이다.

이는 힙에 최대 O(4 \* N)개의 노드가 저장될 수 있음을 의미한다.

따라서 힙에서 top을 구할 때 O(log_2(4 \* N))의 시간 복잡도를 사용할 수 있으며 이는 O(log_2(N))이다.

다음과 같은 자료형을 사용한다.

```cpp
struct Axis {
  int y, x;
};

struct Status {
  Axis axis;
  int count;

  bool operator<(const Status& b) const { return count > b.count; }
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
```

이를 구현하면 다음과 같다.

```cpp
int longestIncreasingPath(vector<vector<int>>& matrix) {
  int rows = matrix.size();
  int cols = matrix.front().size();

  vector<vector<int>> dp(rows, vector<int>(cols, 1));

  priority_queue<Status> pq;

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      pq.push({{y, x}, 1});
    }
  }

  while (!pq.empty()) {
    Status cur = pq.top();
    pq.pop();

    Axis axis = cur.axis;

    for (Axis& dir : dirs) {
      Axis next = {dir.y + axis.y, dir.x + axis.x};

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      if (matrix[next.y][next.x] <= matrix[axis.y][axis.x]) continue;
      if (dp[next.y][next.x] >= dp[axis.y][axis.x] + 1) continue;

      dp[next.y][next.x] = dp[axis.y][axis.x] + 1;
      pq.push({next, dp[next.y][next.x]});
    }
  }

  int answer = 1;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      answer = max(answer, dp[y][x]);
    }
  }
  return answer;
}
```

## 고생한 점
