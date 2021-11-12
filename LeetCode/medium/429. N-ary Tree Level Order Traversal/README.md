# 429. N-ary Tree Level Order Traversal

[링크](https://leetcode.com/problems/n-ary-tree-level-order-traversal/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 개수를 N이라 하자.

모든 노드를 한번씩 방문해야 하므로 노드의 순회에 O(N)의 시간 복잡도를 사용한다.

BFS를 이용해 depth별로 순회할 경우 각 depth마다 방문한 노드들을 정답에 저장하면 된다.

이 때 왼쪽 노드부터 순차적으로 순회한다.

이 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

BFS를 이용할 경우 O(N)의 공간 복잡도를 사용한다.

또한 방문한 노드의 순서를 저장하는 정답 배열에 O(N)의 공간 복잡도를 사용한다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      16      |    O(N)     |    O(N)     |

BFS를 이용해 level별로 순회가 가능하다.

각 노드들의 자식들은 오름차순으로 정렬되어 있으며 이를 순차적으로 순회하면 된다.

```cpp
vector<vector<int>> levelOrder(Node* root) {
  queue<Node*> q;
  vector<vector<int>> answer;

  if (root) q.push(root);

  while (!q.empty()) {
    int size = q.size();

    vector<int> line;
    while (size--) {
      Node* cur = q.front();
      q.pop();

      line.push_back(cur->val);

      for (Node* child : cur->children) {
        q.push(child);
      }
    }

    answer.push_back(line);
  }

  return answer;
}
```

## 고생한 점
