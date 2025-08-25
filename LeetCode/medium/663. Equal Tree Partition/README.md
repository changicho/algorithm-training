# 663. Equal Tree Partition

[링크](https://leetcode.com/problems/equal-tree-partition/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 수를 N이라 하자.

DFS를 이용해 트리를 순회 후 각 노드를 서브트리의 루트로 하는 합을 구하는데 O(N)의 시간 복잡도를 사용한다.

이후 각 합을 순회하며 전체 합의 절반인지 확인하는데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

DFS로 순회시 O(N)의 공간 복잡도를 사용한다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

DFS를 이용해 각 서브트리의 합을 구하고 합들을 저장한다.

이후 루트의 합을 제외한 나머지 합들 중 전체 합의 절반과 같은 값이 있는지 확인한다.

```cpp
vector<int> sums;

int dfs(TreeNode *node) {
  int sum = node->val;

  if (node->left) {
    sum += dfs(node->left);
  }
  if (node->right) {
    sum += dfs(node->right);
  }

  sums.push_back(sum);

  return sum;
}

bool checkEqualTree(TreeNode *root) {
  int allSum = dfs(root);
  sums.pop_back();  // pop root sum
  if (abs(allSum % 2) == 1) return false;

  for (int &sum : sums) {
    if (sum == allSum) return true;
  }
  return false;
}
```

## 고생한 점
