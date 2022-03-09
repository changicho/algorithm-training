# 222. Count Complete Tree Nodes

[링크](https://leetcode.com/problems/count-complete-tree-nodes/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N, 트리의 높이를 H라고 하자. (H = log_2(N))

모든 노드를 순회하며 count를 수행할 경우 O(N)의 시간 복잡도로 풀이가 가능하다.

각 노드에서 해당 노드가 subTree의 root이고 완전이진트리인지 검사하는 데 O(H)의 시간 복잡도를 사용한다. 이를 자식 노드들에 대해 탐색을 진행할 경우 총 O(H)의 시간 복잡도를 사용한다.

### 공간 복잡도

DFS를 이용해 탐색할 경우 O(H)의 공간 복잡도를 사용한다.

### 브루트 포스

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      41      |    O(N)     |    O(H)     |

각 노드들을 탐색하며 자식 노드들의 갯수와 자기 자신을 더해 반환한다.

자식노드들은 재귀호출로 탐색하며 반환을 계속하며, 리프노드인 경우 0을 반환한다.

```cpp
int countNodes(TreeNode *root) {
  if (!root) return 0;

  return countNodes(root->left) + countNodes(root->right) + 1;
}
```

### 이진 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      35      |    O(H)     |    O(H)     |

루트부터 각 노드를 탐색하며, 해당 노드를 루트로 하는 subTree가 완전 이진 트리인지 탐색한다.

이는 leftMostNode와 rightMostNode의 height가 같은지 여부를 판단하면 되며 이 과정에 O(H)의 시간 복잡도를 사용한다.

만약 완전 이진 트리가 아닌 경우 자식 노드들에 대해서 이 탐색을 반복한다.

완전 이진 트리의 경우 노드의 개수는 다음과 같다.

- 2^H - 1

각 노드에서 이 탐색을 반복할 때, 둘 중 한 노드는 완전 이진 트리이다. (문제 조건상)

따라서 최악의 경우도 탐색은 최대 H번 진행된다.

이를 구현하면 다음과 같다.

```cpp
int countNodes(TreeNode *root) {
  if (!root) return 0;

  int leftHeight = 0, rightHeight = 0;
  TreeNode *leftNode = root, *rightNode = root;

  // O(H)
  while (leftNode) {
    leftHeight++;
    leftNode = leftNode->left;
  }
  while (rightNode) {
    rightHeight++;
    rightNode = rightNode->right;
  }

  // full case
  if (leftHeight == rightHeight) return pow(2, leftHeight) - 1;
  // O(H)
  return 1 + countNodes(root->left) + countNodes(root->right);
}
```

## 고생한 점
