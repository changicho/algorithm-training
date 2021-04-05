# 101. Symmetric Tree

[링크](https://leetcode.com/problems/symmetric-tree/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

트리의 노드의 개수는 최대 1000개 이다.

왼쪽과 오른쪽을 나눠서 탐색을 진행해야 하며, 이 경우에 최종 시간 복잡도는 O(N)이다.

### 공간 복잡도

왼쪽에서 현재 진행하는 노드, 오른쪽에서 현재 진행하는 노드를 비교할 경우 별도의 공간이 필요하지 않다.

### 트리 순회

root노드를 기준으로 왼쪽 노드는 DLR, 오른쪽 노드는 DRL 순으로 탐색을 진행한다고 하자.

이는 서로 비교할 대상 노드끼리 탐색 순서를 맞추기 위해 오른쪽 노드의 경우 방문 순서를 뒤바꾼 것이다.

이 때, 트리의 왼쪽과 오른쪽이 균형잡히지 않은 경우를 고려해야한다.

탐색은 BFS로 수행해 순서를 맞춘다.

```cpp
bool isSymmetric(TreeNode *root) {
  queue<TreeNode *> leftQueue;
  queue<TreeNode *> rightQueue;

  if (root->left) {
    leftQueue.push(root->left);
  }
  if (root->right) {
    rightQueue.push(root->right);
  }
  while (!leftQueue.empty() && !rightQueue.empty()) {
    TreeNode *left = leftQueue.front();
    TreeNode *right = rightQueue.front();
    leftQueue.pop();
    rightQueue.pop();

    if (!left && !right) continue;
    if (!left || !right) return false;
    if (left->val != right->val) return false;

    leftQueue.push(left->left);
    leftQueue.push(left->right);

    rightQueue.push(right->right);
    rightQueue.push(right->left);
  }

  if (!leftQueue.empty() || !rightQueue.empty()) return false;

  return true;
}
```

재귀함수를 이용할 경우 다음과 같다.

```cpp
bool isSymmetric(TreeNode *root) {
  return isMirror(root, root);
}

bool isMirror(TreeNode *t1, TreeNode *t2) {
  if (!t1 && !t2) return true;
  if (!t1 || !t2) return false;

  if (t1->val != t2->val) return false;
  if (!isMirror(t1->right, t2->left)) return false;
  if (!isMirror(t1->left, t2->right)) return false;

  return true;
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      4       |

## 고생한 점

트리의 null 공간이 나올 수 있으므로 각 level마다 문자열로 치환해 문제를 풀이할 수 없음
