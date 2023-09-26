# 1485. Clone Binary Tree With Random Pointer

[링크](https://leetcode.com/problems/clone-binary-tree-with-random-pointer/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N개 라고 하자.

트리를 순회하며 방문한 노드를 재방문하지 않기 위해 메모이제이션을 사용한다.

이 경우 방문에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

메모이제이션에 O(N)의 공간 복잡도를 사용한다.

### 메모이제이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     196      |    O(N)     |    O(N)     |

각 노드를 복제한 NodeCopy를 저장해놓는다.

이 때 각 노드 자체를 key로 관리해 빠르게 방문할 수 있도록 한다.

이후 재귀호출을 이용해 각 노드들을 복사하며, 메모이제이션을 사용해 재방문한 노드의 경우 기존에 만든 노드를 재사용한다.

```cpp
unordered_map<Node*, NodeCopy*> cache;

NodeCopy* recursive(Node* node) {
  if (!node) return NULL;
  // cache hit
  if (cache.count(node) > 0) return cache[node];

  NodeCopy* ret = new NodeCopy(node->val);
  cache[node] = ret;

  ret->left = recursive(node->left);
  ret->right = recursive(node->right);
  ret->random = recursive(node->random);
  return ret;
}

NodeCopy* copyRandomBinaryTree(Node* root) {
  NodeCopy* ret = recursive(root);
  return ret;
}
```

## 고생한 점
