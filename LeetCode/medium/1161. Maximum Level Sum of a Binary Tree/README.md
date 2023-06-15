# 1161. Maximum Level Sum of a Binary Tree

[링크](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

모든 노드를 level별로 BFS순회할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

BFS순회에 O(N)의 공간 복잡도를 사용한다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     186      |    O(N)     |    O(N)     |

BFS로 레벨별로 순회하며 정답을 갱신한다.

```cpp
int maxLevelSum(TreeNode *root) {
  int maximum = INT_MIN;
  int answer = 0;

  queue<TreeNode *> q;
  q.push(root);

  int step = 1;
  while (!q.empty()) {
    int size = q.size();

    int curSum = 0;
    while (size--) {
      TreeNode *cur = q.front();
      q.pop();

      curSum += cur->val;

      if (cur->left) {
        q.push(cur->left);
      }
      if (cur->right) {
        q.push(cur->right);
      }
    }

    if (maximum < curSum) {
      maximum = curSum;
      answer = step;
    }
    step++;
  }

  return answer;
}
```

## 고생한 점
