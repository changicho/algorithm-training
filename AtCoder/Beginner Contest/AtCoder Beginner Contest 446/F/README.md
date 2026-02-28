# F - Reachable Set 2

[링크](https://atcoder.jp/contests/abc446/tasks/abc446_f)

| 난이도 |
| :----: |
|  500   |

## 설계

### 시간 복잡도

그래프의 노드의 수를 V, 간선의 수를 E라 하자.

각 step별로 방문 가능한 노드의 범위가 정해진다.

각 step별로 순회하며 BFS를 수행할 수 있다.

이 경우 O(V + E)의 시간 복잡도를 사용한다.

### 공간 복잡도

BFS에 O(V)의 공간 복잡도를, 그래프 생성에 O(V + E)의 공간 복잡도를 사용한다.

### BFS by step

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     118      |  O(V + E)   |  O(V + E)   |

1번 노드부터 시작해 각 step별로 방문 가능한 노드번호가 증가한다.

BFS를 수행하며 현재 step별로 방문 가능한 노드만 큐에 넣고 탐색을 진행하며, step보다 큰 방문 불가능한 노드들의 경우 별도로 저장하며 다음 step에서 방문 가능한지 확인한다.

현재 BFS 탐색이 끝난 경우, 방문한 노드의 수가 현재 step과 일치하는지 확인한다.

만약 일치하지 않는 경우 step개의 노드에 방문 불가능하므로 -1을 저장한다.

만약 일치하는 경우, 현재 step에서 방문 불가능하지만, 추후에 도달 가능한 노드들을 삭제해야만 step개의 노드만 방문할 수 있다.

따라서 방문 가능하지만 step보다 큰 노드들의 수를 저장한다.

이후 step은 증가하므로 다음 step에서 방문 가능한 노드가 있는 경우 큐에 넣고 탐색을 진행한다.

```cpp
struct Edge {
  int from, to;
};

vector<int> solution(int n, int eSize, vector<Edge>& edges) {
  vector<int> answer;

  vector<vector<int>> graph(n + 1);
  for (Edge& e : edges) {
    graph[e.from].push_back(e.to);
  }

  unordered_set<int> visited;
  unordered_set<int> remainNodes;
  queue<int> q;

  q.push(1);
  visited.insert(1);

  for (int canReach = 1; canReach <= n; canReach++) {
    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      for (int& next : graph[cur]) {
        if (visited.count(next)) continue;

        if (next <= canReach) {
          q.push(next);
          visited.insert(next);
        } else {
          remainNodes.insert(next);
        }
      }
    }

    if (visited.size() == canReach) {
      answer.push_back(remainNodes.size());
    } else {
      answer.push_back(-1);
    }

    if (remainNodes.count(canReach + 1) > 0) {
      q.push(canReach + 1);
      visited.insert(canReach + 1);

      remainNodes.erase(canReach + 1);
    }
  }

  return answer;
}
```

## 고생한 점
