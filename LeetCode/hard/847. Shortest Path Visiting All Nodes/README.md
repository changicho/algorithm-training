# 847. Shortest Path Visiting All Nodes

[링크](https://leetcode.com/problems/shortest-path-visiting-all-nodes/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

그래프의 노드의 갯수를 N이라 하자.

각 상황마다 방문한 노드의 경우의 수는 2^N개이다. 이 상황이 각 노드에 존재할 수 있으므로 2^N \* N개의 경우가 발생한다.

여기서 각 노드에서 다른 노드까지 연결된 갯수는 최대 N개까지 가능하다.

이 유일한 경우들에 대해 탐색할 경우 O(2^N \* N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

유일한 경우의 수마다 최소 이동횟수를 저장해 사용할 수 있다. 따라서 공간 복잡도는 O(2^N \* N)이다.

### BFS & 백트래킹

| 내 코드 (ms) |  시간 복잡도  | 공간 복잡도 |
| :----------: | :-----------: | :---------: |
|     172      | O(2^N \* N^2) | O(2^N \* N) |

N은 최대 12까지이며, 방문 여부의 가능한 경우의 수는 최대 2^N이다.

따라서 비트 연산을 이용해 방문 여부를 체크할 수 있다.

BFS에서 각 상황마다의 상태는 다음과 같다.

```cpp
struct Status {
  int visited;
  int node;
  int step;
};
```

이를 캐싱으로 저장해 정답이 불가능한 경우를 제외하기 위해 백트래킹을 사용한다.

```cpp
int cache[1 << 12][12] = {0};
```

BFS를 순회하며 현재까지 방문한 노드상황, 현재 노드 두가지 경우에 따라 불필요한 경우 탐색을 중지한다.

```cpp
int shortestPathLength(vector<vector<int>>& graph) {
  int size = graph.size();

  queue<Status> q;

  for (int node = 0; node < size; node++) {
    int bit = 0;
    bit |= 1 << node;

    q.push({bit, node, 0});
  }

  int answer = -1;
  int step = 0;
  while (!q.empty() && answer == -1) {
    int qSize = q.size();

    while (qSize--) {
      Status cur = q.front();
      q.pop();

      int node = cur.node;

      if (cur.visited == (1 << size) - 1) {
        answer = step;
        break;
      }

      for (int to : graph[node]) {
        Status next = cur;
        next.visited |= 1 << to;
        next.node = to;
        next.step++;

        if (cache[next.visited][next.node] != 0 &&
            cache[next.visited][next.node] <= next.step) {
          continue;
        }
        cache[next.visited][next.node] = next.step;

        q.push(next);
      }
    }

    step++;
  }

  return answer;
}
```

## 고생한 점
