# 98. Validate Binary Search Tree

[링크](https://leetcode.com/problems/validate-binary-search-tree/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 모든 노드를 순회하며 올바른 트리인지 검사해야 하므로 outer 시간 복잡도는 O(N)이다.

이전에 방문한 부모들을 이용해 범위에 포함되는지, 범위를 넘어서는지 판단하면 되므로 inner 시간 복잡도는 O(N)이다.

### 공간 복잡도

재귀 호출을 진행하며 stack에 각 노드의 상태들이 쌓인다. 콜 스택에 호출은 최대 N번까지 일어나므로 필요한 공간 복잡도는 O(N)

### 정리

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |    O(N)     |    O(N)     |

현재 노드에서 탐색을 진행하며 valid한 범위를 함께 넘긴다.

min ~ max 범위의 값을 넘기며 자식 노드를 탐색할 때 해당 범위를 넘는 경우에 false를 반환한다.

여기서 다음 경우를 판단한다

- 현재 노드의 val가 min값보다 이하인 경우
- 현재 노드의 val가 max값보다 이상인 경우

위 경우들은 BST의 조건을 위배하는 경우들이므로 해당 경우에는 탐색을 중지하고 false를 반환한다.

이후 left노드와 right노드에 대해서 탐색을 진행한다

- left : min ~ node->val
- right : node->val ~ max

```cpp
bool isValidBST(TreeNode *root) {
  return recursive(root, LONG_MIN, LONG_MAX);
}

bool recursive(TreeNode *root, long min, long max) {
  if (!root) return true;
  if (root->val <= min) return false;
  if (root->val >= max) return false;

  return recursive(root->left, min, root->val) && recursive(root->right, root->val, max);
}
```

위 코드에서 long 형태 대신 노드만 이용해 다음과 같이 구현할 수 있다.

```cpp
bool isValidBST(TreeNode *root) {
  return recursive(root, NULL, NULL);
}

bool recursive(TreeNode *root, TreeNode *minNode, TreeNode *maxNode) {
  if (!root) return true;
  if (minNode && root->val <= minNode->val) return false;
  if (maxNode && root->val >= maxNode->val) return false;

  return recursive(root->left, minNode, root) && recursive(root->right, root, maxNode);
}
```

stack을 이용해 동일하게 구현할 수 있다.

```cpp
bool isValidBST(TreeNode *root) {
  long pre = LONG_MIN;
  stack<TreeNode *> s;

  while (root || !s.empty()) {
    while (root) {
      s.push(root);
      root = root->left;
    }
    root = s.top();
    s.pop();

    if (root->val <= pre) {
      return false;
    }

    pre = root->val;
    root = root->right;
  }

  return true;
}
```

## 고생한 점
