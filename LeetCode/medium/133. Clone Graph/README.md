# 133. Clone Graph

[링크](https://leetcode.com/problems/clone-graph/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

모든 노드의 개수를 N이라 하자.

모든 노드에 대해서 복사해야 하므로 모든 노드를 한번 탐색해야 한다.

이 때 시간 복잡도는 O(N)이다.

이웃 노드의 개수는 최대 N까지 가능하다.

내부적으로 노드의 이웃노드들을 벡터에 담으면서 이전에 방문했던 노드의 값을 다시 참조할 수도 있다.

이 시간을 최적화 하기 위해 hash map을 이용한다. 이는 다른 노드를 찾는데 내부적으로 O(1)의 공간복잡도가 필요하다.

따라서 최악의 경우 시간 복잡도는 O(N^2)이다.

### 공간 복잡도

hash map을 사용하기 위해 O(N)크기만큼의 공간이 필요하다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(N)     |

현재 노드에서 다음 이웃 노드들을 방문하며 이웃들을 채워나간다.

이 때 map을 이용해 이전에 방문한 노드들의 경우는 이전에 생성한 노드를 그대로 집어넣는다.

또한 탐색을 진행하며 이전에 생성한 노드가 아닌 새로 생성한 노드에 대해서만 queue에 집어넣어 탐색을 진행한다.

```cpp
Node* cloneGraph(Node* node) {
  if (!node) return NULL;
  unordered_map<Node*, Node*> copies;

  Node* copy = new Node(node->val, {});
  copies[node] = copy;

  queue<Node*> q;
  q.push(node);
  while (!q.empty()) {
    Node* cur = q.front();
    q.pop();

    for (Node* neighbor : cur->neighbors) {
      if (copies.find(neighbor) == copies.end()) {
        copies[neighbor] = new Node(neighbor->val, {});
        q.push(neighbor);
      }
      copies[cur]->neighbors.push_back(copies[neighbor]);
    }
  }
  return copy;
}
```

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(N)     |

BFS방법과 마찬가지로 탐색을 진행한다.

이 때 새로 생성한 노드에 대해서만 재귀호출로 탐색을 진행한다.

```cpp
Node* cloneGraph(Node* node) {
  if (!node) return NULL;

  unordered_map<Node*, Node*> copies;
  Node* copy = recursive(copies, node);

  return copies[node];
}

Node* recursive(unordered_map<Node*, Node*>& copies, Node* node) {
  if (copies.find(node) == copies.end()) {
    copies[node] = new Node(node->val, {});

    for (Node* neighbor : node->neighbors) {
      copies[node]->neighbors.push_back(recursive(copies, neighbor));
    }
  }

  return copies[node];
}
```

## 고생한 점
