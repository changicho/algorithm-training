# 107. Binary Tree Level Order Traversal II

[링크](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

모든 노드의 개수를 N이라 하자.

모든 노드를 한번씩 방문해야 한다. 방문하는데 들어가는 시간 복잡도는 O(N)이다.

각 계층별로 노드의 값들을 저장해야한다. 해당 연산은 O(1)의 연산이 필요하다.

따라서 최종 시간 복잡도는 O(N)이다.

### 공간 복잡도

한쪽으로 치우친 트리인 경우 콜스택에 최대 N개까지 쌓일 수 있다. 또한 방문한 모든 노드를 저장해야 하므로 공간 복잡도는 O(N)이다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(N)     |

BFS를 이용해 level 별로 방문한 뒤 이후 순서를 뒤집어준다.

```cpp
vector<vector<int>> levelOrderBottom(TreeNode *root) {
  vector<vector<int>> answers;

  queue<TreeNode *> q;
  if (root) q.push(root);

  while (!q.empty()) {
    int size = q.size();
    vector<int> line;

    while (size--) {
      TreeNode *cur = q.front();
      q.pop();

      line.push_back(cur->val);

      if (cur->left) q.push(cur->left);
      if (cur->right) q.push(cur->right);
    }

    answers.push_back(line);
  }

  reverse(answers.begin(), answers.end());
  return answers;
}
```

## 고생한 점
