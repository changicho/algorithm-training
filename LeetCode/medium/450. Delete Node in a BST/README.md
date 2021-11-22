# 450. Delete Node in a BST

[링크](https://leetcode.com/problems/delete-node-in-a-bst/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 개수를 N이라 하자.

트리는 BST로 주어지며 최악의 경우 한쪽으로 쏠린 상황이 될 수 있으므로 삭제해야 할 노드가 있는지 확인 하는 데 O(N)의 시간 복잡도가 소요된다.

이후 노드를 삭제 후 새로운 트리를 생성하는 데 O(N)의 시간 복잡도를 소요한다.

### 공간 복잡도

재귀 호출로 구현할 경우 call stack에 최대 O(N)의 공간 복잡도를 사용한다.

### 재귀호출

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      56      |    O(N)     |    O(N)     |

재귀 호출을 반복하면서 key에 값을 가지는 노드를 찾는다.

이 때 BST 구조이므로 현재 노드의 값이 key가 아닌 경우 대소관계에 따라서 key값을 가지는 노드의 위치를 찾을 수 있다.

만약 현재 노드가 key값인 경우 다음 3가지 경우에 따라서 삭제 방법이 나뉜다.

- 현재 노드가 리프 노드인 경우 : 현재 노드만 삭제한다
- 현재 노드의 자식이 하나인 경우 : 현재 노드를 삭제하고 하나뿐인 자식을 이어붙인다.
- 현재 노드의 자식이 2개인 경우 : 아래 참고

만약 현재 노드의 자식이 2개인 경우 두 노드 중 아무것이나 선택한다.

이후 해당 노드의 자식들 중에서 현재 노드의 value와 가장 차이가 적은 value를 찾는다.

- 왼쪽 노드를 선택했을 경우 : subTree에서 가장 오른쪽에 있는 노드
- 오른쪽 노드를 선택했을 경우 : subTree에서 가장 왼쪽에 있는 노드

이후 해당 노드의 값을 현재 노드의 값으로 치환 후에 해당 리프 노드를 삭제한다.

(해당 노드에 자식이 있는 경우 이를 연결해준다.)

이는 삭제할 노드를 root로 하는 subTree에서 해당 노드를 선택했을 때 기존 구조를 유지한 상태로 대소 관계가 유지되기 때문이다.

(BST구조이므로 가장 차이의 절대값이 작은 노드를 선택해야 나머지 대소관계가 유지됨)

```cpp
TreeNode* deleteNode(TreeNode* root, int key) {
  if (!root) return NULL;

  // move to left
  if (key < root->val) {
    root->left = deleteNode(root->left, key);
    return root;
  }
  // move to right
  if (key > root->val) {
    root->right = deleteNode(root->right, key);
    return root;
  }

  // current node is target to delete
  // leaf node case
  if (!root->left && !root->right) {
    delete root;
    return NULL;
  }
  // one child case
  if (!root->left || !root->right) {
    TreeNode* ret = root->left ? root->left : root->right;
    delete root;
    return ret;
  }
  // two child case
  if (root->left && root->right) {
    // we cen choose left, right whatever
    // just pick the node that has closest value from root->val
    TreeNode* temp = root->right;
    while (temp->left) {
      temp = temp->left;
    }
    root->val = temp->val;
    root->right = deleteNode(root->right, root->val);
  }

  return root;
}
```

### 반복문

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      44      |    O(N)     |    O(N)     |

위 방법과 동일하지만 반복문으로 구현이 가능하다.

이 때 노드를 지우기 위해서 탐색 시에 부모를 함께 지정해준다.

```cpp
void changeChild(TreeNode* parent, TreeNode* child, TreeNode* value) {
  if (child == parent->left) {
    parent->left = value;
  } else if (child == parent->right) {
    parent->right = value;
  }
}

TreeNode* deleteNode(TreeNode* root, int key) {
  TreeNode* target = root;
  TreeNode* parent = NULL;

  while (target && target->val != key) {
    parent = target;
    if (key > target->val) {
      target = target->right;
    } else if (key < target->val) {
      target = target->left;
    }
  }

  if (!target) return root;

  // leaf node case
  if (!target->left && !target->right) {
    if (!parent) return NULL;
    changeChild(parent, target, NULL);
    return root;
  }

  // one child case
  if (!target->left || !target->right) {
    TreeNode* ret = target->left ? target->left : target->right;

    if (!parent) return ret;
    changeChild(parent, target, ret);
    return root;
  }

  // two child case
  TreeNode *leafParent = target, *leaf = target->right;
  while (leaf->left) {
    leafParent = leaf;
    leaf = leaf->left;
  }

  target->val = leaf->val;
  changeChild(leafParent, leaf, NULL);

  return root;
}
```

## 고생한 점
