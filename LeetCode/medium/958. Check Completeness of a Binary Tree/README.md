# 958. Check Completeness of a Binary Tree

[링크](https://leetcode.com/problems/check-completeness-of-a-binary-tree/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

모든 노드를 순회하며 null인 노드가 어디에 위치하는지, 혹은 갯수를 이용해 판단할 수 있다.

이 경우 모든 노드를 순회하므로 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

모든 노드를 순회할 경우 BFS, DFS에 O(N)의 공간 복잡도를 사용한다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(N)     |

트리의 모든 노드를 level별로 순회한다.

이후 null이 나오고 나서 이후에 숫자가 나오는 경우가 존재하면 complete하지 않은 경우임을 바로 판단할 수 있다.

```cpp
bool isCompleteTree(TreeNode *root) {
  queue<TreeNode *> q;

  if (root) q.push(root);
  vector<int> paths;

  while (!q.empty()) {
    TreeNode *cur = q.front();
    q.pop();

    if (cur == NULL) {
      paths.push_back(-1);
    } else {
      paths.push_back(cur->val);
    }

    if (cur) {
      q.push(cur->left);
      q.push(cur->right);
    }
  }

  bool foundNull = false;

  for (int &p : paths) {
    if (p == -1) {
      foundNull = true;
    } else if (foundNull) {
      return false;
    }
  }

  return true;
}
```

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      7       |    O(N)     |    O(N)     |

```cpp
int count(TreeNode *node) {
  if (!node) return 0;

  int left = count(node->left);
  int right = count(node->right);

  // to check x = 2^k - 1
  // we use x & (x + 1) == 0
  if ((left & (left + 1)) == 0 && left / 2 <= right && right <= left) {
    return left + right + 1;
  }
  if ((right & (right + 1)) == 0 && right <= left && left <= right * 2 + 1) {
    return left + right + 1;
  }

  return -1;
}

bool isCompleteTree(TreeNode *root) {
  bool answer = count(root) >= 0;

  return answer;
}
```

## 고생한 점
