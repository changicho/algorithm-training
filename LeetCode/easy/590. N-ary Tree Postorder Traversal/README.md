# 590. N-ary Tree Postorder Traversal

[링크](https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

DFS를 이용해 트리를 순회할 경우 모든 노드를 한번씩 방문해야 하므로 시간 복잡도는 O(N)이다.

### 공간 복잡도

DFS에 최대 O(N)의 call stack이 필요하다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      17      |    O(N)     |    O(N)     |

트리의 children을 순서대로 순회하며 postOrder로 순회한다.

```cpp
vector<int> postorder(Node* root) {
  vector<int> answer;

  function<void(Node * root)> recursive = [&](Node* node) {
    for (Node* child : node->children) {
      recursive(child);
    }

    answer.push_back(node->val);
  };

  if (root) recursive(root);
  return answer;
}
```

## 고생한 점
