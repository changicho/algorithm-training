# 99. Recover Binary Search Tree

[링크](https://leetcode.com/problems/recover-binary-search-tree/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

inOrder를 이용해 문제를 풀이할 수 있다. 이 경우 탐색의 시간 복잡도는 O(N)이다.

inOrder를 수행하는 동안 변경할 두 노드를 찾아야 한다. 두 노드를 따로 저장하는 데 필요한 시간 복잡도는 O(1)이다.

따라서 최종 시간 복잡도는 O(1)이다.

### 공간 복잡도

트리를 순회하며 call stack에 최대 N개의 노드가 쌓일 수 있다. 이 공간 복잡도는 O(N)이다.

순회를 진행하며 변경할 두 노드를 저장하면 되므로 이 공간 복잡도는 O(1)이다.

따라서 공간 복잡도는 O(N)이다.

### 중위 순회 with Array

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      80      |    O(N)     |    O(N)     |

중위순회로 모든 노드를 방문하며 배열에 이를 저장한다고 하자.

올바른 BST의 경우는 모든 노드의 val들이 오름차순으로 정렬되어있을것이다.

이후 이 배열을 순회하며 오름차순을 깨뜨리는 노드들을 찾는다.

오름차순을 깨뜨리는 노드 중 가장 먼저 발견되는 노드와, 가장 나중에 발견되는 노드 2개를 찾는다.

다음과 같은 수들이 연속해서 나온다고 하자.

```javascript
[1, 8, 3, 4, 5, 6, 7, 2, 9, 10]; // 8, 3, 7, 2
```

순회를 진행하며 잘못된 수들을 8, 3, 7, 2 순으로 발견한다.

맨 처음 8과 마지막 2가 오름차순을 깨뜨리는 수이므로 제일 처음과 나중에 발견되는 수를 변경해야 올바른 BST를 만들 수 있다.

```cpp
vector<TreeNode*> array;

void recoverTree(TreeNode* root) {
  recursive(root);

  vector<TreeNode*> errors;
  int size = array.size();
  for (int i = 0; i < size; i++) {
    if (i - 1 >= 0 && array[i - 1]->val >= array[i]->val) {
      errors.push_back(array[i]);
    }

    if (i + 1 < size && array[i]->val >= array[i + 1]->val) {
      errors.push_back(array[i]);
    }
  }

  swap(errors.front()->val, errors.back()->val);
}

void recursive(TreeNode* node) {
  if (!node) return;

  recursive(node->left);
  array.push_back(node);
  recursive(node->right);
}
```

### 중위 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      28      |    O(N)     |    O(N)     |

위 방범에서 방문 노드를 따로 저장하지 않고 중위순회만을 이용해 변경할 두 노드를 찾는다.

중위순회를 진행하며 현재 노드에서 right를 방문하기 전에 이전에 방문한 노드를 현재 노드로 변경한다.

이 경우 이전에 방문한 노드는 서브트리의 루트 노드가 된다.

이전에 방문한 노드가 현재 노드의 값보다 큰 경우에 이전 노드를 변경할 노드로 선택한다.

첫번째 변경할 노드가 선택된 경우 제일 마지막 변경할 노드를 결정하면 된다.

이는 현재 노드값 보다 이전에 방문한 노드의 값이 큰 노드이므로 이를 선택한다.

```cpp
TreeNode* first;
TreeNode* second;
TreeNode* prev = NULL;

void recoverTree(TreeNode* root) {
  recursive(root);

  swap(first->val, second->val);
}

void recursive(TreeNode* node) {
  if (!node) return;

  recursive(node->left);

  if (!first && prev && prev->val >= node->val) first = prev;
  if (first && prev && prev->val >= node->val) second = node;
  prev = node;

  recursive(node->right);
}
```

위 방법처럼 직접 중위순회를 진행해도 되고, Morris Traversal을 이용해 중위순회를 진행할 수도 있다.

```cpp
void recoverTree(TreeNode* root) {
  TreeNode* prev = NULL;
  TreeNode* first = NULL;
  TreeNode* second = NULL;

  // Morris Traversal
  TreeNode* temp = NULL;
  while (root) {
    if (root->left) {
      // connect threading for root
      temp = root->left;
      while (temp->right && temp->right != root) {
        temp = temp->right;
      }

      // the threading already exists
      if (temp->right) {
        if (prev && prev->val > root->val) {
          if (!first) {
            first = prev;
            second = root;
          } else {
            second = root;
          }
        }
        prev = root;

        temp->right = NULL;
        root = root->right;
      } else {
        // construct the threading
        temp->right = root;
        root = root->left;
      }
      continue;
    }

    if (prev && prev->val > root->val) {
      if (!first) {
        first = prev;
        second = root;
      } else {
        second = root;
      }
    }
    prev = root;
    root = root->right;
  }

  swap(first->val, second->val);
}
```

## 고생한 점
