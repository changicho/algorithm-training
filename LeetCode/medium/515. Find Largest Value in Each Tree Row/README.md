# 515. Find Largest Value in Each Tree Row

[링크](https://leetcode.com/problems/find-largest-value-in-each-tree-row/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

각 노드를 depth별로 방문하기 위해 BFS를 사용할 수 있다.

이 경우 O(N)의 공간 복잡도를 사용한다.

### 공간 복잡도

BFS탐색에 O(N)의 공간 복잡도를 사용한다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(N)     |

각 노드를 depth 별로 방문하며 이 때의 최대값을 갱신해 정답에 추가한다. (depth별)

```cpp
vector<int> largestValues(TreeNode *root) {
  vector<int> answer;

  queue<TreeNode *> q;
  if (root) q.push(root);

  while (!q.empty()) {
    int curMax = INT_MIN;
    int size = q.size();

    while (size--) {
      TreeNode *cur = q.front();
      q.pop();

      curMax = max(curMax, cur->val);

      if (cur->left) q.push(cur->left);
      if (cur->right) q.push(cur->right);
    }

    answer.push_back(curMax);
  }
  return answer;
}
```

## 고생한 점
