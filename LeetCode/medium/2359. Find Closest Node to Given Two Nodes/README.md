# 2359. Find Closest Node to Given Two Nodes

[링크](https://leetcode.com/problems/find-closest-node-to-given-two-nodes/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 수를 N이라 하자.

입력받은 두 노드에 대해 각각 다른 노드 까지의 거리중 최소를 구하는 데 O(N)의 시간 복잡도를 사용한다.

이후 각 노드마다의 거리를 이용해 두 노드가 만나는 점 중 최소점을 구한다.

이 경우 노드의 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 노드마다의 정보를 저장하는 데 O(N)의 공간 복잡도를 사용한다.

### BFS & 거리 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     286      |    O(N)     |    O(N)     |

입력받은 두 노드에 대해서, 다른 노드까지의 거리에 대한 정보를 저장한다.

이후 두 노드의 거리정보를 순회하며, 각 노드마다의 거리를 비교하고 두 거리 중 최대값이 작은 노드를 찾는다.

하나의 노드에서 다른 노드까지의 거리를 구하기 위해 BFS를 사용하며, 사이클이 존재할 수 있으므로 이미 방문한 노드는 건너뛴다.

```cpp
vector<int> getDistances(int startNode, vector<int>& edges) {
  int size = edges.size();
  vector<int> dist(size, INT_MAX);
  vector<bool> visit(size, false);

  queue<int> q;
  q.push(startNode);
  dist[startNode] = 0;
  while (!q.empty()) {
    int node = q.front();
    q.pop();

    if (visit[node]) {
      continue;
    }

    visit[node] = true;
    int neighbor = edges[node];
    if (neighbor != -1 && !visit[neighbor]) {
      dist[neighbor] = 1 + dist[node];
      q.push(neighbor);
    }
  }
  return dist;
}

int closestMeetingNode(vector<int>& edges, int node1, int node2) {
  int size = edges.size();
  vector<int> dist1 = getDistances(node1, edges), dist2 = getDistances(node2, edges);

  int target = -1, minDist = INT_MAX;
  for (int node = 0; node < size; node++) {
    if (minDist > max(dist1[node], dist2[node])) {
      target = node;
      minDist = max(dist1[node], dist2[node]);
    }
  }

  return target;
}
```

## 고생한 점
