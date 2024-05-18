# 2331. Evaluate Boolean Binary Tree

[링크](https://leetcode.com/problems/evaluate-boolean-binary-tree/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

각 노드를 DFS로 순회하며 연산을 수행할 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

재귀호출을 이용할 경우 call stack에 최대 N개의 함수가 쌓일 수 있다.

따라서 공간 복잡도는 O(N)이다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |    O(N)     |    O(N)     |

현재 루트 노드가 리프노드인지, 아닌지에 따라 다른 연산을 수행한다.

```cpp
bool evaluateTree(TreeNode *root) {
  if (!root->left && !root->right) {
    // leaf case

    return root->val;
  }

  bool left = evaluateTree(root->left);
  bool right = evaluateTree(root->right);

  if (root->val == 2) {
    return left || right;
  } else {
    return left && right;
  }
}
```

## 고생한 점
