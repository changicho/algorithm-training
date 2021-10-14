# 1008. Construct Binary Search Tree from Preorder Traversal

[링크](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 개수를 N이라 하자.

트리를 복원하기 위해서 모든 노드를 한번 씩 방문해야 한다.

따라서 O(N)의 시간 복잡도가 필요하다.

각 노드를 binary tree에 삽입할 경우, 한 노드당 최악의 경우 O(N), 일반적인 경우 O(log_2(N))의 시간 복잡도가 소요된다.

따라서 2진 트리를 모두 생성할 경우 O(N^2), O(N \* log_2(N))의 시간 복잡도를 사용한다.

혹은 스택을 사용해 한번의 순회로 풀이할 수 있다.

이 경우 시간 복잡도는 O(N)이 소요된다.

### 공간 복잡도

재귀 호출로 구현할 경우 call stack에 최대 N개의 함수가 쌓이게 된다.

이는 스택을 이용할 경우 또한 마찬가지 이므로 O(N)의 공간 복잡도를 사용한다.

### 이진트리 생성

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |   O(N^2)    |    O(N)     |

한쪽으로 치우친 트리가 되는 경우 최악의 경우가 된다.

이 경우 시간 복잡도는 O(N^2)가 되며 일반적으로는 O(N \* log_2(N))의 시간 복잡도를 사용한다.

입력받은 preorder의 맨 앞 노드가 root이므로 나머지 노드들을 하나하나 삽입하며 이진 트리를 생성한다.

```cpp
TreeNode* bstFromPreorder(vector<int>& preorder) {
  TreeNode* root = new TreeNode(preorder.front());

  int size = preorder.size();
  for (int i = 1; i < size; i++) {
    int num = preorder[i];
    TreeNode* cur = root;
    TreeNode* prev = NULL;

    while (cur) {
      prev = cur;
      if (cur->val < num) {
        cur = cur->right;
      } else {
        cur = cur->left;
      }
    }

    if (prev->val < num) {
      prev->right = new TreeNode(num);
    } else {
      prev->left = new TreeNode(num);
    }
  }

  return root;
}
```

### 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(N)     |

스택에 노드들을 다음과 같은 규칙으로 쌓아간다.

- 왼쪽에 위치해야 하는 노드인 경우 스택에 쌓는다
- 오른쪽에 위치해야 하는 경우 스택을 pop하며 적합한 위치를 찾는다.

```cpp
TreeNode* bstFromPreorder(vector<int>& preorder) {
  TreeNode* root = new TreeNode(preorder.front());
  stack<TreeNode*> s;
  s.push(root);

  for (int i = 1; i < preorder.size(); i++) {
    TreeNode* node = new TreeNode(preorder[i]);
    if (node->val < s.top()->val) {
      s.top()->left = node;
    } else {
      TreeNode* prev;

      while (!s.empty() && s.top()->val < node->val) {
        prev = s.top();
        s.pop();
      }

      prev->right = node;
    }
    s.push(node);
  }

  return root;
}
```

이를 재귀호출로 구현할 경우 다음과 같다.

```cpp
TreeNode* recursive(vector<int>& preorder, int& index, TreeNode* parent) {
  if (index >= preorder.size() || (parent && preorder[index] > parent->val))
    return NULL;

  TreeNode* node = new TreeNode(preorder[index]);
  index++;

  node->left = recursive(preorder, index, node);
  node->right = recursive(preorder, index, parent);

  return node;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
  TreeNode* parent = NULL;
  int index = 0;

  return recursive(preorder, index, parent);
}
```

## 고생한 점
