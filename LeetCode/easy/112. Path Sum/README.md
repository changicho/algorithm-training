# 112. Path Sum

[링크](https://leetcode.com/problems/path-sum/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

모든 노드를 탐색해야 하므로 시간 복잡도는 O(N)이다.

### 공간 복잡도

각 과정마다 지나온 경로의 합을 저장해야한다.

따라서 공간 복잡도는 O(N) 이다.

### DFS

> 4ms

재귀함수를 호출하며 node->val + sum이 target과 같은지 비교한다.

```cpp
// with backtracking
bool ret;
int target;
bool hasPathSum(TreeNode *root, int targetSum) {
  target = targetSum;

  if (root) {
    recursive(root, 0);
  }

  return ret;
}

void recursive(TreeNode *node, int sum) {
  if (ret || !node) return;
  int val = node->val;

  recursive(node->left, sum + val);
  recursive(node->right, sum + val);

  if (!node->left && !node->right && sum + val == target) {
    ret = true;
  }
}
```

sum이 아닌 target과의 차이를 넘길 경우 하나의 함수로 끝낼 수 있다.

```cpp
bool hasPathSum(TreeNode *root, int targetSum) {
  if (!root) return false;
  if (!root->left && !root->right && targetSum - root->val == 0) return true;

  if (hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val)) {
    return true;
  } else {
    return false;
  }
}
```

### BFS

> 12ms

BFS를 이용해 리프노드에 도달했을 때 값이 target인지 체크한다.

```cpp
bool hasPathSum(TreeNode *root, int targetSum) {
  queue<Status> q;
  q.push({root, 0});

  while (!q.empty()) {
    Status cur = q.front();
    q.pop();

    if (!cur.node) continue;
    if (!cur.node->left && !cur.node->right) {
      if (cur.sum + cur.node->val == targetSum) return true;
      continue;
    }

    if (cur.node->left) {
      q.push({cur.node->left, cur.sum + cur.node->val});
    }
    if (cur.node->right) {
      q.push({cur.node->right, cur.sum + cur.node->val});
    }
  }

  return false;
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      4       |

## 고생한 점
