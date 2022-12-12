# 872. Leaf-Similar Trees

[링크](https://leetcode.com/problems/leaf-similar-trees/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

각 노드들을 순회하며 leaf 노드인 경우 배열에 저장후 이를 비교할 수 있다.

이 경우 트리의 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

leaf노드인경우 저장하는데 O(N)의 공간 복잡도를 사용한다.

재귀 호출을 이용해 노드를 탐색할 경우 O(H)의 공간 복잡도를 사용한다.

### 재귀 호출

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |  O(N + H)   |

각 과정마다 순회하며 리프노드일 때 visited에 삽입한다.

이후 두 루트노드에서의 visited가 같은지 확인한다.

```cpp
void recursive(TreeNode *node, vector<int> &visited) {
  if (!node) return;
  bool hasChild = node->left || node->right;

  if (node->left) {
    recursive(node->left, visited);
  }
  if (node->right) {
    recursive(node->right, visited);
  }
  if (!hasChild) {
    visited.emplace_back(node->val);
  }
}

vector<int> getLeafSequence(TreeNode *root) {
  vector<int> sequence;
  recursive(root, sequence);
  return sequence;
}

bool leafSimilar(TreeNode *root1, TreeNode *root2) {
  vector<int> sequence1 = getLeafSequence(root1),
              sequence2 = getLeafSequence(root2);

  return sequence1 == sequence2;
}
```

## 고생한 점
