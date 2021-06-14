# 105. Construct Binary Tree from Preorder and Inorder Traversal

[링크](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

방문 경로의 길이를 N이라 하자.

방문 경로를 순회하며 트리구조를 재생성해야 한다.

preorder, inorder를 순회하며 각 range마다 root노드를 판별하고 재귀적으로 문제를 풀이할 수 있다.

모든 정점을 한번씩 방문해야 하므로 outer 시간 복잡도는 O(N)이다.

트리를 생성하기 위한 inner 시간 복잡도는 내부적으로 range를 찾기 위해 탐색하는 과정이 필요하며

이를 hash map으로 최적화 할 경우 O(1)이다.

만약 직접 탐색을 수행할 경우 한번 순회해야 하므로 O(N)이다.

따라서 최종 시간 복잡도는 hash map을 이용할 경우 O(N), 이용하지 않을 경우 O(N^2)이다.

### 공간 복잡도

탐색을 진행하며 call stack이 쌓이고 이는 최악의 경우 O(N)까지 쌓일 수 있다.

따라서 기본 공간 복잡도는 O(N)이다.

별도로 hash map을 이용해 현재 index를 찾는 경우 O(N)의 공간 복잡도가 필요하다.

### 재귀호출

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      16      |    O(N)     |    O(N)     |

preOrder 배열을 이용해 root노드를 빠르게 찾을 수 있고, 이후 자식노드에 대한 정보는 inOrder를 이용한다.

inOrder의 경우 현재 노드에서 왼쪽 자식은 왼쪽에, 오른쪽 자식은 오른쪽에 위치하는 성질을 이용한다.

이를 이용해 inOrder의 왼쪽 범위, 오른쪽 범위를 나눠 재귀호출로 탐색하고 각 sub tree마다의 root노드는 preOrder를 이용해 구한다.

hash map을 이용해 root노드를 찾을 경우 시간 복잡도 : O(N), 공간 복잡도 : O(N) 이다.

직접 매 경우마다 찾을 경우 시간 복잡도 : O(N^2), 공간 복잡도 : O(N) 이다.

```cpp
unordered_map<int, int> m;

TreeNode* recursive(vector<int>& preorder, int& rootIndex, vector<int>& inorder, int left, int right) {
  if (rootIndex >= preorder.size() || left > right) return NULL;

  TreeNode* root = new TreeNode(preorder[rootIndex]);
  int pivot = find(inorder.begin() + left, inorder.begin() + right, preorder[rootIndex]) - inorder.begin();
  // int pivot = m[preorder[rootIndex]];
  rootIndex++;

  root->left = recursive(preorder, rootIndex, inorder, left, pivot - 1);
  root->right = recursive(preorder, rootIndex, inorder, pivot + 1, right);

  return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
  int rootIndex = 0;
  for (int i = 0; i < inorder.size(); i++) m[inorder[i]] = i;

  return recursive(preorder, rootIndex, inorder, 0, inorder.size() - 1);
}
```

## 고생한 점
