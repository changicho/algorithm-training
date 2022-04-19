# 230. Kth Smallest Element in a BST

[링크](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N, 입력받은 수를 K라고 하자.

BST를 inOrder로 방문할 경우 오름차순으로 방문할 수 있다.

이를 모두 방문할 때 O(N)의 시간 복잡도를 사용한다.

K번째 수를 구하면 되므로 O(K)의 시간 복잡도로 원하는 값을 찾을 수 있다.

### 공간 복잡도

call stack에 최대 O(K)의 공간 복잡도를 사용한다.

### 중위 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      16      |    O(K)     |    O(K)     |

중위 순회로 트리를 순회하며 K번째 노드까지만 순회한다.

방문한 노드를 배열에 순서대로 저장하며, 해당 배열의 제일 마지막 값이 K번째 원소의 값이 된다.

```cpp
void recursive(TreeNode* node, vector<int>& vals, int& k) {
  if (vals.size() == k) return;
  if (node->left) recursive(node->left, vals, k);
  vals.push_back(node->val);
  if (node->right) recursive(node->right, vals, k);
}

int kthSmallest(TreeNode* root, int k) {
  vector<int> vals;
  if (root) recursive(root, vals, k);

  return vals[k - 1];
}
```

## 고생한 점
