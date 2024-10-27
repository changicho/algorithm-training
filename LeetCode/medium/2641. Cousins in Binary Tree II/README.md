# 2641. Cousins in Binary Tree II

[링크](https://leetcode.com/problems/cousins-in-binary-tree-ii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

각 depth마다 노드의 합을 구하는데 O(N)의 시간 복잡도가 필요하다.

이후 각 노드를 순회하며 자식들의 값을 갱신하는데 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

BFS로 순회할 경우 O(N)의 공간 복잡도가 필요하다. 각 depth마다 노드의 합을 저장할 배열이 필요하다. 이에 최대 O(N)의 공간 복잡도가 필요하다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      15      |    O(N)     |    O(N)     |

각 depth마다 같은 depth에 존재하는 노드의 합을 미리 구해놓는다.

이후 각 노드를 순회하며 각 노드의 자식들의 값을 갱신한다.

이 때 sibling의 값은 해당 depth의 합에서 자식의 값들을 뺀 값이다.

```cpp
TreeNode* replaceValueInTree(TreeNode* root) {
  queue<TreeNode*> q;
  q.push(root);
  vector<int> sumByLevels;

  while (!q.empty()) {
    int sum = 0;
    int size = q.size();
    while (size--) {
      TreeNode* cur = q.front();
      q.pop();

      sum += cur->val;
      if (cur->left) q.push(cur->left);
      if (cur->right) q.push(cur->right);
    }

    sumByLevels.push_back(sum);
  }

  q.push(root);
  int level = 1;
  root->val = 0;

  while (!q.empty()) {
    int size = q.size();
    while (size--) {
      TreeNode* cur = q.front();
      q.pop();

      int siblingSum = (cur->left ? cur->left->val : 0) + (cur->right ? cur->right->val : 0);

      // update children's value
      if (cur->left) {
        cur->left->val = sumByLevels[level] - siblingSum;
        q.push(cur->left);
      }
      if (cur->right) {
        cur->right->val = sumByLevels[level] - siblingSum;
        q.push(cur->right);
      }
    }
    level++;
  }

  return root;
}
```

## 고생한 점
